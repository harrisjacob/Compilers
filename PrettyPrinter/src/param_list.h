
#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "type.h"
#include <string.h>
#include <stdio.h>

struct expr;

struct param_list {
	char *name;
	struct type *type;
	struct symbol *symbol;
	struct param_list *next;
};

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
void param_list_print( struct param_list *a );

#endif
