
/*
Declare token types at the top of the bison file,
causing them to be automatically generated in parser.tab.h
for use by scanner.c.
*/

	%token TOKEN_EOF
	%token TOKEN_ARRAY
	%token TOKEN_ELSE
	%token TOKEN_FALSE
	%token TOKEN_FOR
	%token TOKEN_FUNCTION
	%token TOKEN_IF
	%token TOKEN_PRINT
	%token TOKEN_RETURN
	%token TOKEN_TRUE
	%token TOKEN_VOID
	%token TOKEN_WHILE
	%token TOKEN_INTEGER
	%token TOKEN_BOOLEAN
	%token TOKEN_CHARACTER
	%token TOKEN_STRING
	%token TOKEN_INTEGER_LITERAL
	%token TOKEN_CHARACTER_LITERAL
	%token TOKEN_STRING_LITERAL
	%token TOKEN_IDENTIFIER
	%token TOKEN_L_PAREN
	%token TOKEN_R_PAREN
	%token TOKEN_L_SUB
	%token TOKEN_R_SUB
	%token TOKEN_POST_INC
	%token TOKEN_POST_DEC
	%token TOKEN_UNARY_NEG
	%token TOKEN_LOGIC_NOT
	%token TOKEN_EXP
	%token TOKEN_MULT
	%token TOKEN_DIVIDE
	%token TOKEN_MOD
	%token TOKEN_ADD
	%token TOKEN_SUB
	%token TOKEN_LT
	%token TOKEN_LE
	%token TOKEN_GT
	%token TOKEN_GE
	%token TOKEN_EQUIV
	%token TOKEN_NOT_EQUIV
	%token TOKEN_LOGIC_AND
	%token TOKEN_LOGIC_OR
	%token TOKEN_ASSIGNMENT
	%token TOKEN_SEMICOLON
	%token TOKEN_COLON
	%token TOKEN_COMMA
	%token TOKEN_L_CURLY
	%token TOKEN_R_CURLY
	%token TOKEN_BACKSLASH
	%token TOKEN_ERROR

	%union {
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	struct param_list *param_list;
	};

	%type <decl> decl decl_list program
	%type <stmt> stmt inside stmtList
	%type <expr> expr expr1 expr2 expr3 expr4 expr5 expr6 expr7 expr8 expr9 index opt_expr literal boolean optionalArgList id arrayLit
	%type <type> type
	%type <param_list> fDef fDefOpt


%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "type.h"
#include "stmt.h"
#include "expr.h"
#include "param_list.h"
/*
Clunky: Manually declare the interface to the scanner generated by flex. 
*/

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
extern struct decl* program_output;
//extern void check_paren(struct expr** e);
%}

%%

/* Here is the grammar: program is the start symbol. */

program : decl_list TOKEN_EOF { program_output = $1; return 0; }
		;

decl_list: decl decl_list
			{ 	

				$1->next = $2;
				$$ = $1; 
			}
		| /*epsilon*/
			{ $$ = NULL; }
		;

decl 	: id TOKEN_COLON type TOKEN_SEMICOLON																		//declaration without assignment
			{ $$ = decl_create((char *) $1->name, $3, NULL, NULL, NULL); }
		| id TOKEN_COLON type TOKEN_ASSIGNMENT expr TOKEN_SEMICOLON													//declaration with expression assignment
			{ $$ = decl_create((char *)$1->name, $3, $5, NULL, NULL); }
		| id TOKEN_COLON type TOKEN_ASSIGNMENT TOKEN_L_CURLY stmtList TOKEN_R_CURLY									//declaration with block assignment
			{ $$ = decl_create((char *)$1->name, $3, NULL, $6, NULL); }
		// | id TOKEN_COLON type TOKEN_ASSIGNMENT TOKEN_L_CURLY bracList TOKEN_R_CURLY TOKEN_SEMICOLON					//declaration with array assignment
		// 	{ $$ = decl_create((char *)$1->name, $3, NULL, $6, NULL); }
		;

stmtList: stmt stmtList
			{
				$1->next = $2;
				$$ = $1;
			}
		| /*epsilon*/
			{ $$ = NULL; }
		;

stmt 	: TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN stmt 															//if 1
			{ $$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $3, NULL, $5, NULL, NULL); }
		| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN inside TOKEN_ELSE stmt 											//if 2
			{ $$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $3, NULL, $5, $7, NULL);}
		| TOKEN_FOR TOKEN_L_PAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_R_PAREN stmt 	//for()stmt
			{ $$ = stmt_create(STMT_FOR, NULL, $3, $5, $7, $9, NULL, NULL); }
		| TOKEN_RETURN expr TOKEN_SEMICOLON 																		//return
			{ $$ = stmt_create(STMT_RETURN, NULL, NULL, $2, NULL, NULL, NULL, NULL); }
		| TOKEN_L_CURLY stmtList TOKEN_R_CURLY 																		//body
			{ $$ = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, $2, NULL, NULL); }		
		| TOKEN_PRINT optionalArgList TOKEN_SEMICOLON																//print
			{ $$ = stmt_create(STMT_PRINT, NULL, NULL, $2, NULL, NULL, NULL, NULL); }		
		| decl 																										// declaration
			{ $$ = stmt_create(STMT_DECL, $1, NULL, NULL, NULL, NULL, NULL, NULL); }	
		| expr TOKEN_SEMICOLON																						// regular statement
			{ $$ = stmt_create(STMT_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); }	
		;
