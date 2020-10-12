#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "decl.h"


extern FILE *yyin;
extern int yyparse();
struct decl* program_output = NULL;
int main( int argc, char *argv[] )
{
	if(argc > 1 && strcmp(argv[1], "-print")==0){
		if(argc>2){
			char* program = argv[2];
			yyin = fopen(program,"r");
			if(!yyin){
				fprintf(stderr,"Error: could not open %s\n", program);
				return 1;
			}

			int res;
			if((res=yyparse())) {
				printf("Parse failed.\n");
				return 1;
			}

			int indent = 0;
			struct decl* declaration = program_output;
			if(program_output) decl_print(program_output);

		}

	}
	
	return 0;
}

