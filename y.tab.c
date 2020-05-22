/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "pascal.y"

#include <iostream>
#include <vector>
#include <string>
#include "global.h"
using namespace std;

ast::BasicAstNode* root;

#line 81 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    DOT = 259,                     /* DOT  */
    DOTDOT = 260,                  /* DOTDOT  */
    SEMI = 261,                    /* SEMI  */
    COMMA = 262,                   /* COMMA  */
    COLON = 263,                   /* COLON  */
    LP = 264,                      /* LP  */
    RP = 265,                      /* RP  */
    LB = 266,                      /* LB  */
    RB = 267,                      /* RB  */
    EQUAL = 268,                   /* EQUAL  */
    UNEQUAL = 269,                 /* UNEQUAL  */
    GE = 270,                      /* GE  */
    GT = 271,                      /* GT  */
    LE = 272,                      /* LE  */
    LT = 273,                      /* LT  */
    PLUS = 274,                    /* PLUS  */
    MINUS = 275,                   /* MINUS  */
    MUL = 276,                     /* MUL  */
    DIV = 277,                     /* DIV  */
    MOD = 278,                     /* MOD  */
    OR = 279,                      /* OR  */
    AND = 280,                     /* AND  */
    NOT = 281,                     /* NOT  */
    INTEGER = 282,                 /* INTEGER  */
    REAL = 283,                    /* REAL  */
    CHAR = 284,                    /* CHAR  */
    STRING = 285,                  /* STRING  */
    BOOLEAN = 286,                 /* BOOLEAN  */
    ARRAY = 287,                   /* ARRAY  */
    PROGRAM = 288,                 /* PROGRAM  */
    PROCEDURE = 289,               /* PROCEDURE  */
    FUNCTION = 290,                /* FUNCTION  */
    CONST = 291,                   /* CONST  */
    TYPE = 292,                    /* TYPE  */
    VAR = 293,                     /* VAR  */
    RECORD = 294,                  /* RECORD  */
    BEG = 295,                     /* BEG  */
    END = 296,                     /* END  */
    ASSIGN = 297,                  /* ASSIGN  */
    IF = 298,                      /* IF  */
    THEN = 299,                    /* THEN  */
    ELSE = 300,                    /* ELSE  */
    REPEAT = 301,                  /* REPEAT  */
    UNTIL = 302,                   /* UNTIL  */
    WHILE = 303,                   /* WHILE  */
    DO = 304,                      /* DO  */
    FOR = 305,                     /* FOR  */
    TO = 306,                      /* TO  */
    DOWNTO = 307,                  /* DOWNTO  */
    CASE = 308,                    /* CASE  */
    OF = 309,                      /* OF  */
    GOTO = 310,                    /* GOTO  */
    READ = 311,                    /* READ  */
    SYS_CON = 312,                 /* SYS_CON  */
    SYS_PROC = 313,                /* SYS_PROC  */
    SYS_TYPE = 314,                /* SYS_TYPE  */
    SYS_FUNCT = 315                /* SYS_FUNCT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define BOOLEAN 286
#define ARRAY 287
#define PROGRAM 288
#define PROCEDURE 289
#define FUNCTION 290
#define CONST 291
#define TYPE 292
#define VAR 293
#define RECORD 294
#define BEG 295
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "pascal.y"

    char*                  aststring;
    char                    astchar;
    int                     astint;
    double                  astreal;
    bool                    astbool;
    ast::SYSFUNCT           astSYSFUNCT;
    ast::SYSPROC            astSYSPROC;
    ast::TypeKind           astTypeKind;
    ast::Identifier*        astIdentifier;
    ast::NameList*          astNameList;
    ast::Expression*        astExpression;
    ast::Stmt*              astStmt;
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

#line 291 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_DOT = 4,                        /* DOT  */
  YYSYMBOL_DOTDOT = 5,                     /* DOTDOT  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_COLON = 8,                      /* COLON  */
  YYSYMBOL_LP = 9,                         /* LP  */
  YYSYMBOL_RP = 10,                        /* RP  */
  YYSYMBOL_LB = 11,                        /* LB  */
  YYSYMBOL_RB = 12,                        /* RB  */
  YYSYMBOL_EQUAL = 13,                     /* EQUAL  */
  YYSYMBOL_UNEQUAL = 14,                   /* UNEQUAL  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_PLUS = 19,                      /* PLUS  */
  YYSYMBOL_MINUS = 20,                     /* MINUS  */
  YYSYMBOL_MUL = 21,                       /* MUL  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_MOD = 23,                       /* MOD  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_REAL = 28,                      /* REAL  */
  YYSYMBOL_CHAR = 29,                      /* CHAR  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_BOOLEAN = 31,                   /* BOOLEAN  */
  YYSYMBOL_ARRAY = 32,                     /* ARRAY  */
  YYSYMBOL_PROGRAM = 33,                   /* PROGRAM  */
  YYSYMBOL_PROCEDURE = 34,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 35,                  /* FUNCTION  */
  YYSYMBOL_CONST = 36,                     /* CONST  */
  YYSYMBOL_TYPE = 37,                      /* TYPE  */
  YYSYMBOL_VAR = 38,                       /* VAR  */
  YYSYMBOL_RECORD = 39,                    /* RECORD  */
  YYSYMBOL_BEG = 40,                       /* BEG  */
  YYSYMBOL_END = 41,                       /* END  */
  YYSYMBOL_ASSIGN = 42,                    /* ASSIGN  */
  YYSYMBOL_IF = 43,                        /* IF  */
  YYSYMBOL_THEN = 44,                      /* THEN  */
  YYSYMBOL_ELSE = 45,                      /* ELSE  */
  YYSYMBOL_REPEAT = 46,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 47,                     /* UNTIL  */
  YYSYMBOL_WHILE = 48,                     /* WHILE  */
  YYSYMBOL_DO = 49,                        /* DO  */
  YYSYMBOL_FOR = 50,                       /* FOR  */
  YYSYMBOL_TO = 51,                        /* TO  */
  YYSYMBOL_DOWNTO = 52,                    /* DOWNTO  */
  YYSYMBOL_CASE = 53,                      /* CASE  */
  YYSYMBOL_OF = 54,                        /* OF  */
  YYSYMBOL_GOTO = 55,                      /* GOTO  */
  YYSYMBOL_READ = 56,                      /* READ  */
  YYSYMBOL_SYS_CON = 57,                   /* SYS_CON  */
  YYSYMBOL_SYS_PROC = 58,                  /* SYS_PROC  */
  YYSYMBOL_SYS_TYPE = 59,                  /* SYS_TYPE  */
  YYSYMBOL_SYS_FUNCT = 60,                 /* SYS_FUNCT  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_programPrime = 62,              /* programPrime  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_program_head = 64,              /* program_head  */
  YYSYMBOL_routine = 65,                   /* routine  */
  YYSYMBOL_sub_routine = 66,               /* sub_routine  */
  YYSYMBOL_routine_head = 67,              /* routine_head  */
  YYSYMBOL_const_part = 68,                /* const_part  */
  YYSYMBOL_const_expr_list = 69,           /* const_expr_list  */
  YYSYMBOL_const_value = 70,               /* const_value  */
  YYSYMBOL_type_part = 71,                 /* type_part  */
  YYSYMBOL_type_decl_list = 72,            /* type_decl_list  */
  YYSYMBOL_type_definition = 73,           /* type_definition  */
  YYSYMBOL_type_decl = 74,                 /* type_decl  */
  YYSYMBOL_simple_type_decl = 75,          /* simple_type_decl  */
  YYSYMBOL_array_type_decl = 76,           /* array_type_decl  */
  YYSYMBOL_record_type_decl = 77,          /* record_type_decl  */
  YYSYMBOL_field_decl_list = 78,           /* field_decl_list  */
  YYSYMBOL_field_decl = 79,                /* field_decl  */
  YYSYMBOL_name_list = 80,                 /* name_list  */
  YYSYMBOL_var_part = 81,                  /* var_part  */
  YYSYMBOL_var_decl_list = 82,             /* var_decl_list  */
  YYSYMBOL_var_decl = 83,                  /* var_decl  */
  YYSYMBOL_routine_part = 84,              /* routine_part  */
  YYSYMBOL_function_decl = 85,             /* function_decl  */
  YYSYMBOL_function_head = 86,             /* function_head  */
  YYSYMBOL_procedure_decl = 87,            /* procedure_decl  */
  YYSYMBOL_procedure_head = 88,            /* procedure_head  */
  YYSYMBOL_parameters = 89,                /* parameters  */
  YYSYMBOL_para_decl_list = 90,            /* para_decl_list  */
  YYSYMBOL_para_type_list = 91,            /* para_type_list  */
  YYSYMBOL_routine_body = 92,              /* routine_body  */
  YYSYMBOL_compound_stmt = 93,             /* compound_stmt  */
  YYSYMBOL_stmt_list = 94,                 /* stmt_list  */
  YYSYMBOL_stmt = 95,                      /* stmt  */
  YYSYMBOL_assign_stmt = 96,               /* assign_stmt  */
  YYSYMBOL_proc_stmt = 97,                 /* proc_stmt  */
  YYSYMBOL_if_stmt = 98,                   /* if_stmt  */
  YYSYMBOL_repeat_stmt = 99,               /* repeat_stmt  */
  YYSYMBOL_while_stmt = 100,               /* while_stmt  */
  YYSYMBOL_for_stmt = 101,                 /* for_stmt  */
  YYSYMBOL_direction = 102,                /* direction  */
  YYSYMBOL_case_stmt = 103,                /* case_stmt  */
  YYSYMBOL_case_expr_list = 104,           /* case_expr_list  */
  YYSYMBOL_case_expr = 105,                /* case_expr  */
  YYSYMBOL_goto_stmt = 106,                /* goto_stmt  */
  YYSYMBOL_expression_list = 107,          /* expression_list  */
  YYSYMBOL_expression = 108,               /* expression  */
  YYSYMBOL_expr = 109,                     /* expr  */
  YYSYMBOL_term = 110,                     /* term  */
  YYSYMBOL_factor = 111,                   /* factor  */
  YYSYMBOL_args_list = 112                 /* args_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   105,   110,   115,   120,   125,   130,   133,
     138,   142,   148,   149,   150,   151,   152,   153,   156,   157,
     162,   166,   172,   177,   178,   179,   182,   201,   204,   207,
     210,   216,   221,   226,   230,   235,   241,   245,   250,   251,
     254,   258,   263,   270,   274,   278,   281,   285,   289,   294,
     299,   302,   306,   310,   316,   321,   330,   334,   339,   343,
     357,   360,   363,   366,   369,   372,   375,   378,   381,   386,
     389,   392,   398,   401,   404,   410,   416,   420,   423,   435,
     440,   444,   448,   451,   456,   461,   465,   471,   474,   479,
     483,   487,   493,   496,   499,   502,   505,   508,   511,   515,
     518,   521,   524,   529,   532,   535,   538,   541,   546,   549,
     552,   555,   558,   561,   564,   567,   570,   573,   577,   581
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "DOT", "DOTDOT",
  "SEMI", "COMMA", "COLON", "LP", "RP", "LB", "RB", "EQUAL", "UNEQUAL",
  "GE", "GT", "LE", "LT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "OR",
  "AND", "NOT", "INTEGER", "REAL", "CHAR", "STRING", "BOOLEAN", "ARRAY",
  "PROGRAM", "PROCEDURE", "FUNCTION", "CONST", "TYPE", "VAR", "RECORD",
  "BEG", "END", "ASSIGN", "IF", "THEN", "ELSE", "REPEAT", "UNTIL", "WHILE",
  "DO", "FOR", "TO", "DOWNTO", "CASE", "OF", "GOTO", "READ", "SYS_CON",
  "SYS_PROC", "SYS_TYPE", "SYS_FUNCT", "$accept", "programPrime",
  "program", "program_head", "routine", "sub_routine", "routine_head",
  "const_part", "const_expr_list", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "simple_type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "name_list", "var_part", "var_decl_list", "var_decl", "routine_part",
  "function_decl", "function_head", "procedure_decl", "procedure_head",
  "parameters", "para_decl_list", "para_type_list", "routine_body",
  "compound_stmt", "stmt_list", "stmt", "assign_stmt", "proc_stmt",
  "if_stmt", "repeat_stmt", "while_stmt", "for_stmt", "direction",
  "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", "args_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    51,    67,  -136,    33,    84,  -136,    98,   108,    66,
      86,  -136,   111,   122,  -136,  -136,  -136,  -136,   124,    93,
      90,   117,   102,   119,   124,  -136,   131,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,   129,    90,    49,  -136,    19,  -136,
      19,   133,    19,   110,   132,   135,  -136,   140,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,    54,  -136,  -136,    30,
     131,  -136,    27,  -136,   143,   150,    19,    19,    19,    15,
      19,    19,    19,   161,  -136,   314,     1,    50,  -136,   173,
     302,   141,    16,  -136,    19,    19,  -136,   166,    90,   127,
     131,  -136,   170,   185,  -136,  -136,  -136,   191,    54,  -136,
     194,   195,  -136,   196,  -136,   199,  -136,   159,   360,    45,
     347,   360,   197,    19,    19,   323,  -136,  -136,    19,    19,
      19,    19,    19,    19,    19,  -136,    19,    19,    19,    19,
      19,    19,    19,    19,  -136,    19,   151,   201,    70,   360,
     203,   207,   136,    10,  -136,    92,    90,  -136,  -136,   212,
     200,   200,    33,    33,    19,    19,  -136,   180,  -136,    85,
     354,  -136,    87,     1,     1,     1,     1,     1,     1,   187,
      50,    50,    50,  -136,  -136,  -136,  -136,   360,   250,   296,
     216,   226,   158,  -136,  -136,    19,  -136,  -136,   238,   229,
    -136,  -136,    54,  -136,  -136,     5,  -136,   230,   240,    66,
     242,   360,   360,    19,  -136,  -136,  -136,  -136,  -136,  -136,
      19,  -136,  -136,  -136,  -136,   360,    90,  -136,   202,   243,
     131,    96,    17,  -136,   136,  -136,  -136,  -136,   360,   250,
     308,   204,   233,  -136,    54,  -136,   107,   136,     5,  -136,
    -136,  -136,  -136,  -136,  -136,   136,  -136,  -136,   250,  -136
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     9,     0,     1,     0,     0,     0,
      19,     4,     0,     8,     3,    59,     5,    56,     0,    39,
       0,     0,     0,     0,    18,    21,     0,    45,    12,    13,
      14,    15,    16,    17,     0,     0,    72,    57,     0,    59,
       0,     0,     0,     0,     0,    74,    62,     0,    60,    61,
      63,    64,    65,    66,    67,    68,     0,    20,    37,     0,
      38,    41,     7,    11,     0,     0,     0,     0,     0,   108,
       0,     0,     0,   110,   112,     0,    98,   102,   107,     0,
       0,     0,     0,    89,     0,     0,    58,     0,     0,     0,
       0,    26,     0,     0,    23,    24,    25,     0,     0,    40,
       0,     0,    43,     0,    44,     0,    10,     0,   119,     0,
       0,    69,     0,     0,     0,     0,   115,   114,     0,     0,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,    91,
       0,     0,     0,     0,    34,     0,     0,    22,    36,     0,
      51,    51,     9,     9,     0,     0,    73,     0,   117,     0,
       0,   113,     0,    96,    97,    92,    93,    94,    95,    78,
      99,   100,   101,   103,   104,   105,   106,    79,    80,     0,
       0,     0,     0,    86,    76,     0,    75,    30,     0,     0,
      32,    33,     0,    27,    42,     0,    49,     0,     0,     0,
       0,    71,   118,     0,   109,   116,   111,    59,    82,    83,
       0,    59,    59,    84,    85,    90,     0,    28,     0,     0,
       0,     0,     0,    53,     0,    46,     6,    48,    70,    77,
       0,     0,     0,    29,     0,    35,     0,     0,     0,    50,
      47,    59,    88,    87,    31,     0,    55,    52,    81,    54
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,  -136,   118,   247,  -136,  -136,   -20,
    -136,  -136,   231,   -94,  -135,  -136,  -136,  -136,   120,   -87,
    -136,  -136,   210,  -136,  -136,  -136,  -136,  -136,   113,  -136,
      23,    73,    -7,   -38,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,    95,  -136,  -136,   -26,   260,  -117,
     -66,   -78
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,   198,   199,    10,    13,    74,
      19,    24,    25,    93,    94,    95,    96,   143,   144,    59,
      27,    60,    61,    62,   102,   103,   104,   105,   196,   222,
     223,    16,    46,    22,    47,    48,    49,    50,    51,    52,
      53,   210,    54,   182,   183,    55,   138,   108,    76,    77,
      78,   109
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    79,    17,   145,   149,   116,   117,   189,    58,   170,
     171,   172,    75,    58,    80,    64,    82,     1,   137,   112,
     126,   127,    69,   238,   113,   128,   114,   239,    70,   119,
     120,   121,   122,   123,   124,   159,    92,    97,    98,    71,
     162,   110,   111,   220,   115,    72,    28,    29,    30,    31,
      32,   190,   155,    65,     5,   156,   145,    87,    66,   139,
      67,   100,   101,   173,   174,   175,   176,     6,   141,     7,
     136,   129,   130,   131,    88,   132,    33,   185,    92,    73,
     186,    28,    29,    30,    31,    32,    89,   169,   160,   240,
      11,    68,   155,    90,   155,   204,   178,   206,   219,    97,
     192,    12,   246,    97,   237,    36,    15,   177,   221,   179,
     249,    33,    14,    91,    97,   245,   181,    28,    29,    30,
      31,    32,    92,    18,    20,    21,   193,    23,   201,   202,
      35,    26,    56,   236,    58,    63,    81,    83,   142,    87,
     244,    84,    15,    37,    85,    38,    86,    33,    39,   106,
      40,   221,    41,   107,   180,    42,    88,    43,    44,   215,
      45,   180,   181,    28,    29,    30,    31,    32,   217,   229,
     118,   140,    92,   231,   232,   146,    36,   228,    28,    29,
      30,    31,    32,   135,   230,    28,    29,    30,    31,    32,
      36,   147,    17,    33,   148,    91,   233,   150,   151,   213,
     158,   154,   152,   248,    92,   153,   187,    36,    33,   195,
     242,   184,   188,    15,    92,    33,    38,    92,   194,    39,
     133,    40,   203,    41,   211,    92,    42,    15,    43,    44,
      38,    45,   207,    39,   212,    40,    36,    41,   224,   243,
      42,   218,    43,    44,    15,    45,   225,    38,   227,   235,
      39,     9,    40,    36,    41,    57,   234,    42,   216,    43,
      44,   247,    45,   191,   197,    28,    29,    30,    31,    32,
      99,   200,   226,    15,     0,     0,    38,   214,     0,    39,
       0,    40,     0,    41,     0,     0,    42,     0,    43,    44,
      15,    45,     0,    38,     0,    33,    39,     0,    40,     0,
      41,     0,     0,    42,     0,    43,    44,     0,    45,   119,
     120,   121,   122,   123,   124,   119,   120,   121,   122,   123,
     124,   119,   120,   121,   122,   123,   124,   119,   120,   121,
     122,   123,   124,   161,     0,     0,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,   208,   209,     0,
       0,   134,     0,     0,     0,     0,     0,   241,   125,   157,
     119,   120,   121,   122,   123,   124,   205,   119,   120,   121,
     122,   123,   124,   119,   120,   121,   122,   123,   124,   163,
     164,   165,   166,   167,   168
};

static const yytype_int16 yycheck[] =
{
      20,    39,     9,    90,    98,    71,    72,   142,     3,   126,
     127,   128,    38,     3,    40,    35,    42,    33,    84,     4,
      19,    20,     3,     6,     9,    24,    11,    10,     9,    13,
      14,    15,    16,    17,    18,   113,    56,     7,     8,    20,
     118,    67,    68,    38,    70,    26,    27,    28,    29,    30,
      31,    41,     7,     4,     3,    10,   143,     3,     9,    85,
      11,    34,    35,   129,   130,   131,   132,     0,    88,    36,
      54,    21,    22,    23,    20,    25,    57,     7,    98,    60,
      10,    27,    28,    29,    30,    31,    32,   125,   114,   224,
       6,    42,     7,    39,     7,    10,   134,    10,   192,     7,
       8,     3,   237,     7,     8,     3,    40,   133,   195,   135,
     245,    57,     4,    59,     7,     8,   136,    27,    28,    29,
      30,    31,   142,    37,    13,     3,   146,     3,   154,   155,
      13,    38,    13,   220,     3,     6,     3,    27,    11,     3,
     234,     9,    40,    41,     9,    43,     6,    57,    46,     6,
      48,   238,    50,     3,     3,    53,    20,    55,    56,   185,
      58,     3,   182,    27,    28,    29,    30,    31,   188,   207,
       9,     5,   192,   211,   212,     5,     3,   203,    27,    28,
      29,    30,    31,    42,   210,    27,    28,    29,    30,    31,
       3,     6,   199,    57,     3,    59,   216,     3,     3,    41,
       3,    42,     6,   241,   224,     6,     3,     3,    57,     9,
       6,    10,     5,    40,   234,    57,    43,   237,     6,    46,
      47,    48,    42,    50,     8,   245,    53,    40,    55,    56,
      43,    58,    45,    46,     8,    48,     3,    50,     8,     6,
      53,    12,    55,    56,    40,    58,     6,    43,     6,     6,
      46,     4,    48,     3,    50,    24,    54,    53,    20,    55,
      56,   238,    58,   143,   151,    27,    28,    29,    30,    31,
      60,   153,   199,    40,    -1,    -1,    43,   182,    -1,    46,
      -1,    48,    -1,    50,    -1,    -1,    53,    -1,    55,    56,
      40,    58,    -1,    43,    -1,    57,    46,    -1,    48,    -1,
      50,    -1,    -1,    53,    -1,    55,    56,    -1,    58,    13,
      14,    15,    16,    17,    18,    13,    14,    15,    16,    17,
      18,    13,    14,    15,    16,    17,    18,    13,    14,    15,
      16,    17,    18,    10,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    49,    44,    12,
      13,    14,    15,    16,    17,    18,    12,    13,    14,    15,
      16,    17,    18,    13,    14,    15,    16,    17,    18,   119,
     120,   121,   122,   123,   124
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    62,    63,    64,     3,     0,    36,    65,    67,
      68,     6,     3,    69,     4,    40,    92,    93,    37,    71,
      13,     3,    94,     3,    72,    73,    38,    81,    27,    28,
      29,    30,    31,    57,    70,    13,     3,    41,    43,    46,
      48,    50,    53,    55,    56,    58,    93,    95,    96,    97,
      98,    99,   100,   101,   103,   106,    13,    73,     3,    80,
      82,    83,    84,     6,    70,     4,     9,    11,    42,     3,
       9,    20,    26,    60,    70,   108,   109,   110,   111,    94,
     108,     3,   108,    27,     9,     9,     6,     3,    20,    32,
      39,    59,    70,    74,    75,    76,    77,     7,     8,    83,
      34,    35,    85,    86,    87,    88,     6,     3,   108,   112,
     108,   108,     4,     9,    11,   108,   111,   111,     9,    13,
      14,    15,    16,    17,    18,    44,    19,    20,    24,    21,
      22,    23,    25,    47,    49,    42,    54,   111,   107,   108,
       5,    70,    11,    78,    79,    80,     5,     6,     3,    74,
       3,     3,     6,     6,    42,     7,    10,    12,     3,   112,
     108,    10,   112,   109,   109,   109,   109,   109,   109,    94,
     110,   110,   110,   111,   111,   111,   111,   108,    94,   108,
       3,    70,   104,   105,    10,     7,    10,     3,     5,    75,
      41,    79,     8,    70,     6,     9,    89,    89,    66,    67,
      66,   108,   108,    42,    10,    12,    10,    45,    51,    52,
     102,     8,     8,    41,   105,   108,    20,    70,    12,    74,
      38,    80,    90,    91,     8,     6,    92,     6,   108,    94,
     108,    94,    94,    70,    54,     6,    80,     8,     6,    10,
      75,    49,     6,     6,    74,     8,    75,    91,    94,    75
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    66,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    76,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    83,    84,    84,    84,    85,    86,    87,    88,
      89,    89,    90,    90,    91,    91,    92,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    98,    99,
     100,   101,   102,   102,   103,   104,   104,   105,   105,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   110,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     4,     2,     0,
       5,     4,     1,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     4,     1,     1,     1,     1,     3,     4,     5,
       3,     6,     3,     2,     1,     4,     3,     1,     2,     0,
       2,     1,     4,     2,     2,     0,     4,     5,     4,     3,
       3,     0,     3,     1,     4,     3,     1,     3,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       6,     5,     1,     4,     1,     4,     4,     6,     4,     4,
       4,     8,     1,     1,     5,     2,     1,     4,     4,     2,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     4,
       1,     4,     1,     3,     2,     2,     4,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 104 "pascal.y"
                          { root = (yyvsp[0].astProgram); }
#line 1593 "y.tab.c"
    break;

  case 3:
#line 105 "pascal.y"
                                             { 
                    (yyval.astProgram) = new ast::Program((yyvsp[-2].astProgramHead), (yyvsp[-1].astRoutine)); 
                }
#line 1601 "y.tab.c"
    break;

  case 4:
#line 110 "pascal.y"
                                    { 
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), new ast::ParamList(), new ast::VoidType()); 
                }
#line 1609 "y.tab.c"
    break;

  case 5:
#line 115 "pascal.y"
                                             { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1617 "y.tab.c"
    break;

  case 6:
#line 120 "pascal.y"
                                             { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1625 "y.tab.c"
    break;

  case 7:
#line 125 "pascal.y"
                                                                { 
                    (yyval.astRoutineHead) = new ast::RoutineHead((yyvsp[-3].astConstDeclList), (yyvsp[-2].astTypeDeclList), (yyvsp[-1].astVarDeclList), (yyvsp[0].astRoutinePartList)); 
                }
#line 1633 "y.tab.c"
    break;

  case 8:
#line 130 "pascal.y"
                                         { 
                    (yyval.astConstDeclList) = (yyvsp[0].astConstDeclList); 
                }
#line 1641 "y.tab.c"
    break;

  case 9:
#line 133 "pascal.y"
                  { 
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                }
#line 1649 "y.tab.c"
    break;

  case 10:
#line 138 "pascal.y"
                                                                { 
                    (yyval.astConstDeclList) = (yyvsp[-4].astConstDeclList);
                    (yyvsp[-4].astConstDeclList)->push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1658 "y.tab.c"
    break;

  case 11:
#line 142 "pascal.y"
                                                {
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                    (yyval.astConstDeclList)->push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1667 "y.tab.c"
    break;

  case 12:
#line 148 "pascal.y"
                            {(yyval.astBasicConst) = new ast::IntegerNode((yyvsp[0].astint)); /*需不需要atoi呢， 注意这里还有一些问题*/}