//inside must pass statements up
inside 	: TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN inside TOKEN_ELSE inside										//if3
			{ $$ = stmt_create(STMT_IF_ELSE, NULL, NULL, $3, NULL, $5, $7, NULL);}
		| TOKEN_FOR TOKEN_L_PAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_R_PAREN inside	//for()stmt
			{ $$ = stmt_create(STMT_FOR, NULL, $3, $5, $7, $9, NULL, NULL); }
		| TOKEN_RETURN expr TOKEN_SEMICOLON																			//return
			{ $$ = stmt_create(STMT_RETURN, NULL, NULL, $2, NULL, NULL, NULL, NULL); }
		| TOKEN_L_CURLY stmtList TOKEN_R_CURLY																		//body
			{ $$ = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, $2, NULL, NULL); }
		| TOKEN_PRINT optionalArgList TOKEN_SEMICOLON																//print
			{ $$ = stmt_create(STMT_PRINT, NULL, NULL, $2, NULL, NULL, NULL, NULL); }
		| decl 																										//declaration
			{ $$ = stmt_create(STMT_DECL, $1, NULL, NULL, NULL, NULL, NULL, NULL); }
		| expr TOKEN_SEMICOLON																					// regular statement
			{ $$ = stmt_create(STMT_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); }
		;

type 	: TOKEN_INTEGER
			{ $$ = type_create(TYPE_INTEGER, NULL, NULL, NULL); } 
		| TOKEN_BOOLEAN
			{ $$ = type_create(TYPE_BOOLEAN, NULL, NULL, NULL); }
		| TOKEN_CHARACTER
			{ $$ = type_create(TYPE_CHARACTER, NULL, NULL, NULL); }
		| TOKEN_STRING
			{ $$ = type_create(TYPE_STRING, NULL, NULL, NULL); }
		| TOKEN_FUNCTION type TOKEN_L_PAREN fDefOpt TOKEN_R_PAREN
			{ $$ = type_create(TYPE_FUNCTION, $2, $4, NULL); }


		| TOKEN_ARRAY TOKEN_L_SUB expr TOKEN_R_SUB type
			{ $$ = type_create(TYPE_ARRAY, $5, NULL, $3); }


		| TOKEN_ARRAY TOKEN_L_SUB TOKEN_R_SUB type
			{ $$ = type_create(TYPE_ARRAY, $4, NULL, NULL); }
		| TOKEN_VOID
			{ $$ = type_create(TYPE_VOID, NULL, NULL, NULL);}
		;


literal : TOKEN_INTEGER_LITERAL
			{ $$ = expr_create_integer_literal(atoi(yytext)); }
		| TOKEN_CHARACTER_LITERAL
			{ $$ = expr_create_char_literal(yytext[0]); }
		| TOKEN_STRING_LITERAL
			{ $$ = expr_create_string_literal(yytext); }
		| TOKEN_L_CURLY arrayLit TOKEN_R_CURLY
			{ $$ = expr_create_paren(EXPR_ARRAY_LIT, $2, NULL); } 
			//$$ = expr_create(EXPR_ARRAY_LIT, 0, 0, $2); }
		;

arrayLit: expr
		{ $$ = $1; }
		| expr TOKEN_COMMA arrayLit
		{ 
			$1->next = $3;
			$$ = $1;
		}


boolean : TOKEN_TRUE
			{ $$ = expr_create_boolean_literal(1); }
		| TOKEN_FALSE
			{ $$ = expr_create_boolean_literal(0); }
		;

fDefOpt : /* epsilon */
			{ $$ = NULL; }
		| fDef
			{ $$ = $1; }
		;

fDef 	: id TOKEN_COLON type
			{ $$ = param_list_create((char *)$1->name, $3, NULL); }
		| id TOKEN_COLON type TOKEN_COMMA fDef
			{ $$ = param_list_create((char *)$1->name, $3, $5); }
		;

optionalArgList	: /*no args*/
					{ $$ = NULL; }
				| arrayLit
					{ $$ = $1; }
				;
