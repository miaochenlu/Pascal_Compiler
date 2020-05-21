/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     DOT = 259,
     DOTDOT = 260,
     SEMI = 261,
     COMMA = 262,
     COLON = 263,
     LP = 264,
     RP = 265,
     LB = 266,
     RB = 267,
     EQUAL = 268,
     UNEQUAL = 269,
     GE = 270,
     GT = 271,
     LE = 272,
     LT = 273,
     PLUS = 274,
     MINUS = 275,
     MUL = 276,
     DIV = 277,
     MOD = 278,
     OR = 279,
     AND = 280,
     NOT = 281,
     INTEGER = 282,
     REAL = 283,
     CHAR = 284,
     STRING = 285,
     ARRAY = 286,
     BOOLEAN = 287,
     PROGRAM = 288,
     PROCEDURE = 289,
     FUNCTION = 290,
     CONST = 291,
     TYPE = 292,
     VAR = 293,
     RECORD = 294,
     BEGIN = 295,
     END = 296,
     ASSIGN = 297,
     IF = 298,
     THEN = 299,
     ELSE = 300,
     REPEAT = 301,
     UNTIL = 302,
     WHILE = 303,
     DO = 304,
     FOR = 305,
     TO = 306,
     DOWNTO = 307,
     CASE = 308,
     OF = 309,
     GOTO = 310,
     READ = 311,
     SYS_CON = 312,
     SYS_PROC = 313,
     SYS_TYPE = 314,
     SYS_FUNCT = 315
   };
#endif
/* Tokens.  */
#define ID 258
#define DOT 259
#define DOTDOT 260
#define SEMI 261
#define COMMA 262
#define COLON 263
#define LP 264
#define RP 265
#define LB 266
#define RB 267
#define EQUAL 268
#define UNEQUAL 269
#define GE 270
#define GT 271
#define LE 272
#define LT 273
#define PLUS 274
#define MINUS 275
#define MUL 276
#define DIV 277
#define MOD 278
#define OR 279
#define AND 280
#define NOT 281
#define INTEGER 282
#define REAL 283
#define CHAR 284
#define STRING 285
#define ARRAY 286
#define BOOLEAN 287
#define PROGRAM 288
#define PROCEDURE 289
#define FUNCTION 290
#define CONST 291
#define TYPE 292
#define VAR 293
#define RECORD 294
#define BEGIN 295
#define END 296
#define ASSIGN 297
#define IF 298
#define THEN 299
#define ELSE 300
#define REPEAT 301
#define UNTIL 302
#define WHILE 303
#define DO 304
#define FOR 305
#define TO 306
#define DOWNTO 307
#define CASE 308
#define OF 309
#define GOTO 310
#define READ 311
#define SYS_CON 312
#define SYS_PROC 313
#define SYS_TYPE 314
#define SYS_FUNCT 315




/* Copy the first part of user declarations.  */
#line 1 "pascal.y"

#include <iostream>
#include <vector>
#include <string>
#include "global.h"
using namespace std;

