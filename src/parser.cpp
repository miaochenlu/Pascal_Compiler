/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:339  */

#include <iostream>
#include <vector>
#include <string>
#include "ast/ast.h"
#include "parser.hpp"

using namespace std;
static ast::BasicAstNode* root;
void yyerror(string msg, ...);
extern int yylex(void);


#line 80 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parser.hpp".  */
#ifndef YY_YY_HOME_LIANJIAYI_DOCUMENTS_CCPROJECT_PASCAL_COMPILER_SRC_PARSER_HPP_INCLUDED
# define YY_YY_HOME_LIANJIAYI_DOCUMENTS_CCPROJECT_PASCAL_COMPILER_SRC_PARSER_HPP_INCLUDED
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
    ID = 258,
    INTEGER = 259,
    REAL = 260,
    CHAR = 261,
    STRING = 262,
    BOOLEAN = 263,
    SYS_PROC = 264,
    SYS_TYPE = 265,
    SYS_FUNCT = 266,
    SYS_CON = 267,
    DOT = 268,
    DOTDOT = 269,
    SEMI = 270,
    COMMA = 271,
    COLON = 272,
    LP = 273,
    RP = 274,
    LB = 275,
    RB = 276,
    EQUAL = 277,
    UNEQUAL = 278,
    GE = 279,
    GT = 280,
    LE = 281,
    LT = 282,
    PLUS = 283,
    MINUS = 284,
    MUL = 285,
    DIV = 286,
    MOD = 287,
    OR = 288,
    AND = 289,
    NOT = 290,
    PROGRAM = 291,
    PROCEDURE = 292,
    FUNCTION = 293,
    CONST = 294,
    TYPE = 295,
    VAR = 296,
    RECORD = 297,
    ARRAY = 298,
    BEG = 299,
    END = 300,
    ASSIGN = 301,
    IF = 302,
    THEN = 303,
    ELSE = 304,
    REPEAT = 305,
    UNTIL = 306,
    WHILE = 307,
    DO = 308,
    FOR = 309,
    TO = 310,
    DOWNTO = 311,
    CASE = 312,
    OF = 313,
    GOTO = 314,
    READ = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:355  */

    char                    astchar;
    char*                   aststring;
    int                     astint;
    double                  astreal;
    bool                    astbool;

    ast::SYSFUNCT           astSYSFUNCT;
    ast::SYSPROC            astSYSPROC;
    ast::TypeKind           astTypeKind;
    ast::Direction          astDirection;

    ast::BasicConst*        astBasicConst;
    ast::BasicType*         astBasicType;
    ast::Identifier*        astIdentifier;
    ast::Expression*        astExpression;
    ast::CaseExpr*          astCaseExpr;
    ast::BasicStmt*         astBasicStmt;

    ast::Program*           astProgram;
    ast::ProgramHead*       astProgramHead;
    ast::Routine*           astRoutine;
    ast::RoutineHead*       astRoutineHead;
    ast::Parameter*         astParameter;
    ast::LabelDecl*         astLabelDecl;
    ast::ConstDecl*         astConstDecl;
    ast::TypeDecl*          astTypeDecl;
    ast::VarDecl*           astVarDecl;

    ast::StmtList*          astStmtList;
    ast::NameList*          astNameList;
    ast::ParamList*         astParamList;
    ast::LabelDeclList*     astLabelDeclList;
    ast::ConstDeclList*     astConstDeclList;
    ast::TypeDeclList*      astTypeDeclList;
    ast::VarDeclList*       astVarDeclList;
    ast::RoutinePartList*   astRoutinePartList;
    ast::ExpressionList*    astExpressionList;
    ast::CaseExprList*      astCaseExprList;
    ast::ArgList*           astArgList;

