#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
     TOKEN_EOF=0,
     
     //Keywords
     TOKEN_ARRAY,
     TOKEN_ELSE,
     TOKEN_FALSE,
     TOKEN_FOR,
     TOKEN_FUNCTION,
     TOKEN_IF,
     TOKEN_PRINT,
     TOKEN_RETURN,
     TOKEN_TRUE,
     TOKEN_VOID,
     TOKEN_WHILE,

     //Types
     TOKEN_INTEGER,
     TOKEN_BOOLEAN,
     TOKEN_CHARACTER,
     TOKEN_STRING,

     //Type values
     TOKEN_INTEGER_LITERAL, //An integer is a signed 64 bit value with an optional leading plus or minus.
     TOKEN_CHARACTER_LITERAL, //a single 8-bit ASCII character in single quotes.
     TOKEN_STRING_LITERAL, //a double-quoted constant string that is null-terminated and cannot be modified.


     /* 
     Both char and string may contain the following backslash codes. 
     \n indicates a linefeed (ASCII value 10), \0 indicates a null (ASCII value zero),
      and a backslash followed by anything else indicates exactly the following character. 
      Both strings and identifiers may be up to 256 characters long.
	*/
     
     TOKEN_IDENTIFIER, //May contain letters, numbers, and underscores and may be up to 256 characters long. Identifiers must begin with a letter or an underscore


     //EXPRESSIONS
     TOKEN_L_PAREN,
     TOKEN_R_PAREN,
     TOKEN_L_SUB,
     TOKEN_R_SUB,
     TOKEN_POST_INC,
     TOKEN_POST_DEC,
     TOKEN_UNARY_NEG,
     TOKEN_LOGIC_NOT,
     TOKEN_EXP,
     TOKEN_MULT,
     TOKEN_DIVIDE,
     TOKEN_MOD,
     TOKEN_ADD,
     TOKEN_SUB,
     TOKEN_LT,
     TOKEN_LE,
     TOKEN_GT,
     TOKEN_GE,
     TOKEN_EQUIV,
     TOKEN_NOT_EQUIV,
     TOKEN_LOGIC_AND,
     TOKEN_LOGIC_OR,
     TOKEN_ASSIGNMENT,
     TOKEN_SEMICOLON,
     TOKEN_COLON,
     TOKEN_COMMA,
     TOKEN_L_CURLY,
     TOKEN_R_CURLY,
     TOKEN_BACKSLASH,
     TOKEN_ERROR
} token_t;

#endif
