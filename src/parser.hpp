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
#line 16 "pascal.y"

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

#line 166 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