#line 223 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_LIANJIAYI_DOCUMENTS_CCPROJECT_PASCAL_COMPILER_SRC_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 240 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:358  */

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
# elif ! defined YYSIZE_T
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   427

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   111,   116,   121,   126,   131,   136,   139,
     144,   149,   153,   159,   160,   161,   162,   163,   164,   165,
     166,   169,   170,   175,   179,   185,   190,   191,   192,   195,
     208,   214,   217,   220,   223,   229,   234,   239,   243,   248,
     254,   258,   263,   264,   267,   271,   276,   283,   287,   291,
     294,   298,   302,   307,   312,   315,   319,   323,   329,   334,
     343,   347,   352,   356,   362,   365,   370,   373,   376,   379,
     382,   385,   388,   391,   394,   399,   402,   405,   410,   413,
     416,   422,   428,   432,   435,   447,   452,   456,   460,   463,
     468,   473,   477,   483,   486,   491,   495,   499,   505,   508,
     511,   514,   517,   520,   523,   527,   530,   533,   536,   541,
     544,   547,   550,   553,   558,   561,   564,   567,   570,   573,
     576,   579,   582,   585,   589,   593
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTEGER", "REAL", "CHAR",
  "STRING", "BOOLEAN", "SYS_PROC", "SYS_TYPE", "SYS_FUNCT", "SYS_CON",
  "DOT", "DOTDOT", "SEMI", "COMMA", "COLON", "LP", "RP", "LB", "RB",
  "EQUAL", "UNEQUAL", "GE", "GT", "LE", "LT", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "OR", "AND", "NOT", "PROGRAM", "PROCEDURE", "FUNCTION",
  "CONST", "TYPE", "VAR", "RECORD", "ARRAY", "BEG", "END", "ASSIGN", "IF",
  "THEN", "ELSE", "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO",
  "CASE", "OF", "GOTO", "READ", "$accept", "programPrime", "program",
  "program_head", "routine", "sub_routine", "routine_head", "const_part",
  "NAME", "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "routine_body", "compound_stmt",
  "stmt_list", "stmt", "non_label_stmt", "assign_stmt", "proc_stmt",
  "if_stmt", "repeat_stmt", "while_stmt", "for_stmt", "direction",
  "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", "args_list", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -148

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-148)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,    20,    72,  -148,    -2,    71,  -148,    77,    75,    83,
      89,  -148,  -148,   111,    77,  -148,  -148,  -148,  -148,    77,
      93,   214,   118,    17,   119,    77,  -148,   135,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,    55,   129,   214,    65,   130,
     128,  -148,   264,  -148,   264,   145,   264,   148,   138,   140,
    -148,   146,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,   248,  -148,  -148,    79,   135,  -148,    66,  -148,  -148,
    -148,   147,   161,   264,   264,   133,   264,    -3,   151,   264,
     297,   264,   153,  -148,   338,    18,    67,  -148,   116,   261,
     126,     5,  -148,   264,   264,  -148,  -148,   363,   135,   158,
     165,   170,   173,  -148,  -148,  -148,   162,   248,  -148,   188,
     193,  -148,   183,  -148,   184,  -148,   155,   381,   394,  -148,
       6,   394,   202,   264,   264,   371,  -148,  -148,  -148,  -148,
     264,   264,   264,   264,   264,   264,   264,   150,   264,   264,
     264,   264,   264,   264,   264,   264,   150,   264,   345,   187,
     394,    19,   194,    10,  -148,    92,   330,    77,   214,  -148,
    -148,   196,   195,   195,    -2,    -2,   264,   168,   264,  -148,
    -148,   388,    54,  -148,    74,    18,    18,    18,    18,    18,
      18,   175,    67,    67,    67,  -148,  -148,  -148,  -148,   394,
    -148,   239,   208,   210,    37,  -148,  -148,   264,  -148,   372,
    -148,  -148,   248,   207,  -148,  -148,  -148,    16,  -148,   213,
     216,    83,   217,   394,   264,   394,  -148,  -148,  -148,   150,
    -148,  -148,   264,   150,   150,  -148,  -148,   394,   363,  -148,
     218,   177,   135,   101,    60,  -148,   330,  -148,  -148,  -148,
     394,  -148,   294,   222,   223,  -148,  -148,   248,   115,   330,
      16,  -148,  -148,   150,  -148,  -148,  -148,   330,  -148,  -148,
    -148,  -148
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     9,     0,     1,     0,     0,     0,
      22,     4,    10,     0,     8,     3,    63,     5,    60,     0,
      43,     0,     0,     0,     0,    21,    24,     0,    49,    13,
      15,    17,    18,    19,    20,     0,     0,     0,    10,     0,
      80,    61,     0,    63,     0,     0,     0,     0,     0,    78,
      68,     0,    65,    66,    67,    69,    70,    71,    72,    73,
      74,     0,    23,    41,     0,    42,    45,     7,    14,    16,
      12,     0,     0,     0,     0,     0,     0,    10,   116,     0,
       0,     0,   114,   118,     0,   104,   108,   113,     0,     0,
       0,     0,    95,     0,     0,    62,    29,     0,     0,     0,
      30,     0,     0,    26,    27,    28,     0,     0,    44,     0,
       0,    47,     0,    48,     0,    11,     0,     0,    75,    64,
       0,    97,     0,     0,     0,     0,    13,    15,   121,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,    38,     0,     0,     0,     0,    25,
      40,     0,    55,    55,     9,     9,     0,     0,     0,    81,
     123,     0,     0,   119,     0,   102,   103,    98,    99,   100,
     101,    84,   105,   106,   107,   109,   110,   111,   112,    85,
      86,     0,     0,     0,     0,    92,    82,     0,    79,     0,
      36,    37,     0,     0,    34,    31,    46,     0,    53,     0,
       0,     0,     0,    77,     0,    96,   122,   117,   115,     0,
      88,    89,     0,     0,     0,    90,    91,   124,     0,    32,
       0,     0,     0,     0,     0,    57,     0,    50,     6,    52,
      76,    83,     0,     0,     0,    33,    39,     0,     0,     0,
       0,    54,    51,     0,    94,    93,    35,     0,    59,    56,
      87,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,    76,   235,  -148,    -7,  -148,
     -13,  -148,  -148,   220,   -96,  -147,  -148,  -148,  -148,    94,
     -95,  -148,  -148,   192,  -148,  -148,  -148,  -148,  -148,    85,
    -148,    -1,    48,    -8,   230,  -132,   199,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,    84,  -148,  -148,   -40,
     291,   -16,   -28,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,   210,   211,    10,    82,    14,
      83,    20,    25,    26,   102,   103,   104,   105,   153,   154,
      64,    28,    65,    66,    67,   111,   112,   113,   114,   208,
     234,   235,    17,    50,    23,    51,    52,    53,    54,    55,
      56,    57,    58,   222,    59,   194,   195,    60,   120,   150,
      85,    86,    87,   151
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      13,    18,    84,   155,    89,   181,    91,    22,    36,   203,
     122,   161,    24,    63,   190,     1,    49,   123,    24,    63,
      38,    39,   168,     5,    71,   169,    40,   131,   132,   133,
     134,   135,   136,   117,   118,   197,   121,     7,   198,   125,
     192,    29,    30,    31,    32,    33,   138,   139,   101,    34,
     172,   140,   128,   129,   100,   200,   174,   232,   155,    68,
      69,    16,    41,   148,    42,   149,    35,    43,    49,    44,
     197,    45,     6,   217,    46,   250,    47,    48,    72,   251,
      12,    49,   225,   171,   152,    73,    11,   241,    15,   252,
     197,   243,   244,   218,   101,   106,   107,   141,   142,   143,
     100,   144,   258,   109,   110,   189,   230,   191,   106,   202,
     261,    74,   233,   185,   186,   187,   188,   106,   249,    38,
      39,   260,   182,   183,   184,    40,   213,    16,   215,    19,
      49,   106,   257,    21,    27,   193,    38,   248,    63,    49,
      37,    61,    40,   101,    70,   205,    76,    75,    90,   100,
     204,   256,    92,    38,    39,   233,    93,   227,    94,    40,
      16,    95,   115,    42,   116,   160,    43,   145,    44,   124,
      45,   130,   147,    46,   240,    47,    48,    16,   156,   157,
      42,   193,   242,    43,   158,    44,   229,    45,   159,   101,
      46,   162,    47,    48,    16,   100,   163,    42,   164,   165,
      43,   166,    44,    18,    45,   170,   196,    46,   199,    47,
      48,   206,    49,   207,   214,   245,    49,    49,    29,    30,
      31,    32,    33,   101,   219,   223,    34,   224,   231,   100,
     236,   237,   239,   246,   101,   247,   101,   254,   255,     9,
     100,   212,   100,    35,   101,    62,    49,   201,   209,   259,
     100,    12,    29,    30,    31,    32,    33,   108,    96,   238,
      34,   131,   132,   133,   134,   135,   136,    77,    29,    30,
      31,    32,    33,    88,   119,    78,    34,    97,   226,     0,
       0,     0,    79,   131,   132,   133,   134,   135,   136,     0,
      98,    99,     0,    80,   220,   221,     0,     0,     0,    81,
      77,   126,   127,    31,    32,    33,     0,     0,    78,    34,
       0,     0,     0,     0,   146,    79,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,    81,    12,    29,    30,    31,    32,    33,     0,
      96,     0,    34,     0,     0,     0,     0,   253,   192,    29,
      30,    31,    32,    33,     0,     0,     0,    34,     0,    97,
     131,   132,   133,   134,   135,   136,     0,   126,   127,    31,
      32,    33,     0,     0,    35,    34,    29,    30,    31,    32,
      33,     0,     0,     0,    34,     0,   137,     0,     0,     0,
     173,     0,    35,   131,   132,   133,   134,   135,   136,     0,
       0,   228,   167,   131,   132,   133,   134,   135,   136,   216,
     131,   132,   133,   134,   135,   136,   131,   132,   133,   134,
     135,   136,   175,   176,   177,   178,   179,   180
};

