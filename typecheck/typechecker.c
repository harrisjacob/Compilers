#include "typechecker.h"

struct type * expr_typecheck(struct expr *e){
	if(!e) return NULL;

	struct type *lt = expr_typecheck(e->left);
	struct type *rt = expr_typecheck(e->right);

	struct type *result;

	switch(e->kind){
		case EXPR_ASSIGN:
			operands_typecheck(e->kind, TYPE_BOOLEAN, lt->kind, TYPE_BOOLEAN, rt->kind);
			result = type_create(rt->kind, NULL, NULL, NULL);
			break;
		case EXPR_OR:
			operands_typecheck(e->kind, TYPE_BOOLEAN, lt->kind, TYPE_BOOLEAN, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_AND:
			operands_typecheck(e->kind, TYPE_BOOLEAN, lt->kind, TYPE_BOOLEAN, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_LT:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_LE:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_GT:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_GE:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_EQ:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_NEQ:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_ADD:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_SUB:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_MOD:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_MUL:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_DIV:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_EXP:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_NEG:
			operands_typecheck(e->kind, 0, 0, TYPE_INTEGER, lt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_NOT:
			operands_typecheck(e->kind, 0, 0, TYPE_BOOLEAN, lt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_POST_INC:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, 0, 0);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_POST_DEC:
			operands_typecheck(e->kind, TYPE_INTEGER, lt->kind, 0, 0);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_INDEX:

			break;
		case EXPR_FUNC:
			result = type_create(TYPE_FUNCTION, NULL, NULL, NULL);
			break;
		case EXPR_PAREN:

			break;
		case EXPR_ID:

			break;
		case EXPR_INT_LIT:
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_BOOL_LIT:
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_CHAR_LIT:
			result = type_create(TYPE_CHARACTER, NULL, NULL, NULL);
			break;
		case EXPR_STRING_LIT:
			result = type_create(TYPE_STRING, NULL, NULL, NULL);
			break;
		case EXPR_ARRAY_LIT:
			result = type_create(TYPE_ARRAY, NULL, NULL, NULL);
			break;
		default:
			printf("type error: Cannot type check unknown type\n");
			result = NULL;
			break;	
	}

	type_delete(lt);
	type_delete(rt);

	return result;
}

void operands_typecheck(expr_t op, expr_t lt_exp, expr_t lt, expr_t rt_exp, expr_t rt){
	//No operand should expect a 0 enum expression type (assignment)
	//Expected data types are always literals
	int argCount = 1;
	if(lt_exp) operands_typecheck_util(op, lt_exp, lt, argCount++);
	if(rt_exp) operands_typecheck_util(op, rt_exp, rt, argCount);
}

void operands_typecheck_util(expr_t op, expr_t exp, expr_t act, int argCount){
	if(act!=exp){
		printf("type error: Argument %i of ", argCount);
		print_expr_t(op);
		printf(" expression is of type ");
		print_expr_t(act);
		printf(". Argument %i should be of type ", argCount);
		print_expr_t(exp);
		printf(".\n");
	}
}


