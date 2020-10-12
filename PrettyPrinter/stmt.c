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
			print_tabs(indent);
			decl_print(s->decl, indent);
			break;
		case STMT_EXPR:
			print_tabs(indent);
			expr_print(s->expr);
			break;
		case STMT_IF_ELSE:
			print_tabs(indent);
			printf("if(");
			expr_print(s->expr);
			printf(") {\n");
			//Read one pointer into the block so that if-else handles tabs for its body
			if(s->body && s->body->kind == STMT_BLOCK)stmt_print(s->body->body, indent+1);
			//stmt_print(s->body, indent);
			print_tabs(indent);
			printf("} else {\n");
			if(s->else_body && s->else_body->kind == STMT_BLOCK)stmt_print(s->else_body->body, indent+1);
			print_tabs(indent);
			printf("}\n");
			//stmt_print(s->else_body, indent);
			break;
		case STMT_FOR:
			print_tabs(indent);
			printf("for(");
			expr_print(s->init_expr);
			printf(";");
			expr_print(s->expr);
			printf(";");
			expr_print(s->next_expr);
			printf(")");
			stmt_print(s->body, indent+2);
			break;
		case STMT_PRINT:
			print_tabs(indent);
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
			print_tabs(indent);
			printf("return ");
			expr_print(s->expr);
			printf(";\n");
			break;
		case STMT_BLOCK:
			printf("{\n");
			print_tabs(indent);
			stmt_print(s->body, indent);
			printf("\n");
			print_tabs(indent);
			printf("}\n");
			break;
		default: 
			printf("Something broke in stmt\n");
			return;

	}
	stmt_print(s->next, indent);
}

void print_tabs(int indent){
	int i;
	for(i=0;i<indent;i++,printf("\t"));
}