static const yytype_int16 yycheck[] =
{
       7,     9,    42,    98,    44,   137,    46,    14,    21,   156,
      13,   107,    19,     3,   146,    36,    23,    20,    25,     3,
       3,     4,    16,     3,    37,    19,     9,    22,    23,    24,
      25,    26,    27,    73,    74,    16,    76,    39,    19,    79,
       3,     4,     5,     6,     7,     8,    28,    29,    61,    12,
     124,    33,    80,    81,    61,    45,   130,    41,   153,     4,
       5,    44,    45,    58,    47,    93,    29,    50,    75,    52,
      16,    54,     0,    19,    57,    15,    59,    60,    13,    19,
       3,    88,    45,   123,    97,    20,    15,   219,    13,   236,
      16,   223,   224,    19,   107,    16,    17,    30,    31,    32,
     107,    34,   249,    37,    38,   145,   202,   147,    16,    17,
     257,    46,   207,   141,   142,   143,   144,    16,    17,     3,
       4,   253,   138,   139,   140,     9,   166,    44,   168,    40,
     137,    16,    17,    22,    41,   148,     3,   232,     3,   146,
      22,    22,     9,   156,    15,   158,    18,    17,     3,   156,
     157,   247,     4,     3,     4,   250,    18,   197,    18,     9,
      44,    15,    15,    47,     3,     3,    50,    51,    52,    18,
      54,    18,    46,    57,   214,    59,    60,    44,    20,    14,
      47,   194,   222,    50,    14,    52,   199,    54,    15,   202,
      57,     3,    59,    60,    44,   202,     3,    47,    15,    15,
      50,    46,    52,   211,    54,     3,    19,    57,    14,    59,
      60,    15,   219,    18,    46,   228,   223,   224,     4,     5,
       6,     7,     8,   236,    49,    17,    12,    17,    21,   236,
      17,    15,    15,    15,   247,    58,   249,    15,    15,     4,
     247,   165,   249,    29,   257,    25,   253,   153,   163,   250,
     257,     3,     4,     5,     6,     7,     8,    65,    10,   211,
      12,    22,    23,    24,    25,    26,    27,     3,     4,     5,
       6,     7,     8,    43,    75,    11,    12,    29,   194,    -1,
      -1,    -1,    18,    22,    23,    24,    25,    26,    27,    -1,
      42,    43,    -1,    29,    55,    56,    -1,    -1,    -1,    35,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    -1,    -1,    53,    18,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,    -1,    -1,    -1,    -1,    53,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    -1,    29,
      22,    23,    24,    25,    26,    27,    -1,     4,     5,     6,
       7,     8,    -1,    -1,    29,    12,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    48,    -1,    -1,    -1,
      19,    -1,    29,    22,    23,    24,    25,    26,    27,    -1,
      -1,    29,    21,    22,    23,    24,    25,    26,    27,    21,
      22,    23,    24,    25,    26,    27,    22,    23,    24,    25,
      26,    27,   131,   132,   133,   134,   135,   136
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    62,    63,    64,     3,     0,    39,    65,    67,
      68,    15,     3,    69,    70,    13,    44,    93,    94,    40,
      72,    22,    69,    95,    69,    73,    74,    41,    82,     4,
       5,     6,     7,     8,    12,    29,    71,    22,     3,     4,
       9,    45,    47,    50,    52,    54,    57,    59,    60,    69,
      94,    96,    97,    98,    99,   100,   101,   102,   103,   105,
     108,    22,    74,     3,    81,    83,    84,    85,     4,     5,
      15,    71,    13,    20,    46,    17,    18,     3,    11,    18,
      29,    35,    69,    71,   110,   111,   112,   113,    95,   110,
       3,   110,     4,    18,    18,    15,    10,    29,    42,    43,
      69,    71,    75,    76,    77,    78,    16,    17,    84,    37,
      38,    86,    87,    88,    89,    15,     3,   110,   110,    97,
     109,   110,    13,    20,    18,   110,     4,     5,   113,   113,
      18,    22,    23,    24,    25,    26,    27,    48,    28,    29,
      33,    30,    31,    32,    34,    51,    53,    46,    58,   113,
     110,   114,    71,    79,    80,    81,    20,    14,    14,    15,
       3,    75,     3,     3,    15,    15,    46,    21,    16,    19,
       3,   110,   114,    19,   114,   111,   111,   111,   111,   111,
     111,    96,   112,   112,   112,   113,   113,   113,   113,   110,
      96,   110,     3,    71,   106,   107,    19,    16,    19,    14,
      45,    80,    17,    76,    69,    71,    15,    18,    90,    90,
      66,    67,    66,   110,    46,   110,    21,    19,    19,    49,
      55,    56,   104,    17,    17,    45,   107,   110,    29,    71,
      75,    21,    41,    81,    91,    92,    17,    15,    93,    15,
     110,    96,   110,    96,    96,    71,    15,    58,    81,    17,
      15,    19,    76,    53,    15,    15,    75,    17,    76,    92,
      96,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    66,    67,    68,    68,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    74,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    78,    79,    79,    80,
      81,    81,    82,    82,    83,    83,    84,    85,    85,    85,
      86,    87,    88,    89,    90,    90,    91,    91,    92,    92,
      93,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   100,   101,   102,   103,   104,   104,
     105,   106,   106,   107,   107,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     4,     2,     0,
       1,     5,     4,     1,     2,     1,     2,     1,     1,     1,
       1,     2,     0,     2,     1,     4,     1,     1,     1,     1,
       1,     3,     4,     5,     3,     6,     3,     2,     1,     4,
       3,     1,     2,     0,     2,     1,     4,     2,     2,     0,
       4,     5,     4,     3,     3,     0,     3,     1,     4,     3,
       1,     3,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     1,     4,
       1,     4,     4,     6,     4,     4,     4,     8,     1,     1,
       5,     2,     1,     4,     4,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     4,     1,     4,     1,     3,
       2,     2,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
| yyreduce -- Do a reduction.  |
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
#line 108 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    root = (yyvsp[0].astProgram);
                }