ast::BasicAstNode* root;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "pascal.y"
{
    string                  aststring;
    ast::Identifier*        astIdentifier;
    ast::NameList*          astNameList;
    ast::Expression*        astExpression;
    ast::stmt*              astStmt;
    ast::Program*           astProgram;
    ast::ProgramHead*       astProgramHead;
    ast::Routine*           astRoutine;
    ast::RoutineHead*       astRoutineHead;
    ast::StmtList*          astStmtList;
    ast::Parameter*         astParameter;
    ast::ParamList*         astParamList;
    ast::LabelDecl*         astLabelDecl;
    ast::ConstDecl*         astConstDecl;
    ast::TypeDecl*          astTypeDecl;
    ast::VarDecl*           astVarDecl;
    ast::LabelDeclList*     astLabelDeclList;
    ast::ConstDeclList*     astConstDeclList;
    ast::TypeDeclList*      astTypeDeclList;
    ast::VarDeclList*       astVarDeclList;
    ast::RoutinePartList*   astRoutinePartList;
    ast::BasicConst*        astBasicConst;
    ast::BasicType*         astBasicType;
    ast::CaseExpr*          astCaseExpr;
    ast::CaseExprList*      astCaseExprList;
    ast::ArgList*           astArgList;
    ast::ExpressionList*    astExpressionList;
    ast::Direction          astDirection;
}
/* Line 193 of yacc.c.  */
#line 257 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 270 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   325

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    16,    19,    24,    27,
      28,    34,    39,    41,    43,    45,    47,    49,    51,    54,
      55,    58,    60,    65,    67,    69,    71,    73,    77,    82,
      88,    92,    99,   103,   106,   108,   113,   117,   119,   122,
     123,   126,   128,   133,   136,   139,   140,   145,   151,   156,
     160,   164,   165,   169,   171,   176,   180,   182,   186,   190,
     191,   193,   195,   197,   199,   201,   203,   205,   207,   209,
     213,   220,   226,   228,   233,   235,   240,   245,   251,   254,
     255,   260,   265,   274,   276,   278,   284,   287,   289,   294,
     299,   302,   306,   308,   312,   316,   320,   324,   328,   332,
     334,   338,   342,   346,   348,   352,   356,   360,   364,   366,
     368,   373,   375,   380,   382,   386,   389,   392,   397,   401,
     405
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    63,    -1,    64,    65,     4,    -1,    33,
       3,     6,    -1,    67,    92,    -1,    67,    92,    -1,    68,
      71,    81,    84,    -1,    36,    69,    -1,    -1,    69,     3,
      13,    70,     6,    -1,     3,    13,    70,     6,    -1,    27,
      -1,    28,    -1,    29,    -1,    30,    -1,    32,    -1,    57,
      -1,    37,    72,    -1,    -1,    72,    73,    -1,    73,    -1,
       3,    13,    74,     6,    -1,    75,    -1,    76,    -1,    77,
      -1,    59,    -1,    70,     5,    70,    -1,    20,    70,     5,
      70,    -1,    20,    70,     5,    20,    70,    -1,     3,     5,
       3,    -1,    31,    11,    75,    12,    54,    74,    -1,    39,
      78,    41,    -1,    78,    79,    -1,    79,    -1,    80,     8,
      74,     6,    -1,    80,     7,     3,    -1,     3,    -1,    38,
      82,    -1,    -1,    82,    83,    -1,    83,    -1,    80,     8,
      74,     6,    -1,    84,    85,    -1,    84,    87,    -1,    -1,
      86,     6,    66,     6,    -1,    35,     3,    89,     8,    75,
      -1,    88,     6,    66,     6,    -1,    34,     3,    89,    -1,
       9,    90,    10,    -1,    -1,    90,     6,    91,    -1,    91,
      -1,    38,    80,     8,    75,    -1,    80,     8,    75,    -1,
      93,    -1,    40,    94,    41,    -1,    94,    95,     6,    -1,
      -1,    96,    -1,    97,    -1,    93,    -1,    98,    -1,   100,
      -1,   101,    -1,   102,    -1,   104,    -1,   107,    -1,     3,
      42,   109,    -1,     3,    11,   109,    12,    42,   109,    -1,
       3,     4,     3,    42,   109,    -1,     3,    -1,     3,     9,
     113,    10,    -1,    58,    -1,    58,     9,   108,    10,    -1,
      56,     9,   112,    10,    -1,    43,   109,    44,    95,    99,
      -1,    45,    95,    -1,    -1,    46,    94,    47,   109,    -1,
      48,   109,    49,    95,    -1,    50,     3,    42,   109,   103,
     109,    49,    95,    -1,    51,    -1,    52,    -1,    53,   109,
      54,   105,    41,    -1,   105,   106,    -1,   106,    -1,    70,
       8,    95,     6,    -1,     3,     8,    95,     6,    -1,    55,
      27,    -1,   108,     7,   109,    -1,   109,    -1,   109,    15,
     110,    -1,   109,    16,   110,    -1,   109,    17,   110,    -1,
     109,    18,   110,    -1,   109,    13,   110,    -1,   109,    14,
     110,    -1,   110,    -1,   110,    19,   111,    -1,   110,    20,
     111,    -1,   110,    24,   111,    -1,   111,    -1,   111,    21,
     112,    -1,   111,    22,   112,    -1,   111,    23,   112,    -1,
     111,    25,   112,    -1,   112,    -1,     3,    -1,     3,     9,
     113,    10,    -1,    60,    -1,    60,     9,   113,    10,    -1,
      70,    -1,     9,   109,    10,    -1,    26,   112,    -1,    20,
     112,    -1,     3,    11,   109,    12,    -1,     3,     4,     3,
      -1,   113,     7,   109,    -1,   109,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   102,   107,   112,   117,   122,   127,   130,
     135,   139,   145,   146,   147,   148,   149,   150,   153,   154,
     159,   163,   169,   174,   175,   176,   179,   198,   201,   204,
     207,   213,   218,   223,   227,   233,   239,   243,   248,   249,
     252,   256,   261,   268,   272,   276,   279,   283,   287,   292,
     297,   300,   304,   308,   314,   320,   329,   333,   338,   342,
     356,   359,   362,   365,   368,   371,   374,   377,   380,   385,
     388,   391,   397,   400,   403,   406,   409,   413,   417,   420,
     425,   430,   434,   438,   441,   446,   451,   455,   461,   464,
     469,   473,   477,   483,   486,   489,   492,   495,   498,   501,
     505,   508,   511,   514,   519,   522,   525,   528,   531,   536,
     539,   542,   545,   548,   551,   554,   557,   560,   563,   567,
     571
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "DOT", "DOTDOT", "SEMI", "COMMA",
  "COLON", "LP", "RP", "LB", "RB", "EQUAL", "UNEQUAL", "GE", "GT", "LE",
  "LT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "OR", "AND", "NOT",
  "INTEGER", "REAL", "CHAR", "STRING", "ARRAY", "BOOLEAN", "PROGRAM",
  "PROCEDURE", "FUNCTION", "CONST", "TYPE", "VAR", "RECORD", "BEGIN",
  "END", "ASSIGN", "IF", "THEN", "ELSE", "REPEAT", "UNTIL", "WHILE", "DO",
  "FOR", "TO", "DOWNTO", "CASE", "OF", "GOTO", "READ", "SYS_CON",
  "SYS_PROC", "SYS_TYPE", "SYS_FUNCT", "$accept", "programPrime",
  "program", "program_head", "routine", "sub_routine", "routine_head",
  "const_part", "const_expr_list", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "simple_type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "name_list", "var_part", "var_decl_list", "var_decl", "routine_part",
  "function_decl", "function_head", "procedure_decl", "procedure_head",
  "parameters", "para_decl_list", "para_type_list", "routine_body",
  "compound_stmt", "stmt_list", "stmt", "assign_stmt", "proc_stmt",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt",
  "direction", "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", "args_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    66,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    76,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    83,    84,    84,    84,    85,    86,    87,    88,
      89,    89,    90,    90,    91,    91,    92,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    99,    99,
     100,   101,   102,   103,   103,   104,   105,   105,   106,   106,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     4,     2,     0,
       5,     4,     1,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     4,     1,     1,     1,     1,     3,     4,     5,
       3,     6,     3,     2,     1,     4,     3,     1,     2,     0,
       2,     1,     4,     2,     2,     0,     4,     5,     4,     3,
       3,     0,     3,     1,     4,     3,     1,     3,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       6,     5,     1,     4,     1,     4,     4,     5,     2,     0,
       4,     4,     8,     1,     1,     5,     2,     1,     4,     4,
       2,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     1,
       4,     1,     4,     1,     3,     2,     2,     4,     3,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     9,     0,     1,     0,     0,     0,
      19,     4,     0,     8,     3,    59,     5,    56,     0,    39,
       0,     0,     0,     0,    18,    21,     0,    45,    12,    13,
      14,    15,    16,    17,     0,     0,    72,    57,     0,    59,
       0,     0,     0,     0,     0,    74,    62,     0,    60,    61,
      63,    64,    65,    66,    67,    68,     0,    20,    37,     0,
      38,    41,     7,    11,     0,     0,     0,     0,     0,   109,
       0,     0,     0,   111,   113,     0,    99,   103,   108,     0,
       0,     0,     0,    90,     0,     0,    58,     0,     0,     0,
       0,    26,     0,     0,    23,    24,    25,     0,     0,    40,
       0,     0,    43,     0,    44,     0,    10,     0,   120,     0,
       0,    69,     0,     0,     0,     0,   116,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,    34,     0,     0,    22,    36,     0,
      51,    51,     9,     9,     0,     0,    73,     0,   118,     0,
       0,   114,     0,    97,    98,    93,    94,    95,    96,    79,
     100,   101,   102,   104,   105,   106,   107,    80,    81,     0,
       0,     0,     0,    87,    76,     0,    75,    30,     0,     0,
      32,    33,     0,    27,    42,     0,    49,     0,     0,     0,
       0,    71,   119,     0,   110,   117,   112,     0,    77,    83,
      84,     0,     0,     0,    85,    86,    91,     0,    28,     0,
       0,     0,     0,     0,    53,     0,    46,     6,    48,    70,
      78,     0,     0,     0,    29,     0,    35,     0,     0,     0,
      50,    47,     0,    89,    88,    31,     0,    55,    52,    82,
      54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,   198,   199,    10,    13,    74,
      19,    24,    25,    93,    94,    95,    96,   143,   144,    59,
      27,    60,    61,    62,   102,   103,   104,   105,   196,   223,
     224,    16,    46,    22,    47,    48,    49,    50,   208,    51,
      52,    53,   211,    54,   182,   183,    55,   138,   108,    76,
      77,    78,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -138
