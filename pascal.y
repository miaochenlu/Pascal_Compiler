
%{
#include <iostream>
#include <vector>
#include <string>
#include "ast/ast.h"
#include "parser.hpp"

using namespace std;
static ast::BasicAstNode* root;
void yyerror(string msg, ...);
extern int yylex(void);

%}

%union {
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
}

%token<aststring>   ID
%token<astint>      INTEGER 
%token<astreal>     REAL 
%token<astchar>     CHAR 
%token<aststring>   STRING 
%token<astbool>     BOOLEAN
%token<astSYSPROC>  SYS_PROC 
%token<astTypeKind> SYS_TYPE 
%token<astSYSFUNCT> SYS_FUNCT
%token<aststring>   SYS_CON 
%token<aststring>   DOT DOTDOT SEMI COMMA COLON LP RP LB RB
%token<aststring>   EQUAL UNEQUAL GE GT LE LT PLUS MINUS MUL DIV MOD OR AND NOT
%token<aststring>   PROGRAM PROCEDURE FUNCTION CONST TYPE VAR RECORD ARRAY BEG END ASSIGN
%token<aststring>   IF THEN ELSE REPEAT UNTIL WHILE DO FOR TO DOWNTO CASE OF GOTO READ

%type<aststring>            NAME;
%type<astProgram>           program function_decl procedure_decl;
%type<astProgramHead>       program_head function_head procedure_head;
%type<astRoutine>           routine sub_routine;
%type<astRoutineHead>       routine_head;
%type<astStmtList>          routine_body compound_stmt stmt_list;
// %type<astLabelDeclList>     label_part;
%type<astConstDeclList>     const_part const_expr_list;
%type<astTypeDeclList>      type_part type_decl_list;
%type<astVarDeclList>       var_part var_decl_list field_decl_list var_decl field_decl;
%type<astRoutinePartList>   routine_part;

%type<astBasicConst>        const_value;

%type<astTypeDecl>          type_definition;
%type<astBasicType>         type_decl simple_type_decl array_type_decl record_type_decl;
        

%type<astParamList>         parameters para_decl_list para_type_list;;     
%type<astNameList>          name_list; //val_para_list var_para_list

%type<astStmt>              stmt  assign_stmt proc_stmt if_stmt repeat_stmt while_stmt for_stmt case_stmt goto_stmt; //non_label_stmt else_clause
%type<astCaseExprList>      case_expr_list;
%type<astCaseExpr>          case_expr;

%type<astExpressionList>    expression_list;
%type<astExpression>        expression expr term factor;

%type<astArgList>           args_list;
%type<astDirection>         direction;
        


%%

programPrime    : program { 
                    root = $1;
                }
program         : program_head  routine  DOT { 
                    $$ = new ast::Program($1, $2); 
                    $$->printAstNode();
                }
;

program_head    : PROGRAM  ID  SEMI { 
                    $$ = new ast::ProgramHead(new ast::Identifier($2), new ast::ParamList(), new ast::VoidType()); 
                }
;

routine         : routine_head  routine_body { 
                    $$ = new ast::Routine($1, $2); 
                }
;

sub_routine     : routine_head  routine_body { 
                    $$ = new ast::Routine($1, $2); 
                }
;

routine_head    : const_part  type_part  var_part  routine_part { 
                    $$ = new ast::RoutineHead($1, $2, $3, $4); 
                }
;

const_part      : CONST  const_expr_list { 
                    $$ = $2; 
                }
                | { 
                    $$ = new ast::ConstDeclList();
                }
;

NAME            : ID { 
                    new ast::Name($1); 
                }
;

const_expr_list : const_expr_list  NAME  EQUAL  const_value  SEMI { 
                    $$ = $1;
                    $1->push_back(new ast::ConstDecl(new ast::Name($2), $4));
                }
                |  NAME  EQUAL  const_value  SEMI {
                    $$ = new ast::ConstDeclList();
                    $$->push_back(new ast::ConstDecl(new ast::Name($1), $3));
                }
;