#line 1544 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astProgram) = new ast::Program((yyvsp[-2].astProgramHead), (yyvsp[-1].astRoutine)); 
                }
#line 1552 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 116 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), new ast::ParamList(), new ast::VoidType()); 
                }
#line 1560 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1568 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 126 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1576 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 131 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astRoutineHead) = new ast::RoutineHead((yyvsp[-3].astConstDeclList), (yyvsp[-2].astTypeDeclList), (yyvsp[-1].astVarDeclList), (yyvsp[0].astRoutinePartList)); 
                }
#line 1584 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astConstDeclList) = (yyvsp[0].astConstDeclList); 
                }
#line 1592 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 139 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                }
#line 1600 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    new ast::Name((yyvsp[0].aststring)); 
                }
#line 1608 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astConstDeclList) = (yyvsp[-4].astConstDeclList);
                    (yyvsp[-4].astConstDeclList)->push_back(new ast::ConstDecl(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1617 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 153 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                    (yyval.astConstDeclList)->push_back(new ast::ConstDecl(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1626 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 159 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::IntegerNode((yyvsp[0].astint));}
#line 1632 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 160 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::IntegerNode(-(yyvsp[0].astint));}
#line 1638 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 161 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::RealNode((yyvsp[0].astreal));}
#line 1644 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 162 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::RealNode(-(yyvsp[0].astreal));}
#line 1650 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::CharNode((yyvsp[0].astchar));}
#line 1656 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::StringNode((yyvsp[0].aststring));}
#line 1662 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 165 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::BooleanNode((yyvsp[0].astbool));}
#line 1668 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {(yyval.astBasicConst) = new ast::MaxIntNode();}
#line 1674 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { (yyval.astTypeDeclList) = (yyvsp[0].astTypeDeclList); }
#line 1680 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 170 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astTypeDeclList) = new ast::TypeDeclList(); 
                }
#line 1688 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astTypeDeclList) = (yyvsp[-1].astTypeDeclList);
                    (yyvsp[-1].astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1697 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 179 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astTypeDeclList) = new ast::TypeDeclList();
                    (yyval.astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1706 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 185 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astTypeDecl) = new ast::TypeDecl(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astBasicType)); 
                }
