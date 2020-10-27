#include "resolve.h"

int resolve_tree(struct decl* tree){
	struct hash_table *stkPTR = NULL;
	if(scope_enter(&stkPTR)) return 1;
	decl_resolve(tree, stkPTR);
	scope_leave(&stkPTR);

	return 0;
}

int decl_resolve(struct decl *d, struct hash_table *ht){
	
	if(!d) return 1;

	symbol_t kind = scope_level(ht) > 0 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;

	if(!(d->symbol = symbol_create(kind, d->type, d->name))){
			printf("Declaration symbol create failed!\n");
			return 1;
	}

	expr_resolve(d->value, ht);
	if(scope_bind(d->name, d->symbol, ht)) return 1;

	if(d->code){
		d->symbol->which = 1;
		if(scope_enter(&ht)) return 1;
		param_list_resolve(d->type->params, ht);
		stmt_resolve(d->code, ht);
		scope_leave(&ht);
	}

	decl_resolve(d->next, ht);

	return 0;
}

void expr_resolve(struct expr *e, struct hash_table* ht){
	if(!e) return;

	if(e->kind == EXPR_ID){
		if(!(e->symbol = scope_lookup(e->name, ht))){
			undeclared(e->name);
		}
	}else if(e->kind == EXPR_PAREN){
		expr_resolve(e->inner, ht);
	}else{
		expr_resolve(e->left, ht);
		expr_resolve(e->right, ht);
	}

	expr_resolve(e->next, ht);

}

void stmt_resolve(struct stmt* s, struct hash_table* ht){
	if(!s) return;

	switch(s->kind){
		case STMT_DECL:
			decl_resolve(s->decl, ht);
			break;
		case STMT_EXPR:
			expr_resolve(s->expr, ht);
			break;
		case STMT_IF_ELSE:
			expr_resolve(s->expr, ht);
			if(s->body && s->body->kind!=STMT_BLOCK){ 	//If the body is single line, enter a new scope
				scope_enter(&ht);
				stmt_resolve(s->body, ht);
				scope_leave(&ht);
			}else{										//If the body is multiline, let STMT_BLOCK handle scope
				stmt_resolve(s->body, ht);		
			}
			if(s->else_body){
				if(s->else_body && s->else_body->kind!=STMT_BLOCK){
					scope_enter(&ht);
					stmt_resolve(s->else_body, ht);
					scope_leave(&ht);
				}else{
					 stmt_resolve(s->else_body, ht);
				}
			}
			break;
		case STMT_FOR:
			expr_resolve(s->init_expr, ht);
			expr_resolve(s->expr, ht);
			expr_resolve(s->next_expr, ht);
			if(s->body && s->body->kind!=STMT_BLOCK){		//See if_else explanation
				scope_enter(&ht);
				stmt_resolve(s->body, ht);
				scope_leave(&ht);
			}else{
				stmt_resolve(s->body, ht);
			}
			break;
		case STMT_PRINT:
			expr_resolve(s->expr,ht);
			break;
		case STMT_RETURN:
			expr_resolve(s->expr, ht);
			break;
		case STMT_BLOCK:
			scope_enter(&ht);
			stmt_resolve(s->body, ht);
			scope_leave(&ht);
			break;
		default:
			printf("Failed to resolve unknown statement type\n");
			return;
	}

	stmt_resolve(s->next, ht);
}

void param_list_resolve(struct param_list* pl, struct hash_table *ht){
	if(!pl) return;
	if(!(pl->symbol = symbol_create(SYMBOL_PARAM, pl->type, pl->name))){
		printf("Parameter symbol create failed!\n");
	}else{
		scope_bind(pl->name, pl->symbol, ht);
	}
	param_list_resolve(pl->next, ht);
}

void undeclared(const char* name){
	printf("\nMy dear, sweet, innocent friend,\n\n");
	printf("If my records are correct, sometime in the chaos of today you forgot to declare %s.\n", name);
	printf("Maybe it's mispelled. Maybe you commented out the declaration. Maybe you just didn't\n");
	printf("declare it because you assumed somebody else would come along and declare it for you.\n");
	printf("Well I'm sorry to break the news to you, but nobody is going to declare %s for you.\n", name);
	printf("You'll have to do that yourself. Please give %s a proper declaration so we can get\n", name);
	printf("this whole execution thing underway.\n\nSincerely,\n\t The Name Resolver\n\n");
}