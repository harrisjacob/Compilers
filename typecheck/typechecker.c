#include "typechecker.h"

int typecheck_err = 0;
int function_lock = 0;
type_t return_type = TYPE_VOID;

struct type * expr_typecheck(struct expr *e){
	if(!e) return NULL;

	struct type *lt = expr_typecheck(e->left);
	struct type *in;
	struct type *rt = NULL;

	//Let the function handle its own evalutations

	if(e->kind!=EXPR_FUNC) rt = expr_typecheck(e->right);

	struct type *result;

	struct type *firstType, *nextType;
	struct expr *nextExpr;

	// print_expr_t(e->kind);
	// printf("(switch) \n");

	switch(e->kind){
		case EXPR_ASSIGN:
			if(type_equals(lt, rt)){
				printf("type error (%i): Cannot perform assignment operation of '", ++typecheck_err);
				expr_print(e);
				printf("' due to mismatched types. Left hand side is of operator is of type ");
				print_type_t(lt);
				printf(" while right hand side of operator is of type ");
				print_type_t(rt);
				printf("\n\n");
			}else{
				//Arrays have assignment restrictions on assigning to identifiers
				if(lt->kind == TYPE_ARRAY){
					if(catchArray(e->left)){
						printf("type error (%i): Array literal assignment to identifier is not permitted.\n\n", ++typecheck_err);
					}
					if(lt->subtype->kind == TYPE_FUNCTION || lt->subtype->kind == TYPE_VOID){
						printf("type error (%i): Array cannot be of type ", ++typecheck_err);
						print_type_t(lt->subtype);
						printf("\n\n.");
					}
				}
			}
			
			if(lt->kind == TYPE_VOID){
				printf("type error (%i): Assignment in expression '", ++typecheck_err);
				expr_print(e);
				printf("' is not allowed because left hand side is type 'void'. Defaulting to result of type 'int'\n\n");
				result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			}else{
				result = type_copy(lt);
			}
			//operands_typecheck(e, lt->kind, lt->kind, lt->kind, rt->kind);
			break;
		case EXPR_OR:
		case EXPR_AND:
			if(!lt || !rt) break;
			if(type_equals(lt, rt) || lt->kind != TYPE_BOOLEAN){
				printf("type error (%i): Arguments of expression '", ++typecheck_err);
				expr_print(e);
				printf("' must be of type 'boolean'. Arguments are of type ");
				print_type_t(lt);
				printf(" and type ");
				print_type_t(rt);
				printf(" respectively.\n\n");
			}
			//operands_typecheck(e, TYPE_BOOLEAN, lt->kind, TYPE_BOOLEAN, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_LT:
		case EXPR_LE:
		case EXPR_GT:
		case EXPR_GE:
			if(!lt || !rt) break;
			if(type_equals(lt, rt) || lt->kind != TYPE_INTEGER){
				printf("type error (%i): Arguments of expression '", ++typecheck_err);
				expr_print(e);
				printf("' must be of type 'integer'. Arguments are of type ");
				print_type_t(lt);
				printf(" and type ");
				print_type_t(rt);
				printf(" respectively.\n\n");
			}
			//operands_typecheck(e, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_EQ:
		case EXPR_NEQ:
			if(!lt || !rt) break;
			if(type_equals(lt,rt)){
				printf("type error (%i): Cannot evaluate %s comparison due to type mismatch\n", ++typecheck_err, (e->kind == EXPR_EQ) ? "equivalence": "unequal");
				printf("\tcompared expressions '");
				expr_print(e->left);
				printf("' and '");
				expr_print(e->right);
				printf("' were of type ");
				print_type_t(lt);
				printf(" and type ");
				print_type_t(rt);
				printf(" respectively \n\n");
			}
			if(lt->kind != TYPE_INTEGER && lt->kind != TYPE_BOOLEAN){
				printf("type error (%i): Comparison between '", ++typecheck_err);
				expr_print(e->left);
				printf("' and '");
				expr_print(e->right);
				printf("' cannot be accomplished because ");
				print_type_t(lt);
				printf(" is a non-comparable type\n\n");
			}
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_ADD:
		case EXPR_SUB:
		case EXPR_MOD:
		case EXPR_MUL:
		case EXPR_DIV:
		case EXPR_EXP:
			if(!lt || !rt) break;
			if(type_equals(lt, rt) || lt->kind != TYPE_INTEGER){
				printf("type error (%i): Arguments of expression '", ++typecheck_err);
				expr_print(e);
				printf("' must be of type 'integer'. Arguments are of type ");
				print_type_t(lt);
				printf(" and type ");
				print_type_t(rt);
				printf(" respectively.\n\n");
			}
			//operands_typecheck(e, TYPE_INTEGER, lt->kind, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_NEG:
			if(!rt) break;
			if(rt->kind != TYPE_INTEGER){
				printf("type error (%i): Argument of expression '", ++typecheck_err);
				expr_print(e);
				printf("' must be of type 'integer'. Argument is of type ");
				print_type_t(lt);
				printf(".\n\n");
			}
			//operands_typecheck(e, 0, 0, TYPE_INTEGER, rt->kind);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_NOT:
			if(!rt) break;
			if(rt->kind != TYPE_BOOLEAN){
				printf("type error (%i): Argument of expression '", ++typecheck_err);
				expr_print(e);
				printf("' must be of type 'boolean'. Argument is of type ");
				print_type_t(lt);
				printf(".\n\n");
			}
			//operands_typecheck(e, 0, 0, TYPE_BOOLEAN, rt->kind);
			result = type_create(TYPE_BOOLEAN, NULL, NULL, NULL);
			break;
		case EXPR_POST_INC:
		case EXPR_POST_DEC:
			if(!lt) break;
			if(lt->kind != TYPE_INTEGER){
				printf("type error (%i): Argument of expression '", ++typecheck_err);
				expr_print(e);
				printf("' must be of type 'integer'. Argument is of type ");
				print_type_t(lt);
				printf(".\n\n");
			}
			//operands_typecheck(e, TYPE_INTEGER, lt->kind, 0, 0);
			result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			break;
		case EXPR_INDEX:
			if(!lt || !rt) break;
			if(lt->kind==TYPE_ARRAY){
				if(rt->kind!=TYPE_INTEGER){
					printf("type error (%i): array dereference at '", ++typecheck_err);
					expr_print(e);
					printf("' has non-integer index\n");
					printf("\tindex was of type ");
					print_type_t(rt);
					printf("\n\n");
				}

				//WORKING HERE
				result = type_copy(lt->subtype);
			}else{
				printf("type error (%i): dereferencing ", ++typecheck_err);
				print_type_t(lt);
				printf(" operation is not allowed within '");
				expr_print(e);
				printf("' context. Are you sure you're dereferencing an array?\n\n");
				result = type_copy(lt);
			}
			break;
		case EXPR_FUNC:
			if(!lt) break;
			if(lt->kind==TYPE_FUNCTION){
				nextExpr = e->right;
				struct type* t;
				struct param_list *pl = lt->params;
				int argCounter = 1;
				while(nextExpr && pl){
					t = expr_typecheck(nextExpr);
					if(type_equals(t, pl->type)){
						printf("type error (%i): expected argument %i of ", ++typecheck_err, argCounter); 
						expr_print(e->left);
						printf(" to be type ");
						print_type_t(pl->type);
						printf(". Argument %i was of type ", argCounter);
						print_type_t(t);
						printf(".\n\n");
					}
					type_delete(t);
					nextExpr = nextExpr->next;
					pl = pl->next;
					argCounter++;
				}

				argCounter--;
				if(nextExpr && !pl){
					printf("type error (%i): Too many arguments provided to ", ++typecheck_err);
					expr_print(e->left);
					printf(". This function requires %i argumnets.", argCounter);
					while(nextExpr){
						argCounter++;
						nextExpr = nextExpr->next;
					}
					printf(" %i arguments were provided.\n\n", argCounter);
				}else if(!nextExpr && pl){
					printf("type error (%i): Too few arguments provided (only %i given) to ", ++typecheck_err, argCounter);
					expr_print(e->left);
					while(pl){
						argCounter++;
						pl = pl->next;
					}
					printf(". A call to this function requires %i arguments.\n\n", argCounter);
				}

			}else{
				printf("type error (%i): argument 1 of function call '", ++typecheck_err);
				expr_print(e);
				printf("' does not describe a function\n\n");
			}

			result = type_copy(lt->subtype);
			break;
		case EXPR_PAREN:
			if((in = expr_typecheck(e->inner))){
				result = type_create(in->kind, NULL, NULL, NULL);
				type_delete(in);
			}else{
				printf("type error (%i): Could not identify type of parenthesized expression.", ++typecheck_err);
				printf(" Defaulting to integer type for expression '");
				expr_print(e->inner);
				printf("'\n\n");
				result = type_create(TYPE_INTEGER, NULL, NULL, NULL);
			}
			break;
		case EXPR_ID:
			if(e->symbol){
				result = type_copy(e->symbol->type);
			}else{
				printf("type error (%i): identifier '", ++typecheck_err);
				expr_print(e);
				printf("' did not resolve to known value\n\n");
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
					if((nextType = expr_typecheck(nextExpr))){
						if(type_equals(firstType, nextType)){
							printf("type error (%i): Illegal mixing of array literal elements\n", ++typecheck_err);
							printf("\tInitial element is of type ");
							print_type_t(firstType);
							printf(" and element %i is of type ", elemCounter);
							print_type_t(nextType);
							printf(".\n\n");
						}
						nextExpr = nextExpr->next;
						type_delete(nextType);
						elemCounter++;
					}

				}
				result = type_create(TYPE_ARRAY, firstType, NULL, NULL);
			}
			break;
		default:
			printf("type error (%i): Cannot type check unknown type at expression '", ++typecheck_err);
			expr_print(e);
			printf("'\n\n");
			result = NULL;
			break;
	}

	type_delete(lt);
	type_delete(rt);

	// expr_print(e);		
	// if(result) printf("\nresult->kind = %i\n\n\n", result->kind);
	return result;
}

