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
		e->symbol = scope_lookup(e->name, ht);
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
			scope_enter(&ht);
			stmt_resolve(s->body, ht);
			scope_leave(&ht);
			scope_enter(&ht);
			stmt_resolve(s->else_body, ht);
			scope_leave(&ht);
			break;
		case STMT_FOR:
			expr_resolve(s->init_expr, ht);
			expr_resolve(s->expr, ht);
			expr_resolve(s->next_expr, ht);
			scope_enter(&ht);
			stmt_resolve(s->body, ht);
			scope_leave(&ht);
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
	if(!(pl->symbol = symbol_create(SYMBOL_PARAM, pl->type, pl->name))) printf("Parameter symbol create failed!\n");
	param_list_resolve(pl->next, ht);
}