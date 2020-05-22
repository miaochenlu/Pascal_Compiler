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
#include "ast/ast.h"
#include "parser.hpp"

using namespace std;
static ast::BasicAstNode* root;
// extern "C" {
//     int yyparse(void);
//     extern int yylineno;
// }
void yyerror(string msg, ...);
static int yylex(void);


#line 89 "parser.cpp"

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
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    INTEGER = 259,                 /* INTEGER  */
    REAL = 260,                    /* REAL  */
    CHAR = 261,                    /* CHAR  */
    STRING = 262,                  /* STRING  */
    BOOLEAN = 263,                 /* BOOLEAN  */
    SYS_PROC = 264,                /* SYS_PROC  */
    SYS_TYPE = 265,                /* SYS_TYPE  */
    SYS_FUNCT = 266,               /* SYS_FUNCT  */
    SYS_CON = 267,                 /* SYS_CON  */
    DOT = 268,                     /* DOT  */
    DOTDOT = 269,                  /* DOTDOT  */
    SEMI = 270,                    /* SEMI  */
    COMMA = 271,                   /* COMMA  */
    COLON = 272,                   /* COLON  */
    LP = 273,                      /* LP  */
    RP = 274,                      /* RP  */
    LB = 275,                      /* LB  */
    RB = 276,                      /* RB  */
    EQUAL = 277,                   /* EQUAL  */
    UNEQUAL = 278,                 /* UNEQUAL  */
    GE = 279,                      /* GE  */
    GT = 280,                      /* GT  */
    LE = 281,                      /* LE  */
    LT = 282,                      /* LT  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    MUL = 285,                     /* MUL  */
    DIV = 286,                     /* DIV  */
    MOD = 287,                     /* MOD  */
    OR = 288,                      /* OR  */
    AND = 289,                     /* AND  */
    NOT = 290,                     /* NOT  */
    PROGRAM = 291,                 /* PROGRAM  */
    PROCEDURE = 292,               /* PROCEDURE  */
    FUNCTION = 293,                /* FUNCTION  */
    CONST = 294,                   /* CONST  */
    TYPE = 295,                    /* TYPE  */
    VAR = 296,                     /* VAR  */
    RECORD = 297,                  /* RECORD  */
    ARRAY = 298,                   /* ARRAY  */
    BEG = 299,                     /* BEG  */
    END = 300,                     /* END  */
    ASSIGN = 301,                  /* ASSIGN  */
    IF = 302,                      /* IF  */
    THEN = 303,                    /* THEN  */
    ELSE = 304,                    /* ELSE  */
    REPEAT = 305,                  /* REPEAT  */
    UNTIL = 306,                   /* UNTIL  */
    WHILE = 307,                   /* WHILE  */
    DO = 308,                      /* DO  */
    FOR = 309,                     /* FOR  */
    TO = 310,                      /* TO  */
    DOWNTO = 311,                  /* DOWNTO  */
    CASE = 312,                    /* CASE  */
    OF = 313,                      /* OF  */
    GOTO = 314,                    /* GOTO  */
    READ = 315                     /* READ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "pascal.y"

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
    ast::Stmt*              astStmt;

    ast::Program*           astProgram;
    ast::ProgramHead*       astProgramHead;
    ast::Routine*           astRoutine;
    ast::RoutineHead*       astRoutineHead;
    ast::Parameter*         astParameter;
    ast::LabelDecl*         astLabelDecl;
    ast::ConstDecl*         astConstDecl;
    ast::TypeDecl*          astTypeDecl;
    ast::VarDecl*           astVarDecl;

    ast::NameList*          astNameList;
    ast::StmtList*          astStmtList;
    ast::ParamList*         astParamList;
    ast::LabelDeclList*     astLabelDeclList;
    ast::ConstDeclList*     astConstDeclList;
    ast::TypeDeclList*      astTypeDeclList;
    ast::VarDeclList*       astVarDeclList;
    ast::RoutinePartList*   astRoutinePartList;
    ast::ExpressionList*    astExpressionList;
    ast::CaseExprList*      astCaseExprList;
    ast::ArgList*           astArgList;

#line 241 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_BOOLEAN = 8,                    /* BOOLEAN  */
  YYSYMBOL_SYS_PROC = 9,                   /* SYS_PROC  */
  YYSYMBOL_SYS_TYPE = 10,                  /* SYS_TYPE  */
  YYSYMBOL_SYS_FUNCT = 11,                 /* SYS_FUNCT  */
  YYSYMBOL_SYS_CON = 12,                   /* SYS_CON  */
  YYSYMBOL_DOT = 13,                       /* DOT  */
  YYSYMBOL_DOTDOT = 14,                    /* DOTDOT  */
  YYSYMBOL_SEMI = 15,                      /* SEMI  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_COLON = 17,                     /* COLON  */
  YYSYMBOL_LP = 18,                        /* LP  */
  YYSYMBOL_RP = 19,                        /* RP  */
  YYSYMBOL_LB = 20,                        /* LB  */
  YYSYMBOL_RB = 21,                        /* RB  */
  YYSYMBOL_EQUAL = 22,                     /* EQUAL  */
  YYSYMBOL_UNEQUAL = 23,                   /* UNEQUAL  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_MINUS = 29,                     /* MINUS  */
  YYSYMBOL_MUL = 30,                       /* MUL  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_PROGRAM = 36,                   /* PROGRAM  */
  YYSYMBOL_PROCEDURE = 37,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 38,                  /* FUNCTION  */
  YYSYMBOL_CONST = 39,                     /* CONST  */
  YYSYMBOL_TYPE = 40,                      /* TYPE  */
  YYSYMBOL_VAR = 41,                       /* VAR  */
  YYSYMBOL_RECORD = 42,                    /* RECORD  */
  YYSYMBOL_ARRAY = 43,                     /* ARRAY  */
  YYSYMBOL_BEG = 44,                       /* BEG  */
  YYSYMBOL_END = 45,                       /* END  */
  YYSYMBOL_ASSIGN = 46,                    /* ASSIGN  */
  YYSYMBOL_IF = 47,                        /* IF  */
  YYSYMBOL_THEN = 48,                      /* THEN  */
  YYSYMBOL_ELSE = 49,                      /* ELSE  */
  YYSYMBOL_REPEAT = 50,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 51,                     /* UNTIL  */
  YYSYMBOL_WHILE = 52,                     /* WHILE  */
  YYSYMBOL_DO = 53,                        /* DO  */
  YYSYMBOL_FOR = 54,                       /* FOR  */
  YYSYMBOL_TO = 55,                        /* TO  */
  YYSYMBOL_DOWNTO = 56,                    /* DOWNTO  */
  YYSYMBOL_CASE = 57,                      /* CASE  */
  YYSYMBOL_OF = 58,                        /* OF  */
  YYSYMBOL_GOTO = 59,                      /* GOTO  */
  YYSYMBOL_READ = 60,                      /* READ  */
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
#define YYLAST   398

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
       0,   111,   111,   114,   120,   125,   130,   135,   140,   143,
     148,   152,   158,   159,   160,   161,   162,   163,   166,   167,
     172,   176,   182,   187,   188,   189,   192,   211,   214,   217,
     220,   226,   231,   236,   240,   245,   251,   255,   260,   261,
     264,   268,   273,   280,   284,   288,   291,   295,   299,   304,
     309,   312,   316,   320,   326,   331,   340,   344,   349,   353,
     367,   370,   373,   376,   379,   382,   385,   388,   391,   396,
     399,   402,   407,   410,   413,   419,   425,   429,   432,   444,
     449,   453,   457,   460,   465,   470,   474,   480,   483,   488,
     492,   496,   502,   505,   508,   511,   514,   517,   520,   524,
     527,   530,   533,   538,   541,   544,   547,   550,   555,   558,
     561,   564,   567,   570,   573,   576,   579,   582,   586,   590
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTEGER",
  "REAL", "CHAR", "STRING", "BOOLEAN", "SYS_PROC", "SYS_TYPE", "SYS_FUNCT",
  "SYS_CON", "DOT", "DOTDOT", "SEMI", "COMMA", "COLON", "LP", "RP", "LB",
  "RB", "EQUAL", "UNEQUAL", "GE", "GT", "LE", "LT", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "OR", "AND", "NOT", "PROGRAM", "PROCEDURE", "FUNCTION",
  "CONST", "TYPE", "VAR", "RECORD", "ARRAY", "BEG", "END", "ASSIGN", "IF",
  "THEN", "ELSE", "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO",
  "CASE", "OF", "GOTO", "READ", "$accept", "programPrime", "program",
  "program_head", "routine", "sub_routine", "routine_head", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "routine_body", "compound_stmt",
  "stmt_list", "stmt", "assign_stmt", "proc_stmt", "if_stmt",
  "repeat_stmt", "while_stmt", "for_stmt", "direction", "case_stmt",
  "case_expr_list", "case_expr", "goto_stmt", "expression_list",
  "expression", "expr", "term", "factor", "args_list", YY_NULLPTR
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

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,    40,    49,  -140,    21,    61,  -140,    70,    88,    63,
      81,  -140,   101,   129,  -140,  -140,  -140,  -140,   130,    96,
     360,   117,    91,   122,   130,  -140,   143,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,   132,   360,    26,   131,  -140,   300,
    -140,   300,   150,   300,   152,   137,  -140,   142,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,   290,  -140,  -140,     1,
     143,  -140,     0,  -140,   144,   155,   300,   300,   300,   300,
     104,   145,   300,   300,   300,  -140,    57,    42,    27,  -140,
     169,    89,   115,    28,  -140,   300,  -140,   148,  -140,   360,
     143,   146,   153,   160,  -140,  -140,  -140,   162,   290,  -140,
     167,   174,  -140,   164,  -140,   165,  -140,   135,   365,    58,
     352,   365,    71,   365,   179,   300,   300,   300,   334,  -140,
    -140,   300,   300,   300,   300,   300,   300,  -140,   300,   300,
     300,   300,   300,   300,   300,   300,  -140,   300,   182,   172,
     180,   183,     2,  -140,    87,   333,   360,  -140,  -140,   178,
     181,   181,    21,    21,   300,   300,  -140,   161,   300,  -140,
    -140,    76,   359,    83,  -140,    42,    42,    42,    42,    42,
      42,   151,    27,    27,    27,  -140,  -140,  -140,  -140,   365,
     232,     8,   192,   197,    17,  -140,  -140,  -140,   342,  -140,
    -140,   290,   201,  -140,  -140,     7,  -140,   210,   216,    63,
     217,   365,   365,   300,   365,  -140,  -140,  -140,  -140,  -140,
    -140,   300,  -140,  -140,  -140,  -140,   360,  -140,   218,   176,
     143,   103,    -6,  -140,   333,  -140,  -140,  -140,   365,   232,
     298,   203,   221,  -140,  -140,   290,   113,   333,     7,  -140,
    -140,  -140,  -140,  -140,  -140,   333,  -140,  -140,   232,  -140
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     9,     0,     1,     0,     0,     0,
      19,     4,     0,     8,     3,    59,     5,    56,     0,    39,
       0,     0,     0,     0,    18,    21,     0,    45,    12,    13,
      14,    15,    16,    17,     0,     0,    72,    74,    57,     0,
      59,     0,     0,     0,     0,     0,    62,     0,    60,    61,
      63,    64,    65,    66,    67,    68,     0,    20,    37,     0,
      38,    41,     7,    11,     0,     0,     0,     0,     0,     0,
     108,   110,     0,     0,     0,   112,     0,    98,   102,   107,
       0,     0,     0,     0,    89,     0,    58,     0,    26,     0,
       0,     0,     0,     0,    23,    24,    25,     0,     0,    40,
       0,     0,    43,     0,    44,     0,    10,     0,   119,     0,
       0,    69,     0,    91,     0,     0,     0,     0,     0,   115,
     114,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,    22,    36,     0,
      51,    51,     9,     9,     0,     0,    73,     0,     0,    75,
     117,     0,     0,     0,   113,    96,    97,    92,    93,    94,
      95,    78,    99,   100,   101,   103,   104,   105,   106,    79,
      80,     0,     0,     0,     0,    86,    76,    30,     0,    32,
      33,     0,     0,    27,    42,     0,    49,     0,     0,     0,
       0,    71,   118,     0,    90,   109,   116,   111,    59,    82,
      83,     0,    59,    59,    84,    85,     0,    28,     0,     0,
       0,     0,     0,    53,     0,    46,     6,    48,    70,    77,
       0,     0,     0,    29,    35,     0,     0,     0,     0,    50,
      47,    59,    88,    87,    31,     0,    55,    52,    81,    54
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,  -140,  -140,    84,   234,  -140,  -140,   -20,
    -140,  -140,   215,   -95,  -139,  -140,  -140,  -140,    98,   -86,
    -140,  -140,   184,  -140,  -140,  -140,  -140,  -140,    92,  -140,
       4,    46,    -7,   -39,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,    62,  -140,  -140,   -27,   272,  -102,
     -66,   -24
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,   198,   199,    10,    13,    75,
      19,    24,    25,    93,    94,    95,    96,   142,   143,    59,
      27,    60,    61,    62,   102,   103,   104,   105,   196,   222,
     223,    16,    46,    22,    47,    48,    49,    50,    51,    52,
      53,   211,    54,   184,   185,    55,   112,   108,    77,    78,
      79,   109
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    80,    17,   149,   144,    58,   192,   119,   120,   238,
      58,     1,    76,   239,    81,    64,    83,    97,    98,   139,
     182,    28,    29,    30,    31,    32,   172,   173,   174,    33,
     121,   122,   123,   124,   125,   126,    92,   100,   101,    65,
     110,   111,   113,     5,    66,   118,    67,   189,   220,     6,
     121,   122,   123,   124,   125,   126,   144,   131,   132,   133,
       7,   134,   214,   209,   210,   175,   176,   177,   178,   141,
     128,   129,    68,    12,   155,   130,    11,   156,    92,   121,
     122,   123,   124,   125,   126,   240,   138,   158,   171,   162,
     159,   161,   155,   163,    36,   205,   218,   180,   246,   155,
      37,    14,   207,    97,   191,   127,   249,    15,   179,   221,
     181,   121,   122,   123,   124,   125,   126,   114,   183,    97,
     237,    18,   115,    20,   116,    92,   193,   201,   202,    97,
     245,   204,    21,    23,   236,    15,    38,    26,    39,    35,
     244,    40,   136,    41,    56,    42,    58,    63,    43,    69,
      44,    45,   221,    82,    36,    85,    84,    86,   107,   106,
      37,   137,   140,   117,   183,   148,   145,   146,   217,   229,
     150,    92,    36,   231,   232,   147,   228,   151,    37,   152,
     153,   154,   160,   187,   230,   182,    28,    29,    30,    31,
      32,   186,    17,   194,    33,    15,   233,   188,    39,   195,
     208,    40,   248,    41,    92,    42,    36,   203,    43,   212,
      44,    45,    37,    15,   213,    92,    39,    92,   242,    40,
     135,    41,   219,    42,    36,    92,    43,   224,    44,    45,
      37,   225,   227,   234,   235,    36,   243,   200,     9,    57,
     190,    37,   247,   197,    99,   226,   215,    15,     0,     0,
      39,     0,     0,    40,     0,    41,     0,    42,     0,     0,
      43,     0,    44,    45,     0,    15,     0,     0,    39,     0,
       0,    40,     0,    41,     0,    42,    15,     0,    43,    39,
      44,    45,    40,     0,    41,     0,    42,     0,     0,    43,
       0,    44,    45,    87,    28,    29,    30,    31,    32,     0,
      88,     0,    33,    70,    28,    29,    30,    31,    32,     0,
       0,    71,    33,     0,     0,     0,     0,     0,    72,    89,
     121,   122,   123,   124,   125,   126,     0,     0,     0,    73,
       0,     0,    90,    91,     0,    74,    87,    28,    29,    30,
      31,    32,     0,    88,     0,    33,    28,    29,    30,    31,
      32,   241,     0,   164,    33,     0,   121,   122,   123,   124,
     125,   126,    89,     0,    28,    29,    30,    31,    32,     0,
       0,   216,    33,   157,   121,   122,   123,   124,   125,   126,
     206,   121,   122,   123,   124,   125,   126,   121,   122,   123,
     124,   125,   126,   165,   166,   167,   168,   169,   170
};

