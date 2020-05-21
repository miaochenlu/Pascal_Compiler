/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 200 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

