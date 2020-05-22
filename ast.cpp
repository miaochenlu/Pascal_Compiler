// #include "global.h"
// /*
// |---------------------------------------------------------------|
// |                                                               |
// |                             START                             |
// |                                                               |
// |---------------------------------------------------------------|
// */

// class BasicAstNode
// { 
// public:  
//     BasicAstNode(){};
//     ~BasicAstNode(){};
// }; 

// class Expression: public BasicAstNode
// {
// public:
//     Expression() {}
// };

// class Stmt: public BasicAstNode 
// {
// public:
//     Stmt() {}
// };

// /******************program***********************/
// class Program: public BasicAstNode
// {
// public:
//     ProgramHead* programHead;
//     Routine* routine;
//     Program(ProgramHead* programHead, Routine* routine): programHead(programHead), routine(routine) {}
// };

// class ProgramHead: public BasicAstNode 
// {
// public: 
//     Identifier* name;
//     ParamList*  parameters;
//     BasicType*  returnType;
//     ProgramHead(Identifier* name, ParamList* parameters, BasicType* returnType):
//         name(name), parameters(parameters), returnType(returnType) {}
// };

// class Routine: public BasicAstNode 
// {
// public: 
//     RoutineHead* routineHead;
//     StmtList* routineBody;
//     Routine(RoutineHead* routineHead, StmtList* routineBody): routineHead(routineHead), routineBody(routineBody) {}
// };

// class RoutineHead: public BasicAstNode 
// {
// public:
//     ConstDeclList*      constPart;
//     TypeDeclList*       typePart;
//     VarDeclList*        varPart;
//     RoutinePartList*    routinePart;
//     RoutineHead(ConstDeclList* constPart, TypeDeclList* typePart, VarDeclList* varPart, RoutinePartList* routinePart):
//         constPart(constPart), typePart(typePart), varPart(varPart), routinePart(routinePart) {}
// };

// /****************program head********************/
// class Parameter: public BasicAstNode
// {
// public:  
//     Identifier* name;
//     BasicType*  type;
//     Parameter(Identifier* name, BasicType* type): name(name), type(type) {}
// };

// /****************** const ***********************/
// enum class TypeKind {
//     ERRORtype, INTtype, REALtype, CHARtype, STRINGtype, 
//     ARRAYtype, RECORDtype, BOOLEANtype, RANGEtype,
//     VOIDtype, USERDEFtype,
// };

// class ConstDecl: public BasicAstNode 
// {
// public:
//     Identifier* name;
//     BasicConst* value;
//     ConstDecl(Identifier* name, BasicConst* value): name(name), value(value) {}
// };

// class BasicConst: public Expression
// {
// public:
//     TypeKind type = TypeKind::ERRORtype;
// };

// class IntegerNode: public BasicConst
// {
// public:
//     int integerVal;
//     IntegerNode(int integerVal): integerVal(integerVal) {
//         type = TypeKind::INTtype;
//     }
// };

// class RealNode: public BasicConst
// {
// public:
//     double realVal;
//     RealNode(double realVal): realVal(realVal) {
//         type = TypeKind::REALtype;
//     }
// };

// class CharNode: public BasicConst
// {
// public:
//     char charVal;
//     CharNode(char charVal): charVal(charVal) {
//         type = TypeKind::CHARtype;
//     }
// };

// class StringNode: public BasicConst
// {
// public:
//     string stringVal;
//     StringNode(string stringVal): stringVal(stringVal) {
//         type = TypeKind::STRINGtype;
//     }
// };

// class BooleanNode: public BasicConst 
// {
// public:
//     bool boolVal;
//     BooleanNode(bool boolVal): boolVal(boolVal) {
//         type = TypeKind::BOOLEANtype;
//     }
// };

// class MaxIntNode: public BasicConst
// {
// public:
//     int maxintVal;
//     MaxIntNode() {
//         maxintVal = 32767;
//         type = TypeKind::INTtype;
//     }
// };

// /******************* TYPE ***********************/


// class TypeDecl: public BasicAstNode
// {
// public:  
//     Identifier*  name;
//     BasicType*   type;
//     TypeDecl(Identifier* name, BasicType* type): name(name), type(type) {}

// };

// class BasicType: public BasicAstNode
// {
// public:  
//     TypeKind type = TypeKind::ERRORtype;
//     BasicType() {}
// };

// class SimpleType: public BasicType
// {
// public:  
//     SimpleType() {}
// };

// class ArrayType: public BasicType
// {
// public: 
//     BasicType* range;
//     BasicType* elementType;
//     ArrayType(BasicType* range, BasicType* elementType): range(range), elementType(elementType) { 
//         type = TypeKind:: ARRAYtype;
//     }
// };

// class RecordType: public BasicType
// {
// public:  
//     VarDeclList* fieldList;
//     RecordType(VarDeclList* fieldList): fieldList(fieldList) { 
//         type = TypeKind::RECORDtype;
//     }

// };

// class BooleanType: public SimpleType
// {
// public:
//     BooleanType() { type = TypeKind::BOOLEANtype; }
// };

// class CharType: public SimpleType
// {
// public:
//     CharType() { type = TypeKind::CHARtype; }
// };

// class IntegerType: public SimpleType 
// {
// public: 
//     IntegerType() { type = TypeKind::INTtype; }
// };

// class RealType: public SimpleType
// {
// public: 
//     RealType() { type = TypeKind::REALtype; }
// };

// class StringType: public SimpleType
// {
// public: 
//     StringType() { type = TypeKind::STRINGtype; }
// };

// class RangeType: public SimpleType
// {
// public:
//     Expression* lowerB, *upperB;
//     RangeType(Expression* lowerB, Expression* upperB): lowerB(lowerB), upperB(upperB) {}
// };

