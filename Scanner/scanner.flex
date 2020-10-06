%{
#include "token.h"
%}
DIGIT  [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n)  /* skip whitespace */
<<EOF>>                                         { return TOKEN_EOF; }
array											{ return TOKEN_ARRAY; }
else	    									{ return TOKEN_ELSE; }
false		    								{ return TOKEN_FALSE; }
for		    									{ return TOKEN_FOR; }
function	    								{ return TOKEN_FUNCTION; }
if		    									{ return TOKEN_IF; }
print		    								{ return TOKEN_PRINT; }
return		    								{ return TOKEN_RETURN; }
true		    								{ return TOKEN_TRUE; }
void		    								{ return TOKEN_VOID; }
while		    								{ return TOKEN_WHILE; }
boolean 										{ return TOKEN_BOOLEAN; }
integer 										{ return TOKEN_INTEGER; }
char 											{ return TOKEN_CHARACTER; }
string 											{ return TOKEN_STRING; }
\(    											{ return TOKEN_L_PAREN; }
\)    											{ return TOKEN_R_PAREN; }
\[    											{ return TOKEN_L_SUB; }
\]    											{ return TOKEN_R_SUB; }
\+    											{ return TOKEN_ADD; }
\+\+   											{ return TOKEN_POST_INC; }
\-    											{ return TOKEN_SUB; }
\-\-   											{ return TOKEN_POST_DEC; }
!    											{ return TOKEN_LOGIC_NOT; }
\^    											{ return TOKEN_EXP; }
\*    											{ return TOKEN_MULT; }
\/    											{ return TOKEN_DIVIDE; }
%    											{ return TOKEN_MOD; }
(\/\/[^(\r\n)]*\r\n|\/\*[^(\*\/)]*\*\/)
\<    											{ return TOKEN_LT; }
\<=   											{ return TOKEN_LE; }
>    											{ return TOKEN_GT; }
>=   											{ return TOKEN_GE; }
=	 											{ return TOKEN_ASSIGNMENT; }
==   											{ return TOKEN_EQUIV; }
!=   											{ return TOKEN_NOT_EQUIV; }
&&   											{ return TOKEN_LOGIC_AND; }
\|\|   											{ return TOKEN_LOGIC_OR; }
;	 											{ return TOKEN_SEMICOLON; }
:												{ return TOKEN_COLON; }
,												{ return TOKEN_COMMA; }
\{												{ return TOKEN_L_CURLY; }	
\}												{ return TOKEN_R_CURLY; }
\\												{ return TOKEN_BACKSLASH; }
({LETTER}|_)({LETTER}|{DIGIT}|_){0,255} 	    { 
                                                    if(yyleng>255) return TOKEN_ERROR;
                                                    return TOKEN_IDENTIFIER;
                                                }
({DIGIT}){1,8}          						{ return TOKEN_INTEGER_LITERAL; }

\'(\\)?([^\']){1}\'								{
													yytext++;			//remove first '
													if(yyleng == 4){	//contains escape character
												  		if(yytext[1] == 'n'){
												  			*yytext = '\n';
												  		}else if(yytext[1]=='0'){
												  			*yytext = '\0';
												  		}else{
												  			*yytext = yytext[1];
												  		}
												  	}
												  	yytext[1] = '\0';
												  	yyleng = 1;

												  	return (*yytext == '\\')? TOKEN_ERROR: TOKEN_CHARACTER_LITERAL;
												}

\"([^\"\n\\]|(\\[^\n])){0,255}\"								{ 	
													if(yyleng>255) return TOKEN_ERROR;
													
													yytext[yyleng-1]='\0';
													yytext++;
													char *tort, *hare; //The hare pointers checks for escape characters and pushes ahead while the tortise keeps the current char array position
													tort=hare=yytext;


													while(*hare){
														if(*hare=='\\'){
															hare++;
															if(*(hare) == 'n'){
																*tort = '\n';
															}else if(*(hare) == '0'){
																*tort = '\0';
															}else{
																*tort = *hare;
															}
														}else{
															*tort = *hare;
														}
														hare++;
														tort++;														
													}
													*(tort) = '\0';
													yyleng = strlen(yytext);
													return TOKEN_STRING_LITERAL; }
												


.    											{ return TOKEN_ERROR; }


%%
int yywrap() { return 1; }
const char* token_to_string(int token){
	
	const char* token_trans[] = {
    	"TOKEN_EOF",
    	"TOKEN_ARRAY",
    	"TOKEN_ELSE",
    	"TOKEN_FALSE",
    	"TOKEN_FOR",
    	"TOKEN_FUNCTION",
    	"TOKEN_IF",
    	"TOKEN_PRINT",
    	"TOKEN_RETURN",
    	"TOKEN_TRUE",
    	"TOKEN_VOID",
    	"TOKEN_WHILE",
    	"TOKEN_INTEGER",
    	"TOKEN_BOOLEAN",
    	"TOKEN_CHARACTER",
    	"TOKEN_STRING",
    	"TOKEN_INTEGER_LITERAL",
    	"TOKEN_CHARACTER_LITERAL",
    	"TOKEN_STRING_LITERAL",
    	"TOKEN_IDENTIFIER",
    	"TOKEN_L_PAREN",
    	"TOKEN_R_PAREN",
    	"TOKEN_L_SUB",
    	"TOKEN_R_SUB",
    	"TOKEN_POST_INC",
    	"TOKEN_POST_DEC",
    	"TOKEN_UNARY_NEG",
    	"TOKEN_LOGIC_NOT",
    	"TOKEN_EXP",
    	"TOKEN_MULT",
    	"TOKEN_DIVIDE",
    	"TOKEN_MOD",
    	"TOKEN_ADD",
    	"TOKEN_SUB",
    	"TOKEN_LT",
    	"TOKEN_LE",
    	"TOKEN_GT",
    	"TOKEN_GE",
    	"TOKEN_EQUIV",
    	"TOKEN_NOT_EQUIV",
    	"TOKEN_LOGIC_AND",
    	"TOKEN_LOGIC_OR",
    	"TOKEN_ASSIGNMENT",
    	"TOKEN_SEMICOLON",
    	"TOKEN_COLON",
    	"TOKEN_COMMA",
    	"TOKEN_L_CURLY",
    	"TOKEN_R_CURLY",
    	"TOKEN_BACKSLASH",
    	"TOKEN_ERROR"
     };

    return token_trans[token];
}