static const yytype_int16 yycheck[] =
{
      20,    40,     9,    98,    90,     3,   145,    73,    74,    15,
       3,    36,    39,    19,    41,    35,    43,    16,    17,    85,
       3,     4,     5,     6,     7,     8,   128,   129,   130,    12,
      22,    23,    24,    25,    26,    27,    56,    37,    38,    13,
      67,    68,    69,     3,    18,    72,    20,    45,    41,     0,
      22,    23,    24,    25,    26,    27,   142,    30,    31,    32,
      39,    34,    45,    55,    56,   131,   132,   133,   134,    89,
      28,    29,    46,     3,    16,    33,    15,    19,    98,    22,
      23,    24,    25,    26,    27,   224,    58,    16,   127,   116,
      19,   115,    16,   117,     3,    19,   191,   136,   237,    16,
       9,    13,    19,    16,    17,    48,   245,    44,   135,   195,
     137,    22,    23,    24,    25,    26,    27,    13,   138,    16,
      17,    40,    18,    22,    20,   145,   146,   154,   155,    16,
      17,   158,     3,     3,   220,    44,    45,    41,    47,    22,
     235,    50,    53,    52,    22,    54,     3,    15,    57,    18,
      59,    60,   238,     3,     3,    18,     4,    15,     3,    15,
       9,    46,    14,    18,   184,     3,    20,    14,   188,   208,
       3,   191,     3,   212,   213,    15,   203,     3,     9,    15,
      15,    46,     3,     3,   211,     3,     4,     5,     6,     7,
       8,    19,   199,    15,    12,    44,   216,    14,    47,    18,
      49,    50,   241,    52,   224,    54,     3,    46,    57,    17,
      59,    60,     9,    44,    17,   235,    47,   237,    15,    50,
      51,    52,    21,    54,     3,   245,    57,    17,    59,    60,
       9,    15,    15,    15,    58,     3,    15,   153,     4,    24,
     142,     9,   238,   151,    60,   199,   184,    44,    -1,    -1,
      47,    -1,    -1,    50,    -1,    52,    -1,    54,    -1,    -1,
      57,    -1,    59,    60,    -1,    44,    -1,    -1,    47,    -1,
      -1,    50,    -1,    52,    -1,    54,    44,    -1,    57,    47,
      59,    60,    50,    -1,    52,    -1,    54,    -1,    -1,    57,
      -1,    59,    60,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    18,    29,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    29,
      -1,    -1,    42,    43,    -1,    35,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    12,     4,     5,     6,     7,
       8,    53,    -1,    19,    12,    -1,    22,    23,    24,    25,
      26,    27,    29,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    29,    12,    21,    22,    23,    24,    25,    26,    27,
      21,    22,    23,    24,    25,    26,    27,    22,    23,    24,
      25,    26,    27,   121,   122,   123,   124,   125,   126
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    62,    63,    64,     3,     0,    39,    65,    67,
      68,    15,     3,    69,    13,    44,    92,    93,    40,    71,
      22,     3,    94,     3,    72,    73,    41,    81,     4,     5,
       6,     7,     8,    12,    70,    22,     3,     9,    45,    47,
      50,    52,    54,    57,    59,    60,    93,    95,    96,    97,
      98,    99,   100,   101,   103,   106,    22,    73,     3,    80,
      82,    83,    84,    15,    70,    13,    18,    20,    46,    18,
       3,    11,    18,    29,    35,    70,   108,   109,   110,   111,
      94,   108,     3,   108,     4,    18,    15,     3,    10,    29,
      42,    43,    70,    74,    75,    76,    77,    16,    17,    83,
      37,    38,    85,    86,    87,    88,    15,     3,   108,   112,
     108,   108,   107,   108,    13,    18,    20,    18,   108,   111,
     111,    22,    23,    24,    25,    26,    27,    48,    28,    29,
      33,    30,    31,    32,    34,    51,    53,    46,    58,   111,
      14,    70,    78,    79,    80,    20,    14,    15,     3,    74,
       3,     3,    15,    15,    46,    16,    19,    21,    16,    19,
       3,   112,   108,   112,    19,   109,   109,   109,   109,   109,
     109,    94,   110,   110,   110,   111,   111,   111,   111,   108,
      94,   108,     3,    70,   104,   105,    19,     3,    14,    45,
      79,    17,    75,    70,    15,    18,    89,    89,    66,    67,
      66,   108,   108,    46,   108,    19,    21,    19,    49,    55,
      56,   102,    17,    17,    45,   105,    29,    70,    74,    21,
      41,    80,    90,    91,    17,    15,    92,    15,   108,    94,
     108,    94,    94,    70,    15,    58,    80,    17,    15,    19,
      75,    53,    15,    15,    74,    17,    75,    91,    94,    75
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
#line 111 "pascal.y"
                          { 
                    root = (yyvsp[0].astProgram);
                }
#line 1547 "parser.cpp"
    break;

  case 3:
#line 114 "pascal.y"
                                             { 
                    (yyval.astProgram) = new ast::Program((yyvsp[-2].astProgramHead), (yyvsp[-1].astRoutine)); 
                    (yyval.astProgram)->printAstNode();
                }
#line 1556 "parser.cpp"
    break;

  case 4:
#line 120 "pascal.y"
                                    { 
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), new ast::ParamList(), new ast::VoidType()); 
                }