#line 1714 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 190 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1720 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1726 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 192 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1732 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 195 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    if((yyvsp[0].astTypeKind) == ast::TypeKind::INTtype) {
                        (yyval.astBasicType) = new ast::IntegerType();
                    } else if((yyvsp[0].astTypeKind) == ast::TypeKind::REALtype) {
                        (yyval.astBasicType) = new ast::RealType();
                    } else if((yyvsp[0].astTypeKind) == ast::TypeKind::CHARtype) {
                        (yyval.astBasicType) = new ast::CharType();
                    } else if((yyvsp[0].astTypeKind) == ast::TypeKind::BOOLEANtype) {
                        (yyval.astBasicType) = new ast::BooleanType();
                    } else if((yyvsp[0].astTypeKind) == ast::TypeKind::STRINGtype) {
                        (yyval.astBasicType) = new ast::StringType();
                    }
                }
#line 1750 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 208 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicType) = new ast::UserDefType(new ast::Name((yyvsp[0].aststring)));
                }
#line 1758 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 214 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astBasicType) = new ast::RangeType((yyvsp[-2].astBasicConst), (yyvsp[0].astBasicConst)); 
                }
#line 1766 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 217 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-2].astBasicConst)), (yyvsp[0].astBasicConst)); 
                }
#line 1774 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 220 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-3].astBasicConst)), new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astBasicConst))); 
                }