void decl_typecheck(struct decl *d){
	if(!d) return;

	if(d->type && d->type->kind == TYPE_FUNCTION){
		if(d->symbol && d->symbol->type && d->type){
			if(type_equals(d->symbol->type->subtype, d->type->subtype)){
				printf("type error (%i): Function %s was initially declared with return type ", ++typecheck_err, d->name);
				print_type_t(d->symbol->type->subtype);
				printf(" but is later declared with type ");
				print_type_t(d->type->subtype);
				printf(".\n\n");
			}

			if(d->symbol->type->subtype->kind == TYPE_FUNCTION || d->symbol->type->subtype->kind == TYPE_ARRAY){
				printf("type error (%i): Function %s cannot return type ", ++typecheck_err, d->name);
				print_type_t(d->symbol->type->subtype);
				printf(".\n\n");
			}
		}else{
			printf("type error (%i): unable to determine original return type of function %s\n\n", ++typecheck_err, d->name);
		}
	}

	if(d->value){
		struct type *t;
		t = expr_typecheck(d->value);
		if(type_equals(t,d->symbol->type)){
			printf("type error (%i): Attempted to define variable declared as ", ++typecheck_err);
			print_type_t(d->symbol->type);
			printf(" with a value of type ");
			print_type_t(t);
			printf(".\n\n");
		}
		type_delete(t);
	}
	if(d->code){
		int local_lock;
		//printf("attempting lock\n");	
		local_lock = set_return(d); 
		stmt_typecheck(d->code);
		//printf("releasing lock\n");
		if(!local_lock){
			function_lock = 0;
			return_type = TYPE_VOID;
		} 
	}


	decl_typecheck(d->next);

}