const_value     :  INTEGER          {$$ = new ast::IntegerNode($1);}
                |  MINUS INTEGER    {$$ = new ast::IntegerNode(-$2);}
                |  REAL             {$$ = new ast::RealNode($1);}
                |  MINUS REAL       {$$ = new ast::RealNode(-$2);}
                |  CHAR             {$$ = new ast::CharNode($1);}
                |  STRING           {$$ = new ast::StringNode($1);}
                |  BOOLEAN          {$$ = new ast::BooleanNode($1);}
                |  SYS_CON          {$$ = new ast::MaxIntNode();}
;

type_part       : TYPE type_decl_list  { $$ = $2; }
                |   { 
                    $$ = new ast::TypeDeclList(); 
                }
;

type_decl_list  : type_decl_list  type_definition { 
                    $$ = $1;
                    $1->push_back($2);
                }
                |  type_definition {
                    $$ = new ast::TypeDeclList();
                    $$->push_back($1);
                }
;

type_definition : NAME  EQUAL  type_decl  SEMI { 
                    $$ = new ast::TypeDecl(new ast::Name($1), $3); 
                }
;

type_decl       : simple_type_decl  { $$ = $1; }
                | array_type_decl   { $$ = $1; }
                | record_type_decl  { $$ = $1; }
;

simple_type_decl: SYS_TYPE { 
                    if($1 == ast::TypeKind::INTtype) {
                        $$ = new ast::IntegerType();
                    } else if($1 == ast::TypeKind::REALtype) {
                        $$ = new ast::RealType();
                    } else if($1 == ast::TypeKind::CHARtype) {
                        $$ = new ast::CharType();
                    } else if($1 == ast::TypeKind::BOOLEANtype) {
                        $$ = new ast::BooleanType();
                    } else if($1 == ast::TypeKind::STRINGtype) {
                        $$ = new ast::StringType();
                    }
                } 
                |  NAME  {
                    $$ = new ast::UserDefType(new ast::Name($1));
                }
                // |  LP  name_list  RP  {

                // }
                |  const_value  DOTDOT  const_value { 
                    $$ = new ast::RangeType($1, $3); 
                }
                |  MINUS  const_value  DOTDOT  const_value { 
                    $$ = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, $2), $4); 
                }
                |  MINUS  const_value  DOTDOT  MINUS  const_value { 
                    $$ = new ast::RangeType(new ast::UnaryExpr(ast::UnaryOperator::NEGop, $2), new ast::UnaryExpr(ast::UnaryOperator::NEGop, $5)); 
                }
                |  NAME  DOTDOT  NAME {
                    $$ = new ast::RangeType(new ast::Name($1), new ast::Name($3));
                }
;


array_type_decl : ARRAY  LB  simple_type_decl  RB  OF  type_decl { 
                    $$ = new ast::ArrayType($3, $6); 
                }
;

record_type_decl: RECORD  field_decl_list  END { 
                    $$ = new ast::RecordType($2); 
                }
;

field_decl_list : field_decl_list  field_decl { 
                    $$ = $1;
                    $1->insert($1->end(), $2->begin(), $2->end());;
                }
                |  field_decl {
                    $$ = $1;
                }
;

field_decl      : name_list  COLON  type_decl  SEMI {
                    $$ = new ast::VarDeclList(); 
                    for(auto name: *($1)) 
                        $$->push_back(new ast::VarDecl(name, $3));
                }

name_list       : name_list  COMMA  ID {
                    $$ = $1;
                    $$->push_back(new ast::Identifier($3));
                }
                |  ID {
                    $$ = new ast::NameList;
                    $$->push_back(new ast::Identifier($1));
                }
;
var_part        : VAR  var_decl_list { $$ = $2; }
                | { $$ = new ast::VarDeclList(); }
;

var_decl_list   :  var_decl_list  var_decl { 
                    $$ = $1;
                    $1->insert($1->end(), $2->begin(), $2->end());
                }
                |  var_decl {
                    $$ = $1;
                }
;

var_decl        :  name_list  COLON  type_decl  SEMI {
                    $$ = new ast::VarDeclList(); 
                    for(auto name: *($1)) 
                        $$->push_back(new ast::VarDecl(name, $3));
                }
;

routine_part    :  routine_part  function_decl {
                    $$ = $1;
                    $$->push_back($2);
                }
                |  routine_part  procedure_decl {
                    $$ = $1;
                    $$->push_back($2);
                }
                |   { $$ = new ast::RoutinePartList(); }
;

