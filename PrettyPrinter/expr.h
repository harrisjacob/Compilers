#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_INDEX,
	EXPR_PAR,
	EXPR_FUNC,
	EXPR_POST_INC,
	EXPR_POST_DEC,
	EXPR_NEG,
	EXPR_NOT,
	EXPR_EXP,
	EXPR_MOD,
	EXPR_LT,
	EXPR_LE,
	EXPR_GT,
	EXPR_GE,
	EXPR_EQ,
	EXPR_NEQ,
	EXPR_AND,
	EXPR_OR,
	EXPR_ASSIGN
	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	int literal_value;
	const char * string_literal;
	struct symbol *symbol;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name( const char *n );

struct expr * expr_create_integer_literal( int c );

struct expr * expr_create_boolean_literal( int c );

struct expr * expr_create_char_literal( char c );

struct expr * expr_create_string_literal( const char *str );

void expr_print( struct expr *e );

#endif