#line 1673 "y.tab.c"
    break;

  case 13:
#line 149 "pascal.y"
                            {(yyval.astBasicConst) = new ast::RealNode((yyvsp[0].astreal));}
#line 1679 "y.tab.c"
    break;

  case 14:
#line 150 "pascal.y"
                            {(yyval.astBasicConst) = new ast::CharNode((yyvsp[0].astchar));}
#line 1685 "y.tab.c"
    break;

  case 15:
#line 151 "pascal.y"
                            {(yyval.astBasicConst) = new ast::StringNode((yyvsp[0].aststring));}
#line 1691 "y.tab.c"
    break;

  case 16:
#line 152 "pascal.y"
                            {(yyval.astBasicConst) = new ast::BooleanNode((yyvsp[0].astbool));}
#line 1697 "y.tab.c"
    break;

  case 17:
#line 153 "pascal.y"
                            {(yyval.astBasicConst) = new ast::MaxIntNode();}
#line 1703 "y.tab.c"
    break;

  case 18:
#line 156 "pascal.y"
                                       { (yyval.astTypeDeclList) = (yyvsp[0].astTypeDeclList); }
#line 1709 "y.tab.c"
    break;

  case 19:
#line 157 "pascal.y"
                    { 
                    (yyval.astTypeDeclList) = new ast::TypeDeclList(); 
                }
