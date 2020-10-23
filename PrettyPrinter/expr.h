#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{ //used to enforce operator precedence
	e_Class0,		// default low
	e_Class1,		// =
	e_Class2,		// ||
	e_Class3,		// &&
	e_Class4,		// <, <=, >, >=, ==, !=
	e_Class5,		// +, -
	e_Class6,		// *, /, %
	e_Class7,		// ^
	e_Class8,		// -, !
	e_Class9,		// ++, --
	e_Class10,		// (), [], f()
	e_Class11		// literals, id
} expr_class;


typedef enum {
	EXPR_ASSIGN,
	EXPR_OR,
	EXPR_AND,
	EXPR_LT,
	EXPR_LE,
	EXPR_GT,
	EXPR_GE,
	EXPR_EQ,
	EXPR_NEQ,
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MOD,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_EXP,
	EXPR_NEG,
	EXPR_NOT,
	EXPR_POST_INC,
	EXPR_POST_DEC,
	EXPR_INDEX,
	EXPR_FUNC,
	EXPR_PAREN,
	EXPR_ID,
	EXPR_INT_LIT,
	EXPR_BOOL_LIT,
	EXPR_CHAR_LIT,
	EXPR_STRING_LIT,
	EXPR_ARRAY_LIT
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
	struct expr* inner;
	struct expr* next;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right, struct expr *next);

struct expr * expr_create_paren(expr_t kind, struct expr * inner, struct expr *next);

struct expr * expr_create_name( const char *n );

struct expr * expr_create_integer_literal( int c );

struct expr * expr_create_boolean_literal( int c );

struct expr * expr_create_char_literal( char c );

struct expr * expr_create_string_literal( const char *str );

void expr_print( struct expr *e );

void check_parens(expr_class p_OP, struct expr *f, int rArg);

expr_class expr_get_class(expr_t e);

// void expr_operator(char* oper, struct expr* e);

// void check_right_parens(expr_t p_OP, struct expr *f);

// void check_left_parens(expr_t p_OP, struct expr *f);

#endif
