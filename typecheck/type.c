#include "type.h"

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params, struct expr* array_len){
	struct type* newType;
	
	if(!(newType = malloc(sizeof(struct type)))){
		printf("AST: Failed to allocate type structure");
		return NULL;
	}

	newType->kind = kind;
	newType->subtype = subtype;
	newType->params = params;
	newType->array_len = array_len;

	return newType;
}

void type_print( struct type *t ){
	if(!t) return;
	printf("%s", getType(t->kind));
	if(t->kind == TYPE_ARRAY){
		printf("[");
		if(t->array_len){
			expr_print(t->array_len);
		}
		printf("] ");
		type_print(t->subtype);
	}else if(t->kind == TYPE_FUNCTION){
		printf(" ");
		type_print(t->subtype);
		printf("(");
		param_list_print(t->params);
		printf(")");
	}
}

char* getType(type_t t){
	switch(t){
		case TYPE_VOID: return "void";
		case TYPE_BOOLEAN: return "boolean";
		case TYPE_CHARACTER: return "char";
		case TYPE_INTEGER: return "integer";
		case TYPE_STRING: return "string";
		case TYPE_ARRAY: return "array";
		case TYPE_FUNCTION: return "function";
		default:
			printf("Something broke in type\n"); 
			return NULL;
	}
}


int type_equals(struct type *a, struct type *b){
	if(!a || !b) return 1;

	if(a->kind == b->kind){
		if(a->kind==TYPE_FUNCTION){
			int error_collect = 0;
			//Check return types
			error_collect += type_equals(a->subtype, b->subtype);
			struct param_list *a_param, *b_param;
			a_param = a->params;
			b_param = b->params;
			int arg_count = 0;
			//Iterate through function parameters
			while(a_param && b_param){
				arg_count += 1;
				error_collect += type_equals(a_param->type, b_param->type);
				a_param = a_param->next;
				b_param = b_param->next;
			}
			//Check for mismatched funciton argument counts
			if((!a_param && b_param) || (a_param && !b_param)){
				printf("type error: mismatched error count\n");
				error_collect += 1;
			}
			return error_collect;
		}else if(a->kind==TYPE_ARRAY){
			return type_equals(a->subtype, b->subtype);
		}else if(a->kind <= TYPE_STRING){ //TYPE_STRING is the largest enum of the atomic types
			return 0;
		}else{
			printf("type error: Both types are unknown\n");
			return 1;
		}
	} else {
		return 1;
	}
}

struct type *type_copy(struct type *t){
	if(!t) return NULL;
	struct type *copy_type;
	if(!(copy_type = (struct type*) malloc(sizeof(struct type)))){
		printf("type error: type allocation failure when copying type\n");
		return NULL;
	}

	copy_type->kind = t->kind;

	if(t->kind == TYPE_FUNCTION){
		//Copy function return type
		struct type *copy_returnType;
		if(!(copy_returnType = type_copy(t->subtype))){
			//Error message was displayed by called function
			free(copy_type);
			return NULL;
		}
		copy_type -> subtype = copy_returnType;

		//param_list_copy will handle copying the list recursively
		copy_type -> params = param_list_copy(t->params);

	}else if(t->kind == TYPE_ARRAY){
		copy_type -> subtype = type_copy(t->subtype);
		

		//copy_type -> array_len = t->array_len;
	}else if(t->kind > TYPE_STRING){
		printf("type error: Cannot copy unknown type\n");
		free(copy_type);
		return NULL;
	}

	return copy_type;
}

void type_delete(struct type* t){
	if(!t) return;
	if(t->kind == TYPE_FUNCTION){
		type_delete(t->subtype);
		//Let param_list_delete handle the parameter list
		param_list_delete(t->params);
	}else if(t->kind == TYPE_ARRAY){
		type_delete(t->subtype);
		t->subtype = NULL;
	}else if(t->kind > TYPE_STRING){
		printf("type error: Unknown type cannot be deleted\n");
		return;
	}

	free(t);
}