#line 1717 "y.tab.c"
    break;

  case 20:
#line 162 "pascal.y"
                                                  { 
                    (yyval.astTypeDeclList) = (yyvsp[-1].astTypeDeclList);
                    (yyvsp[-1].astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1726 "y.tab.c"
    break;

  case 21:
#line 166 "pascal.y"
                                   {
                    (yyval.astTypeDeclList) = new ast::TypeDeclList();
                    (yyval.astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1735 "y.tab.c"
    break;

  case 22:
#line 172 "pascal.y"
                                             { 
                    (yyval.astTypeDecl) = new ast::TypeDecl(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicType)); 
                }
#line 1743 "y.tab.c"
    break;

  case 23:
#line 177 "pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1749 "y.tab.c"
    break;

  case 24:
#line 178 "pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1755 "y.tab.c"
    break;

  case 25:
#line 179 "pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1761 "y.tab.c"
    break;

  case 26:
#line 182 "pascal.y"
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
#line 1779 "y.tab.c"
    break;

  case 27:
#line 201 "pascal.y"
                                                    { 
                    (yyval.astBasicType) = new ast::RangeType((yyvsp[-2].astBasicConst), (yyvsp[0].astBasicConst)); 
                }
#line 1787 "y.tab.c"
    break;

  case 28:
#line 204 "pascal.y"
                                                           { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-2].astBasicConst)), (yyvsp[0].astBasicConst)); 
                }
