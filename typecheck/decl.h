
#ifndef DECL_H
#define DECL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stmt.h"
#include "type.h"
#include "expr.h"

struct decl {
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
};

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next );
void decl_print( struct decl *d, int indent );




#endif


