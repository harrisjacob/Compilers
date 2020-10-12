#include "type.h"

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params ){
	struct type* newType;
	
	if(!(newType = malloc(sizeof(struct type)))){
		printf("AST: Failed to allocate type structure");
		return NULL;
	}

	newType->kind = kind;
	newType->subtype = subtype;
	newType->params = params;

	return newType;
}

void type_print( struct type *t ){
	if(!t) return;
	printf("%s", getType(t->kind));
	if(t->kind == TYPE_ARRAY){
		printf("[] ");
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