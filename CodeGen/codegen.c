#include "codegen.h"

const char* symbol_codegen(struct symbol* s){
	if(!s) return NULL;

	switch(s->kind){
		case SYMBOL_GLOBAL:
			return s->name;
		case :
		case :
		default:

	}
}