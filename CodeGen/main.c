#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "token.h"
#include "parser.h"
#include "resolve.h"
#include "typechecker.h"


extern FILE *yyin;
extern int yyparse();
extern int yylex();
extern char *yytext;
extern int yyleng;
extern int typecheck_err;
extern const char* token_to_string();

void helpInfo(int status);

struct decl* program_output = NULL;
int main( int argc, char *argv[] )
{

	if(argc==2 && !strcmp(argv[1],"-help")) helpInfo(0);

	if(argc<3) helpInfo(1);
	
	char* program = argv[2];
	yyin = fopen(program,"r");
	if(!yyin) {
		fprintf(stderr, "Error: could not open %s\n", program);
		return 1;
	}

	if(!strcmp(argv[1],"-scan")){

		while(1) {
			
			enum yytokentype t = yylex();

			if(t==TOKEN_EOF){
				printf("%s\n", token_to_string(t));
				break;
			} 

			if(t==TOKEN_ERROR){
				fprintf(stderr,"scan error: invalid token encountered\n");
				return 1;
			}
			if(t==TOKEN_STRING_LITERAL || t==TOKEN_CHARACTER_LITERAL || t==TOKEN_INTEGER_LITERAL || t==TOKEN_IDENTIFIER){
				printf("%s %s \n", token_to_string(t), yytext);
			}else{
				const char* tString;
				if((tString = token_to_string(t))) printf("%s\n", tString);
			}
		}

	}else if(!strcmp(argv[1],"-parse")){
		
		int res;
		if(!(res=yyparse())) {
			printf("Parse successful!\n");
			return 0;
		} else {
			printf("Parse failed.\n");
			return 1;
		}

	}else if(!strcmp(argv[1],"-print")){
		
		int res;
		if((res=yyparse())) {
			printf("Parse failed.\n");
			return 1;
		}

		int indent = 0;
		if(program_output) decl_print(program_output, indent);
	
	}else if(!strcmp(argv[1],"-resolve")){
		
		int res;
		if((res=yyparse())) {
			printf("Parse failed.\n");
			return 1;
		}
		int ret= resolve_tree(program_output);
		printf("Return code: %i\n", ret);
		return ret;

	}else if(!strcmp(argv[1],"-typecheck")){
		if(yyparse()){
			printf("Parse failed.\n");
			return 1;
		}
		if(resolve_tree(program_output)) return 1;
		printf("\n");
		decl_typecheck(program_output);
		return (!typecheck_err) ? 0 : 1;

	}else{
		printf("Error: Unknown stage requested\n");
		helpInfo(1);
	}

	
	return 0;
}

void helpInfo(int status){
	printf("Use:\n");
	printf("\t./bminor [stage] [file.bminor]\n");
	printf("\tstage: -scan, -parse, -print\n");
	exit(status);
}