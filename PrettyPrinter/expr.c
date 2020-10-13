#include "expr.h"

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
	struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}

	newExpr->kind = kind;
	newExpr->left = left;
	newExpr->right = right;

	return newExpr;
}

struct expr * expr_create_name( const char *n ){
	struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}

	newExpr->name = strdup(n);
	newExpr->kind = EXPR_ID;

	return newExpr;
}

struct expr * expr_create_integer_literal( int c ){
		struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}

	newExpr->literal_value = c;
	newExpr->kind = EXPR_INT_LIT;

	return newExpr;
}

struct expr * expr_create_boolean_literal( int c ){
	struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}

	newExpr->literal_value = c;
	newExpr->kind = EXPR_BOOL_LIT;

	return newExpr;
}

struct expr * expr_create_char_literal( char c ){
	struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}
	newExpr->literal_value = (int) c;
	newExpr->kind = EXPR_CHAR_LIT;

	return newExpr;
}

struct expr * expr_create_string_literal( const char *str ){
	struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}

	newExpr-> string_literal = strdup(str);
	newExpr->kind = EXPR_STRING_LIT;

	return newExpr;
}

void expr_print( struct expr *e ){
	if(!e) return;
	switch(e->kind){
		case EXPR_ADD:
			expr_operator("+", e->left, e->right);
			break;
		case EXPR_SUB:
			expr_operator("-", e->left, e->right);
			break;
		case EXPR_MUL:
			expr_operator("*", e->left, e->right);
			break;
		case EXPR_DIV:
			expr_operator("/", e->left, e->right);
			break;
		case EXPR_INDEX:
			expr_print(e->left);
			printf("[");
			expr_print(e->right);
			printf("]");
			break;
		case EXPR_FUNC:
			expr_print(e->left);
			printf("(");
			expr_print(e->right);
			printf(")");
			break;
		case EXPR_POST_INC:
			expr_print(e->right);
			printf("++");
			break;
		case EXPR_POST_DEC:
			expr_print(e->right);
			printf("--");
			break;
		case EXPR_NEG:
			printf("-");
			expr_print(e->right);
			break;
		case EXPR_NOT:
			printf("!");
			expr_print(e->right);
			break;
		case EXPR_EXP:
			expr_operator("^", e->left, e->right);
			break;
		case EXPR_MOD:
			expr_operator("%", e->left, e->right);
			break;
		case EXPR_LT:
			expr_operator("<", e->left, e->right);
			break;
		case EXPR_LE:
			expr_operator("<=", e->left, e->right);
			break;
		case EXPR_GT:
			expr_operator(">", e->left, e->right);
			break;
		case EXPR_GE:
			expr_operator(">=", e->left, e->right);
			break;
		case EXPR_EQ:
			expr_operator("==", e->left, e->right);
			break;
		case EXPR_NEQ:
			expr_operator("!=", e->left, e->right);
			break;
		case EXPR_AND:
			expr_operator("&&", e->left, e->right);
			break;
		case EXPR_OR:
			expr_operator("||", e->left, e->right);
			break;
		case EXPR_ASSIGN:
			expr_operator("=", e->left, e->right);
			break;
		case EXPR_ID:
			printf("%s", e->name);
			break;
		case EXPR_INT_LIT:
			printf("%i", e->literal_value);
			break;
		case EXPR_BOOL_LIT:
			printf("%s", (e->literal_value) ? "true" : "false" );
			break;
		case EXPR_CHAR_LIT:
			printf("\'%c\'", ((char) e->literal_value));
			break;
		case EXPR_STRING_LIT:
			printf("\"%s\"", e->string_literal);
			break;
		default: 
			printf("Something broke in expr\n");
			return;		
	}


}

void expr_operator(char* oper, struct expr* a, struct expr* b){
	expr_print(a);
	printf("%s", oper);
	expr_print(b);
}