// class VoidType: public SimpleType
// {
// public:
//     VoidType() { type = TypeKind::VOIDtype; }
// };

// //这个可能会有点问题
// class UserDefType: public SimpleType
// {

// };

// /******************** VAR ***********************/

// class VarDecl: public BasicAstNode
// {
// public:  
//     Identifier* name;
//     BasicType*  type;
//     VarDecl(Identifier* name, BasicType* type): name(name), type(type) {}
// };

// /***************** routine body ****************/
// enum class Direction {
//     To, DownTo
// };

// class AssignStmt: public Stmt
// {
// public:
//     Expression* name;   //ID, arrayref, recordref都继承了expression
//     Expression* value;
//     AssignStmt(Expression* name, Expression* value): name(name), value(value) {}

// };

// class IfStmt: public Stmt
// {
// public: 
//     Expression* cond;
//     StmtList* thenStmts;
//     StmtList* elseStmts;
    
//     //with else clause
//     IfStmt(Expression* cond, StmtList* thenStmts, StmtList* elseStmts): cond(cond), thenStmts(thenStmts), elseStmts(elseStmts) {}
//     //miss else clause
//     IfStmt(Expression* cond, StmtList* thenStmts): cond(cond), thenStmts(thenStmts) {}

// };

// class RepeatStmt: public Stmt
// {
// public:
//     Expression* cond;
//     StmtList* loopStmts;
//     RepeatStmt(Expression* cond, StmtList* loopStmts): cond(cond), loopStmts(loopStmts) {}
// };

// class WhileStmt: public Stmt
// {
// public:
//     Expression* cond;
//     StmtList* loopStmts;
//     WhileStmt(Expression* cond, StmtList* loopStmts): cond(cond), loopStmts(loopStmts) {}

// };

// class ForStmt: public Stmt
// {
// public:  
//     Identifier* name;
//     Expression* start;
//     Direction direction;
//     Expression* end;
//     StmtList* loopStmts;
//     ForStmt(Identifier* name, Expression* start, Direction direction, Expression* end, StmtList* loopStmts): 
//         name(name), start(start), direction(direction), end(end), loopStmts(loopStmts) {}
// };

// class CaseStmt: public Stmt
// {
// public:
//     Expression* exp;
//     CaseExprList* caseList;
//     CaseStmt(Expression* exp, CaseExprList* caseList): exp(exp), caseList(caseList) {}

// };

// class CaseExpr: public Stmt
// {
// public:
//     Expression* cond;
//     StmtList*   exeStmts;
//     CaseExpr(Expression* cond, StmtList* exeStmts): cond(cond), exeStmts(exeStmts) {}
// };

// class GotoStmt: public Stmt
// {
// public: 
//     int label;
//     GotoStmt(int label): label(label) {}
// };

// enum class SYSPROC {
//     WRITE, WRITELN,
// };

// enum class SYSFUNCT {
//     ABS,  CHR, ODD,  ORD, 
//     PRED, SQR, SQRT, SUCC,
// };

// class ProcCallStmt: public Stmt
// {

// };

// class SysProcCall: public ProcCallStmt
// {
// public:  
//     SYSPROC procName;
//     ArgList* args;
//     //有参数
//     SysProcCall(SYSPROC procName, ArgList* args): procName(procName), args(args) {}
//     //无参数
//     SysProcCall(SYSPROC procName): procName(procName) {}
// };

// class SysFuncCall: public ProcCallStmt, public Expression
// {
// public:
//     SYSFUNCT functName;
//     ArgList* args;
//     SysFuncCall(SYSFUNCT functName, ArgList* args): functName(functName), args(args) {}
//     SysFuncCall(SYSFUNCT functName): functName(functName) {}
// };

// class UserDefProcCall: public ProcCallStmt, public Expression
// {
// public:
//     Identifier* procName;
//     ArgList*    args;
//     //有参数
//     UserDefProcCall(Identifier* procName, ArgList* args): procName(procName), args(args) {}
//     //无参数
//     UserDefProcCall(Identifier* procName): procName(procName) {}

// };

// class ReadProcCall: public ProcCallStmt
// {
// public:
//     Expression* readElement;
//     ReadProcCall(Expression* readElement): readElement(readElement) {}
// };

// /******************** expr **********************/
// enum class BinaryOperator {
//     GEop, GTop, LEop, LTop, EQUALop, UNEQUALop,
//     PLUSop, MINUSop, MULop, DIVop, MODop,
//     ORop, ANDop
// };
// enum class UnaryOperator {
//     NOTop, NEGop,
// };

// class BinaryExpr: public Expression
// {
// public:  
//     BinaryOperator bOp;
//     Expression* leftOperand, *rightOperand;
//     BinaryExpr(Expression* leftOperand, BinaryOperator bOp, Expression* rightOperand): leftOperand(leftOperand), bOp(bOp), rightOperand(rightOperand) {}
// };

// class UnaryExpr: public Expression
// {
// public:  
//     UnaryOperator uOp;
//     Expression* operand;
//     UnaryExpr(UnaryOperator uOp, Expression* operand): uOp(uOp), operand(operand) {}

// };

// class Identifier: public Expression
// {
// public: 
//     string name;
//     Identifier(const string& name): name(name) {}
// };

// class ArrayElementRef: public Expression
// {
// public:
//     Identifier* arrayName;
//     Expression* index;
//     ArrayElementRef(Identifier* arrayName, Expression* index): arrayName(arrayName), index(index) {}
// };

// class RecordElementRef: public Expression
// {
// public:
//     Identifier* recordName;
//     Identifier* field;
//     RecordElementRef(Identifier* recordName, Identifier* field): recordName(recordName), field(field) {}
// };

// }