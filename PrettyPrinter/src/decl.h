
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>
#include <string.h>

struct decl {
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
};

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ){
	struct decl* newDecl;
	if(!(newDecl = malloc(sizeof(struct decl)))){
		printf("AST: Failed to allocate decl structure");
		return NULL;
	}

	newDecl->name = strdup(name);
	newDecl->type = type;
	newDecl->value = value;
	newDecl->code = code;
	newDecl->next = next;

	return newDecl;

}
void decl_print( struct decl *d, int indent );




#endif