#line 1795 "y.tab.c"
    break;

  case 29:
#line 207 "pascal.y"
                                                                  { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-3].astBasicConst)), new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astBasicConst))); 
                }
#line 1803 "y.tab.c"
    break;

  case 30:
#line 210 "pascal.y"
                                  {
                    (yyval.astBasicType) = new ast::RangeType((ast::Expression*)(new ast::Identifier((yyvsp[-2].aststring))), (ast::Expression*)(new ast::Identifier((yyvsp[0].aststring))));
                }
#line 1811 "y.tab.c"
    break;

  case 31:
#line 216 "pascal.y"
                                                                 { 
                    (yyval.astBasicType) = new ast::ArrayType((yyvsp[-3].astBasicType), (yyvsp[0].astBasicType)); 
                }
#line 1819 "y.tab.c"
    break;

  case 32:
#line 221 "pascal.y"
                                               { 
                    (yyval.astBasicType) = new ast::RecordType((yyvsp[-1].astVarDeclList)); 
                }
#line 1827 "y.tab.c"
    break;

  case 33:
#line 226 "pascal.y"
                                              { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());;
                }
#line 1836 "y.tab.c"
    break;

  case 34:
#line 230 "pascal.y"
                              {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 1844 "y.tab.c"
    break;

  case 35:
#line 235 "pascal.y"
                                                    {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 1854 "y.tab.c"
    break;

  case 36:
#line 241 "pascal.y"
                                       {
                    (yyval.astNameList) = (yyvsp[-2].astNameList);
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1863 "y.tab.c"
    break;

  case 37:
#line 245 "pascal.y"
                      {
                    (yyval.astNameList) = new ast::NameList;
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1872 "y.tab.c"
    break;

  case 38:
#line 250 "pascal.y"
                                     { (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList); }
#line 1878 "y.tab.c"
    break;

  case 39:
#line 251 "pascal.y"
                  { (yyval.astVarDeclList) = new ast::VarDeclList(); }
#line 1884 "y.tab.c"
    break;

  case 40:
#line 254 "pascal.y"
                                           { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());
                }
#line 1893 "y.tab.c"
    break;

  case 41:
#line 258 "pascal.y"
                            {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 1901 "y.tab.c"
    break;

  case 42:
#line 263 "pascal.y"
                                                     {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 1911 "y.tab.c"
    break;

  case 43:
#line 270 "pascal.y"
                                               {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 1920 "y.tab.c"
    break;

  case 44:
#line 274 "pascal.y"
                                                {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 1929 "y.tab.c"
    break;

  case 45:
#line 278 "pascal.y"
                    { (yyval.astRoutinePartList) = new ast::RoutinePartList(); }
#line 1935 "y.tab.c"
    break;

  case 46:
#line 281 "pascal.y"
                                                         {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 1943 "y.tab.c"
    break;

  case 47:
#line 285 "pascal.y"
                                                                     {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-2].astParamList), (yyvsp[0].astBasicType));
                }
#line 1951 "y.tab.c"
    break;

  case 48:
#line 289 "pascal.y"
                                                           {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 1959 "y.tab.c"
    break;

  case 49:
#line 294 "pascal.y"
                                           {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), (yyvsp[0].astParamList), new ast::VoidType()); 
                }
#line 1967 "y.tab.c"
    break;

  case 50:
#line 299 "pascal.y"
                                     {
                    (yyval.astParamList) = (yyvsp[-1].astParamList);
                }
#line 1975 "y.tab.c"
    break;

  case 51:
#line 302 "pascal.y"
                   {
                    (yyval.astParamList) = new ast::ParamList();
                }
#line 1983 "y.tab.c"
    break;

  case 52:
#line 306 "pascal.y"
                                                       {
                    (yyval.astParamList) = (yyvsp[-2].astParamList);
                    (yyvsp[-2].astParamList)->insert((yyvsp[-2].astParamList)->end(), (yyvsp[0].astParamList)->begin(), (yyvsp[0].astParamList)->end());
                }
#line 1992 "y.tab.c"
    break;

  case 53:
#line 310 "pascal.y"
                                 {
                    (yyval.astParamList) = (yyvsp[0].astParamList);
                }
#line 2000 "y.tab.c"
    break;

  case 54:
#line 316 "pascal.y"
                                                         {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 2010 "y.tab.c"
    break;

  case 55:
#line 321 "pascal.y"
                                                     {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 2020 "y.tab.c"
    break;

  case 56:
#line 330 "pascal.y"
                                {
                    (yyval.astStmtList) = (yyvsp[0].astStmtList);
                }
#line 2028 "y.tab.c"
    break;

  case 57:
#line 334 "pascal.y"
                                      {
                    (yyval.astStmtList) = (yyvsp[-1].astStmtList);
                }
#line 2036 "y.tab.c"
    break;

  case 58:
#line 339 "pascal.y"
                                        {
                    (yyval.astStmtList) = (yyvsp[-2].astStmtList);
                    (yyval.astStmtList)->push_back((yyvsp[-1].astStmt));
                }
#line 2045 "y.tab.c"
    break;

  case 59:
#line 343 "pascal.y"
                   {
                    (yyval.astStmtList) = new ast::StmtList();
                }
#line 2053 "y.tab.c"
    break;

  case 60:
#line 357 "pascal.y"
                              {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2061 "y.tab.c"
    break;

  case 61:
#line 360 "pascal.y"
                            {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2069 "y.tab.c"
    break;

  case 62:
#line 363 "pascal.y"
                                {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmtList);
                }
#line 2077 "y.tab.c"
    break;

  case 63:
#line 366 "pascal.y"
                          {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2085 "y.tab.c"
    break;

  case 64:
#line 369 "pascal.y"
                              {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2093 "y.tab.c"
    break;

  case 65:
#line 372 "pascal.y"
                             {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2101 "y.tab.c"
    break;

  case 66:
#line 375 "pascal.y"
                           {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2109 "y.tab.c"
    break;

  case 67:
#line 378 "pascal.y"
                            {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2117 "y.tab.c"
    break;

  case 68:
#line 381 "pascal.y"
                           {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2125 "y.tab.c"
    break;

  case 69:
#line 386 "pascal.y"
                                         {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::Identifier((yyvsp[-2].aststring)), (yyvsp[0].astExpression));
                }
#line 2133 "y.tab.c"
    break;

  case 70:
#line 389 "pascal.y"
                                                        {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::ArrayElementRef(new ast::Identifier((yyvsp[-5].aststring)), (yyvsp[-3].astExpression)), (yyvsp[0].astExpression));
                }
#line 2141 "y.tab.c"
    break;

  case 71:
#line 392 "pascal.y"
                                                  {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::RecordElementRef(new ast::Identifier((yyvsp[-4].aststring)), new ast::Identifier((yyvsp[-2].aststring))), (yyvsp[0].astExpression));
                }
#line 2149 "y.tab.c"
    break;

  case 72:
#line 398 "pascal.y"
                      {
                    (yyval.astStmt) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 2157 "y.tab.c"
    break;

  case 73:
#line 401 "pascal.y"
                                      {
                    (yyval.astStmt) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2165 "y.tab.c"
    break;

  case 74:
#line 404 "pascal.y"
                            {
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE);
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN);
                }
#line 2176 "y.tab.c"
    break;

  case 75:
#line 410 "pascal.y"
                                                     {
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE, (yyvsp[-1].astExpressionList));
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN, (yyvsp[-1].astExpressionList));
                }
#line 2187 "y.tab.c"
    break;

  case 76:
#line 416 "pascal.y"
                                        {
                    (yyval.astStmt) = new ast::ReadProcCall((yyvsp[-1].astExpression));
                }
#line 2195 "y.tab.c"
    break;

  case 77:
#line 420 "pascal.y"
                                                                  {
                    (yyval.astStmt) = new ast::IfStmt((yyvsp[-4].astExpression), (yyvsp[-2].astStmtList), (yyvsp[0].astStmtList));
                }
#line 2203 "y.tab.c"
    break;

  case 78:
#line 423 "pascal.y"
                                                  {
                    (yyval.astStmt) = new ast::IfStmt((yyvsp[-2].astExpression), (yyvsp[0].astStmtList));
                }
#line 2211 "y.tab.c"
    break;

  case 79:
#line 435 "pascal.y"
                                                       {
                    (yyval.astStmt) = new ast::RepeatStmt((yyvsp[0].astExpression), (yyvsp[-2].astStmtList));
                }
#line 2219 "y.tab.c"
    break;

  case 80:
#line 440 "pascal.y"
                                                  {
                    (yyval.astStmt) = new ast::WhileStmt((yyvsp[-2].astExpression), (yyvsp[0].astStmtList));
                }
#line 2227 "y.tab.c"
    break;

  case 81:
#line 444 "pascal.y"
                                                                                   {
                    (yyval.astStmt) = new ast::ForStmt(new ast::Identifier((yyvsp[-6].aststring)), (yyvsp[-4].astExpression), (yyvsp[-3].astDirection), (yyvsp[-2].astExpression), (yyvsp[0].astStmtList));
                }
#line 2235 "y.tab.c"
    break;

  case 82:
#line 448 "pascal.y"
                     {
                    (yyval.astDirection) = ast::Direction::To;
                }
#line 2243 "y.tab.c"
    break;

  case 83:
#line 451 "pascal.y"
                         {
                    (yyval.astDirection) = ast::Direction::DownTo;
                }
#line 2251 "y.tab.c"
    break;

  case 84:
#line 456 "pascal.y"
                                                         {
                    (yyval.astStmt) = new ast::CaseStmt((yyvsp[-3].astExpression), (yyvsp[-1].astCaseExprList));
                }
#line 2259 "y.tab.c"
    break;

  case 85:
#line 461 "pascal.y"
                                             {
                    (yyval.astCaseExprList) = (yyvsp[-1].astCaseExprList);
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2268 "y.tab.c"
    break;

  case 86:
#line 465 "pascal.y"
                             {
                    (yyval.astCaseExprList) = new ast::CaseExprList();
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2277 "y.tab.c"
    break;

  case 87:
#line 471 "pascal.y"
                                                      {
                    (yyval.astCaseExpr) = new ast::CaseExpr((yyvsp[-3].astBasicConst), (yyvsp[-1].astStmtList));
                }
#line 2285 "y.tab.c"
    break;

  case 88:
#line 474 "pascal.y"
                                              {
                    (yyval.astCaseExpr) = new ast::CaseExpr(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astStmtList));
                }
#line 2293 "y.tab.c"
    break;

  case 89:
#line 479 "pascal.y"
                                {
                    (yyval.astStmt) = new ast::GotoStmt((yyvsp[0].astint));
                }
#line 2301 "y.tab.c"
    break;

  case 90:
#line 483 "pascal.y"
                                                      {
                    (yyval.astExpressionList) = (yyvsp[-2].astExpressionList);
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2310 "y.tab.c"
    break;

  case 91:
#line 487 "pascal.y"
                              {
                    (yyval.astExpressionList) = new ast::ExpressionList();
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2319 "y.tab.c"
    break;

  case 92:
#line 493 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GEop, (yyvsp[0].astExpression));
                }
#line 2327 "y.tab.c"
    break;

  case 93:
#line 496 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GTop, (yyvsp[0].astExpression));
                }
#line 2335 "y.tab.c"
    break;

  case 94:
#line 499 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LEop, (yyvsp[0].astExpression));
                }
#line 2343 "y.tab.c"
    break;

  case 95:
#line 502 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LTop, (yyvsp[0].astExpression));
                }
#line 2351 "y.tab.c"
    break;

  case 96:
#line 505 "pascal.y"
                                           {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::EQUALop, (yyvsp[0].astExpression));
                }
#line 2359 "y.tab.c"
    break;

  case 97:
#line 508 "pascal.y"
                                             {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::UNEQUALop, (yyvsp[0].astExpression));
                }
#line 2367 "y.tab.c"
    break;

  case 98:
#line 511 "pascal.y"
                        {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2375 "y.tab.c"
    break;

  case 99:
#line 515 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::PLUSop, (yyvsp[0].astExpression));
                }
#line 2383 "y.tab.c"
    break;

  case 100:
#line 518 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MINUSop, (yyvsp[0].astExpression));
                }
#line 2391 "y.tab.c"
    break;

  case 101:
#line 521 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ORop, (yyvsp[0].astExpression));
                }
#line 2399 "y.tab.c"
    break;

  case 102:
#line 524 "pascal.y"
                        {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2407 "y.tab.c"
    break;

  case 103:
#line 529 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MULop, (yyvsp[0].astExpression));
                }
#line 2415 "y.tab.c"
    break;

  case 104:
#line 532 "pascal.y"
                                      {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::DIVop, (yyvsp[0].astExpression));
                }
#line 2423 "y.tab.c"
    break;

  case 105:
#line 535 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MODop, (yyvsp[0].astExpression));
                }
#line 2431 "y.tab.c"
    break;

  case 106:
#line 538 "pascal.y"
                                      {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ANDop, (yyvsp[0].astExpression));
                }