//Returns an expr
// argList : expr 																			//expr
// 			{ $$ = $1; }
// 		| expr TOKEN_COMMA argList 														// expr, expr, ...
// 			{
// 				$1 -> next = $3;
// 				$$ = $1;
// 			}
// 		;
// //Returns a statement
// bracList: argList
// 			{ $$ = stmt_create(STMT_LIST, NULL, NULL, $1, NULL, NULL, NULL, NULL); }
// 		| TOKEN_L_CURLY bracList TOKEN_R_CURLY
// 			{ $$ = stmt_create(STMT_LIST, NULL, NULL, NULL, NULL, $2, NULL, NULL); }
// 		| TOKEN_L_CURLY bracList TOKEN_R_CURLY TOKEN_COMMA bracList
// 			{ $$ = stmt_create(STMT_LIST, NULL, NULL, NULL, NULL, $2, NULL, $5); }
// 		;


expr	: id TOKEN_ASSIGNMENT expr
			{ $$ = expr_create(EXPR_ASSIGN, $1, $3, NULL);}
		| index TOKEN_ASSIGNMENT expr
			{ $$ = expr_create(EXPR_ASSIGN, $1, $3, NULL); }
		| expr1
			{ $$ = $1; }
		;

expr1	: expr2 TOKEN_LOGIC_OR expr1
			{ $$ = expr_create(EXPR_OR, $1, $3, NULL); }
		| expr2
			{ $$ = $1; }
		;

expr2	: expr3 TOKEN_LOGIC_AND expr2
			{ $$ = expr_create(EXPR_AND, $1, $3, NULL); }
		| expr3
			{ $$ = $1; }
		;

expr3	: expr4 TOKEN_LT expr3
			{ $$ = expr_create(EXPR_LT, $1, $3, NULL); }
		| expr4 TOKEN_LE expr3
			{ $$ = expr_create(EXPR_LE, $1, $3, NULL); }
		| expr4	TOKEN_GT expr3
			{ $$ = expr_create(EXPR_GT, $1, $3, NULL); }
		| expr4 TOKEN_GE expr3
			{ $$ = expr_create(EXPR_GE, $1, $3, NULL); }
		| expr4 TOKEN_EQUIV expr3
			{ $$ = expr_create(EXPR_EQ, $1, $3, NULL); }
		| expr4 TOKEN_NOT_EQUIV expr3
			{ $$ = expr_create(EXPR_NEQ, $1, $3, NULL); }
		| expr4
			{ $$ = $1; }
		;

expr4	: expr5 TOKEN_ADD expr4
			{ $$ = expr_create(EXPR_ADD, $1, $3, NULL); }
		| expr5 TOKEN_SUB expr4
			{  $$ = expr_create(EXPR_SUB, $1, $3, NULL); }
		| expr5
			{ $$ = $1; }
		;

expr5	: expr6 TOKEN_MULT expr5
			{ $$ = expr_create(EXPR_MUL, $1, $3, NULL); }
		| expr6 TOKEN_DIVIDE expr5
			{ $$ = expr_create(EXPR_DIV, $1, $3, NULL); }
		| expr6 TOKEN_MOD expr5
			{ $$ = expr_create(EXPR_MOD, $1, $3, NULL); }
		| expr6
			{ $$ = $1; }
		;

expr6	: expr7 TOKEN_EXP expr6
			{ $$ = expr_create(EXPR_EXP, $1, $3, NULL); }
		| expr7
			{ $$ = $1; }
		;

expr7	: TOKEN_SUB expr7
			{ $$ = expr_create(EXPR_NEG, NULL, $2, NULL); }
		| TOKEN_LOGIC_NOT expr7
			{ $$ = expr_create(EXPR_NOT, NULL, $2, NULL); }
		| expr8
			{ $$ = $1; }
		;

expr8	: expr9 TOKEN_POST_INC
			{

				$$ = expr_create(EXPR_POST_INC, $1, NULL, NULL); 
			}
		| expr9 TOKEN_POST_DEC
			{ 
				$$ = expr_create(EXPR_POST_DEC, $1, NULL, NULL); 
			}

		| expr9
			{ $$ = $1; }
		;

expr9	: literal
			{ $$ = $1; }
		| TOKEN_L_PAREN expr TOKEN_R_PAREN
			{ $$ = expr_create_paren(EXPR_PAREN, $2, NULL); }
		| id
			{ $$ = $1; }
		| boolean
			{ $$ = $1; }
		| index
			{ $$ = $1; }
		| id TOKEN_L_PAREN optionalArgList TOKEN_R_PAREN
			{ $$ = expr_create(EXPR_FUNC, $1, $3, NULL); }
		;

index	: expr9 TOKEN_L_SUB expr TOKEN_R_SUB
			{ $$ = expr_create(EXPR_INDEX, $1, $3, NULL); }
 		;

id 		: TOKEN_IDENTIFIER
			{ $$ = expr_create_name(yytext); }
		;

opt_expr: /*no epxr*/
 			{ $$ = NULL; }
		| expr
			{ $$ = $1; }
		;


%%

/*
This function will be called by bison if the parse should
encounter an error.  In principle, "str" will contain something
useful.  In practice, it often does not.
*/

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}

