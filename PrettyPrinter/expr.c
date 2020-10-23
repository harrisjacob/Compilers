#include "expr.h"

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right, struct expr *next){
	struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}

	newExpr->kind = kind;
	newExpr->left = left;
	newExpr->right = right;
	newExpr->next = next;

	return newExpr;
}

struct expr * expr_create_paren(expr_t kind, struct expr * inner, struct expr *next){
	struct expr* newExpr;
	
	if(!(newExpr = malloc(sizeof(struct expr)))){
		printf("AST: Failed to allocate expr structure");
		return NULL;
	}

	newExpr->kind = kind;
	newExpr->inner = inner;
	newExpr->next = next;

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
			check_parens(expr_get_class(EXPR_ADD), e->left, 0);
			printf("+");
			check_parens(expr_get_class(EXPR_ADD), e->right, 1);
			//expr_operator("+", e, e_Class4);
			break;
		case EXPR_SUB:
			check_parens(expr_get_class(EXPR_SUB), e->left, 0);
			printf("-");
			check_parens(expr_get_class(EXPR_SUB), e->right, 1);
			//expr_operator("-", e, e_Class4);
			break;
		case EXPR_MUL:
			check_parens(expr_get_class(EXPR_MUL), e->left, 0);
			printf("*");
			check_parens(expr_get_class(EXPR_MUL), e->right, 1);
			//expr_operator("*", e, e_Class5);
			break;
		case EXPR_DIV:
			check_parens(expr_get_class(EXPR_DIV), e->left, 0);
			printf("/");
			check_parens(expr_get_class(EXPR_DIV), e->right, 1);
			//expr_operator("/", e, e_Class5);
			break;
		case EXPR_INDEX:
			check_parens(e_Class0, e->left, 0); //Always break parens around an index
			printf("[");
			check_parens(e_Class0, e->right, 1);
			printf("]");
			//expr_print(e->left);
			//printf("[");
			//expr_print(e->right);
			//printf("]");
			break;
		case EXPR_PAREN:
			check_parens(e_Class0, e->inner, 1);
			// printf("(");
			// expr_print(e->inner);
			// printf(")");
			break;
		case EXPR_FUNC:
			check_parens(e_Class0, e->left, 0); //Always break parens around a function
			printf("(");
			check_parens(e_Class0, e->right, 1);
			printf(")");
			// expr_print(e->left);
			// printf("(");
			// expr_print(e->right);
			// printf(")");
			break;
		case EXPR_POST_INC:
			check_parens(expr_get_class(EXPR_POST_INC), e->left, 0);
			//check_left_parens(e->kind, e->right, );
			//expr_print(e->right);
			printf("++");
			break;
		case EXPR_POST_DEC:
			check_parens(expr_get_class(EXPR_POST_DEC), e->left, 0);
			//check_left_parens(e->kind, e->right);
			//expr_print(e->right);
			printf("--");
			break;
		case EXPR_NEG:
			printf("-");
			check_parens(expr_get_class(EXPR_NEG), e->right, 0);
			//expr_print(e->right);
			break;
		case EXPR_NOT:
			printf("!");
			check_parens(expr_get_class(EXPR_NOT), e->right, 0);
			//expr_print(e->right);
			break;
		case EXPR_EXP:
			check_parens(expr_get_class(EXPR_EXP), e->left, 0);
			printf("^");
			check_parens(expr_get_class(EXPR_EXP), e->right, 1);
			//expr_operator("^", e);
			break;
		case EXPR_MOD:
			check_parens(expr_get_class(EXPR_MOD), e->left, 0);
			printf("%c", '%');
			check_parens(expr_get_class(EXPR_MOD), e->right, 1);
			//expr_operator("%", e);
			break;
		case EXPR_LT:
			check_parens(expr_get_class(EXPR_LT), e->left, 0);
			printf("<");
			check_parens(expr_get_class(EXPR_LT), e->right, 1);
			//expr_operator("<", e);
			break;
		case EXPR_LE:
			check_parens(expr_get_class(EXPR_LE), e->left, 0);
			printf("<=");
			check_parens(expr_get_class(EXPR_LE), e->right, 1);	
			//expr_operator("<=", e);
			break;
		case EXPR_GT:
			check_parens(expr_get_class(EXPR_GT), e->left, 0);
			printf(">");
			check_parens(expr_get_class(EXPR_GT), e->right, 1);
			//expr_operator(">", e);
			break;
		case EXPR_GE:
			check_parens(expr_get_class(EXPR_GE), e->left, 0);
			printf(">=");
			check_parens(expr_get_class(EXPR_GE), e->right, 1);
			//expr_operator(">=", e);
			break;
		case EXPR_EQ:
			check_parens(expr_get_class(EXPR_EQ), e->left, 0);
			printf("==");
			check_parens(expr_get_class(EXPR_EQ), e->right, 1);
			//expr_operator("==", e);
			break;
		case EXPR_NEQ:
			check_parens(expr_get_class(EXPR_NEQ), e->left, 0);
			printf("!=");
			check_parens(expr_get_class(EXPR_NEQ), e->right, 1);
			//expr_operator("!=", e);
			break;
		case EXPR_AND:
			check_parens(expr_get_class(EXPR_AND), e->left, 0);
			printf("&&");
			check_parens(expr_get_class(EXPR_AND), e->right, 1);
			//expr_operator("&&", e);
			break;
		case EXPR_OR:
			check_parens(expr_get_class(EXPR_OR), e->left, 0);
			printf("||");
			check_parens(expr_get_class(EXPR_OR), e->right, 1);
			//expr_operator("||", e);
			break;
		case EXPR_ASSIGN:
			check_parens(expr_get_class(EXPR_ASSIGN), e->left, 0);
			printf("=");
			check_parens(expr_get_class(EXPR_ASSIGN), e->right, 1);
			//expr_operator("=", e);
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
		case EXPR_ARRAY_LIT:
			printf("{");
			expr_print(e->inner);
			printf("}");
			return;
		default: 
			printf("Something broke in expr\n");
			return;		
	}

	if(e->next){
		printf(",");
		expr_print(e->next);
	}

}

