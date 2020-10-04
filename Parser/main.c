/*
Main program of calculator example.
Validate whether the input matches the grammar.
*/

#include <stdio.h>

/* Clunky: Declare the parse function generated from parser.bison */
extern int yyparse();
int parser_result = 0;

int main( int argc, char *argv[] )
{
	int res;
	if(!(res=yyparse())) {
		printf("Parse successful!\n");
		printf("Value: %d\n", parser_result);
		return 0;
	} else {
		printf("Parse failed.\n");
		printf("Error: %d\n", res);
		return 1;
	}
}

