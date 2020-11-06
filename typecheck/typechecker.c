#include "typechecker.h"

struct type * expr_typecheck(struct expr *e){
	if(!e) return NULL;

	struct type *lt = expr_typecheck(e->left);
	struct type *in = expr_typecheck(e->inner);
	struct type *rt = expr_typecheck(e->right);

	struct type *result;

	struct type *firstType, *nextType;
	struct expr *nextExpr;

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
			if(type_equals(lt,rt)){
				printf("type error: Cannot evaluate equivalence comparison due to type mismatch\n");
				printf("\tcompared expressions were of type ");
				print_expr_t(lt->kind);
				printf(" and type ");
				print_expr_t(rt->kind);
				printf("\n");
			}
			if(lt->kind == TYPE_VOID || lt->kind == TYPE_ARRAY || lt->kind == TYPE_FUNCTION){
				printf("type error: Comparison cannot be made between ");
				print_expr_t(lt->kind);
				printf(" types\n");
			}
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_NEQ:
			if(type_equals(lt,rt)){
				printf("type error: Cannot evaluate unequal comparison due to type mismatch\n");
				printf("\tcompared expressions were of type ");
				print_expr_t(lt->kind);
				printf(" and type ");
				print_expr_t(rt->kind);
				printf("\n");
			}
			if(lt->kind == TYPE_VOID || lt->kind == TYPE_ARRAY || lt->kind == TYPE_FUNCTION){
				printf("type error: Comparison cannot be made between ");
				print_expr_t(lt->kind);
				printf(" types\n");
			}
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
			if(lt->kind==TYPE_ARRAY){
				if(rt->kind!=TYPE_INTEGER){
					printf("type error: array dereference must be of type integer\n");
					printf("\tindex was of type ");
					print_expr_t(rt->kind);
					printf("\n");
				}
				result = type_copy(lt->subtype);
			}else{
				printf("type error: dereferencing ");
				print_expr_t(lt->kind);
				printf(" operation is not allowed.\n");
				result = type_copy(lt);
			}
			break;
		case EXPR_FUNC:
			if(lt->kind==TYPE_FUNCTION){
				nextExpr = e->right;
				struct type* t;
				while(nextExpr){
					t = expr_typecheck(nextExpr);
					type_delete(t);
					nextExpr = nextExpr->next;
				}
			}else{
				printf("type error: argument 1 of function call does not describe a function\n");
			}
			result = type_create(TYPE_FUNCTION, NULL, NULL, NULL);
			break;
		case EXPR_PAREN:
			result = type_create(in->kind, NULL, NULL, NULL);
			break;
		case EXPR_ID:
			if(e->symbol && e->symbol->type){
				result = type_create(e->symbol->type->kind,NULL,NULL,NULL);
			}else{
				printf("type error: identifier did not resolve to known type\n");
				result = NULL;
			}
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
			if(!(firstType = expr_typecheck(e->inner))){
				//Array is of length 0 and type is unknown at this stage
				result = type_create(TYPE_ARRAY, NULL, NULL, NULL);
			}else{
				struct expr * nextExpr = e->inner->next;
				int elemCounter = 2;
				while(nextExpr){
					nextType = expr_typecheck(nextExpr);
					if(type_equals(firstType, nextType)){
						printf("type error: Illegal mixing of array literal elements\n");
						printf("\tInitial element is of type ");
						print_expr_t(e->inner->kind);
						printf(" and element %i is of type ", elemCounter);
						print_expr_t(nextExpr->kind);
						printf(".\n");
					}
					nextExpr = nextExpr->next;
					elemCounter++;
				}
				result = type_create(TYPE_ARRAY, firstType, NULL, NULL);
			}
			break;
		default:
			printf("type error: Cannot type check unknown type\n");
			result = NULL;
			break;
	}

	type_delete(lt);
	type_delete(in);
	type_delete(rt);

	return result;
}

void decl_typecheck(struct decl *d){
	if(!d) return;
	if(d->value){
		struct type *t;
		t = expr_typecheck(d->value);
		if(type_equals(t,d->symbol->type)){
			printf("type error: Attempted to define variable declared as '%s' with a value of type '%s'\n", getType(d->symbol->type->kind), getType(t->kind));
		}
	}
	if(d->code){
		stmt_typecheck(d->code);
	}

	decl_typecheck(d->next);
}

void stmt_typecheck(struct stmt *s){
	if(!s) return;
	struct type *t;
	struct expr * e;

	switch(s->kind){
		case STMT_DECL:
			decl_typecheck(s->decl);
			break;
		case STMT_EXPR:
			t = expr_typecheck(s->expr);
			type_delete(t);
			break;
		case STMT_IF_ELSE:
			t = expr_typecheck(s->expr);
			if(t->kind!=TYPE_BOOLEAN){
				printf("type error: 'if-then' statement must have type 'boolean' control expression\n");
				printf("\tCurrent control expression is of type '%s'\n", getType(t->kind));
			}
			type_delete(t);
			stmt_typecheck(s->body);
			stmt_typecheck(s->else_body);
			break;
		case STMT_FOR:
			t = expr_typecheck(s->init_expr);
			type_delete(t);
			t = expr_typecheck(s->expr);
			if(t && t->kind!=TYPE_BOOLEAN){
				printf("type error: Condition of for loop must be of type 'boolean'\n");
				printf("\tCurrent condition is of type '%s'\n", getType(t->kind));
			}
			type_delete(t);
			t = expr_typecheck(s->next_expr);
			type_delete(t);
			stmt_typecheck(s->body);
			break;
		case STMT_PRINT:
			e = s->expr;
			while(e){
				t = expr_typecheck(e);
				type_delete(t);
				e = e->next;
			}
			break;
		case STMT_RETURN:
			t = expr_typecheck(s->expr);
			type_delete(t);
			if(s->expr && s->expr->next) printf("type error: function cannot return multiple expressions\n");
			break;
		case STMT_BLOCK:
			stmt_typecheck(s->body);
			break;
		default:
			printf("type error: Unknown statement type detected\n");
			break;
	}

	stmt_typecheck(s->next);
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


