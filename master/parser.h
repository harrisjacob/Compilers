/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_EOF = 258,
    TOKEN_ARRAY = 259,
    TOKEN_ELSE = 260,
    TOKEN_FALSE = 261,
    TOKEN_FOR = 262,
    TOKEN_FUNCTION = 263,
    TOKEN_IF = 264,
    TOKEN_PRINT = 265,
    TOKEN_RETURN = 266,
    TOKEN_TRUE = 267,
    TOKEN_VOID = 268,
    TOKEN_WHILE = 269,
    TOKEN_INTEGER = 270,
    TOKEN_BOOLEAN = 271,
    TOKEN_CHARACTER = 272,
    TOKEN_STRING = 273,
    TOKEN_INTEGER_LITERAL = 274,
    TOKEN_CHARACTER_LITERAL = 275,
    TOKEN_STRING_LITERAL = 276,
    TOKEN_IDENTIFIER = 277,
    TOKEN_L_PAREN = 278,
    TOKEN_R_PAREN = 279,
    TOKEN_L_SUB = 280,
    TOKEN_R_SUB = 281,
    TOKEN_POST_INC = 282,
    TOKEN_POST_DEC = 283,
    TOKEN_UNARY_NEG = 284,
    TOKEN_LOGIC_NOT = 285,
    TOKEN_EXP = 286,
    TOKEN_MULT = 287,
    TOKEN_DIVIDE = 288,
    TOKEN_MOD = 289,
    TOKEN_ADD = 290,
    TOKEN_SUB = 291,
    TOKEN_LT = 292,
    TOKEN_LE = 293,
    TOKEN_GT = 294,
    TOKEN_GE = 295,
    TOKEN_EQUIV = 296,
    TOKEN_NOT_EQUIV = 297,
    TOKEN_LOGIC_AND = 298,
    TOKEN_LOGIC_OR = 299,
    TOKEN_ASSIGNMENT = 300,
    TOKEN_SEMICOLON = 301,
    TOKEN_COLON = 302,
    TOKEN_COMMA = 303,
    TOKEN_L_CURLY = 304,
    TOKEN_R_CURLY = 305,
    TOKEN_BACKSLASH = 306,
    TOKEN_ERROR = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "parser.bison" /* yacc.c:1921  */

	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	struct param_list *param_list;
	

#line 120 "parser.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