#line 1782 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 223 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicType) = new ast::RangeType(new ast::Name((yyvsp[-2].aststring)), new ast::Name((yyvsp[0].aststring)));
                }
#line 1790 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 229 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astBasicType) = new ast::ArrayType((yyvsp[-3].astBasicType), (yyvsp[0].astBasicType)); 
                }
#line 1798 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 234 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astBasicType) = new ast::RecordType((yyvsp[-1].astVarDeclList)); 
                }
#line 1806 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 239 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());
                }
#line 1815 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 243 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 1823 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 248 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 1833 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 254 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astNameList) = (yyvsp[-2].astNameList);
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1842 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 258 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astNameList) = new ast::NameList();
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1851 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 263 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList); }
#line 1857 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 264 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { (yyval.astVarDeclList) = new ast::VarDeclList(); }
#line 1863 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());
                }
#line 1872 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 271 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 1880 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 276 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 1890 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 283 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 1899 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 287 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 1908 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 291 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    { (yyval.astRoutinePartList) = new ast::RoutinePartList(); }
#line 1914 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 294 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 1922 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 298 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-2].astParamList), (yyvsp[0].astBasicType));
                }
#line 1930 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 302 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 1938 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 307 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), (yyvsp[0].astParamList), new ast::VoidType()); 
                }
