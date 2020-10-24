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
			print_tabs(indent);
			expr_print(s->expr);
			printf(";\n");
			break;
		case STMT_IF_ELSE:
			print_tabs(indent);
			printf("if(");
			expr_print(s->expr);
			printf(") {\n");
			//Read one pointer into the block so that if-else handles tabs for its body
			print_body(s->body, indent);
			print_tabs(indent);
			printf("}");
			if(s->else_body){
				printf(" else {\n");
				print_body(s->else_body, indent);
				print_tabs(indent);
				printf("}\n");
			}else{
				printf("\n");
			}

			break;
		case STMT_FOR:
			print_tabs(indent);
			printf("for(");
			expr_print(s->init_expr);
			printf(";");
			expr_print(s->expr);
			printf(";");
			expr_print(s->next_expr);
			printf(") {\n");
			print_body(s->body, indent);
			print_tabs(indent);
			printf("}\n");
			break;
		case STMT_PRINT:
			print_tabs(indent);
			printf("print ");
			if(s->expr){
				struct expr *t = s->expr;
				while(t){
					expr_print(t);
					if(t->right)printf(", ");
					t = t->right;
				}
			}
			printf(";\n");
			break;
		case STMT_RETURN:
			print_tabs(indent);
			printf("return ");
			expr_print(s->expr);
			printf(";\n");
			break;
		case STMT_BLOCK:
			print_tabs(indent);
			printf("{\n");
			stmt_print(s->body, indent+1);
			printf("\n");
			print_tabs(indent);
			printf("}\n");
			break;
		case STMT_LIST:
			printf("{");
			expr_print(s->expr);
			printf("}");
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

void print_body(struct stmt* s, int indent){
	if(!s) return;
	if(s->kind == STMT_BLOCK){
		stmt_print(s->body, indent+1);
	}else{
		stmt_print(s, indent+1);
	}
}