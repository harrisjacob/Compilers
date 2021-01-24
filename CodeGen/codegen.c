#include "codegen.h"

static const char* argRegList[] = {"%rdi","%rsi","%rdx","%rcx","%r8","%r9"};
static int valsOnStack = 0;
//This keeps track of the variables of the current scope that have been put on the stack
const char* symbol_codegen(struct symbol* s){
	if(!s) return NULL;

	switch(s->kind){
		case SYMBOL_GLOBAL:
			return s->name;
		case SYMBOL_PARAM:
			if(s->defined < 6){
				if(!(s->defined)) valsOnStack = 0; //If this is the first param reset the counter
				
				return argRegList[(s->defined)-1]; //Use a reserved register
			}

			//Params greater than 6 should fall through to a stack assignment

		case SYMBOL_LOCAL:
			if(!(s->defined)) valsOnStack = 0; //If this is the first local variable reset the valOnStack counter
			
			char* stackRef = (char*) malloc(16);
			sprintf(stackRef, "-%i(%%rbp)", (++valsOnStack)*8); //Offset the stack pointer by the number of values on the stack already
			return stackRef;

		default:
			printf("CodeGen: Unknown symbol type detected.\n");
			return NULL;
	}
}