#line 1564 "parser.cpp"
    break;

  case 5:
#line 125 "pascal.y"
                                             { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1572 "parser.cpp"
    break;

  case 6:
#line 130 "pascal.y"
                                             { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1580 "parser.cpp"
    break;

  case 7:
#line 135 "pascal.y"
                                                                { 
                    (yyval.astRoutineHead) = new ast::RoutineHead((yyvsp[-3].astConstDeclList), (yyvsp[-2].astTypeDeclList), (yyvsp[-1].astVarDeclList), (yyvsp[0].astRoutinePartList)); 
                }
#line 1588 "parser.cpp"
    break;

  case 8:
#line 140 "pascal.y"
                                         { 
                    (yyval.astConstDeclList) = (yyvsp[0].astConstDeclList); 
                }
#line 1596 "parser.cpp"
    break;

  case 9:
#line 143 "pascal.y"
                  { 
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                }
#line 1604 "parser.cpp"
    break;

  case 10:
#line 148 "pascal.y"
                                                                { 
                    (yyval.astConstDeclList) = (yyvsp[-4].astConstDeclList);
                    (yyvsp[-4].astConstDeclList)->push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1613 "parser.cpp"
    break;

  case 11:
#line 152 "pascal.y"
                                                {
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                    (yyval.astConstDeclList)->push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1622 "parser.cpp"
    break;

  case 12:
#line 158 "pascal.y"
                            {(yyval.astBasicConst) = new ast::IntegerNode((yyvsp[0].astint)); /*需不需要atoi呢， 注意这里还有一些问题*/}
#line 1628 "parser.cpp"
    break;

  case 13:
#line 159 "pascal.y"
                            {(yyval.astBasicConst) = new ast::RealNode((yyvsp[0].astreal));}
#line 1634 "parser.cpp"
    break;

  case 14:
#line 160 "pascal.y"
                            {(yyval.astBasicConst) = new ast::CharNode((yyvsp[0].astchar));}
#line 1640 "parser.cpp"
    break;

  case 15:
#line 161 "pascal.y"
                            {(yyval.astBasicConst) = new ast::StringNode((yyvsp[0].aststring));}
#line 1646 "parser.cpp"
    break;

  case 16:
#line 162 "pascal.y"
                            {(yyval.astBasicConst) = new ast::BooleanNode((yyvsp[0].astbool));}
#line 1652 "parser.cpp"
    break;

  case 17:
#line 163 "pascal.y"
                            {(yyval.astBasicConst) = new ast::MaxIntNode();}
#line 1658 "parser.cpp"
    break;

  case 18:
#line 166 "pascal.y"
                                       { (yyval.astTypeDeclList) = (yyvsp[0].astTypeDeclList); }
#line 1664 "parser.cpp"
    break;

  case 19:
#line 167 "pascal.y"
                    { 
                    (yyval.astTypeDeclList) = new ast::TypeDeclList(); 
                }
#line 1672 "parser.cpp"
    break;

  case 20:
#line 172 "pascal.y"
                                                  { 
                    (yyval.astTypeDeclList) = (yyvsp[-1].astTypeDeclList);
                    (yyvsp[-1].astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1681 "parser.cpp"
    break;

  case 21:
#line 176 "pascal.y"
                                   {
                    (yyval.astTypeDeclList) = new ast::TypeDeclList();
                    (yyval.astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1690 "parser.cpp"
    break;

  case 22:
#line 182 "pascal.y"
                                             { 
                    (yyval.astTypeDecl) = new ast::TypeDecl(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicType)); 
                }
#line 1698 "parser.cpp"
    break;

  case 23:
#line 187 "pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1704 "parser.cpp"
    break;

  case 24:
#line 188 "pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1710 "parser.cpp"
    break;

  case 25:
#line 189 "pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1716 "parser.cpp"
    break;

  case 26:
#line 192 "pascal.y"
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
#line 1734 "parser.cpp"
    break;

  case 27:
#line 211 "pascal.y"
                                                    { 
                    (yyval.astBasicType) = new ast::RangeType((yyvsp[-2].astBasicConst), (yyvsp[0].astBasicConst)); 
                }
#line 1742 "parser.cpp"
    break;

  case 28:
#line 214 "pascal.y"
                                                           { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-2].astBasicConst)), (yyvsp[0].astBasicConst)); 
                }
#line 1750 "parser.cpp"
    break;

  case 29:
#line 217 "pascal.y"
                                                                  { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-3].astBasicConst)), new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astBasicConst))); 
                }