static const yytype_int16 yypact[] =
{
       1,    22,    48,  -138,    41,    46,  -138,   101,   109,    78,
      82,  -138,   115,   120,  -138,  -138,  -138,  -138,   129,    97,
      53,   128,    90,   131,   129,  -138,   139,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,   141,    53,    12,  -138,    15,  -138,
      15,   150,    15,   133,   147,   154,  -138,   159,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,    30,  -138,  -138,    63,
     139,  -138,    60,  -138,   170,   182,    15,    15,    15,    42,
      15,    15,    15,   177,  -138,   248,    87,   173,  -138,   111,
      14,   146,   206,  -138,    15,    15,  -138,   198,    53,   195,
     139,  -138,   209,   187,  -138,  -138,  -138,   208,    30,  -138,
     213,   214,  -138,   219,  -138,   221,  -138,   186,   273,    10,
     281,   273,   238,    15,    15,   261,  -138,  -138,    15,    15,
      15,    15,    15,    15,    15,   134,    15,    15,    15,    15,
      15,    15,    15,    15,   134,    15,   180,   232,    69,   273,
     244,   250,    70,     8,  -138,   142,    53,  -138,  -138,   251,
     247,   247,    41,    41,    15,    15,  -138,   225,  -138,   105,
     288,  -138,   110,    87,    87,    87,    87,    87,    87,   227,
     173,   173,   173,  -138,  -138,  -138,  -138,   273,  -138,   217,
     262,   272,   172,  -138,  -138,    15,  -138,  -138,   216,   246,
    -138,  -138,    30,  -138,  -138,    36,  -138,   274,   253,    78,
     275,   273,   273,    15,  -138,  -138,  -138,   134,  -138,  -138,
    -138,    15,   134,   134,  -138,  -138,   273,    53,  -138,   229,
     278,   139,   163,    16,  -138,    70,  -138,  -138,  -138,   273,
    -138,   236,   307,   308,  -138,    30,  -138,   171,    70,    36,
    -138,  -138,   134,  -138,  -138,  -138,    70,  -138,  -138,  -138,
    -138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,  -138,   162,   312,  -138,  -138,   -20,
    -138,  -138,   293,   -96,  -137,  -138,  -138,  -138,   175,   -87,
    -138,  -138,   259,  -138,  -138,  -138,  -138,  -138,   169,  -138,
      83,   122,    -8,   284,  -121,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,   143,  -138,  -138,   -30,   188,
     112,   -65,  -104
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    17,   149,   145,   169,   189,   116,   117,    75,   159,
      80,    58,    82,   178,   162,    64,    65,   155,    69,   137,
     156,    66,   239,    67,    70,     5,   240,   119,   120,   121,
     122,   123,   124,    87,     1,    71,    92,   110,   111,    58,
     115,    72,    28,    29,    30,    31,   112,    32,     6,   190,
      88,   113,    11,   114,    68,   139,   145,    28,    29,    30,
      31,    89,    32,   134,   173,   174,   175,   176,   141,    90,
      97,    98,    33,    87,   221,    73,   185,     7,    92,   186,
      28,    29,    30,    31,   160,    32,   230,    33,   241,    91,
      88,   232,   233,    36,   100,   101,   220,    28,    29,    30,
      31,   247,    32,   177,    12,   179,   126,   127,   222,   250,
      33,   128,   155,    14,    36,   204,   181,   155,    15,    18,
     206,   249,    92,    21,   201,   202,   193,    33,    20,    91,
      15,    37,    23,    38,   237,    26,    39,    36,    40,   245,
      41,    35,    58,    42,    56,    43,    44,    63,    45,    97,
     192,    15,   222,    81,    38,   216,    84,    39,   133,    40,
      83,    41,   181,    85,    42,    86,    43,    44,   218,    45,
      97,   238,    92,   229,    15,   180,   106,    38,    97,   246,
      39,   231,    40,   180,    41,   107,   118,    42,   135,    43,
      44,    17,    45,   147,   129,   130,   131,   234,   132,    28,
      29,    30,    31,   140,    32,    92,   142,    28,    29,    30,
      31,   148,    32,   214,   146,    92,   150,   151,    92,   119,
     120,   121,   122,   123,   124,   152,    92,   153,   154,    33,
     119,   120,   121,   122,   123,   124,   217,    33,   170,   171,
     172,   158,   184,    28,    29,    30,    31,   187,    32,   119,
     120,   121,   122,   123,   124,   188,   195,   194,   219,   226,
     136,   119,   120,   121,   122,   123,   124,   203,   209,   210,
     212,   161,   207,    33,   119,   120,   121,   122,   123,   124,
     213,   228,   225,   235,   236,   242,   119,   120,   121,   122,
     123,   124,   125,   157,   119,   120,   121,   122,   123,   124,
     205,   119,   120,   121,   122,   123,   124,   163,   164,   165,
     166,   167,   168,   243,   244,   200,     9,    57,   191,    99,
     197,   227,   248,    79,     0,   215
};

