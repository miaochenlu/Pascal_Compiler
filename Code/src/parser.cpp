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
#line 2 "/Users/jones/desktop/group5/Code/src/pascal.y"

#include <iostream>
#include <vector>
#include <string>
#include "ast/ast.h"
#include "parser.hpp"

using namespace std;
static ast::BasicAstNode* root;
void yyerror(string msg, ...);
extern int yylex(void);
extern int lineno;


#line 86 "/Users/jones/desktop/group5/Code/src/parser.cpp"

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
#ifndef YY_YY_USERS_JONES_DESKTOP_GROUP5_CODE_SRC_PARSER_HPP_INCLUDED
# define YY_YY_USERS_JONES_DESKTOP_GROUP5_CODE_SRC_PARSER_HPP_INCLUDED
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
#line 17 "/Users/jones/desktop/group5/Code/src/pascal.y"

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

#line 238 "/Users/jones/desktop/group5/Code/src/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_USERS_JONES_DESKTOP_GROUP5_CODE_SRC_PARSER_HPP_INCLUDED  */
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
  YYSYMBOL_NAME = 69,                      /* NAME  */
  YYSYMBOL_const_expr_list = 70,           /* const_expr_list  */
  YYSYMBOL_const_value = 71,               /* const_value  */
  YYSYMBOL_type_part = 72,                 /* type_part  */
  YYSYMBOL_type_decl_list = 73,            /* type_decl_list  */
  YYSYMBOL_type_definition = 74,           /* type_definition  */
  YYSYMBOL_type_decl = 75,                 /* type_decl  */
  YYSYMBOL_simple_type_decl = 76,          /* simple_type_decl  */
  YYSYMBOL_array_type_decl = 77,           /* array_type_decl  */
  YYSYMBOL_record_type_decl = 78,          /* record_type_decl  */
  YYSYMBOL_field_decl_list = 79,           /* field_decl_list  */
  YYSYMBOL_field_decl = 80,                /* field_decl  */
  YYSYMBOL_name_list = 81,                 /* name_list  */
  YYSYMBOL_var_part = 82,                  /* var_part  */
  YYSYMBOL_var_decl_list = 83,             /* var_decl_list  */
  YYSYMBOL_var_decl = 84,                  /* var_decl  */
  YYSYMBOL_routine_part = 85,              /* routine_part  */
  YYSYMBOL_function_decl = 86,             /* function_decl  */
  YYSYMBOL_function_head = 87,             /* function_head  */
  YYSYMBOL_procedure_decl = 88,            /* procedure_decl  */
  YYSYMBOL_procedure_head = 89,            /* procedure_head  */
  YYSYMBOL_parameters = 90,                /* parameters  */
  YYSYMBOL_para_decl_list = 91,            /* para_decl_list  */
  YYSYMBOL_para_type_list = 92,            /* para_type_list  */
  YYSYMBOL_routine_body = 93,              /* routine_body  */
  YYSYMBOL_compound_stmt = 94,             /* compound_stmt  */
  YYSYMBOL_stmt_list = 95,                 /* stmt_list  */
  YYSYMBOL_stmt = 96,                      /* stmt  */
  YYSYMBOL_non_label_stmt = 97,            /* non_label_stmt  */
  YYSYMBOL_assign_stmt = 98,               /* assign_stmt  */
  YYSYMBOL_proc_stmt = 99,                 /* proc_stmt  */
  YYSYMBOL_if_stmt = 100,                  /* if_stmt  */
  YYSYMBOL_repeat_stmt = 101,              /* repeat_stmt  */
  YYSYMBOL_while_stmt = 102,               /* while_stmt  */
  YYSYMBOL_for_stmt = 103,                 /* for_stmt  */
  YYSYMBOL_direction = 104,                /* direction  */
  YYSYMBOL_case_stmt = 105,                /* case_stmt  */
  YYSYMBOL_case_expr_list = 106,           /* case_expr_list  */
  YYSYMBOL_case_expr = 107,                /* case_expr  */
  YYSYMBOL_goto_stmt = 108,                /* goto_stmt  */
  YYSYMBOL_expression_list = 109,          /* expression_list  */
  YYSYMBOL_expression = 110,               /* expression  */
  YYSYMBOL_expr = 111,                     /* expr  */
  YYSYMBOL_term = 112,                     /* term  */
  YYSYMBOL_factor = 113,                   /* factor  */
  YYSYMBOL_args_list = 114                 /* args_list  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   463

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  312

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
       0,   109,   109,   112,   117,   120,   124,   130,   133,   139,
     142,   147,   152,   155,   160,   165,   169,   174,   178,   185,
     186,   187,   188,   189,   190,   191,   192,   195,   196,   201,
     205,   211,   214,   220,   221,   222,   225,   238,   244,   247,
     250,   253,   259,   264,   267,   273,   277,   282,   287,   295,
     299,   304,   305,   308,   312,   317,   322,   330,   334,   338,
     341,   344,   349,   353,   356,   362,   367,   370,   374,   378,
     384,   389,   398,   402,   405,   411,   415,   420,   426,   429,
     434,   437,   440,   443,   446,   449,   452,   455,   458,   463,
     466,   469,   474,   477,   480,   486,   492,   496,   499,   503,
     506,   519,   522,   528,   531,   536,   539,   544,   547,   552,
     555,   561,   565,   571,   574,   578,   581,   587,   591,   595,
     601,   604,   607,   610,   613,   616,   619,   623,   626,   629,
     632,   637,   640,   643,   646,   649,   654,   657,   660,   663,
     666,   669,   672,   675,   678,   681,   685,   689
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

#define YYPACT_NINF (-172)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,   -28,    14,    30,  -172,     5,    59,    88,  -172,    67,
      65,    20,    48,    84,    96,  -172,  -172,    95,    67,  -172,
     100,  -172,  -172,  -172,    67,    87,  -172,  -172,   390,   117,
    -172,   133,   140,    67,  -172,   161,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,    89,    90,   390,   139,    29,   185,   186,
    -172,   328,  -172,   328,   207,   328,   209,   197,   202,  -172,
      94,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
     301,  -172,  -172,   153,   161,  -172,   151,  -172,  -172,   210,
    -172,    99,  -172,   219,   328,   328,   188,   328,   110,   208,
     328,   347,   328,   216,  -172,    12,   112,   199,  -172,    22,
     257,   193,   266,  -172,   328,   328,   213,  -172,  -172,   399,
     161,   226,   222,   235,   103,  -172,  -172,  -172,   247,   301,
    -172,   249,   251,  -172,   240,  -172,   241,  -172,   242,  -172,
     214,   417,   430,  -172,   136,   430,   259,   328,   328,   407,
    -172,  -172,  -172,  -172,   328,   215,   328,   328,   328,   328,
     328,   328,   164,   328,   328,   328,   328,   328,   328,   328,
     218,   328,   211,   164,   328,   381,   246,   430,   137,  -172,
     252,    26,  -172,   158,   363,    67,   390,   256,  -172,  -172,
     105,   254,   254,     5,     5,  -172,   328,   227,   328,  -172,
    -172,   424,   144,  -172,   160,   164,   112,   112,   112,   112,
     112,   112,   225,   199,   199,   199,  -172,  -172,  -172,  -172,
     328,   430,   164,  -172,   292,   258,   268,    51,  -172,  -172,
     328,  -172,   408,   250,  -172,  -172,   301,   275,  -172,  -172,
    -172,   297,  -172,     2,  -172,   303,   111,    39,   114,   430,
     328,   430,  -172,  -172,  -172,   272,   164,   430,  -172,  -172,
    -172,   328,   164,   164,   277,  -172,  -172,   430,   399,  -172,
    -172,   118,   265,  -172,   161,   182,   131,  -172,   363,   310,
    -172,   100,  -172,   311,  -172,   430,   164,  -172,   276,   120,
     123,  -172,  -172,   313,  -172,   301,   190,   363,     2,  -172,
    -172,  -172,  -172,  -172,  -172,   274,   164,   322,  -172,   323,
    -172,  -172,  -172,   363,  -172,  -172,   164,  -172,  -172,  -172,
    -172,  -172
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,    13,     0,     0,     1,     0,
       0,     0,    28,     0,     0,     4,    14,     0,    12,     3,
       0,    77,     7,    72,     0,    52,     6,     5,     0,     0,
       8,     0,     0,    27,    30,     0,    59,    19,    21,    23,
      24,    25,    26,     0,     0,     0,     0,    14,     0,    94,
      73,     0,    77,     0,     0,     0,     0,     0,    92,    82,
       0,    79,    80,    81,    83,    84,    85,    86,    87,    88,
       0,    29,    50,     0,    51,    54,    11,    20,    22,     0,
      17,     0,    74,     0,     0,     0,     0,     0,    14,   138,
       0,     0,     0,   136,   140,     0,   126,   130,   135,     0,
       0,     0,     0,   117,     0,     0,     0,    75,    36,     0,
       0,     0,    37,     0,     0,    33,    34,    35,     0,     0,
      53,     0,     0,    57,     0,    58,     0,    18,     0,    15,
       0,     0,    89,    78,     0,   119,     0,     0,     0,     0,
      19,    21,   143,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,     0,    76,
       0,     0,    46,     0,     0,     0,     0,     0,    31,    49,
       0,    67,    67,    13,    13,    16,     0,     0,     0,    95,
     145,     0,     0,   141,     0,     0,   124,   125,   120,   121,
     122,   123,    99,   127,   128,   129,   131,   132,   133,   134,
       0,   101,     0,   103,     0,     0,     0,     0,   112,    96,
       0,    93,     0,     0,    43,    45,     0,     0,    41,    38,
      32,     0,    55,     0,    65,     0,     0,     0,     0,    91,
       0,   118,   144,   139,   137,   100,     0,   102,   104,   107,
     108,     0,     0,     0,     0,   109,   111,   146,     0,    39,
      44,     0,     0,    56,     0,     0,     0,    69,     0,     0,
      60,     0,     9,     0,    63,    90,     0,    97,     0,     0,
       0,   110,    40,     0,    47,     0,     0,     0,     0,    66,
      62,    61,    10,    64,    98,     0,     0,     0,   115,     0,
     113,    48,    42,     0,    71,    68,     0,   105,   116,   114,
      70,   106
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -172,  -172,  -172,   157,   337,  -172,    -9,  -172,
     -17,  -172,  -172,   316,  -113,  -171,  -172,  -172,  -172,   174,
    -106,  -172,  -172,   282,  -172,  -172,  -172,  -172,  -172,   178,
    -172,    73,   -18,   -10,   320,  -145,   278,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,   145,  -172,  -172,   -39,
     312,    41,   -72,   -97
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    10,   236,   237,    12,    93,    18,
      94,    25,    33,    34,   114,   115,   116,   117,   171,   172,
      73,    36,    74,    75,    76,   123,   124,   125,   126,   234,
     266,   267,    22,    59,    31,    60,    61,    62,    63,    64,
      65,    66,    67,   251,    68,   217,   218,    69,   134,   167,
      96,    97,    98,   168
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    23,    30,   227,   173,    72,   180,   202,     6,    29,
      23,    44,    95,   145,   100,    32,   102,     7,   213,   142,
     143,    20,    58,   160,    32,    47,    48,   223,    81,    72,
       8,    49,   166,     1,   146,   147,   148,   149,   150,   151,
     271,   192,    83,   264,     9,   131,   132,   194,   135,    84,
     245,   139,   254,   113,   215,    37,    38,    39,    40,    41,
     152,   112,    13,    42,    21,   173,    21,   248,     2,    51,
      16,   224,    52,   161,    53,    85,    54,    58,    19,    55,
      43,    56,    57,    21,   206,   207,   208,   209,    24,    14,
      58,    79,   170,    77,    78,   106,   255,   290,   191,    26,
     128,   277,   113,    15,   177,    80,   231,   279,   280,   107,
     112,    27,   269,   261,   129,   273,   304,    28,   178,   283,
     232,   297,   211,   136,   299,   214,   270,   265,    35,   274,
     137,   294,   310,   284,    46,   298,    47,    48,   300,    45,
     153,   154,    49,    58,    21,   155,   288,   239,   216,   241,
     289,   307,   188,   220,    58,   189,   221,   113,   286,   229,
     220,   311,    70,   243,    72,   112,   228,    47,    48,   118,
     119,   247,   302,    49,   118,   226,   220,    21,    50,   244,
      51,   257,   265,    52,    82,    53,    58,    54,   121,   122,
      55,    47,    56,    57,   203,   204,   205,    49,   118,   287,
     216,   275,    86,    58,    87,   259,   118,   303,    21,   113,
     101,    51,   278,   103,    52,   104,    53,   112,    54,   272,
     105,    55,   130,    56,    57,   127,   138,    23,   169,   156,
     157,   158,    21,   159,   144,    51,   175,    58,    52,   164,
      53,   282,    54,    58,    58,    55,   174,    56,    57,   176,
     179,   113,   181,   292,   182,   183,   184,   185,   162,   112,
     186,    23,   190,   195,   212,   219,   222,    58,   113,   210,
     113,   230,   233,   240,   246,   252,   112,   295,   112,   146,
     147,   148,   149,   150,   151,   253,   113,    58,   146,   147,
     148,   149,   150,   151,   112,   260,   262,    58,   146,   147,
     148,   149,   150,   151,    16,    37,    38,    39,    40,    41,
     163,   108,   263,    42,   146,   147,   148,   149,   150,   151,
     268,   276,   281,   285,   165,   291,   293,   306,   301,   296,
     109,    88,    37,    38,    39,    40,    41,   308,   309,    89,
      42,   238,    11,   110,   111,   225,    90,   249,   250,    71,
      88,   140,   141,    39,    40,    41,   120,    91,    89,    42,
     235,   305,   256,    92,   133,    90,    16,    37,    38,    39,
      40,    41,    99,   108,     0,    42,    91,     0,     0,     0,
       0,     0,    92,     0,   215,    37,    38,    39,    40,    41,
       0,     0,   109,    42,    37,    38,    39,    40,    41,     0,
       0,     0,    42,   140,   141,    39,    40,    41,     0,     0,
      43,    42,    37,    38,    39,    40,    41,     0,     0,    43,
      42,     0,     0,     0,     0,     0,   193,     0,    43,   146,
     147,   148,   149,   150,   151,     0,     0,   258,   187,   146,
     147,   148,   149,   150,   151,   242,   146,   147,   148,   149,
     150,   151,   146,   147,   148,   149,   150,   151,   196,   197,
     198,   199,   200,   201
};

static const yytype_int16 yycheck[] =
{
       9,    11,    20,   174,   110,     3,   119,   152,    36,    18,
      20,    28,    51,     1,    53,    24,    55,     3,   163,    91,
      92,     1,    31,     1,    33,     3,     4,     1,    45,     3,
       0,     9,   104,     1,    22,    23,    24,    25,    26,    27,
       1,   138,    13,    41,    39,    84,    85,   144,    87,    20,
     195,    90,     1,    70,     3,     4,     5,     6,     7,     8,
      48,    70,     3,    12,    44,   171,    44,   212,    36,    47,
       3,    45,    50,    51,    52,    46,    54,    86,    13,    57,
      29,    59,    60,    44,   156,   157,   158,   159,    40,     1,
      99,     1,   109,     4,     5,     1,    45,   268,   137,    15,
       1,   246,   119,    15,     1,    15,     1,   252,   253,    15,
     119,    15,     1,   226,    15,     1,   287,    22,    15,     1,
      15,     1,   161,    13,     1,   164,    15,   233,    41,    15,
      20,   276,   303,    15,     1,    15,     3,     4,    15,    22,
      28,    29,     9,   152,    44,    33,    15,   186,   165,   188,
      19,   296,    16,    16,   163,    19,    19,   174,   264,   176,
      16,   306,    22,    19,     3,   174,   175,     3,     4,    16,
      17,   210,   285,     9,    16,    17,    16,    44,    45,    19,
      47,   220,   288,    50,    45,    52,   195,    54,    37,    38,
      57,     3,    59,    60,   153,   154,   155,     9,    16,    17,
     217,   240,    17,   212,    18,   222,    16,    17,    44,   226,
       3,    47,   251,     4,    50,    18,    52,   226,    54,   237,
      18,    57,     3,    59,    60,    15,    18,   237,    15,    30,
      31,    32,    44,    34,    18,    47,    14,   246,    50,    46,
      52,   258,    54,   252,   253,    57,    20,    59,    60,    14,
       3,   268,     3,   271,     3,    15,    15,    15,     1,   268,
      46,   271,     3,    48,    53,    19,    14,   276,   285,    51,
     287,    15,    18,    46,    49,    17,   285,     1,   287,    22,
      23,    24,    25,    26,    27,    17,   303,   296,    22,    23,
      24,    25,    26,    27,   303,    45,    21,   306,    22,    23,
      24,    25,    26,    27,     3,     4,     5,     6,     7,     8,
      53,    10,    15,    12,    22,    23,    24,    25,    26,    27,
      17,    49,    45,    58,    58,    15,    15,    53,    15,    53,
      29,     3,     4,     5,     6,     7,     8,    15,    15,    11,
      12,   184,     5,    42,    43,   171,    18,    55,    56,    33,
       3,     4,     5,     6,     7,     8,    74,    29,    11,    12,
     182,   288,   217,    35,    86,    18,     3,     4,     5,     6,
       7,     8,    52,    10,    -1,    12,    29,    -1,    -1,    -1,
      -1,    -1,    35,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    29,    12,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,     4,     5,     6,     7,     8,    -1,    -1,
      29,    12,     4,     5,     6,     7,     8,    -1,    -1,    29,
      12,    -1,    -1,    -1,    -1,    -1,    19,    -1,    29,    22,
      23,    24,    25,    26,    27,    -1,    -1,    29,    21,    22,
      23,    24,    25,    26,    27,    21,    22,    23,    24,    25,
      26,    27,    22,    23,    24,    25,    26,    27,   146,   147,
     148,   149,   150,   151
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    36,    62,    63,    64,    36,     3,     0,    39,
      65,    67,    68,     3,     1,    15,     3,    69,    70,    13,
       1,    44,    93,    94,    40,    72,    15,    15,    22,    69,
      93,    95,    69,    73,    74,    41,    82,     4,     5,     6,
       7,     8,    12,    29,    71,    22,     1,     3,     4,     9,
      45,    47,    50,    52,    54,    57,    59,    60,    69,    94,
      96,    97,    98,    99,   100,   101,   102,   103,   105,   108,
      22,    74,     3,    81,    83,    84,    85,     4,     5,     1,
      15,    71,    45,    13,    20,    46,    17,    18,     3,    11,
      18,    29,    35,    69,    71,   110,   111,   112,   113,    95,
     110,     3,   110,     4,    18,    18,     1,    15,    10,    29,
      42,    43,    69,    71,    75,    76,    77,    78,    16,    17,
      84,    37,    38,    86,    87,    88,    89,    15,     1,    15,
       3,   110,   110,    97,   109,   110,    13,    20,    18,   110,
       4,     5,   113,   113,    18,     1,    22,    23,    24,    25,
      26,    27,    48,    28,    29,    33,    30,    31,    32,    34,
       1,    51,     1,    53,    46,    58,   113,   110,   114,    15,
      71,    79,    80,    81,    20,    14,    14,     1,    15,     3,
      75,     3,     3,    15,    15,    15,    46,    21,    16,    19,
       3,   110,   114,    19,   114,    48,   111,   111,   111,   111,
     111,   111,    96,   112,   112,   112,   113,   113,   113,   113,
      51,   110,    53,    96,   110,     3,    71,   106,   107,    19,
      16,    19,    14,     1,    45,    80,    17,    76,    69,    71,
      15,     1,    15,    18,    90,    90,    66,    67,    66,   110,
      46,   110,    21,    19,    19,    96,    49,   110,    96,    55,
      56,   104,    17,    17,     1,    45,   107,   110,    29,    71,
      45,    75,    21,    15,    41,    81,    91,    92,    17,     1,
      15,     1,    93,     1,    15,   110,    49,    96,   110,    96,
      96,    45,    71,     1,    15,    58,    81,    17,    15,    19,
      76,    15,    93,    15,    96,     1,    53,     1,    15,     1,
      15,    15,    75,    17,    76,    92,    53,    96,    15,    15,
      76,    96
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    64,    64,    64,    65,    65,    66,
      66,    67,    68,    68,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      86,    86,    87,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    93,    94,    94,    95,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    98,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   107,   107,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     4,     4,     2,     3,     2,
       3,     4,     2,     0,     1,     5,     6,     4,     5,     1,
       2,     1,     2,     1,     1,     1,     1,     2,     0,     2,
       1,     4,     5,     1,     1,     1,     1,     1,     3,     4,
       5,     3,     6,     3,     4,     2,     1,     4,     5,     3,
       1,     2,     0,     2,     1,     4,     5,     2,     2,     0,
       4,     5,     5,     4,     5,     3,     3,     0,     3,     1,
       4,     3,     1,     3,     4,     3,     4,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       6,     5,     1,     4,     1,     4,     4,     6,     7,     4,
       5,     4,     5,     4,     5,     8,     9,     1,     1,     5,
       6,     2,     1,     4,     5,     4,     5,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     4,     1,     4,
       1,     3,     2,     2,     4,     3,     3,     1
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
#line 109 "/Users/jones/desktop/group5/Code/src/pascal.y"
                          { 
                    root = (yyvsp[0].astProgram);
                }
#line 1590 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 3:
#line 112 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                             { 
                    (yyval.astProgram) = new ast::Program((yyvsp[-2].astProgramHead), (yyvsp[-1].astRoutine)); 
                }
#line 1598 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 4:
#line 117 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    { 
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), new ast::ParamList(), new ast::VoidType()); 
                }
#line 1606 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 5:
#line 120 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                       {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-2].aststring)), new ast::ParamList(), new ast::VoidType()); 
                    yyerrok;
                }
#line 1615 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 6:
#line 124 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), new ast::ParamList(), new ast::VoidType()); 
                    yyerrok;
                }
#line 1624 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 7:
#line 130 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                             { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1632 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 8:
#line 133 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                   { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-2].astRoutineHead), (yyvsp[0].astStmtList)); 
                    yyerrok;
                }
#line 1641 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 9:
#line 139 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                             { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-1].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1649 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 10:
#line 142 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                   { 
                    (yyval.astRoutine) = new ast::Routine((yyvsp[-2].astRoutineHead), (yyvsp[0].astStmtList)); 
                }
#line 1657 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 11:
#line 147 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                { 
                    (yyval.astRoutineHead) = new ast::RoutineHead((yyvsp[-3].astConstDeclList), (yyvsp[-2].astTypeDeclList), (yyvsp[-1].astVarDeclList), (yyvsp[0].astRoutinePartList)); 
                }
#line 1665 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 12:
#line 152 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                         { 
                    (yyval.astConstDeclList) = (yyvsp[0].astConstDeclList); 
                }
#line 1673 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 13:
#line 155 "/Users/jones/desktop/group5/Code/src/pascal.y"
                  { 
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                }
#line 1681 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 14:
#line 160 "/Users/jones/desktop/group5/Code/src/pascal.y"
                     { 
                    new ast::Name((yyvsp[0].aststring)); 
                }
#line 1689 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 15:
#line 165 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                  { 
                    (yyval.astConstDeclList) = (yyvsp[-4].astConstDeclList);
                    (yyvsp[-4].astConstDeclList)->push_back(new ast::ConstDecl(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1698 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 16:
#line 169 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                       { 
                    (yyval.astConstDeclList) = (yyvsp[-5].astConstDeclList);
                    (yyvsp[-5].astConstDeclList)->push_back(new ast::ConstDecl(new ast::Name((yyvsp[-4].aststring)), (yyvsp[-2].astBasicConst)));
                    yyerrok;
                }
#line 1708 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 17:
#line 174 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                  {
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                    (yyval.astConstDeclList)->push_back(new ast::ConstDecl(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astBasicConst)));
                }
#line 1717 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 18:
#line 178 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                       {
                    (yyval.astConstDeclList) = new ast::ConstDeclList();
                    (yyval.astConstDeclList)->push_back(new ast::ConstDecl(new ast::Name((yyvsp[-4].aststring)), (yyvsp[-2].astBasicConst)));
                    yyerrok;
                }
#line 1727 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 19:
#line 185 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::IntegerNode((yyvsp[0].astint));}
#line 1733 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 20:
#line 186 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::IntegerNode(-(yyvsp[0].astint));}
#line 1739 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 21:
#line 187 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::RealNode((yyvsp[0].astreal));}
#line 1745 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 22:
#line 188 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::RealNode(-(yyvsp[0].astreal));}
#line 1751 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 23:
#line 189 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::CharNode((yyvsp[0].astchar));}
#line 1757 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 24:
#line 190 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::StringNode((yyvsp[0].aststring));}
#line 1763 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 25:
#line 191 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::BooleanNode((yyvsp[0].astbool));}
#line 1769 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 26:
#line 192 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    {(yyval.astBasicConst) = new ast::MaxIntNode();}
#line 1775 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 27:
#line 195 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                       { (yyval.astTypeDeclList) = (yyvsp[0].astTypeDeclList); }
#line 1781 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 28:
#line 196 "/Users/jones/desktop/group5/Code/src/pascal.y"
                    { 
                    (yyval.astTypeDeclList) = new ast::TypeDeclList(); 
                }
#line 1789 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 29:
#line 201 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                  { 
                    (yyval.astTypeDeclList) = (yyvsp[-1].astTypeDeclList);
                    (yyvsp[-1].astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1798 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 30:
#line 205 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                   {
                    (yyval.astTypeDeclList) = new ast::TypeDeclList();
                    (yyval.astTypeDeclList)->push_back((yyvsp[0].astTypeDecl));
                }
#line 1807 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 31:
#line 211 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                               { 
                    (yyval.astTypeDecl) = new ast::TypeDecl(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astBasicType)); 
                }
#line 1815 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 32:
#line 214 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                    { 
                    (yyval.astTypeDecl) = new ast::TypeDecl(new ast::Name((yyvsp[-4].aststring)), (yyvsp[-2].astBasicType)); 
                    yyerrok;
                }
#line 1824 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 33:
#line 220 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1830 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 34:
#line 221 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1836 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 35:
#line 222 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                    { (yyval.astBasicType) = (yyvsp[0].astBasicType); }
#line 1842 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 36:
#line 225 "/Users/jones/desktop/group5/Code/src/pascal.y"
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
#line 1860 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 37:
#line 238 "/Users/jones/desktop/group5/Code/src/pascal.y"
                         {
                    (yyval.astBasicType) = new ast::UserDefType(new ast::Name((yyvsp[0].aststring)));
                }
#line 1868 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 38:
#line 244 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                    { 
                    (yyval.astBasicType) = new ast::RangeType((yyvsp[-2].astBasicConst), (yyvsp[0].astBasicConst)); 
                }
#line 1876 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 39:
#line 247 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                           { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-2].astBasicConst)), (yyvsp[0].astBasicConst)); 
                }
#line 1884 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 40:
#line 250 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                  { 
                    (yyval.astBasicType) = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[-3].astBasicConst)), new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astBasicConst))); 
                }
#line 1892 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 41:
#line 253 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                      {
                    (yyval.astBasicType) = new ast::RangeType(new ast::Name((yyvsp[-2].aststring)), new ast::Name((yyvsp[0].aststring)));
                }
#line 1900 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 42:
#line 259 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                 { 
                    (yyval.astBasicType) = new ast::ArrayType((yyvsp[-3].astBasicType), (yyvsp[0].astBasicType)); 
                }
#line 1908 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 43:
#line 264 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                               { 
                    (yyval.astBasicType) = new ast::RecordType((yyvsp[-1].astVarDeclList)); 
                }
#line 1916 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 44:
#line 267 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                    { 
                    (yyval.astBasicType) = new ast::RecordType((yyvsp[-2].astVarDeclList)); 
                    yyerrok;
                }
#line 1925 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 45:
#line 273 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                              { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());
                }
#line 1934 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 46:
#line 277 "/Users/jones/desktop/group5/Code/src/pascal.y"
                              {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 1942 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 47:
#line 282 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                    {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 1952 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 48:
#line 287 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                         {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-4].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-2].astBasicType)));
                    yyerrok;
                }
#line 1963 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 49:
#line 295 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                       {
                    (yyval.astNameList) = (yyvsp[-2].astNameList);
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1972 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 50:
#line 299 "/Users/jones/desktop/group5/Code/src/pascal.y"
                      {
                    (yyval.astNameList) = new ast::NameList();
                    (yyval.astNameList)->push_back(new ast::Identifier((yyvsp[0].aststring)));
                }
#line 1981 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 51:
#line 304 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                     { (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList); }
#line 1987 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 52:
#line 305 "/Users/jones/desktop/group5/Code/src/pascal.y"
                  { (yyval.astVarDeclList) = new ast::VarDeclList(); }
#line 1993 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 53:
#line 308 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                           { 
                    (yyval.astVarDeclList) = (yyvsp[-1].astVarDeclList);
                    (yyvsp[-1].astVarDeclList)->insert((yyvsp[-1].astVarDeclList)->end(), (yyvsp[0].astVarDeclList)->begin(), (yyvsp[0].astVarDeclList)->end());
                }
#line 2002 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 54:
#line 312 "/Users/jones/desktop/group5/Code/src/pascal.y"
                            {
                    (yyval.astVarDeclList) = (yyvsp[0].astVarDeclList);
                }
#line 2010 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 55:
#line 317 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                     {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-3].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-1].astBasicType)));
                }
#line 2020 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 56:
#line 322 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                          {
                    (yyval.astVarDeclList) = new ast::VarDeclList(); 
                    for(auto name: *((yyvsp[-4].astNameList))) 
                        (yyval.astVarDeclList)->push_back(new ast::VarDecl(name, (yyvsp[-2].astBasicType)));
                    yyerrok;
                }
#line 2031 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 57:
#line 330 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                               {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 2040 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 58:
#line 334 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                {
                    (yyval.astRoutinePartList) = (yyvsp[-1].astRoutinePartList);
                    (yyval.astRoutinePartList)->push_back((yyvsp[0].astProgram));
                }
#line 2049 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 59:
#line 338 "/Users/jones/desktop/group5/Code/src/pascal.y"
                    { (yyval.astRoutinePartList) = new ast::RoutinePartList(); }
#line 2055 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 60:
#line 341 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                         {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 2063 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 61:
#line 344 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                               {
                    (yyval.astProgram) = new ast::Program((yyvsp[-4].astProgramHead), (yyvsp[-2].astRoutine));
                    yyerrok;
                }
#line 2072 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 62:
#line 349 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                     {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-2].astParamList), (yyvsp[0].astBasicType));
                }
#line 2080 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 63:
#line 353 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                           {
                    (yyval.astProgram) = new ast::Program((yyvsp[-3].astProgramHead), (yyvsp[-1].astRoutine));
                }
#line 2088 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 64:
#line 356 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                {
                    (yyval.astProgram) = new ast::Program((yyvsp[-4].astProgramHead), (yyvsp[-2].astRoutine));
                    yyerrok;
                }
#line 2097 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 65:
#line 362 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                           {
                    (yyval.astProgramHead) = new ast::ProgramHead(new ast::Identifier((yyvsp[-1].aststring)), (yyvsp[0].astParamList), new ast::VoidType()); 
                }
#line 2105 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 66:
#line 367 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                     {
                    (yyval.astParamList) = (yyvsp[-1].astParamList);
                }
#line 2113 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 67:
#line 370 "/Users/jones/desktop/group5/Code/src/pascal.y"
                   {
                    (yyval.astParamList) = new ast::ParamList();
                }
#line 2121 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 68:
#line 374 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                       {
                    (yyval.astParamList) = (yyvsp[-2].astParamList);
                    (yyvsp[-2].astParamList)->insert((yyvsp[-2].astParamList)->end(), (yyvsp[0].astParamList)->begin(), (yyvsp[0].astParamList)->end());
                }
#line 2130 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 69:
#line 378 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                 {
                    (yyval.astParamList) = (yyvsp[0].astParamList);
                }
#line 2138 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 70:
#line 384 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                         {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 2148 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 71:
#line 389 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                     {
                    (yyval.astParamList) = new ast::ParamList(); 
                    for(auto name: *((yyvsp[-2].astNameList))) 
                        (yyval.astParamList)->push_back(new ast::Parameter(name, (yyvsp[0].astBasicType)));
                }
#line 2158 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 72:
#line 398 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                {
                    (yyval.astStmtList) = (yyvsp[0].astStmtList);
                }
#line 2166 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 73:
#line 402 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                      {
                    (yyval.astStmtList) = (yyvsp[-1].astStmtList);
                }
#line 2174 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 74:
#line 405 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                            {
                    (yyval.astStmtList) = (yyvsp[-2].astStmtList);
                    yyerrok;
                }
#line 2183 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 75:
#line 411 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astStmtList) = (yyvsp[-2].astStmtList);
                    (yyval.astStmtList)->stmtPushBack((yyvsp[-1].astBasicStmt));
                }
#line 2192 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 76:
#line 415 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                              {
                    (yyval.astStmtList) = (yyvsp[-3].astStmtList);
                    (yyval.astStmtList)->stmtPushBack((yyvsp[-2].astBasicStmt));
                    yyerrok;
                }
#line 2202 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 77:
#line 420 "/Users/jones/desktop/group5/Code/src/pascal.y"
                   {
                    (yyval.astStmtList) = new ast::StmtList();
                }
#line 2210 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 78:
#line 426 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                  {
                    (yyval.astBasicStmt) = new ast::LabelStmt((yyvsp[-2].astint), (yyvsp[0].astBasicStmt));
                }
#line 2218 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 79:
#line 429 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                  {
                    (yyval.astBasicStmt) = (yyvsp[0].astBasicStmt);
                }
#line 2226 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 80:
#line 434 "/Users/jones/desktop/group5/Code/src/pascal.y"
                              {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2234 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 81:
#line 437 "/Users/jones/desktop/group5/Code/src/pascal.y"
                            {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2242 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 82:
#line 440 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                {
                    (yyval.astBasicStmt) = (yyvsp[0].astStmtList);
                }
#line 2250 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 83:
#line 443 "/Users/jones/desktop/group5/Code/src/pascal.y"
                          {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2258 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 84:
#line 446 "/Users/jones/desktop/group5/Code/src/pascal.y"
                              {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2266 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 85:
#line 449 "/Users/jones/desktop/group5/Code/src/pascal.y"
                             {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2274 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 86:
#line 452 "/Users/jones/desktop/group5/Code/src/pascal.y"
                           {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2282 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 87:
#line 455 "/Users/jones/desktop/group5/Code/src/pascal.y"
                            {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2290 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 88:
#line 458 "/Users/jones/desktop/group5/Code/src/pascal.y"
                           {
                    (yyval.astBasicStmt) = (ast::BasicStmt*)(yyvsp[0].astBasicStmt);
                }
#line 2298 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 89:
#line 463 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                         {
                    (yyval.astBasicStmt) = new ast::AssignStmt(new ast::Identifier((yyvsp[-2].aststring)), (yyvsp[0].astExpression));
                }
#line 2306 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 90:
#line 466 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                        {
                    (yyval.astBasicStmt) = new ast::AssignStmt(new ast::ArrayElementRef(new ast::Identifier((yyvsp[-5].aststring)), (yyvsp[-3].astExpression)), (yyvsp[0].astExpression));
                }
#line 2314 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 91:
#line 469 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                  {
                    (yyval.astBasicStmt) = new ast::AssignStmt(new ast::RecordElementRef(new ast::Identifier((yyvsp[-4].aststring)), new ast::Identifier((yyvsp[-2].aststring))), (yyvsp[0].astExpression));
                }
#line 2322 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 92:
#line 474 "/Users/jones/desktop/group5/Code/src/pascal.y"
                        {
                    (yyval.astBasicStmt) = new ast::UserDefProcCall(new ast::Name((yyvsp[0].aststring)));
                }
#line 2330 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 93:
#line 477 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astBasicStmt) = new ast::UserDefProcCall(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2338 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 94:
#line 480 "/Users/jones/desktop/group5/Code/src/pascal.y"
                            {
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE);
                    if((yyvsp[0].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN);
                }
#line 2349 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 95:
#line 486 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                     {
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITE)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITE, (yyvsp[-1].astExpressionList));
                    if((yyvsp[-3].astSYSPROC) == ast::SYSPROC::WRITELN)
                        (yyval.astBasicStmt) = new ast::SysProcCall(ast::SYSPROC::WRITELN, (yyvsp[-1].astExpressionList));
                }
#line 2360 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 96:
#line 492 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astBasicStmt) = new ast::ReadProcCall((yyvsp[-1].astExpression));
                }
#line 2368 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 97:
#line 496 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                        {
                    (yyval.astBasicStmt) = new ast::IfStmt((yyvsp[-4].astExpression), (yyvsp[-2].astBasicStmt), (yyvsp[0].astBasicStmt));
                }
#line 2376 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 98:
#line 499 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                              {
                    (yyval.astBasicStmt) = new ast::IfStmt((yyvsp[-5].astExpression), (yyvsp[-2].astBasicStmt), (yyvsp[0].astBasicStmt));
                    yyerrok;
                }
#line 2385 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 99:
#line 503 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                             {
                    (yyval.astBasicStmt) = new ast::IfStmt((yyvsp[-2].astExpression), (yyvsp[0].astBasicStmt));
                }
#line 2393 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 100:
#line 506 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                   {
                    (yyval.astBasicStmt) = new ast::IfStmt((yyvsp[-3].astExpression), (yyvsp[0].astBasicStmt));
                    yyerrok;
                }
#line 2402 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 101:
#line 519 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                       {
                    (yyval.astBasicStmt) = new ast::RepeatStmt((yyvsp[0].astExpression), (yyvsp[-2].astStmtList));
                }
#line 2410 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 102:
#line 522 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                             {
                    (yyval.astBasicStmt) = new ast::RepeatStmt((yyvsp[0].astExpression), (yyvsp[-3].astStmtList));
                    yyerrok;
                }
#line 2419 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 103:
#line 528 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                            {
                    (yyval.astBasicStmt) = new ast::WhileStmt((yyvsp[-2].astExpression), (yyvsp[0].astBasicStmt));
                }
#line 2427 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 104:
#line 531 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                  {
                    (yyval.astBasicStmt) = new ast::WhileStmt((yyvsp[-3].astExpression), (yyvsp[0].astBasicStmt));
                    yyerrok;
                }
#line 2436 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 105:
#line 536 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                              {
                    (yyval.astBasicStmt) = new ast::ForStmt(new ast::Identifier((yyvsp[-6].aststring)), (yyvsp[-4].astExpression), (yyvsp[-3].astDirection), (yyvsp[-2].astExpression), (yyvsp[0].astBasicStmt));
                }
#line 2444 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 106:
#line 539 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                                                    {
                    (yyval.astBasicStmt) = new ast::ForStmt(new ast::Identifier((yyvsp[-7].aststring)), (yyvsp[-5].astExpression), (yyvsp[-4].astDirection), (yyvsp[-3].astExpression), (yyvsp[0].astBasicStmt));
                    yyerrok;
                }
#line 2453 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 107:
#line 544 "/Users/jones/desktop/group5/Code/src/pascal.y"
                     {
                    (yyval.astDirection) = ast::Direction::To;
                }
#line 2461 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 108:
#line 547 "/Users/jones/desktop/group5/Code/src/pascal.y"
                         {
                    (yyval.astDirection) = ast::Direction::DownTo;
                }
#line 2469 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 109:
#line 552 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                         {
                    (yyval.astBasicStmt) = new ast::CaseStmt((yyvsp[-3].astExpression), (yyvsp[-1].astCaseExprList));
                }
#line 2477 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 110:
#line 555 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                               {
                    (yyval.astBasicStmt) = new ast::CaseStmt((yyvsp[-4].astExpression), (yyvsp[-2].astCaseExprList));
                    yyerrok;
                }
#line 2486 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 111:
#line 561 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                             {
                    (yyval.astCaseExprList) = (yyvsp[-1].astCaseExprList);
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2495 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 112:
#line 565 "/Users/jones/desktop/group5/Code/src/pascal.y"
                             {
                    (yyval.astCaseExprList) = new ast::CaseExprList();
                    (yyval.astCaseExprList)->push_back((yyvsp[0].astCaseExpr));
                }
#line 2504 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 113:
#line 571 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                 {
                    (yyval.astCaseExpr) = new ast::CaseExpr((yyvsp[-3].astBasicConst), (yyvsp[-1].astBasicStmt));
                }
#line 2512 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 114:
#line 574 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                       {
                    (yyval.astCaseExpr) = new ast::CaseExpr((yyvsp[-4].astBasicConst), (yyvsp[-2].astBasicStmt));
                    yyerrok;
                }
#line 2521 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 115:
#line 578 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                         {
                    (yyval.astCaseExpr) = new ast::CaseExpr(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astBasicStmt));
                }
#line 2529 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 116:
#line 581 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                              {
                    (yyval.astCaseExpr) = new ast::CaseExpr(new ast::Identifier((yyvsp[-4].aststring)), (yyvsp[-2].astBasicStmt));
                    yyerrok;
                }
#line 2538 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 117:
#line 587 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                {
                    (yyval.astBasicStmt) = new ast::GotoStmt((yyvsp[0].astint));
                }
#line 2546 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 118:
#line 591 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                      {
                    (yyval.astExpressionList) = (yyvsp[-2].astExpressionList);
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2555 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 119:
#line 595 "/Users/jones/desktop/group5/Code/src/pascal.y"
                              {
                    (yyval.astExpressionList) = new ast::ExpressionList();
                    (yyval.astExpressionList)->push_back((yyvsp[0].astExpression));
                }
#line 2564 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 120:
#line 601 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GEop, (yyvsp[0].astExpression));
                }
#line 2572 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 121:
#line 604 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::GTop, (yyvsp[0].astExpression));
                }
#line 2580 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 122:
#line 607 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LEop, (yyvsp[0].astExpression));
                }
#line 2588 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 123:
#line 610 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                        {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::LTop, (yyvsp[0].astExpression));
                }
#line 2596 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 124:
#line 613 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                           {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::EQUALop, (yyvsp[0].astExpression));
                }
#line 2604 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 125:
#line 616 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                             {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::UNEQUALop, (yyvsp[0].astExpression));
                }
#line 2612 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 126:
#line 619 "/Users/jones/desktop/group5/Code/src/pascal.y"
                        {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2620 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 127:
#line 623 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::PLUSop, (yyvsp[0].astExpression));
                }
#line 2628 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 128:
#line 626 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MINUSop, (yyvsp[0].astExpression));
                }
#line 2636 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 129:
#line 629 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ORop, (yyvsp[0].astExpression));
                }
#line 2644 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 130:
#line 632 "/Users/jones/desktop/group5/Code/src/pascal.y"
                        {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2652 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 131:
#line 637 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MULop, (yyvsp[0].astExpression));
                }
#line 2660 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 132:
#line 640 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                      {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::DIVop, (yyvsp[0].astExpression));
                }
#line 2668 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 133:
#line 643 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                     {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::MODop, (yyvsp[0].astExpression));
                }
#line 2676 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 134:
#line 646 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                      {
                    (yyval.astExpression) = new ast::BinaryExpr((yyvsp[-2].astExpression), ast::BinaryOperator::ANDop, (yyvsp[0].astExpression));
                }
#line 2684 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 135:
#line 649 "/Users/jones/desktop/group5/Code/src/pascal.y"
                          {
                    (yyval.astExpression) = (yyvsp[0].astExpression);
                }
#line 2692 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 136:
#line 654 "/Users/jones/desktop/group5/Code/src/pascal.y"
                        {
                    (yyval.astExpression) = new ast::Name((yyvsp[0].aststring));
                }
#line 2700 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 137:
#line 657 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                            {
                    (yyval.astExpression) = new ast::UserDefProcCall(new ast::Name((yyvsp[-3].aststring)), (yyvsp[-1].astArgList));
                }
#line 2708 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 138:
#line 660 "/Users/jones/desktop/group5/Code/src/pascal.y"
                             {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[0].astSYSFUNCT));
                }
#line 2716 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 139:
#line 663 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                 {
                    (yyval.astExpression) = new ast::SysFuncCall((yyvsp[-3].astSYSFUNCT), (yyvsp[-1].astArgList));
                }
#line 2724 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 140:
#line 666 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                {
                    (yyval.astExpression) = (yyvsp[0].astBasicConst);
                }
#line 2732 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 141:
#line 669 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                      {
                    (yyval.astExpression) = (yyvsp[-1].astExpression);
                }
#line 2740 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 142:
#line 672 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NOTop, (yyvsp[0].astExpression));
                }
#line 2748 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 143:
#line 675 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                 {
                    (yyval.astExpression) = new ast::UnaryExpr(ast::UnaryOperator::NEGop, (yyvsp[0].astExpression));
                }
#line 2756 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 144:
#line 678 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                          {
                    (yyval.astExpression) = new ast::ArrayElementRef(new ast::Identifier((yyvsp[-3].aststring)), (yyvsp[-1].astExpression));
                }
#line 2764 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 145:
#line 681 "/Users/jones/desktop/group5/Code/src/pascal.y"
                               {
                    (yyval.astExpression) = new ast::RecordElementRef(new ast::Identifier((yyvsp[-2].aststring)), new ast::Identifier((yyvsp[0].aststring)));
                }
#line 2772 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 146:
#line 685 "/Users/jones/desktop/group5/Code/src/pascal.y"
                                                {
                    (yyval.astArgList) = (yyvsp[-2].astArgList);
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2781 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;

  case 147:
#line 689 "/Users/jones/desktop/group5/Code/src/pascal.y"
                              {
                    (yyval.astArgList) = new ast::ArgList();
                    (yyval.astArgList)->push_back((yyvsp[0].astExpression));
                }
#line 2790 "/Users/jones/desktop/group5/Code/src/parser.cpp"
    break;


#line 2794 "/Users/jones/desktop/group5/Code/src/parser.cpp"

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

#line 695 "/Users/jones/desktop/group5/Code/src/pascal.y"

void FreeNode(ast::BasicAstNode* root) {
    ast::childrenList* children= root->getChildrenList();
    delete root;
    if(children->size()) {
        for(auto child: *children) {
            if(child != NULL) FreeNode(child);
        }
    }
}

void yyerror(string msg, ...) {
    cout << "ERROR: Line " << lineno << " " << msg << endl;
}


ast::BasicAstNode* parse(void)
{ 
    yyparse();
    return root;
}