#line 1758 "parser.cpp"
    break;

  case 30:
#line 220 "pascal.y"
                                  {
                    (yyval.astBasicType) = new ast::RangeType((ast::Expression*)(new ast::Identifier((yyvsp[-2].aststring))), (ast::Expression*)(new ast::Identifier((yyvsp[0].aststring))));
                }
#line 1766 "parser.cpp"
    break;

  case 31:
#line 226 "pascal.y"
                                                                 { 
                    (yyval.astBasicType) = new ast::ArrayType((yyvsp[-3].astBasicType), (yyvsp[0].astBasicType)); 
                }
#line 1774 "parser.cpp"
    break;

  case 32:
#line 231 "pascal.y"
                                               { 
                    (yyval.astBasicType) = new ast::RecordType((yyvsp[-1].astVarDeclList)); 
                }
#line 1782 "parser.cpp"
    break;

  case 33:
#line 236 "pascal.y"
                                              { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());;
                }
#line 1791 "parser.cpp"
    break;

  case 34:
#line 240 "pascal.y"
                              {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 1799 "parser.cpp"
    break;

  case 35:
#line 245 "pascal.y"
                                                    {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 1809 "parser.cpp"
    break;

  case 36:
#line 251 "pascal.y"
                                       {
                    (yyval.astNameList) = (yyvsp[-2].astNameList);
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1818 "parser.cpp"
    break;

  case 37:
#line 255 "pascal.y"
                      {
                    (yyval.astNameList) = new ast::NameList;
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1827 "parser.cpp"
    break;

  case 38:
#line 260 "pascal.y"
                                     { (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList); }
#line 1833 "parser.cpp"
    break;

  case 39:
#line 261 "pascal.y"
                  { (yyval.astVarDeclList) = new ast::VarDeclList(); }
#line 1839 "parser.cpp"
    break;

  case 40:
#line 264 "pascal.y"
                                           { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());
                }
#line 1848 "parser.cpp"
    break;

  case 41:
#line 268 "pascal.y"
                            {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 1856 "parser.cpp"
    break;

  case 42:
#line 273 "pascal.y"
                                                     {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 1866 "parser.cpp"
    break;

  case 43:
#line 280 "pascal.y"
                                               {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 1875 "parser.cpp"
    break;

  case 44:
#line 284 "pascal.y"
                                                {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 1884 "parser.cpp"
    break;

  case 45:
#line 288 "pascal.y"
                    { (yyval.astRoutinePartList) = new ast::RoutinePartList(); }
#line 1890 "parser.cpp"
    break;

  case 46:
#line 291 "pascal.y"
                                                         {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 1898 "parser.cpp"
    break;

  case 47:
#line 295 "pascal.y"
                                                                     {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-2].astParamList), (yyvsp[0].astBasicType));
                }
#line 1906 "parser.cpp"
    break;

  case 48:
#line 299 "pascal.y"
                                                           {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 1914 "parser.cpp"
    break;

  case 49:
#line 304 "pascal.y"
                                           {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), (yyvsp[0].astParamList), new ast::VoidType()); 
                }
#line 1922 "parser.cpp"
    break;

  case 50:
#line 309 "pascal.y"
                                     {
                    (yyval.astParamList) = (yyvsp[-1].astParamList);
                }
#line 1930 "parser.cpp"
    break;

  case 51:
#line 312 "pascal.y"
                   {
                    (yyval.astParamList) = new ast::ParamList();
                }
#line 1938 "parser.cpp"
    break;

  case 52:
#line 316 "pascal.y"
                                                       {
                    (yyval.astParamList) = (yyvsp[-2].astParamList);
                    (yyvsp[-2].astParamList)->insert((yyvsp[-2].astParamList)->end(), (yyvsp[0].astParamList)->begin(), (yyvsp[0].astParamList)->end());
                }
#line 1947 "parser.cpp"
    break;

  case 53:
#line 320 "pascal.y"
                                 {
                    (yyval.astParamList) = (yyvsp[0].astParamList);
                }
#line 1955 "parser.cpp"
    break;

  case 54:
#line 326 "pascal.y"
                                                         {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 1965 "parser.cpp"
    break;

  case 55:
#line 331 "pascal.y"
                                                     {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 1975 "parser.cpp"
    break;

  case 56:
#line 340 "pascal.y"
                                {
                    (yyval.astStmtList) = (yyvsp[0].astStmtList);
                }
#line 1983 "parser.cpp"
    break;

  case 57:
#line 344 "pascal.y"
                                      {
                    (yyval.astStmtList) = (yyvsp[-1].astStmtList);
                }
#line 1991 "parser.cpp"
    break;

  case 58:
#line 349 "pascal.y"
                                        {
                    (yyval.astStmtList) = (yyvsp[-2].astStmtList);
                    (yyval.astStmtList)->push_back((yyvsp[-1].astStmt));
                }
#line 2000 "parser.cpp"
    break;

  case 59:
#line 353 "pascal.y"
                   {
                    (yyval.astStmtList) = new ast::StmtList();
                }
#line 2008 "parser.cpp"
    break;

  case 60:
#line 367 "pascal.y"
                              {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2016 "parser.cpp"
    break;

  case 61:
#line 370 "pascal.y"
                            {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2024 "parser.cpp"
    break;

  case 62:
#line 373 "pascal.y"
                                {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmtList);
                }
#line 2032 "parser.cpp"
    break;

  case 63:
#line 376 "pascal.y"
                          {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2040 "parser.cpp"
    break;

  case 64:
#line 379 "pascal.y"
                              {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2048 "parser.cpp"
    break;

  case 65:
#line 382 "pascal.y"
                             {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2056 "parser.cpp"
    break;

  case 66:
#line 385 "pascal.y"
                           {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2064 "parser.cpp"
    break;

  case 67:
#line 388 "pascal.y"
                            {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2072 "parser.cpp"
    break;

  case 68:
#line 391 "pascal.y"
                           {
                    (yyval.astStmt) = (ast::Stmt*)(yyvsp[0].astStmt);
                }
#line 2080 "parser.cpp"
    break;

  case 69:
#line 396 "pascal.y"
                                         {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::Identifier((yyvsp[-2].aststring)), (yyvsp[0].astExpression));
                }
#line 2088 "parser.cpp"
    break;

  case 70:
#line 399 "pascal.y"
                                                        {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::ArrayElementRef(new ast::Identifier((yyvsp[-5].aststring)), (yyvsp[-3].astExpression)), (yyvsp[0].astExpression));
                }
#line 2096 "parser.cpp"
    break;

  case 71:
#line 402 "pascal.y"
                                                  {
                    (yyval.astStmt) = new ast::AssignStmt(new ast::RecordElementRef(new ast::Identifier((yyvsp[-4].aststring)), new ast::Identifier((yyvsp[-2].aststring))), (yyvsp[0].astExpression));
                }
#line 2104 "parser.cpp"
    break;

  case 72:
#line 407 "pascal.y"
                      {
                    (yyval.astStmt) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 2112 "parser.cpp"
    break;

  case 73:
#line 410 "pascal.y"
                                      {
                    (yyval.astStmt) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2120 "parser.cpp"
    break;

  case 74:
#line 413 "pascal.y"
                            {
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE);
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN);
                }
#line 2131 "parser.cpp"
    break;

  case 75:
#line 419 "pascal.y"
                                                     {
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE, (yyvsp[-1].astExpressionList));
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN, (yyvsp[-1].astExpressionList));
                }
#line 2142 "parser.cpp"
    break;

  case 76:
#line 425 "pascal.y"
                                        {
                    (yyval.astStmt) = new ast::ReadProcCall((yyvsp[-1].astExpression));
                }
#line 2150 "parser.cpp"
    break;

  case 77:
#line 429 "pascal.y"
                                                                  {
                    (yyval.astStmt) = new ast::IfStmt((yyvsp[-4].astExpression), (yyvsp[-2].astStmtList), (yyvsp[0].astStmtList));
                }
#line 2158 "parser.cpp"
    break;

  case 78:
#line 432 "pascal.y"
                                                  {
                    (yyval.astStmt) = new ast::IfStmt((yyvsp[-2].astExpression), (yyvsp[0].astStmtList));
                }
#line 2166 "parser.cpp"
    break;

  case 79:
#line 444 "pascal.y"
                                                       {
                    (yyval.astStmt) = new ast::RepeatStmt((yyvsp[0].astExpression), (yyvsp[-2].astStmtList));
                }
#line 2174 "parser.cpp"
    break;

  case 80:
#line 449 "pascal.y"
                                                  {
                    (yyval.astStmt) = new ast::WhileStmt((yyvsp[-2].astExpression), (yyvsp[0].astStmtList));
                }
#line 2182 "parser.cpp"
    break;

  case 81:
#line 453 "pascal.y"
                                                                                   {
                    (yyval.astStmt) = new ast::ForStmt(new ast::Identifier((yyvsp[-6].aststring)), (yyvsp[-4].astExpression), (yyvsp[-3].astDirection), (yyvsp[-2].astExpression), (yyvsp[0].astStmtList));
                }
#line 2190 "parser.cpp"
    break;

  case 82:
#line 457 "pascal.y"
                     {
                    (yyval.astDirection) = ast::Direction::To;
                }
#line 2198 "parser.cpp"
    break;

  case 83:
#line 460 "pascal.y"
                         {
                    (yyval.astDirection) = ast::Direction::DownTo;
                }
#line 2206 "parser.cpp"
    break;

  case 84:
#line 465 "pascal.y"
                                                         {
                    (yyval.astStmt) = new ast::CaseStmt((yyvsp[-3].astExpression), (yyvsp[-1].astCaseExprList));
                }
#line 2214 "parser.cpp"
    break;

  case 85:
#line 470 "pascal.y"
                                             {
                    (yyval.astCaseExprList) = (yyvsp[-1].astCaseExprList);
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2223 "parser.cpp"
    break;

  case 86:
#line 474 "pascal.y"
                             {
                    (yyval.astCaseExprList) = new ast::CaseExprList();
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2232 "parser.cpp"
    break;

  case 87:
#line 480 "pascal.y"
                                                      {
                    (yyval.astCaseExpr) = new ast::CaseExpr((yyvsp[-3].astBasicConst), (yyvsp[-1].astStmtList));
                }
#line 2240 "parser.cpp"
    break;

  case 88:
#line 483 "pascal.y"
                                              {
                    (yyval.astCaseExpr) = new ast::CaseExpr(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astStmtList));
                }
#line 2248 "parser.cpp"
    break;

  case 89:
#line 488 "pascal.y"
                                {
                    (yyval.astStmt) = new ast::GotoStmt((yyvsp[0].astint));
                }
#line 2256 "parser.cpp"
    break;

  case 90:
#line 492 "pascal.y"
                                                      {
                    (yyval.astExpressionList) = (yyvsp[-2].astExpressionList);
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2265 "parser.cpp"
    break;

  case 91:
#line 496 "pascal.y"
                              {
                    (yyval.astExpressionList) = new ast::ExpressionList();
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2274 "parser.cpp"
    break;

  case 92:
#line 502 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GEop, (yyvsp[0].astExpression));
                }
#line 2282 "parser.cpp"
    break;

  case 93:
#line 505 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GTop, (yyvsp[0].astExpression));
                }
#line 2290 "parser.cpp"
    break;

  case 94:
#line 508 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LEop, (yyvsp[0].astExpression));
                }
#line 2298 "parser.cpp"
    break;

  case 95:
#line 511 "pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LTop, (yyvsp[0].astExpression));
                }
#line 2306 "parser.cpp"
    break;

  case 96:
#line 514 "pascal.y"
                                           {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::EQUALop, (yyvsp[0].astExpression));
                }
#line 2314 "parser.cpp"
    break;

  case 97:
#line 517 "pascal.y"
                                             {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::UNEQUALop, (yyvsp[0].astExpression));
                }
#line 2322 "parser.cpp"
    break;

  case 98:
#line 520 "pascal.y"
                        {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2330 "parser.cpp"
    break;

  case 99:
#line 524 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::PLUSop, (yyvsp[0].astExpression));
                }
#line 2338 "parser.cpp"
    break;

  case 100:
#line 527 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MINUSop, (yyvsp[0].astExpression));
                }
#line 2346 "parser.cpp"
    break;

  case 101:
#line 530 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ORop, (yyvsp[0].astExpression));
                }
#line 2354 "parser.cpp"
    break;

  case 102:
#line 533 "pascal.y"
                        {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2362 "parser.cpp"
    break;

  case 103:
#line 538 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MULop, (yyvsp[0].astExpression));
                }
#line 2370 "parser.cpp"
    break;

  case 104:
#line 541 "pascal.y"
                                      {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::DIVop, (yyvsp[0].astExpression));
                }
#line 2378 "parser.cpp"
    break;

  case 105:
#line 544 "pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MODop, (yyvsp[0].astExpression));
                }
#line 2386 "parser.cpp"
    break;

  case 106:
#line 547 "pascal.y"
                                      {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ANDop, (yyvsp[0].astExpression));
                }
