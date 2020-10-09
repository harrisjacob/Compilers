
#ifndef STMT_H
#define STMT_H

#include "decl.h"

typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK
} stmt_t;

struct stmt {
	stmt_t kind;
	struct decl *decl;
	struct expr *init_expr;
	struct expr *expr;
	struct expr *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
};

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

void stmt_print( struct stmt *s, int indent );


#endif
