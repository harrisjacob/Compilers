/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 59 "parser.bison" /* yacc.c:352  */

	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	struct param_list *param_list;
	

#line 174 "parser.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Second part of user prologue.  */
#line 74 "parser.bison" /* yacc.c:354  */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "decl.h"
#include "type.h"
#include "stmt.h"
#include "expr.h"
#include "param_list.h"
/*
Clunky: Manually declare the interface to the scanner generated by flex. 
*/

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
extern struct decl* program_output;
//extern void check_paren(struct expr** e);

#line 211 "parser.c" /* yacc.c:354  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   332

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

#define YYUNDEFTOK  2
#define YYMAXUTOK   307

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   102,   109,   112,   114,   116,   122,   128,
     131,   133,   135,   137,   139,   141,   143,   145,   149,   151,
     153,   155,   157,   159,   161,   165,   167,   169,   171,   173,
     177,   181,   183,   188,   190,   192,   194,   199,   201,   208,
     210,   215,   216,   220,   222,   227,   228,   250,   252,   254,
     258,   260,   264,   266,   270,   272,   274,   276,   278,   280,
     282,   286,   288,   290,   294,   296,   298,   300,   304,   306,
     310,   312,   314,   318,   323,   328,   332,   334,   336,   338,
     340,   342,   346,   350,   355,   356
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_EOF", "TOKEN_ARRAY", "TOKEN_ELSE",
  "TOKEN_FALSE", "TOKEN_FOR", "TOKEN_FUNCTION", "TOKEN_IF", "TOKEN_PRINT",
  "TOKEN_RETURN", "TOKEN_TRUE", "TOKEN_VOID", "TOKEN_WHILE",
  "TOKEN_INTEGER", "TOKEN_BOOLEAN", "TOKEN_CHARACTER", "TOKEN_STRING",
  "TOKEN_INTEGER_LITERAL", "TOKEN_CHARACTER_LITERAL",
  "TOKEN_STRING_LITERAL", "TOKEN_IDENTIFIER", "TOKEN_L_PAREN",
  "TOKEN_R_PAREN", "TOKEN_L_SUB", "TOKEN_R_SUB", "TOKEN_POST_INC",
  "TOKEN_POST_DEC", "TOKEN_UNARY_NEG", "TOKEN_LOGIC_NOT", "TOKEN_EXP",
  "TOKEN_MULT", "TOKEN_DIVIDE", "TOKEN_MOD", "TOKEN_ADD", "TOKEN_SUB",
  "TOKEN_LT", "TOKEN_LE", "TOKEN_GT", "TOKEN_GE", "TOKEN_EQUIV",
  "TOKEN_NOT_EQUIV", "TOKEN_LOGIC_AND", "TOKEN_LOGIC_OR",
  "TOKEN_ASSIGNMENT", "TOKEN_SEMICOLON", "TOKEN_COLON", "TOKEN_COMMA",
  "TOKEN_L_CURLY", "TOKEN_R_CURLY", "TOKEN_BACKSLASH", "TOKEN_ERROR",
  "$accept", "program", "decl_list", "decl", "stmtList", "stmt", "inside",
  "type", "literal", "arrayLit", "boolean", "fDefOpt", "fDef",
  "optionalArgList", "expr", "expr1", "expr2", "expr3", "expr4", "expr5",
  "expr6", "expr7", "expr8", "expr9", "index", "id", "opt_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -25

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,  -135,    23,    49,    13,    10,  -135,  -135,  -135,    74,
      29,    74,  -135,  -135,  -135,  -135,  -135,    -7,   232,    54,
     253,  -135,  -135,  -135,  -135,  -135,  -135,   265,    74,   265,
     265,   265,  -135,  -135,    53,  -135,    36,    38,    59,     7,
     -12,    52,  -135,   -17,    39,    -5,    13,   104,    40,    70,
    -135,  -135,  -135,    80,  -135,    55,    56,    74,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,  -135,  -135,   265,   265,   265,    84,  -135,
      62,    89,    94,   265,   265,   104,  -135,    69,   104,     3,
     -14,  -135,  -135,  -135,   265,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
      92,  -135,  -135,    96,  -135,  -135,    74,   265,   265,    91,
      95,    71,  -135,  -135,    97,  -135,  -135,  -135,  -135,    87,
    -135,    98,   118,  -135,  -135,  -135,    13,   265,   175,  -135,
     100,   125,   126,   265,   265,   104,   149,  -135,   150,   111,
     265,   265,   265,   115,   116,   114,   104,   161,   146,   128,
     147,   172,   173,   174,  -135,   104,   265,   175,  -135,   134,
     178,   265,   175,   164,  -135,   175,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    83,     0,     0,     4,     0,     1,     2,     3,     0,
       0,     0,    32,    25,    26,    27,    28,     0,     0,     0,
       0,     5,    40,    39,    33,    34,    35,     0,     0,     0,
       0,     0,    76,    79,     0,    49,    51,    53,    60,    63,
      67,    69,    72,    75,    80,    78,    41,     9,     0,     0,
      31,    71,    80,    78,    70,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,    45,     0,     0,    42,
       0,     0,     0,    45,     0,     9,    16,     0,     9,    37,
      78,     6,    77,    36,     0,    30,    50,    52,    54,    55,
      56,    57,    58,    59,    61,    62,    64,    65,    66,    68,
       0,    48,    46,     0,    47,    29,     0,    84,     0,     0,
       0,     0,     7,     8,     0,    17,    38,    82,    81,    43,
      85,     0,     0,    15,    13,    14,     0,    84,     0,    44,
       0,     0,     0,    45,     0,     9,    16,    10,     0,     0,
      84,    84,     0,     0,     0,     0,     0,    17,     0,     0,
       0,    15,    13,    14,    11,     0,    84,     0,    12,     0,
       0,    84,     0,     0,    18,     0,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   185,     1,   -73,  -131,  -122,    -9,  -135,   -70,
    -135,  -135,    63,   -69,    75,   132,   133,    68,   -11,   -42,
     120,    46,  -135,  -135,   261,     0,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    86,    87,    88,   148,    17,    32,    55,
      33,    78,    79,   113,   130,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,     4,    19,   140,     5,     4,   112,   147,    72,    76,
      73,    74,   121,   112,   119,   123,   158,   159,    76,    50,
      68,    69,    70,     6,   126,   164,   106,   107,   108,    53,
      53,    77,   169,     9,   168,     1,   147,   173,    20,    21,
      77,   164,    66,    67,   168,   170,    80,    90,    95,   125,
     174,    94,     7,   176,    18,   104,   105,     9,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,   155,   112,   153,    51,    54,    46,    10,    57,
      58,    59,    11,    71,    75,    90,    91,    12,    90,    13,
      14,    15,    16,    34,    92,    48,    60,    61,    62,    63,
      64,    65,    49,    76,    94,    93,    56,   129,   115,   116,
      22,    81,   117,    82,    83,    84,    23,   118,   127,   122,
     128,   135,    89,    24,    25,    26,     1,    27,    98,    99,
     100,   101,   102,   103,    29,   136,    80,   133,    90,   146,
      30,   134,   138,   125,   137,    90,   150,   110,   151,   152,
     111,    56,   114,    85,   -23,   156,    90,   157,    56,   120,
      89,   161,   162,   124,   163,    90,   -24,    90,   146,    56,
     165,   167,    90,   146,   166,    90,   146,   -22,   -20,   -21,
     171,    22,   141,   172,   142,   143,   144,    23,   175,     8,
      96,   109,    97,   132,    24,    25,    26,     1,    27,   139,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,    30,     0,   149,     0,     0,     0,     0,    56,   154,
      89,     0,     0,     0,   145,     0,     0,   160,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,    22,     0,
     124,     0,   149,     0,    23,     0,     0,   149,     0,     0,
     149,    24,    25,    26,     1,    27,     0,     0,    28,    22,
       0,     0,    29,     0,     0,    23,     0,     0,    30,     0,
       0,    22,    24,    25,    26,     1,    27,    23,     0,     0,
       0,    31,     0,    29,    24,    25,    26,     1,    27,    30,
      52,    52,     0,     0,     0,    29,     0,     0,     0,     0,
       0,    30,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52
};