function_decl   : function_head  SEMI  sub_routine  SEMI {
                    $$ = new ast::Program($1, $3);
                }
;
function_head   :  FUNCTION  ID  parameters  COLON  simple_type_decl {
                    $$ = new ast::ProgramHead(new ast::Identifier($2), $3, $5);
                }
;
procedure_decl  :  procedure_head  SEMI  sub_routine  SEMI {
                    $$ = new ast::Program($1, $3);
                }
;

procedure_head  :  PROCEDURE ID parameters {
                    $$ = new ast::ProgramHead(new ast::Identifier($2), $3, new ast::VoidType()); 
                }
;

parameters : LP  para_decl_list  RP  {
                    $$ = $2;
                } 
                |  {
                    $$ = new ast::ParamList();
                }
;
para_decl_list  : para_decl_list  SEMI  para_type_list {
                    $$ = $1;
                    $1->insert($1->end(), $3->begin(), $3->end());
                }
                | para_type_list {
                    $$ = $1;
                }
;

////////error
para_type_list  : VAR name_list COLON  simple_type_decl  {
                    $$ = new ast::ParamList(); 
                    for(auto name: *($2)) 
                        $$->push_back(new ast::Parameter(name, $4));
                }               
                | name_list  COLON  simple_type_decl {
                    $$ = new ast::ParamList(); 
                    for(auto name: *($1)) 
                        $$->push_back(new ast::Parameter(name, $3));
                }
;



routine_body    : compound_stmt {
                    $$ = $1;
                }
;
compound_stmt   : BEG  stmt_list  END {
                    $$ = $2;
                }
;

stmt_list       : stmt_list  stmt  SEMI {
                    $$ = $1;
                    $$->push_back($2);
                }
                |  {
                    $$ = new ast::StmtList();
                }
;

// ///////error label
// stmt            : INTEGER  COLON  non_label_stmt  {

//                 }
//                 |  non_label_stmt {
//                     $$ = $1;
//                 }
// ;
// non_label_stmt
stmt            : assign_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | proc_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | compound_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | if_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | repeat_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | while_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | for_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | case_stmt {
                    $$ = (ast::Stmt*)$1;
                }
                | goto_stmt{
                    $$ = (ast::Stmt*)$1;
                }
;

assign_stmt     : ID  ASSIGN  expression {
                    $$ = new ast::AssignStmt(new ast::Identifier($1), $3);
                }
                | ID LB expression RB ASSIGN expression {
                    $$ = new ast::AssignStmt(new ast::ArrayElementRef(new ast::Identifier($1), $3), $6);
                }
                | ID  DOT  ID  ASSIGN  expression {
                    $$ = new ast::AssignStmt(new ast::RecordElementRef(new ast::Identifier($1), new ast::Identifier($3)), $5);
                }
;

proc_stmt       :  NAME {
                    $$ = new ast::UserDefProcCall(new ast::Name($1));
                }
                |  NAME LP args_list RP {
                    $$ = new ast::UserDefProcCall(new ast::Name($1), $3);
                }
                |  SYS_PROC {
                    if($1 == ast::SYSPROC::WRITE)
                        $$ = new ast::SysProcCall(ast::SYSPROC::WRITE);
                    if($1 == ast::SYSPROC::WRITELN)
                        $$ = new ast::SysProcCall(ast::SYSPROC::WRITELN);
                }
                |  SYS_PROC  LP  expression_list  RP {
                    if($1 == ast::SYSPROC::WRITE)
                        $$ = new ast::SysProcCall(ast::SYSPROC::WRITE, $3);
                    if($1 == ast::SYSPROC::WRITELN)
                        $$ = new ast::SysProcCall(ast::SYSPROC::WRITELN, $3);
                }
                |  READ  LP  factor  RP {
                    $$ = new ast::ReadProcCall($3);
                }
;
if_stmt         : IF  expression  THEN  stmt_list  ELSE stmt_list {
                    $$ = new ast::IfStmt($2, $4, $6);
                }
                | IF  expression  THEN  stmt_list {
                    $$ = new ast::IfStmt($2, $4);
                }
;
// else_clause     : ELSE stmt_list {
//                     $$ = $2;
//                 }
//                 |  {
//                     $$ = NULL;
//                 }
// ;

