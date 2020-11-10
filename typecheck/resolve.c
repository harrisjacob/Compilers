#include "resolve.h"

struct hash_table* baseScope;

int resolve_tree(struct decl* tree){
	int error_state = 0;
	struct hash_table *stkPTR = NULL;
	if(scope_enter(&stkPTR)) return 1;
	error_state = decl_resolve(tree, stkPTR);
	scope_leave(&stkPTR);
	return error_state;
}

int attach_symbol(struct decl* d, symbol_t kind, struct hash_table* ht){
		int error_state = 0;
		if(!(d->symbol = symbol_create(kind, d->type, d->name))){
			printf("Declaration symbol create failed!\n");
			return 1;
		}
		error_state += expr_resolve(d->value, ht);
		if(scope_bind(d->name, d->symbol, ht)) error_state+=1;

		return error_state;
}

int decl_resolve(struct decl *d, struct hash_table *ht){
	if(!d) return 0;

	int error_state = 0;

	symbol_t kind = scope_level(ht) > 0 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;
	
	if(d->type && d->type->kind == TYPE_FUNCTION){
		//Get global scope hash table
		struct hash_table* globalScope = ht;
		while(globalScope->level != 0) globalScope = globalScope->prev;
		if(d->code){ //Actual definition
			if(!(d->symbol = scope_lookup(d->name, globalScope))){
				//This is the first occurance of this function -> make a new symbol
				error_state += attach_symbol(d,kind,ht);
			}
			if(scope_defined(d->name, d->symbol, ht) || scope_enter(&ht)) return 1;
			error_state += param_list_resolve(d->type->params, ht);
			error_state += stmt_resolve(d->code, ht);
			scope_leave(&ht);
			
			//if(scope_defined(d->name, d->symbol, ht) || scope_enter(&ht)) return 1;
			//Look for symbol and attach if found
		}else{
			//Just a prototype
			if(!(d->symbol = scope_lookup(d->name, globalScope))){
				//This is the first occurance of this function prototype -> make a new symbol
				error_state += attach_symbol(d,kind,ht);
			}	
		}
	}else{
		error_state += attach_symbol(d,kind,ht);
	}

	error_state += decl_resolve(d->next, ht);
	return (!error_state) ? 0 : 1;
	/*
	//If symbol already exists attach it
	if(d->type && d->type->kind == TYPE_FUNCTION){
		struct hash_table* globalScope = ht;
		while(ht->level != 0) globalScope = globalScope->prev;
		if((d->symbol = scope_lookup(d->name, globalScope))){
			error_state += param_list_resolve(d->type->params, ht);
			error_state += stmt_resolve(d->code, ht);
			//scope_leave(&ht);
			error_state += decl_resolve(d->next, ht);
			return (!error_state) ? 0 : 1;
		}
	}
	
	//else create a new one

	if(!(d->symbol = symbol_create(kind, d->type, d->name))){
			printf("Declaration symbol create failed!\n");
			return 1;
	}
	


	error_state += expr_resolve(d->value, ht);

	if(scope_bind(d->name, d->symbol, ht)) error_state+=1;

	if(d->code){
		//First function checks if function is already defined, second is checking entering scope
		if(scope_defined(d->name, d->symbol, ht) || scope_enter(&ht)) return 1;

		error_state += param_list_resolve(d->type->params, ht);
		error_state += stmt_resolve(d->code, ht);
		scope_leave(&ht);
	}

	error_state += decl_resolve(d->next, ht);
	*/
	//return (!error_state) ? 0 : 1;
}

int expr_resolve(struct expr *e, struct hash_table* ht){
	if(!e) return 0;

	int error_state = 0;

	if(e->kind == EXPR_ID){
		if(!(e->symbol = scope_lookup(e->name, ht))){
			printf("resolve error: %s was not declared\n", e->name);
			error_state += 1;
		}
	}else if(e->kind == EXPR_PAREN){
		error_state += expr_resolve(e->inner, ht);
	}else{
		error_state += expr_resolve(e->left, ht);
		error_state += expr_resolve(e->right, ht);
	}

	error_state += expr_resolve(e->next, ht);

	return (!error_state) ? 0 : 1;

}

int stmt_resolve(struct stmt* s, struct hash_table* ht){
	if(!s) return 0;

	int error_state = 0;
	
	switch(s->kind){
		case STMT_DECL:
			error_state += decl_resolve(s->decl, ht);
			break;
		case STMT_EXPR:
			error_state += expr_resolve(s->expr, ht);
			break;
		case STMT_IF_ELSE:
			error_state += expr_resolve(s->expr, ht);
			if(s->body && s->body->kind!=STMT_BLOCK){ 	//If the body is single line, enter a new scope
				scope_enter(&ht);
				error_state += stmt_resolve(s->body, ht);
				scope_leave(&ht);
			}else{										//If the body is multiline, let STMT_BLOCK handle scope
				error_state += stmt_resolve(s->body, ht);		
			}
			if(s->else_body){
				if(s->else_body && s->else_body->kind!=STMT_BLOCK){
					scope_enter(&ht);
					error_state += stmt_resolve(s->else_body, ht);
					scope_leave(&ht);
				}else{
					error_state += stmt_resolve(s->else_body, ht);
				}
			}
			break;
		case STMT_FOR:
			error_state += expr_resolve(s->init_expr, ht);
			error_state += expr_resolve(s->expr, ht);
			error_state += expr_resolve(s->next_expr, ht);
			if(s->body && s->body->kind!=STMT_BLOCK){		//See if_else explanation
				scope_enter(&ht);
				error_state += stmt_resolve(s->body, ht);
				scope_leave(&ht);
			}else{
				error_state += stmt_resolve(s->body, ht);
			}
			break;
		case STMT_PRINT:
			error_state += expr_resolve(s->expr,ht);
			break;
		case STMT_RETURN:
			error_state += expr_resolve(s->expr, ht);
			break;
		case STMT_BLOCK:
			scope_enter(&ht);
			error_state += stmt_resolve(s->body, ht);
			scope_leave(&ht);
			break;
		default:
			printf("Failed to resolve unknown statement type\n");
			error_state += 1;
			break;
	}

	error_state += stmt_resolve(s->next, ht);
	return (!error_state) ? 0 : 1;
}

int param_list_resolve(struct param_list* pl, struct hash_table *ht){
	if(!pl) return 0;
	int error_state = 0;

	if(!(pl->symbol = symbol_create(SYMBOL_PARAM, pl->type, pl->name))){
		printf("Parameter symbol create failed!\n");
		error_state += 1;
	}else{
		scope_bind(pl->name, pl->symbol, ht);
	}
	error_state += param_list_resolve(pl->next, ht);
	return (!error_state) ? 0 : 1;
}
