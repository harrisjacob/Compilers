#include "stmt.h"

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ){
	struct stmt* newStmt;
	
	if(!(newStmt = malloc(sizeof(struct stmt)))){
		printf("AST: Failed to allocate stmt structure");
		return NULL;
	}

	newStmt->kind = kind;
	newStmt->decl = decl;
	newStmt->init_expr = init_expr;
	newStmt->expr = expr;
	newStmt->next_expr = next_expr;
	newStmt->body = body;
	newStmt->else_body = else_body;
	newStmt->next = next;

	return newStmt;
}

void stmt_print( struct stmt *s, int indent ){
	if(!s) return;
	switch(s->kind){
		case STMT_DECL:
			decl_print(s->decl, indent);
			break;
		case STMT_EXPR:
			expr_print(s->expr);
			break;
		case STMT_IF_ELSE:
			printf("if(");
			expr_print(s->expr);
			printf(") {\n");
			stmt_print(s->body, indent);
			printf("\n} else {\n");
			stmt_print(s->else_body, indent);
			printf("}\n");
			break;
		case STMT_FOR:
			printf("for(");
			expr_print(s->init_expr);
			printf(";");
			expr_print(s->expr);
			printf(";");
			expr_print(s->next_expr);
			printf(")");
			stmt_print(s->body, indent);
			break;
		case STMT_PRINT:
			printf("print ");
			if(s->expr){
				struct expr *t = s->expr;
				expr_print(t);
				while(t->right){
					printf(", ");
					expr_print(t);
					t = t->right;
				}
			}
			break;
		case STMT_RETURN:
			printf("return ");
			expr_print(s->expr);
			break;
		case STMT_BLOCK:
			printf("{\n");
			stmt_print(s->body, indent);
			printf("\n}");
			break;
		default: 
			printf("Something broke in stmt\n");
			return;

	}
	stmt_print(s->next, indent);
}
