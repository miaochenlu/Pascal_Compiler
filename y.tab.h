/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 224 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