static const yytype_int16 yycheck[] =
{
      20,     9,    98,    90,   125,   142,    71,    72,    38,   113,
      40,     3,    42,   134,   118,    35,     4,     7,     3,    84,
      10,     9,     6,    11,     9,     3,    10,    13,    14,    15,
      16,    17,    18,     3,    33,    20,    56,    67,    68,     3,
      70,    26,    27,    28,    29,    30,     4,    32,     0,    41,
      20,     9,     6,    11,    42,    85,   143,    27,    28,    29,
      30,    31,    32,    49,   129,   130,   131,   132,    88,    39,
       7,     8,    57,     3,    38,    60,     7,    36,    98,    10,
      27,    28,    29,    30,   114,    32,   207,    57,   225,    59,
      20,   212,   213,     3,    34,    35,   192,    27,    28,    29,
      30,   238,    32,   133,     3,   135,    19,    20,   195,   246,
      57,    24,     7,     4,     3,    10,   136,     7,    40,    37,
      10,   242,   142,     3,   154,   155,   146,    57,    13,    59,
      40,    41,     3,    43,   221,    38,    46,     3,    48,   235,
      50,    13,     3,    53,    13,    55,    56,     6,    58,     7,
       8,    40,   239,     3,    43,   185,     9,    46,    47,    48,
      27,    50,   182,     9,    53,     6,    55,    56,   188,    58,
       7,     8,   192,   203,    40,     3,     6,    43,     7,     8,
      46,   211,    48,     3,    50,     3,     9,    53,    42,    55,
      56,   199,    58,     6,    21,    22,    23,   217,    25,    27,
      28,    29,    30,     5,    32,   225,    11,    27,    28,    29,
      30,     3,    32,    41,     5,   235,     3,     3,   238,    13,
      14,    15,    16,    17,    18,     6,   246,     6,    42,    57,
      13,    14,    15,    16,    17,    18,    20,    57,   126,   127,
     128,     3,    10,    27,    28,    29,    30,     3,    32,    13,
      14,    15,    16,    17,    18,     5,     9,     6,    12,     6,
      54,    13,    14,    15,    16,    17,    18,    42,    51,    52,
       8,    10,    45,    57,    13,    14,    15,    16,    17,    18,
       8,     6,     8,    54,     6,    49,    13,    14,    15,    16,
      17,    18,    44,    12,    13,    14,    15,    16,    17,    18,
      12,    13,    14,    15,    16,    17,    18,   119,   120,   121,
     122,   123,   124,     6,     6,   153,     4,    24,   143,    60,
     151,   199,   239,    39,    -1,   182
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    62,    63,    64,     3,     0,    36,    65,    67,
      68,     6,     3,    69,     4,    40,    92,    93,    37,    71,
      13,     3,    94,     3,    72,    73,    38,    81,    27,    28,
      29,    30,    32,    57,    70,    13,     3,    41,    43,    46,
      48,    50,    53,    55,    56,    58,    93,    95,    96,    97,
      98,   100,   101,   102,   104,   107,    13,    73,     3,    80,
      82,    83,    84,     6,    70,     4,     9,    11,    42,     3,
       9,    20,    26,    60,    70,   109,   110,   111,   112,    94,
     109,     3,   109,    27,     9,     9,     6,     3,    20,    31,
      39,    59,    70,    74,    75,    76,    77,     7,     8,    83,
      34,    35,    85,    86,    87,    88,     6,     3,   109,   113,
     109,   109,     4,     9,    11,   109,   112,   112,     9,    13,
      14,    15,    16,    17,    18,    44,    19,    20,    24,    21,
      22,    23,    25,    47,    49,    42,    54,   112,   108,   109,
       5,    70,    11,    78,    79,    80,     5,     6,     3,    74,
       3,     3,     6,     6,    42,     7,    10,    12,     3,   113,
     109,    10,   113,   110,   110,   110,   110,   110,   110,    95,
     111,   111,   111,   112,   112,   112,   112,   109,    95,   109,
       3,    70,   105,   106,    10,     7,    10,     3,     5,    75,
      41,    79,     8,    70,     6,     9,    89,    89,    66,    67,
      66,   109,   109,    42,    10,    12,    10,    45,    99,    51,
      52,   103,     8,     8,    41,   106,   109,    20,    70,    12,
      74,    38,    80,    90,    91,     8,     6,    92,     6,   109,
      95,   109,    95,    95,    70,    54,     6,    80,     8,     6,
      10,    75,    49,     6,     6,    74,     8,    75,    91,    95,
      75
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 101 "pascal.y"
    { root = (yyvsp[(1) - (1)].astProgram); }
    break;

  case 3:
#line 102 "pascal.y"
    { 
                    (yyval.astProgram) = new ast::Program((yyvsp[(1) - (3)].astProgramHead), (yyvsp[(2) - (3)].astRoutine)); 
                }
    break;

  case 4:
#line 107 "pascal.y"
    { 
                    (yyval.label) = new ast::ProgramHead(new ast::Identifier((yyvsp[(2) - (3)].aststring)), new ast::ParamList(), new ast::VoidType()); 
                }
    break;

  case 5:
#line 112 "pascal.y"
    { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[(1) - (2)].astRoutineHead), (yyvsp[(2) - (2)].astStmtList)); 
                }
    break;

  case 6:
#line 117 "pascal.y"
    { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[(1) - (2)].astRoutineHead), (yyvsp[(2) - (2)].astStmtList)); 
                }
    break;

  case 7:
#line 122 "pascal.y"
    { 
                    (yyval.astRoutineHead) = new ast::RoutineHead((yyvsp[(1) - (4)].astConstDeclList), (yyvsp[(2) - (4)].astTypeDeclList), (yyvsp[(3) - (4)].astVarDeclList), (yyvsp[(4) - (4)].astRoutinePartList)); 
                }
    break;

  case 8:
#line 127 "pascal.y"
    { 
                    (yyval.astConstDeclList) = (yyvsp[(2) - (2)].astConstDeclList); 
                }
    break;

  case 9:
#line 130 "pascal.y"
    { 
                    (yyval.astConstDeclList) = new ast::ConstDeclList() 
                }
    break;

  case 10:
#line 135 "pascal.y"
    { 
                    (yyval.astConstDeclList) = (yyvsp[(1) - (5)].astConstDeclList);
                    (yyvsp[(1) - (5)].astConstDeclList).push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[(2) - (5)].aststring)), (yyvsp[(4) - (5)].astBasicConst)));
                }
    break;

  case 11:
#line 139 "pascal.y"
    {
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                    (yyvsp[(1) - (4)].aststring).push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[(2) - (4)].aststring)), (yyvsp[(4) - (4)].aststring)));
                }
    break;

  case 12:
#line 145 "pascal.y"
    {(yyval.astBasicConst) = new ast::IntegerNode((yyvsp[(1) - (1)].aststring)); /*需不需要atoi呢， 注意这里还有一些问题*/}
    break;

  case 13:
#line 146 "pascal.y"
    {(yyval.astBasicConst) = new ast::RealNode((yyvsp[(1) - (1)].aststring));}
    break;

  case 14:
#line 147 "pascal.y"
    {(yyval.astBasicConst) = new ast::CharNode((yyvsp[(1) - (1)].aststring));}
    break;

  case 15:
#line 148 "pascal.y"
    {(yyval.astBasicConst) = new ast::StringNode((yyvsp[(1) - (1)].aststring));}
    break;

  case 16:
#line 149 "pascal.y"
    {(yyval.astBasicConst) = new ast::BooleanNode((yyvsp[(1) - (1)].aststring));}
    break;

  case 17:
#line 150 "pascal.y"
    {(yyval.astBasicConst) = new ast::MaxIntNode((yyvsp[(1) - (1)].aststring));}
    break;

  case 18:
#line 153 "pascal.y"
    { (yyval.astTypeDeclList) = (yyvsp[(2) - (2)].astTypeDeclList); }
    break;

  case 19:
#line 154 "pascal.y"
    { 
                    (yyval.astTypeDeclList) = new ast::TypeDeclList(); 
                }
    break;

  case 20:
#line 159 "pascal.y"
    { 
                    (yyval.astTypeDeclList) = (yyvsp[(1) - (2)].astTypeDeclList);
                    (yyvsp[(1) - (2)].astTypeDeclList).push_back((yyvsp[(2) - (2)].astTypeDecl));
                }
    break;

  case 21:
#line 163 "pascal.y"
    {
                    (yyval.astTypeDeclList) = new ast::TypeDeclList();
                    (yyval.astTypeDeclList).push_back((yyvsp[(1) - (1)].astTypeDecl));
                }
    break;

  case 22:
#line 169 "pascal.y"
    { 
                    (yyval.astTypeDecl) = new ast::TypeDecl(ast::Identifier((yyvsp[(1) - (4)].aststring)), (yyvsp[(3) - (4)].astBasicType)); 
                }
    break;

  case 23:
#line 174 "pascal.y"
    { (yyval.astBasicType) = (yyvsp[(1) - (1)].astBasicType); }
    break;

  case 24:
#line 175 "pascal.y"
    { (yyval.astBasicType) = (yyvsp[(1) - (1)].astBasicType); }
    break;

  case 25:
#line 176 "pascal.y"
    { (yyval.astBasicType) = (yyvsp[(1) - (1)].astBasicType); }
    break;

  case 26:
#line 179 "pascal.y"
    { 
                    if((yyvsp[(1) - (1)].aststring) == ast::SYS_TYPE::INT) {
                        (yyval.astBasicType) = new ast::IntegerType();
                    } else if((yyvsp[(1) - (1)].aststring) == ast::SYS_TYPE::REAL) {
                        (yyval.astBasicType) = new ast::RealType();
                    } else if((yyvsp[(1) - (1)].aststring) == ast::SYS_TYPE::CHAR) {
                        (yyval.astBasicType) = new ast::CharType();
                    } else if((yyvsp[(1) - (1)].aststring) == ast::SYS_TYPE::BOOLEAN) {
                        (yyval.astBasicType) = new ast::BooleanType();
                    } else if((yyvsp[(1) - (1)].aststring) == ast::SYS_TYPE::STRING) {
                        (yyval.astBasicType) = new ast::StringType();
                    }
                }
    break;

  case 27:
#line 198 "pascal.y"
    { 
                    (yyval.astBasicType) = new ast::RangeType((yyvsp[(1) - (3)].astBasicConst), (yyvsp[(3) - (3)].astBasicConst)); 
                }
    break;

  case 28:
#line 201 "pascal.y"
    { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEG, (yyvsp[(2) - (4)].astBasicConst)), (yyvsp[(4) - (4)].astBasicConst)); 
                }
    break;

  case 29:
#line 204 "pascal.y"
    { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEG, (yyvsp[(2) - (5)].astBasicConst)), new ast::UnaryExpr(ast::UnaryOperator::NEG, (yyvsp[(5) - (5)].astBasicConst))); 
                }
    break;

  case 30:
#line 207 "pascal.y"
    {
                    (yyval.astBasicType) = new ast::RangeType((ast::Expression*)(new ast::Identifier((yyvsp[(1) - (3)].aststring))), (ast::Expression*)(new ast::Identifier((yyvsp[(3) - (3)].aststring))));
                }
    break;

  case 31:
#line 213 "pascal.y"
    { 
                    (yyval.astBasicType) = new ast::ArrayType((yyvsp[(3) - (6)].astBasicType), (yyvsp[(6) - (6)].astBasicType)); 
                }
    break;

  case 32:
#line 218 "pascal.y"
    { 
                    (yyval.astBasicType) = new ast::RecordType((yyvsp[(2) - (3)].astVarDeclList)); 
                }
    break;

  case 33:
#line 223 "pascal.y"
    { 
                    (yyval.astVarDeclList) = (yyvsp[(1) - (2)].astVarDeclList);
                    (yyval.astVarDeclList).push_back((yyvsp[(2) - (2)].astVarDecl));
                }
    break;

  case 34:
#line 227 "pascal.y"
    {
                    (yyval.astVarDeclList) = new ast::VarDeclList();
                    (yyval.astVarDeclList).push_back((yyvsp[(1) - (1)].astVarDecl));
                }
    break;

  case 35:
#line 233 "pascal.y"
    {
                    (yyval.astVarDecl) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[(1) - (4)].astNameList))) 
                        (yyval.astVarDecl)->push_back(new ast::Parameter(new ast::Identifier(name), (yyvsp[(3) - (4)].astBasicType)));
                }
    break;

  case 36:
#line 239 "pascal.y"
    {
                    (yyval.astNameList) = (yyvsp[(1) - (3)].astNameList);
                    (yyval.astNameList).push_back(new ast::Identifier((yyvsp[(3) - (3)].aststring)));
                }
    break;

  case 37:
#line 243 "pascal.y"
    {
                    (yyval.astNameList) = new ast::NameList;
                    (yyval.astNameList).push_back(new ast::Identifier((yyvsp[(1) - (1)].aststring)));
                }
    break;

  case 38:
#line 248 "pascal.y"
    { (yyval.astVarDeclList) = (yyvsp[(2) - (2)].astVarDeclList); }
    break;

  case 39:
#line 249 "pascal.y"
    { (yyval.astVarDeclList) = new ast::VarDeclList(); }
    break;

  case 40:
#line 252 "pascal.y"
    { 
                    (yyval.astVarDeclList) = (yyvsp[(1) - (2)].astVarDeclList);
                    (yyval.astVarDeclList).push_back((yyvsp[(2) - (2)].astVarDecl));
                }
    break;

  case 41:
#line 256 "pascal.y"
    {
                    (yyval.astVarDeclList) = (yyvsp[(1) - (1)].astVarDecl);
                }
    break;

  case 42:
#line 261 "pascal.y"
    {
                    (yyval.astVarDecl) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[(1) - (4)].astNameList))) 
                        (yyval.astVarDecl)->push_back(new ast::Parameter(new ast::Identifier(name), (yyvsp[(3) - (4)].astBasicType)));
                }
    break;

  case 43:
#line 268 "pascal.y"
    {
                    (yyval.astRoutinePartList) = (yyvsp[(1) - (2)].astRoutinePartList);
                    (yyval.astRoutinePartList).push_back((yyvsp[(2) - (2)].astProgram));
                }
    break;

  case 44:
#line 272 "pascal.y"
    {
                    (yyval.astRoutinePartList) = (yyvsp[(1) - (2)].astRoutinePartList);
                    (yyval.astRoutinePartList).push_back((yyvsp[(2) - (2)].astProgram));
                }
    break;

  case 45:
#line 276 "pascal.y"
    { (yyval.astRoutinePartList) = new ast::RoutinePartList(); }
    break;

  case 46:
#line 279 "pascal.y"
    {
                    (yyval.astProgram) = new ast::Program((yyvsp[(1) - (4)].astProgramHead), (yyvsp[(3) - (4)].astRoutine));
                }
    break;

  case 47:
#line 283 "pascal.y"
    {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[(2) - (5)].aststring)), (yyvsp[(3) - (5)].astParamList), (yyvsp[(5) - (5)].astBasicType));
                }
    break;

  case 48:
#line 287 "pascal.y"
    {
                    (yyval.astProgram) = new ast::Program((yyvsp[(1) - (4)].astProgramHead), (yyvsp[(3) - (4)].astRoutine));
                }
    break;

  case 49:
#line 292 "pascal.y"
    {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[(2) - (3)].aststring)), (yyvsp[(3) - (3)].astParamList), new ast::VoidType()); 
                }
    break;

  case 50:
#line 297 "pascal.y"
    {
                    (yyval.astParamList) = (yyvsp[(2) - (3)].astParamList);
                }
    break;

  case 51:
#line 300 "pascal.y"
    {
                    (yyval.astParamList) = new ast::ParamList();
                }
    break;

  case 52:
#line 304 "pascal.y"
    {
                    (yyval.astParamList) = (yyvsp[(1) - (3)].astParamList);
                    (yyval.astParamList).push_back((yyvsp[(3) - (3)].astParameter));
                }
    break;

  case 53:
#line 308 "pascal.y"
    {
                    (yyval.astParamList) = (yyvsp[(1) - (1)].astParameter);
                }
    break;

  case 54:
#line 314 "pascal.y"
    {
                    (yyval.astParameter) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[(1) - (4)].aststring))) 
                        (yyval.astParameter)->push_back(new ast::Parameter(new ast::Identifier(name), (yyvsp[(3) - (4)].aststring)));
                }
    break;

  case 55:
#line 320 "pascal.y"
    {
                    (yyval.astParameter) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[(1) - (3)].astNameList))) 
                        (yyval.astParameter)->push_back(new ast::Parameter(new ast::Identifier(name), (yyvsp[(3) - (3)].astBasicType)));
                }
    break;

  case 56:
#line 329 "pascal.y"
    {
                    (yyval.astStmtList) = (yyvsp[(1) - (1)].astStmtList);
                }
    break;

  case 57:
#line 333 "pascal.y"
    {
                    (yyval.astStmtList) = (yyvsp[(2) - (3)].astStmtList);
                }
    break;

  case 58:
#line 338 "pascal.y"
    {
                    (yyval.astStmtList) = (yyvsp[(1) - (3)].astStmtList);
                    (yyval.astStmtList).push_back((yyvsp[(2) - (3)].astStmt));
                }
    break;

  case 59:
#line 342 "pascal.y"
    {
                    (yyval.astStmtList) = new ast::StmtList();
                }
    break;

  case 60:
#line 356 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 61:
#line 359 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 62:
#line 362 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmtList);
                }
    break;

  case 63:
#line 365 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 64:
#line 368 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 65:
#line 371 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 66:
#line 374 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 67:
#line 377 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 68:
#line 380 "pascal.y"
    {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[(1) - (1)].astStmt);
                }
    break;

  case 69:
#line 385 "pascal.y"
    {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::Identifier((yyvsp[(1) - (3)].aststring)), (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 70:
#line 388 "pascal.y"
    {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::ArrayElementRef((yyvsp[(1) - (6)].aststring), (yyvsp[(3) - (6)].astExpression)), (yyvsp[(6) - (6)].astExpression));
                }
    break;

  case 71:
#line 391 "pascal.y"
    {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::RecordElementRef((yyvsp[(1) - (5)].aststring), (yyvsp[(3) - (5)].aststring)), (yyvsp[(5) - (5)].astExpression));
                }
    break;

  case 72:
#line 397 "pascal.y"
    {
                    (yyval.astStmt) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[(1) - (1)].aststring)));
                }
    break;

  case 73:
#line 400 "pascal.y"
    {
                    (yyval.astStmt) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[(1) - (4)].aststring), (yyvsp[(3) - (4)].astArgList)));
                }
    break;

  case 74:
#line 403 "pascal.y"
    {
                    (yyval.astStmt) = new ast::SysProcCall(ast::SYS_PROC::(yyvsp[(1) - (1)].aststring));
                }
    break;

  case 75:
#line 406 "pascal.y"
    {
                    (yyval.astStmt) = new ast::SysProcCall(ast::SYS_PROC::(yyvsp[(1) - (4)].aststring), (yyvsp[(3) - (4)].astExpressionList));
                }
    break;

  case 76:
#line 409 "pascal.y"
    {
                    (yyval.astStmt) = new ast::ReadProcCall((yyvsp[(3) - (4)].astExpression));
                }
    break;

  case 77:
#line 413 "pascal.y"
    {
                    (yyval.astStmt) = new ast::IfStmt((yyvsp[(2) - (5)].astExpression), (yyvsp[(4) - (5)].astStmt),(yyvsp[(5) - (5)].astStmt));
                }
    break;

  case 78:
#line 417 "pascal.y"
    {
                    (yyval.astStmt) = (yyvsp[(2) - (2)].astStmt);
                }
    break;

  case 79:
#line 420 "pascal.y"
    {
                    (yyval.astStmt) = NULL;
                }
    break;

  case 80:
#line 425 "pascal.y"
    {
                    (yyval.astStmt) = new ast::RepeatStmt((yyvsp[(4) - (4)].astExpression), (yyvsp[(2) - (4)].astStmtList));
                }
    break;

  case 81:
#line 430 "pascal.y"
    {
                    (yyval.astStmt) = new ast::WhileStmt((yyvsp[(2) - (4)].astExpression), (yyvsp[(4) - (4)].astStmt));
                }
    break;

  case 82:
#line 434 "pascal.y"
    {
                    (yyval.astStmt) = new ast::ForStmt(new ast::Identifier((yyvsp[(2) - (8)].aststring)), (yyvsp[(4) - (8)].astExpression), (yyvsp[(5) - (8)].astDirection), (yyvsp[(6) - (8)].astExpression), (yyvsp[(8) - (8)].astStmt));
                }
    break;

  case 83:
#line 438 "pascal.y"
    {
                    (yyval.astDirection) = ast::Direction::TO;
                }
    break;

  case 84:
#line 441 "pascal.y"
    {
                    (yyval.astDirection) = ast::Direction::DOWNTO;
                }
    break;

  case 85:
#line 446 "pascal.y"
    {
                    (yyval.astStmt) = new ast::CaseStmt((yyvsp[(2) - (5)].astExpression), (yyvsp[(4) - (5)].astCaseExprList));
                }
    break;

  case 86:
#line 451 "pascal.y"
    {
                    (yyval.astCaseExprList) = (yyvsp[(1) - (2)].astCaseExprList);
                    (yyval.astCaseExprList).push_back((yyvsp[(2) - (2)].astCaseExpr));
                }
    break;

  case 87:
#line 455 "pascal.y"
    {
                    (yyval.astCaseExprList) = new ast::CaseExprList();
                    (yyval.astCaseExprList).push_back((yyvsp[(1) - (1)].astCaseExpr));
                }
    break;

  case 88:
#line 461 "pascal.y"
    {
                    (yyval.astCaseExpr) = new ast::CaseExpr((yyvsp[(1) - (4)].astBasicConst), (yyvsp[(3) - (4)].astStmt));
                }
    break;

  case 89:
#line 464 "pascal.y"
    {
                    (yyval.astCaseExpr) = new ast::CaseExpr(new ast::Identifier((yyvsp[(1) - (4)].aststring)), (yyvsp[(3) - (4)].astStmt));
                }
    break;

  case 90:
#line 469 "pascal.y"
    {
                    (yyval.astStmt) = new ast::GoStmt(new ast::IntegerNode((yyvsp[(2) - (2)].aststring)));
                }
    break;

  case 91:
#line 473 "pascal.y"
    {
                    (yyval.astExpressionList) = (yyvsp[(1) - (3)].astExpressionList);
                    (yyval.astExpressionList).push_back((yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 92:
#line 477 "pascal.y"
    {
                    (yyval.astExpressionList) = new ast::ExpressionList();
                    (yyval.astExpressionList).push_back((yyvsp[(1) - (1)].astExpression));
                }
    break;

  case 93:
#line 483 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::GE, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 94:
#line 486 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::GT, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 95:
#line 489 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::LE, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 96:
#line 492 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::LT, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 97:
#line 495 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::EQUAL, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 98:
#line 498 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::UNEQUAL, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 99:
#line 501 "pascal.y"
    {
                    (yyval.astExpression) = (yyvsp[(1) - (1)].astExpression);
                }
    break;

  case 100:
#line 505 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::PLUS, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 101:
#line 508 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::MINUS, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 102:
#line 511 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::OR, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 103:
#line 514 "pascal.y"
    {
                    (yyval.astExpression) = (yyvsp[(1) - (1)].astExpression);
                }
    break;

  case 104:
#line 519 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::MUL, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 105:
#line 522 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::DIV, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 106:
#line 525 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::MOD, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 107:
#line 528 "pascal.y"
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[(1) - (3)].astExpression), ast::BinaryOperator::AND, (yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 108:
#line 531 "pascal.y"
    {
                    (yyval.astExpression) = (yyvsp[(1) - (1)].astExpression);
                }
    break;

  case 109:
#line 536 "pascal.y"
    {
                    (yyval.astExpression) = new ast::Identifier((yyvsp[(1) - (1)].aststring));
                }
    break;

  case 110:
#line 539 "pascal.y"
    {
                    (yyval.astExpression) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[(1) - (4)].aststring)), (yyvsp[(3) - (4)].astArgList));
                }
    break;

  case 111:
#line 542 "pascal.y"
    {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[(1) - (1)].aststring));
                }
    break;

  case 112:
#line 545 "pascal.y"
    {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[(1) - (4)].aststring), (yyvsp[(3) - (4)].astArgList));
                }
    break;

  case 113:
#line 548 "pascal.y"
    {
                    (yyval.astExpression) = (yyvsp[(1) - (1)].astBasicConst);
                }
    break;

  case 114:
#line 551 "pascal.y"
    {
                    (yyval.astExpression) = (yyvsp[(2) - (3)].astExpression);
                }
    break;

  case 115:
#line 554 "pascal.y"
    {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NOT, (yyvsp[(2) - (2)].astExpression));
                }
    break;

  case 116:
#line 557 "pascal.y"
    {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NEG, (yyvsp[(2) - (2)].astExpression));
                }
    break;

  case 117:
#line 560 "pascal.y"
    {
                    (yyval.astExpression) = new ast::ArrayElementRef(new ast::Identifier((yyvsp[(1) - (4)].aststring)), (yyvsp[(3) - (4)].astExpression));
                }
    break;

  case 118:
#line 563 "pascal.y"
    {
                    (yyval.astExpression) = new ast::RecordElementRef(new ast::Identifier((yyvsp[(1) - (3)].aststring)), new ast::Identifier((yyvsp[(3) - (3)].aststring)))
                }
    break;

  case 119:
#line 567 "pascal.y"
    {
                    (yyval.astArgList) = (yyvsp[(1) - (3)].astArgList);
                    (yyval.astArgList).push_back((yyvsp[(3) - (3)].astExpression));
                }
    break;

  case 120:
#line 571 "pascal.y"
    {
                    (yyval.astArgList) = new ast::ArgList();
                    (yyval.astArgList).push_back((yyvsp[(1) - (1)].astExpression));
                }
    break;


/* Line 1267 of yacc.c.  */
#line 2557 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