static const yytype_int16 yycheck[] =
{
       0,     0,    11,   137,     4,     4,    76,   138,    25,    23,
      27,    28,    85,    83,    83,    88,   150,   151,    23,    28,
      32,    33,    34,     0,    94,   156,    68,    69,    70,    29,
      30,    45,   166,    47,   165,    22,   167,   171,    45,    46,
      45,   172,    35,    36,   175,   167,    46,    47,    57,    46,
     172,    48,     3,   175,    25,    66,    67,    47,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   145,   143,   143,    29,    30,    23,     4,    26,
      44,    43,     8,    31,    45,    85,    46,    13,    88,    15,
      16,    17,    18,    18,    24,    20,    37,    38,    39,    40,
      41,    42,    27,    23,    48,    50,    31,   116,    24,    47,
       6,     7,    23,     9,    10,    11,    12,    23,    26,    50,
      24,    50,    47,    19,    20,    21,    22,    23,    60,    61,
      62,    63,    64,    65,    30,    48,   136,    46,   138,   138,
      36,    46,    24,    46,    46,   145,    46,    72,    23,    23,
      75,    76,    77,    49,     5,     5,   156,    46,    83,    84,
      85,    46,    46,    88,    50,   165,     5,   167,   167,    94,
      24,    24,   172,   172,    46,   175,   175,     5,     5,     5,
      46,     6,     7,     5,     9,    10,    11,    12,    24,     4,
      58,    71,    59,   118,    19,    20,    21,    22,    23,   136,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    49,    -1,    -1,   152,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
     165,    -1,   167,    -1,    12,    -1,    -1,   172,    -1,    -1,
     175,    19,    20,    21,    22,    23,    -1,    -1,    26,     6,
      -1,    -1,    30,    -1,    -1,    12,    -1,    -1,    36,    -1,
      -1,     6,    19,    20,    21,    22,    23,    12,    -1,    -1,
      -1,    49,    -1,    30,    19,    20,    21,    22,    23,    36,
      29,    30,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    54,    55,    56,    78,     0,     3,    55,    47,
       4,     8,    13,    15,    16,    17,    18,    60,    25,    60,
      45,    46,     6,    12,    19,    20,    21,    23,    26,    30,
      36,    49,    61,    63,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    23,    49,    67,    67,
      60,    74,    77,    78,    74,    62,    67,    26,    44,    43,
      37,    38,    39,    40,    41,    42,    35,    36,    32,    33,
      34,    31,    25,    27,    28,    45,    23,    45,    64,    65,
      78,     7,     9,    10,    11,    49,    56,    57,    58,    67,
      78,    46,    24,    50,    48,    60,    68,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    73,
      67,    67,    62,    66,    67,    24,    47,    23,    23,    66,
      67,    57,    50,    57,    67,    46,    62,    26,    24,    60,
      67,    79,    67,    46,    46,    50,    48,    46,    24,    65,
      79,     7,     9,    10,    11,    49,    56,    58,    59,    67,
      46,    23,    23,    66,    67,    57,     5,    46,    79,    79,
      67,    46,    46,    50,    58,    24,    46,    24,    58,    79,
      59,    46,     5,    79,    59,    24,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    73,    73,
      74,    74,    74,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     4,     6,     7,     2,     0,
       5,     7,     9,     3,     3,     3,     1,     2,     7,     9,
       3,     3,     3,     1,     2,     1,     1,     1,     1,     5,
       5,     4,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     0,     1,     3,     5,     0,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     1,
       2,     2,     1,     2,     2,     1,     1,     3,     1,     1,
       1,     4,     4,     1,     0,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 99 "parser.bison" /* yacc.c:1652  */
    { program_output = (yyvsp[-1].decl); return 0; }
#line 1446 "parser.c" /* yacc.c:1652  */
    break;

  case 3:
#line 103 "parser.bison" /* yacc.c:1652  */
    { 	

				(yyvsp[-1].decl)->next = (yyvsp[0].decl);
				(yyval.decl) = (yyvsp[-1].decl); 
			}
#line 1456 "parser.c" /* yacc.c:1652  */
    break;

  case 4:
#line 109 "parser.bison" /* yacc.c:1652  */
    { (yyval.decl) = NULL; }
#line 1462 "parser.c" /* yacc.c:1652  */
    break;

  case 5:
#line 113 "parser.bison" /* yacc.c:1652  */
    { (yyval.decl) = decl_create((char *) (yyvsp[-3].expr)->name, (yyvsp[-1].type), NULL, NULL, NULL); }
#line 1468 "parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 115 "parser.bison" /* yacc.c:1652  */
    { (yyval.decl) = decl_create((char *)(yyvsp[-5].expr)->name, (yyvsp[-3].type), (yyvsp[-1].expr), NULL, NULL); }
#line 1474 "parser.c" /* yacc.c:1652  */
    break;

  case 7:
#line 117 "parser.bison" /* yacc.c:1652  */
    { (yyval.decl) = decl_create((char *)(yyvsp[-6].expr)->name, (yyvsp[-4].type), NULL, (yyvsp[-1].stmt), NULL); }
#line 1480 "parser.c" /* yacc.c:1652  */
    break;

  case 8:
#line 123 "parser.bison" /* yacc.c:1652  */
    {
				(yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
				(yyval.stmt) = (yyvsp[-1].stmt);
			}
#line 1489 "parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 128 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = NULL; }
#line 1495 "parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 132 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-2].expr), NULL, (yyvsp[0].stmt), NULL, NULL); }
#line 1501 "parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 134 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-4].expr), NULL, (yyvsp[-2].stmt), (yyvsp[0].stmt), NULL);}
#line 1507 "parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 136 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_FOR, NULL, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, NULL); }
#line 1513 "parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 138 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1519 "parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 140 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, (yyvsp[-1].stmt), NULL, NULL); }
#line 1525 "parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 142 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1531 "parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 144 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), NULL, NULL, NULL, NULL, NULL, NULL); }
#line 1537 "parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 146 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1543 "parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 150 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-4].expr), NULL, (yyvsp[-2].stmt), (yyvsp[0].stmt), NULL);}
#line 1549 "parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 152 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_FOR, NULL, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, NULL); }
#line 1555 "parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 154 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1561 "parser.c" /* yacc.c:1652  */
    break;

  case 21:
#line 156 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, (yyvsp[-1].stmt), NULL, NULL); }
#line 1567 "parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 158 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1573 "parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 160 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), NULL, NULL, NULL, NULL, NULL, NULL); }
#line 1579 "parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 162 "parser.bison" /* yacc.c:1652  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1585 "parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 166 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL, NULL); }
#line 1591 "parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 168 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL, NULL); }
#line 1597 "parser.c" /* yacc.c:1652  */
    break;

  case 27:
#line 170 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_CHARACTER, NULL, NULL, NULL); }
#line 1603 "parser.c" /* yacc.c:1652  */
    break;

  case 28:
#line 172 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL, NULL); }
#line 1609 "parser.c" /* yacc.c:1652  */
    break;

  case 29:
#line 174 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-3].type), (yyvsp[-1].param_list), NULL); }
#line 1615 "parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 178 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), NULL, (yyvsp[-2].expr)); }
#line 1621 "parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 182 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), NULL, NULL); }
#line 1627 "parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 184 "parser.bison" /* yacc.c:1652  */
    { (yyval.type) = type_create(TYPE_VOID, NULL, NULL, NULL);}
#line 1633 "parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 189 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); }
#line 1639 "parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 191 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_char_literal(yytext[0]); }
#line 1645 "parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 193 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_string_literal(yytext); }
#line 1651 "parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 195 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_paren(EXPR_ARRAY_LIT, (yyvsp[-1].expr), NULL); }
#line 1657 "parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 200 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1663 "parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 202 "parser.bison" /* yacc.c:1652  */
    { 
			(yyvsp[-2].expr)->next = (yyvsp[0].expr);
			(yyval.expr) = (yyvsp[-2].expr);
		}
#line 1672 "parser.c" /* yacc.c:1652  */
    break;

  case 39:
#line 209 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_boolean_literal(1); }
#line 1678 "parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 211 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_boolean_literal(0); }
#line 1684 "parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 215 "parser.bison" /* yacc.c:1652  */
    { (yyval.param_list) = NULL; }
#line 1690 "parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 217 "parser.bison" /* yacc.c:1652  */
    { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1696 "parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 221 "parser.bison" /* yacc.c:1652  */
    { (yyval.param_list) = param_list_create((char *)(yyvsp[-2].expr)->name, (yyvsp[0].type), NULL); }
#line 1702 "parser.c" /* yacc.c:1652  */
    break;

  case 44:
#line 223 "parser.bison" /* yacc.c:1652  */
    { (yyval.param_list) = param_list_create((char *)(yyvsp[-4].expr)->name, (yyvsp[-2].type), (yyvsp[0].param_list)); }
#line 1708 "parser.c" /* yacc.c:1652  */
    break;

  case 45:
#line 227 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = NULL; }
#line 1714 "parser.c" /* yacc.c:1652  */
    break;

  case 46:
#line 229 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1720 "parser.c" /* yacc.c:1652  */
    break;

  case 47:
#line 251 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr), NULL);}
#line 1726 "parser.c" /* yacc.c:1652  */
    break;

  case 48:
#line 253 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1732 "parser.c" /* yacc.c:1652  */
    break;

  case 49:
#line 255 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1738 "parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 259 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1744 "parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 261 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1750 "parser.c" /* yacc.c:1652  */
    break;

  case 52:
#line 265 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1756 "parser.c" /* yacc.c:1652  */
    break;

  case 53:
#line 267 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1762 "parser.c" /* yacc.c:1652  */
    break;

  case 54:
#line 271 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1768 "parser.c" /* yacc.c:1652  */
    break;

  case 55:
#line 273 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1774 "parser.c" /* yacc.c:1652  */
    break;

  case 56:
#line 275 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1780 "parser.c" /* yacc.c:1652  */
    break;

  case 57:
#line 277 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1786 "parser.c" /* yacc.c:1652  */
    break;

  case 58:
#line 279 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1792 "parser.c" /* yacc.c:1652  */
    break;

  case 59:
#line 281 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1798 "parser.c" /* yacc.c:1652  */
    break;

  case 60:
#line 283 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1804 "parser.c" /* yacc.c:1652  */
    break;

  case 61:
#line 287 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1810 "parser.c" /* yacc.c:1652  */
    break;

  case 62:
#line 289 "parser.bison" /* yacc.c:1652  */
    {  (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1816 "parser.c" /* yacc.c:1652  */
    break;

  case 63:
#line 291 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1822 "parser.c" /* yacc.c:1652  */
    break;

  case 64:
#line 295 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1828 "parser.c" /* yacc.c:1652  */
    break;

  case 65:
#line 297 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1834 "parser.c" /* yacc.c:1652  */
    break;

  case 66:
#line 299 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1840 "parser.c" /* yacc.c:1652  */
    break;

  case 67:
#line 301 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1846 "parser.c" /* yacc.c:1652  */
    break;

  case 68:
#line 305 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_EXP, (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1852 "parser.c" /* yacc.c:1652  */
    break;

  case 69:
#line 307 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1858 "parser.c" /* yacc.c:1652  */
    break;

  case 70:
#line 311 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_NEG, NULL, (yyvsp[0].expr), NULL); }
#line 1864 "parser.c" /* yacc.c:1652  */
    break;

  case 71:
#line 313 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_NOT, NULL, (yyvsp[0].expr), NULL); }
#line 1870 "parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 315 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1876 "parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 319 "parser.bison" /* yacc.c:1652  */
    {

				(yyval.expr) = expr_create(EXPR_POST_INC, (yyvsp[-1].expr), NULL, NULL); 
			}
#line 1885 "parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 324 "parser.bison" /* yacc.c:1652  */
    { 
				(yyval.expr) = expr_create(EXPR_POST_DEC, (yyvsp[-1].expr), NULL, NULL); 
			}
#line 1893 "parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 329 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1899 "parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 333 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1905 "parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 335 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_paren(EXPR_PAREN, (yyvsp[-1].expr), NULL); }
#line 1911 "parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 337 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1917 "parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 339 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1923 "parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 341 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1929 "parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 343 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_FUNC, (yyvsp[-3].expr), (yyvsp[-1].expr), NULL); }
#line 1935 "parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 347 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create(EXPR_INDEX, (yyvsp[-3].expr), (yyvsp[-1].expr), NULL); }
#line 1941 "parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 351 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = expr_create_name(yytext); }
#line 1947 "parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 355 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = NULL; }
#line 1953 "parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 357 "parser.bison" /* yacc.c:1652  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1959 "parser.c" /* yacc.c:1652  */
    break;


#line 1963 "parser.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 361 "parser.bison" /* yacc.c:1918  */


/*
This function will be called by bison if the parse should
encounter an error.  In principle, "str" will contain something
useful.  In practice, it often does not.
*/

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}

