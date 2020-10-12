#include "param_list.h"

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){

	struct param_list* newParam;
	if(!(newParam = malloc(sizeof(struct param_list)))){
		printf("AST: Failed to allocate parameter list structure");
		return NULL;
	}

	newParam->name = strdup(name);
	newParam->type = type;
	newParam->next = next;

	return newParam;

}

void param_list_print( struct param_list *a ){
	if(!a) return;
	printf("%s: ", a->name);
	type_print(a->type);
	if(a->next){
		printf(", ");
		param_list_print(a->next);
	}

}