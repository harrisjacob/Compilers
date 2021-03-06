
#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
	SYMBOL_LOCAL,
	SYMBOL_PARAM,
	SYMBOL_GLOBAL
} symbol_t;

struct symbol {
	symbol_t kind;
	struct type *type;
	char *name;
	int which;
	int defined;
};

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name );

#endif