void stmt_typecheck(struct stmt *s){
	if(!s) return;
	struct type *t;
	struct expr *e;

	switch(s->kind){
		case STMT_DECL:
			decl_typecheck(s->decl);
			break;
		case STMT_EXPR:
			if((t = expr_typecheck(s->expr)))type_delete(t);
			break;
		case STMT_IF_ELSE:
			t = expr_typecheck(s->expr);
			if(t->kind!=TYPE_BOOLEAN){
				printf("type error (%i): 'if-then' statement must have type 'boolean' control expression\n", ++typecheck_err);
				printf("\tCurrent control expression is of type '%s'\n\n", getType(t->kind));
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
				printf("type error (%i): Condition of for loop must be of type 'boolean'\n", ++typecheck_err);
				printf("\tCurrent condition is of type '%s'\n\n", getType(t->kind));
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
			if(!function_lock){
				printf("type error (%i): statement 'return ", ++typecheck_err);
				expr_print(s->expr);
				printf("' located outside function definition\n\n");
			}else{
				if(t->kind!=return_type){
					printf("type error (%i): Current function scope has return type '%s'", ++typecheck_err, getType(return_type));
					printf(" but expression returned (");
					expr_print(s->expr);
					printf(") has type ");
					print_type_t(t);
					printf(".\n\n");
				}
			}
			type_delete(t);
			if(s->expr && s->expr->next) printf("type error (%i): function cannot return multiple expressions\n\n", ++typecheck_err);
			break;
		case STMT_BLOCK:
			stmt_typecheck(s->body);
			break;
		default:
			printf("type error (%i): Unknown statement type detected\n\n", ++typecheck_err);
			break;
	}

	stmt_typecheck(s->next);
}

int catchArray(struct expr* e){
	if(!e) return 1;
	if(e->kind == EXPR_ID){
		return 1;
	}else if(e->kind == EXPR_PAREN){
		return catchArray(e->inner);
	}
	return 0;
}

int set_return(struct decl* d){
	if(!function_lock){
		function_lock = 1;
		//printf("got it!\n");
		if(d->type->subtype) return_type = d->type->subtype->kind;
		return 0;
	}else{
		printf("type error (%i): Function %s cannot be declared within a function.\n\n", ++typecheck_err, d->name);
		return 1;
	}
}