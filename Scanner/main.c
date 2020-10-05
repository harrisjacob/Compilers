#include "token.h"
#include <string.h>
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyleng;
extern const char* token_to_string();

int main(int argc, char* argv[]){

	if(argc > 1 && strcmp(argv[1], "-scan") == 0){
		if(argc > 2){
			char* program = argv[2];
			yyin = fopen(program,"r");
			if(!yyin) {
				fprintf(stderr, "Error: could not open %s\n", program);
				return 1;
			}

			while(1) {
				token_t t = yylex();
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
					printf("%s\n", token_to_string(t));
				}
			}
		
		return 0;
		}else{
			fprintf(stderr, "Error: no input file provided");
			return 1;
		}
	}

}
