#include "library.h"

void print_integer( long x )
{
	printf("%ld",x);
}

void print_string( const char *s )
{
	printf("%s",s);
}

void print_boolean( int b )
{
	printf("%s",b?"true":"false");
}

void print_character( char c )
{
	printf("%c",c);
}

long integer_power( long x, long y )
{
	long result = 1;
	while(y>0) {
		result = result * x;
		y = y -1;
	}
	return result;
}

void print_expr_t(expr_t t){
	printf("'");
	switch(t){	
		case EXPR_ASSIGN:
			printf("assignment");
			break;
		case EXPR_OR:
			printf("logical OR");
			break;
		case EXPR_AND:
			printf("logical AND");
			break;
		case EXPR_LT:
			printf("less than comparison");
			break;
		case EXPR_LE:
			printf("less than or equal to comparison");
			break;
		case EXPR_GT:
			printf("greater than comparison");
			break;
		case EXPR_GE:
			printf("greater than or equal to comparison");
			break;
		case EXPR_EQ:
			printf("equivalent comparison");
			break;
		case EXPR_NEQ:
			printf("nonequivalent comparison");
			break;
		case EXPR_ADD:
			printf("addition");
			break;
		case EXPR_SUB:
			printf("subraction");
			break;
		case EXPR_MOD:
			printf("modulus");
			break;
		case EXPR_MUL:
			printf("multiplication");
			break;
		case EXPR_DIV:
			printf("division");
			break;
		case EXPR_EXP:
			printf("exponentiation");
			break;
		case EXPR_NEG:
			printf("unary negation");
			break;
		case EXPR_NOT:
			printf("logical NOT");
			break;
		case EXPR_POST_INC:
			printf("postfix incrementation");
			break;
		case EXPR_POST_DEC:
			printf("postfix decrementation");
			break;
		case EXPR_INDEX:
			printf("array subscript");
			break;
		case EXPR_FUNC:
			printf("function call");
			break;
		case EXPR_PAREN:
			printf("grouping");
			break;
		case EXPR_ID:
			printf("identifier");
			break;
		case EXPR_INT_LIT:
			printf("integer literal");
			break;
		case EXPR_BOOL_LIT:
			printf("boolean literal");
			break;
		case EXPR_CHAR_LIT:
			printf("character literal");
			break;
		case EXPR_STRING_LIT:
			printf("string literal");
			break;
		case EXPR_ARRAY_LIT:
			printf("array literal");
			break;
		default:
			printf("unknown");
			break;
	}
	printf("'");
}

void print_type_t(type_t t){
	//Just a wrapper for the getType function defined in type.c
	printf("'%s'", getType(t));
}