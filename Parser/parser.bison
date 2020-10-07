
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

%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Clunky: Manually declare the interface to the scanner generated by flex. 
*/

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
%}

%%

/* Here is the grammar: program is the start symbol. */

program : decl_list TOKEN_EOF { return 0; }
		;

decl_list: decl decl_list
		| /*epsilon*/
		;

decl 	: TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_SEMICOLON
		| TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGNMENT stmt2
		;

stmtList: stmt stmtList
		| /*epsilon*/
		;

stmt 	: if
		| for
		| print
		| return
		| stmt2
		;

stmt2 	: expr TOKEN_SEMICOLON
		| decl
		| fcall
		| TOKEN_L_CURLY stmtList TOKEN_R_CURLY
		| TOKEN_L_CURLY argList TOKEN_R_CURLY TOKEN_SEMICOLON
		;

type 	: TOKEN_INTEGER 
		| TOKEN_BOOLEAN
		| TOKEN_CHARACTER
		| TOKEN_STRING
		| TOKEN_FUNCTION type TOKEN_L_PAREN fDefOpt TOKEN_R_PAREN
		| TOKEN_ARRAY TOKEN_L_SUB expr TOKEN_R_SUB type
		| TOKEN_VOID
		;

fDefOpt : /* epsilon */
		| fDef
		;

fDef 	: TOKEN_IDENTIFIER TOKEN_COLON type
		| TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_COMMA fDef
		;



if 		: TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN stmt
		| TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN inside TOKEN_ELSE stmt
		// | TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN ifEnds
		// | TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN inside TOKEN_ELSE ifEnds
		;

inside	: TOKEN_IF TOKEN_L_PAREN expr TOKEN_R_PAREN inside TOKEN_ELSE inside
		| stmt2
		;

fcall	: TOKEN_IDENTIFIER TOKEN_L_PAREN optionalArgList TOKEN_R_PAREN TOKEN_SEMICOLON
 		;

optionalArgList	: /*no args*/
				| argList
				;

argList : expr
		| expr TOKEN_COMMA argList
		;
// stmt_m	: stmt_m2
// 		| fDef stmt_m
// 		|
// 		;

// stmt_m2 : flow stmt_m



// flow	: stmt
// 		| if
// 		| for
// 		| print
// 		;

// stmt	: expr TOKEN_SEMICOLON
// 		| return
// 		;



// ifEnds	: print
// 		| stmt
// 		;

// body	: TOKEN_L_CURLY stmt_m2 TOKEN_R_CURLY
//		;



// ifBody 	: body
// 		| ifEnds
// 		;

// fDef	: fDecl TOKEN_ASSIGNMENT body
//		;

// arrDef	: arrDecl TOKEN_ASSIGNMENT TOKEN_L_CURLY argList TOKEN_R_CURLY
// 		;

// decl 	: arrDecl
// 		| decl1
// 		;

// arrDecl : TOKEN_IDENTIFIER TOKEN_COLON arrSize moreArr type
//		;

// arrSize : TOKEN_ARRAY TOKEN_L_SUB TOKEN_INTEGER_LITERAL TOKEN_R_SUB
// 		;

// moreArr	:
// 		| arrSize moreArr
// 		;

// decl1 	: TOKEN_IDENTIFIER TOKEN_COLON type
// 		| TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGNMENT expr
// 		| fDecl
// 		;


// fDecl	: TOKEN_IDENTIFIER TOKEN_COLON TOKEN_FUNCTION type TOKEN_L_PAREN optFargs TOKEN_R_PAREN
// 		;

// optFargs:
// 		| fargs
// 		;

// fargs 	: fargs1
// 		| fargs1 TOKEN_COMMA fargs
// 		;

// fargs1 	: decl
// 		| TOKEN_IDENTIFIER TOKEN_COLON TOKEN_ARRAY TOKEN_L_SUB TOKEN_R_SUB type




literal : TOKEN_INTEGER_LITERAL
		| TOKEN_CHARACTER_LITERAL
		| TOKEN_STRING_LITERAL
		;

expr	: TOKEN_IDENTIFIER TOKEN_ASSIGNMENT expr
		| index TOKEN_ASSIGNMENT expr
		| expr1
		;

expr1	: expr2 TOKEN_LOGIC_OR expr1
		| expr2
		;

expr2	: expr3 TOKEN_LOGIC_AND expr2
		| expr3
		;

expr3	: expr4 TOKEN_LT expr3
		| expr4 TOKEN_LE expr3
		| expr4	TOKEN_GT expr3
		| expr4 TOKEN_GE expr3
		| expr4 TOKEN_EQUIV expr3
		| expr4 TOKEN_NOT_EQUIV expr3
		| expr4
		;

expr4	: expr5 TOKEN_ADD expr4
		| expr5 TOKEN_SUB expr4
		| expr5
		;

expr5	: expr6 TOKEN_MULT expr5
		| expr6 TOKEN_DIVIDE expr5
		| expr6 TOKEN_MOD expr5
		| expr6
		;

expr6	: expr7 TOKEN_EXP expr6
		| expr7
		;

expr7	: TOKEN_SUB expr7
		| TOKEN_LOGIC_NOT expr7
		| expr8
		;

expr8	: expr9 TOKEN_POST_INC
		| expr9 TOKEN_POST_DEC
		| expr9
		;

expr9	: literal
		| TOKEN_L_PAREN expr TOKEN_R_PAREN
		| TOKEN_IDENTIFIER
		| boolean
		| index
		;

 index	: expr9 TOKEN_L_SUB expr TOKEN_R_SUB
 		;

boolean : TOKEN_TRUE
		| TOKEN_FALSE
		;

for 	: TOKEN_FOR TOKEN_L_PAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_R_PAREN stmt
		;

opt_expr: /*no epxr*/
		| expr
		;

return 	: TOKEN_RETURN stmt
		;

print 	: TOKEN_PRINT optionalArgList TOKEN_SEMICOLON
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