#line 1946 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 312 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astParamList) = (yyvsp[-1].astParamList);
                }
#line 1954 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 315 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astParamList) = new ast::ParamList();
                }
#line 1962 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 319 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astParamList) = (yyvsp[-2].astParamList);
                    (yyvsp[-2].astParamList)->insert((yyvsp[-2].astParamList)->end(), (yyvsp[0].astParamList)->begin(), (yyvsp[0].astParamList)->end());
                }
#line 1971 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 323 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astParamList) = (yyvsp[0].astParamList);
                }
#line 1979 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 329 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 1989 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 334 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 1999 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 343 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astStmtList) = (yyvsp[0].astStmtList);
                }
#line 2007 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 347 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astStmtList) = (yyvsp[-1].astStmtList);
                }
#line 2015 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 352 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astStmtList) = (yyvsp[-2].astStmtList);
                    (yyval.astStmtList)->stmtPushBack((yyvsp[-1].astBasicStmt));
                }
#line 2024 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 356 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astStmtList) = new ast::StmtList();
                }
#line 2032 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 362 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::LabelStmt((yyvsp[-2].astint), (yyvsp[0].astBasicStmt));
                }
#line 2040 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 365 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (yyvsp[0].astBasicStmt);
                }
#line 2048 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 370 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2056 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 373 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2064 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 376 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (yyvsp[0].astStmtList);
                }
#line 2072 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 379 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2080 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 382 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2088 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 385 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2096 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 388 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2104 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 391 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2112 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 394 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2120 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 399 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::AssignStmt(new ast::Identifier((yyvsp[-2].aststring)), (yyvsp[0].astExpression));
                }
#line 2128 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 402 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::AssignStmt(new ast::ArrayElementRef(new ast::Identifier((yyvsp[-5].aststring)), (yyvsp[-3].astExpression)), (yyvsp[0].astExpression));
                }
#line 2136 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 405 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::AssignStmt(new ast::RecordElementRef(new ast::Identifier((yyvsp[-4].aststring)), new ast::Identifier((yyvsp[-2].aststring))), (yyvsp[0].astExpression));
                }
#line 2144 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 410 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::UserDefProcCall(new ast::Name((yyvsp[0].aststring)));
                }
#line 2152 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 413 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::UserDefProcCall(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2160 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 416 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE);
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN);
                }
#line 2171 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 422 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE, (yyvsp[-1].astExpressionList));
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN, (yyvsp[-1].astExpressionList));
                }
#line 2182 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 428 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::ReadProcCall((yyvsp[-1].astExpression));
                }
#line 2190 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 432 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::IfStmt((yyvsp[-4].astExpression), (yyvsp[-2].astBasicStmt), (yyvsp[0].astBasicStmt));
                }
#line 2198 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 435 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::IfStmt((yyvsp[-2].astExpression), (yyvsp[0].astBasicStmt));
                }
#line 2206 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 447 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::RepeatStmt((yyvsp[0].astExpression), (yyvsp[-2].astStmtList));
                }