repeat_stmt     : REPEAT  stmt_list  UNTIL  expression {
                    $$ = new ast::RepeatStmt($4, $2);
                }
;

while_stmt      : WHILE  expression  DO stmt_list {
                    $$ = new ast::WhileStmt($2, $4);
                }
;
for_stmt        : FOR  ID  ASSIGN  expression  direction  expression  DO stmt_list {
                    $$ = new ast::ForStmt(new ast::Identifier($2), $4, $5, $6, $8);
                }
;
direction       : TO {
                    $$ = ast::Direction::To;
                }
                | DOWNTO {
                    $$ = ast::Direction::DownTo;
                }
;

case_stmt       : CASE expression OF case_expr_list  END {
                    $$ = new ast::CaseStmt($2, $4);
                }
;

case_expr_list  : case_expr_list  case_expr  {
                    $$ = $1;
                    $$->push_back($2);
                }
                |  case_expr {
                    $$ = new ast::CaseExprList();
                    $$->push_back($1);
                }
;

case_expr       : const_value  COLON  stmt_list  SEMI {
                    $$ = new ast::CaseExpr($1, $3);
                }
                |  ID  COLON  stmt_list  SEMI {
                    $$ = new ast::CaseExpr(new ast::Identifier($1), $3);
                }
;

goto_stmt       : GOTO  INTEGER {
                    $$ = new ast::GotoStmt($2);
                }
;
expression_list : expression_list  COMMA  expression  {
                    $$ = $1;
                    $$->push_back($3);
                }
                |  expression {
                    $$ = new ast::ExpressionList();
                    $$->push_back($1);
                }
;

expression      :  expression  GE  expr {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::GEop, $3);
                }
                |  expression  GT  expr {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::GTop, $3);
                } 
                |  expression  LE  expr {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::LEop, $3);
                }
                |  expression  LT  expr {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::LTop, $3);
                }
                |  expression  EQUAL  expr {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::EQUALop, $3);
                }
                |  expression  UNEQUAL  expr {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::UNEQUALop, $3);
                }
                |  expr {
                    $$ = $1;
                }
;
expr            :  expr  PLUS  term  {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::PLUSop, $3);
                } 
                |  expr  MINUS  term {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::MINUSop, $3);
                }
                |  expr  OR  term    {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::ORop, $3);
                }
                |  term {
                    $$ = $1;
                }
;

term            :  term  MUL  factor {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::MULop, $3);
                }  
                |  term  DIV  factor  {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::DIVop, $3);
                }
                |  term  MOD  factor {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::MODop, $3);
                }
                |  term  AND  factor  {
                    $$ = new ast::BinaryExpr($1, ast::BinaryOperator::ANDop, $3);
                } 
                |  factor {
                    $$ = $1;
                }
;

factor          :  NAME {
                    $$ = new ast::Name($1);
                }
                |  NAME  LP  args_list  RP  {
                    $$ = new ast::UserDefProcCall(new ast::Name($1), $3);
                }
                |  SYS_FUNCT {
                    $$ = new ast::SysFuncCall($1);
                }
                |  SYS_FUNCT  LP  args_list  RP  {
                    $$ = new ast::SysFuncCall($1, $3);
                }
                |  const_value  {
                    $$ = $1;
                }
                |  LP  expression  RP {
                    $$ = $2;
                }
                |  NOT  factor  {
                    $$ = new ast::UnaryExpr(ast::UnaryOperator::NOTop, $2);
                }
                |  MINUS  factor {
                    $$ = new ast::UnaryExpr(ast::UnaryOperator::NEGop, $2);
                }
                |  ID  LB  expression  RB {
                    $$ = new ast::ArrayElementRef(new ast::Identifier($1), $3);
                }
                |  ID  DOT  ID {
                    $$ = new ast::RecordElementRef(new ast::Identifier($1), new ast::Identifier($3));
                }
;
args_list       : args_list  COMMA  expression  {
                    $$ = $1;
                    $$->push_back($3);
                }
                |  expression {
                    $$ = new ast::ArgList();
                    $$->push_back($1);
                }
;

%%


void yyerror(string msg, ...) {
    cout << msg << endl;
}


ast::BasicAstNode* parse(void)
{ 
    yyparse();
    return root;
}