#line 2439 "y.tab.c"
    break;

  case 107:
#line 541 "pascal.y"
                          {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2447 "y.tab.c"
    break;

  case 108:
#line 546 "pascal.y"
                      {
                    (yyval.astExpression) = new ast::Identifier((yyvsp[0].aststring));
                }
#line 2455 "y.tab.c"
    break;

  case 109:
#line 549 "pascal.y"
                                          {
                    (yyval.astExpression) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2463 "y.tab.c"
    break;

  case 110:
#line 552 "pascal.y"
                             {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[0].astSYSFUNCT));
                }
#line 2471 "y.tab.c"
    break;

  case 111:
#line 555 "pascal.y"
                                                 {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[-3].astSYSFUNCT), (yyvsp[-1].astArgList));
                }
#line 2479 "y.tab.c"
    break;

  case 112:
#line 558 "pascal.y"
                                {
                    (yyval.astExpression) = (yyvsp[0].astBasicConst);
                }
#line 2487 "y.tab.c"
    break;

  case 113:
#line 561 "pascal.y"
                                      {
                    (yyval.astExpression) = (yyvsp[-1].astExpression);
                }
#line 2495 "y.tab.c"
    break;

  case 114:
#line 564 "pascal.y"
                                {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NOTop, (yyvsp[0].astExpression));
                }
#line 2503 "y.tab.c"
    break;

  case 115:
#line 567 "pascal.y"
                                 {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astExpression));
                }
#line 2511 "y.tab.c"
    break;

  case 116:
#line 570 "pascal.y"
                                          {
                    (yyval.astExpression) = new ast::ArrayElementRef(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astExpression));
                }
#line 2519 "y.tab.c"
    break;

  case 117:
#line 573 "pascal.y"
                               {
                    (yyval.astExpression) = new ast::RecordElementRef(new ast::Identifier((yyvsp[-2].aststring)), new ast::Identifier((yyvsp[0].aststring)));
                }
#line 2527 "y.tab.c"
    break;

  case 118:
#line 577 "pascal.y"
                                                {
                    (yyval.astArgList) = (yyvsp[-2].astArgList);
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2536 "y.tab.c"
    break;

  case 119:
#line 581 "pascal.y"
                              {
                    (yyval.astArgList) = new ast::ArgList();
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2545 "y.tab.c"
    break;


#line 2549 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 587 "pascal.y"

void yyerror() {}
int main() {
        printf(">>> ");
        while(1) yyparse();
}