#line 2214 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 452 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::WhileStmt((yyvsp[-2].astExpression), (yyvsp[0].astBasicStmt));
                }
#line 2222 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 456 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::ForStmt(new ast::Identifier((yyvsp[-6].aststring)), (yyvsp[-4].astExpression), (yyvsp[-3].astDirection), (yyvsp[-2].astExpression), (yyvsp[0].astBasicStmt));
                }
#line 2230 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 460 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astDirection) = ast::Direction::To;
                }
#line 2238 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 463 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astDirection) = ast::Direction::DownTo;
                }
#line 2246 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 468 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::CaseStmt((yyvsp[-3].astExpression), (yyvsp[-1].astCaseExprList));
                }
#line 2254 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 473 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astCaseExprList) = (yyvsp[-1].astCaseExprList);
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2263 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 477 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astCaseExprList) = new ast::CaseExprList();
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2272 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 483 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astCaseExpr) = new ast::CaseExpr((yyvsp[-3].astBasicConst), (yyvsp[-1].astBasicStmt));
                }
#line 2280 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 486 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astCaseExpr) = new ast::CaseExpr(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicStmt));
                }
#line 2288 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 491 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astBasicStmt) = new ast::GotoStmt((yyvsp[0].astint));
                }
#line 2296 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 495 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpressionList) = (yyvsp[-2].astExpressionList);
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2305 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 499 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpressionList) = new ast::ExpressionList();
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2314 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 505 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GEop, (yyvsp[0].astExpression));
                }
#line 2322 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 508 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GTop, (yyvsp[0].astExpression));
                }
#line 2330 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 511 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LEop, (yyvsp[0].astExpression));
                }
#line 2338 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 514 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LTop, (yyvsp[0].astExpression));
                }
#line 2346 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 517 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::EQUALop, (yyvsp[0].astExpression));
                }
#line 2354 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 520 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::UNEQUALop, (yyvsp[0].astExpression));
                }
#line 2362 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 523 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2370 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 527 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::PLUSop, (yyvsp[0].astExpression));
                }
#line 2378 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 530 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MINUSop, (yyvsp[0].astExpression));
                }
#line 2386 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 533 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ORop, (yyvsp[0].astExpression));
                }
#line 2394 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 536 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2402 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 541 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MULop, (yyvsp[0].astExpression));
                }
#line 2410 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 544 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::DIVop, (yyvsp[0].astExpression));
                }
#line 2418 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 547 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MODop, (yyvsp[0].astExpression));
                }
#line 2426 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 550 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ANDop, (yyvsp[0].astExpression));
                }
#line 2434 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 553 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2442 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 558 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::Name((yyvsp[0].aststring));
                }
#line 2450 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 561 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::UserDefProcCall(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2458 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 564 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[0].astSYSFUNCT));
                }
#line 2466 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 567 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[-3].astSYSFUNCT), (yyvsp[-1].astArgList));
                }
#line 2474 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 570 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = (yyvsp[0].astBasicConst);
                }
#line 2482 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 573 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = (yyvsp[-1].astExpression);
                }
#line 2490 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 576 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NOTop, (yyvsp[0].astExpression));
                }
#line 2498 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 579 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astExpression));
                }
#line 2506 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 582 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::ArrayElementRef(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astExpression));
                }
#line 2514 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 585 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astExpression) = new ast::RecordElementRef(new ast::Identifier((yyvsp[-2].aststring)), new ast::Identifier((yyvsp[0].aststring)));
                }
#line 2522 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 589 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astArgList) = (yyvsp[-2].astArgList);
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2531 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 593 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1646  */
    {
                    (yyval.astArgList) = new ast::ArgList();
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2540 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
    break;


#line 2544 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/parser.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 599 "/home/lianjiayi/Documents/ccproject/Pascal_Compiler/src/pascal.y" /* yacc.c:1906  */



void yyerror(string msg, ...) {
    cout << msg << endl;
}


ast::BasicAstNode* parse(void)
{ 
    yyparse();
    return root;
}