void check_parens(expr_class p_OP, struct expr *f, int rArg){
	if(!f){
		printf("Returning null\n");
		return;
	} //return;									//Null recursive base case
	if(f->kind != EXPR_PAREN){						//Defined recursive base case
		return expr_print(f);						//Print the inner most expression
	}

	//Every f at this point must be of type EXPR_PARENS and will have a defined inner field
	if(f->inner->kind==EXPR_PAREN) return check_parens(p_OP, f->inner, rArg);

	//Every f at this point must be of type EXPR_PARENS with a non EXPR_PARENS expression inside
	if(rArg){														//Argument is to the right of the parent operator
		if(p_OP<expr_get_class(f->inner->kind)){ 	//If the parent operator has lower precedence the child operator
			expr_print(f->inner);									//Print the child expression without parenthesis
		}else{														//The child operator has lower (or equal precedence), print parenthesis
			printf("(");
			expr_print(f->inner);
			printf(")");
		}
	}else{															//Argument is to the left of the parent operator
		if(p_OP<=expr_get_class(f->inner->kind)){ 	//If the parent operator has lower (or equal) precedence
			expr_print(f->inner);									//Print without parenthesis
		}else{														//Parent has higher precedence
			printf("(");
			expr_print(f->inner);
			printf(")");
		}
	}

	// 	if(p_OP < f->inner->kind){						//If the called operator has lower precedence than the right operator
// 		check_right_parens(p_OP, f->inner);			//the right parens may not be needed, recursively check
// 	}else{
// 		expr_print(f->inner);						//The operator has lower precedence, no parenthesis are needed 
// 	}
// }
}

expr_class expr_get_class(expr_t e){
	switch(e){
	case EXPR_ASSIGN: return e_Class0;
	case EXPR_OR: return e_Class1;
	case EXPR_AND: return e_Class2;
	case EXPR_LT: return e_Class3;
	case EXPR_LE: return e_Class3;
	case EXPR_GT: return e_Class3;
	case EXPR_GE: return e_Class3;
	case EXPR_EQ: return e_Class3;
	case EXPR_NEQ: return e_Class3;
	case EXPR_ADD: return e_Class4;
	case EXPR_SUB: return e_Class4;
	case EXPR_MOD: return e_Class5;
	case EXPR_MUL: return e_Class5;
	case EXPR_DIV: return e_Class5;
	case EXPR_EXP: return e_Class6;
	case EXPR_NEG: return e_Class7;
	case EXPR_NOT: return e_Class7;
	case EXPR_POST_INC: return e_Class8;
	case EXPR_POST_DEC: return e_Class8;
	case EXPR_INDEX: return e_Class9;
	case EXPR_FUNC: return e_Class9;
	case EXPR_PAREN: return e_Class9;
	case EXPR_ID: return e_Class10;
	case EXPR_INT_LIT: return e_Class10;
	case EXPR_BOOL_LIT: return e_Class10;
	case EXPR_CHAR_LIT: return e_Class10;
	case EXPR_STRING_LIT: return e_Class10;
	case EXPR_ARRAY_LIT: return e_Class10;
	default:
		printf("Class translation failed for epxr_t: %i\n", e);
		return -1;
	}
}

// void expr_operator(char* oper, struct expr* e){
// 	check_left_parens(e->kind, e->left); 			//Check left item
// 	printf("%s", oper);								//Print operator between items
// 	check_right_parens(e->kind, e->right);			//Check right item
// }

// void check_right_parens(expr_t p_OP, struct expr *f){

// 	if(!f) return;									//Null recursive base case
// 	if(f->kind != EXPR_PAREN){						//Defined recursive base case
// 		expr_print(f);								//Print the inner most expression
// 		return;
// 	}

// 	//Every f at this point must be of type EXPR_PARENS and will have a defined inner field

// 	if(p_OP < f->inner->kind){						//If the called operator has lower precedence than the right operator
// 		check_right_parens(p_OP, f->inner);			//the right parens may not be needed, recursively check
// 	}else{
// 		expr_print(f->inner);						//The operator has lower precedence, no parenthesis are needed 
// 	}
// }

// void check_left_parens(expr_t p_OP, struct expr *f){

// 	if(!f) return;									//Null recursive base case
// 	if(f->kind != EXPR_PAREN){						//Defined recursive base case
// 		return expr_print(f);						//Print the inner most expression
// 	}

// 	//Every f at this point must be of type EXPR_PARENS and will have a defined inner field

// 	if(f->inner->kind==EXPR_PAREN) return check_left_parens(p_OP, f->inner); //Handles embedded parenthesis
	
// 	//Every f at this point must be of type EXPR_PARENS with a non EXPR_PARENS expression inside

// 	if(p_OP > f->inner->kind){						//If the called operator has higher precedence than the left operator
// 		printf("(x");
// 		expr_print(f->inner);
// 		printf("x)");								
// 	}else{
// 		expr_print(f->inner);
// 		//check_left_parens(p_OP, f->inner);
// 	}
// }

//Combine expression check into a single funciton