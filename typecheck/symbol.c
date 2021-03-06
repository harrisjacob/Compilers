#include "symbol.h"

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ){
	struct symbol *retVal;

	if(!(retVal = (struct symbol *) malloc(sizeof(struct symbol)))){
		printf("Error: Failed to allocate symbol structure\n");
		return NULL;
	}

	retVal->kind = kind;
	retVal->type = type;
	retVal->name = strdup(name);

	return retVal;
}