#line 2394 "parser.cpp"
    break;

  case 107:
#line 550 "pascal.y"
                          {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2402 "parser.cpp"
    break;

  case 108:
#line 555 "pascal.y"
                      {
                    (yyval.astExpression) = new ast::Identifier((yyvsp[0].aststring));
                }
#line 2410 "parser.cpp"
    break;

  case 109:
#line 558 "pascal.y"
                                          {
                    (yyval.astExpression) = new ast::UserDefProcCall(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2418 "parser.cpp"
    break;

  case 110:
#line 561 "pascal.y"
                             {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[0].astSYSFUNCT));
                }
#line 2426 "parser.cpp"
    break;

  case 111:
#line 564 "pascal.y"
                                                 {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[-3].astSYSFUNCT), (yyvsp[-1].astArgList));
                }
#line 2434 "parser.cpp"
    break;

  case 112:
#line 567 "pascal.y"
                                {
                    (yyval.astExpression) = (yyvsp[0].astBasicConst);
                }
#line 2442 "parser.cpp"
    break;

  case 113:
#line 570 "pascal.y"
                                      {
                    (yyval.astExpression) = (yyvsp[-1].astExpression);
                }
#line 2450 "parser.cpp"
    break;

  case 114:
#line 573 "pascal.y"
                                {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NOTop, (yyvsp[0].astExpression));
                }
#line 2458 "parser.cpp"
    break;

  case 115:
#line 576 "pascal.y"
                                 {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astExpression));
                }
#line 2466 "parser.cpp"
    break;

  case 116:
#line 579 "pascal.y"
                                          {
                    (yyval.astExpression) = new ast::ArrayElementRef(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astExpression));
                }
#line 2474 "parser.cpp"
    break;

  case 117:
#line 582 "pascal.y"
                               {
                    (yyval.astExpression) = new ast::RecordElementRef(new ast::Identifier((yyvsp[-2].aststring)), new ast::Identifier((yyvsp[0].aststring)));
                }
#line 2482 "parser.cpp"
    break;

  case 118:
#line 586 "pascal.y"
                                                {
                    (yyval.astArgList) = (yyvsp[-2].astArgList);
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2491 "parser.cpp"
    break;

  case 119:
#line 590 "pascal.y"
                              {
                    (yyval.astArgList) = new ast::ArgList();
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2500 "parser.cpp"
    break;


#line 2504 "parser.cpp"

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

#line 596 "pascal.y"



void yyerror(string msg, ...) {
    cout << msg << endl;
}

static int yylex() {
	return get_token();
}

ast::BasicAstNode* parse(void)
{ 
    yyparse();
    return root;
}
