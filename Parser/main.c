#include<string.h>
#include <stdio.h>

extern FILE *yyin;
extern int yyparse();

int main( int argc, char *argv[] )
{
	if(argc > 1 && strcmp(argv[1], "-parse")==0){
		if(argc>2){
			char* program = argv[2];
			yyin = fopen(program,"r");
			if(!yyin){
				fprintf(stderr,"Error: could not open %s\n", program);
				return 1;
			}

			int res;
			if(!(res=yyparse())) {
				printf("Parse successful!\n");
				return 0;
			} else {
				printf("Parse failed.\n");
				return 1;
			}

		}

	}
	
	return 0;
}

