%{
#include "token.h"
%}
DIGIT  [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n|\r)  /* skip whitespace */
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
((\/\/.*\n)|(\/\*(.|\n)*?\*\/))
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


