#include<iostream>
#include<vector>
using namespace std;

/************************************************/
class Identifier;
class Expression;
class Stmt;
typedef vector<Identifier*> NameList;
/******************program***********************/
class Program;
class ProgramHead;
class Routine;
class RoutineHead;
typedef vector<Stmt*> StmtList;

/****************program head********************/
class Parameter;
typedef vector<Parameter*> ParamList;

/****************** routine head ****************/
class LabelDecl;
class ConstDecl;
class TypeDecl;
class VarDecl;
typedef vector<LabelDecl*>      LabelDeclList;
typedef vector<ConstDecl*>      ConstDeclList;
typedef vector<TypeDecl*>       TypeDecllList;
typedef vector<VarDecl*>        VarDeclList;
typedef vector<Program*>        RoutinePartList;

/****************** const ***********************/
class BasicConst;
class IntegerNode;
class RealNode;
class CharNode;
class StringNode;
class BooleanNode;
class MaxIntNode;

/****************** type ************************/
class BasicType;
class SimpleType;
class CharType;
class IntegerType;
class RealType;
class StringType;
class BooleanType;
class RangeType;
class ArrayType;
class RecordType;

/****************** VAR *************************/
class VarDecl;
typedef vector<VarDecl*> VarDeclList;

/****************** routine body ****************/
class AssignStmt;
class ProcCallStmt;
class IfStmt;
class RepeatStmt;
class WhileStmt;
class ForStmt;
class CaseStmt;
class GotoStmt;
class CaseExpr;
typedef vector<CaseExpr*> CaseExprList;
typedef vector<Expression*> ArgList;


/****************** expr ************************/
class BinaryExpr;
class UnaryExpr;
typedef vector<Expression*> ExpressionList;


/*
|---------------------------------------------------------------|
|                                                               |
|                             START                             |
|                                                               |
|---------------------------------------------------------------|
*/

class BasicAstNode
{ 
public:  
    BasicAstNode(){};
    ~BasicAstNode(){};
}; 

class Expression: public BasicAstNode
{
public:
    Expression() {}
};

class Stmt: public BasicAstNode 
{
public:
    Stmt() {}
};

/******************program***********************/
class Program: public BasicAstNode
{
public:
    ProgramHead* programHead;
    Routine* routine;
    Program(ProgramHead* programHead, Routine* routine): programHead(programHead), routine(routine) {}
};

class ProgramHead: public BasicAstNode 
{
public: 
    Identifier* name;
    ParamList*  parameters;
    BasicType*  returnType;
    ProgramHead(Identifier* name, ParamList* parameters, BasicType* returnType):
        name(name), parameters(parameters), returnType(returnType) {}
};

class Routine: public BasicAstNode 
{
public: 
    RoutineHead* routineHead;
    StmtList* routineBody;
    Routine(RoutineHead* routineHead, StmtList* routineBody): routineHead(routineHead), routineBody(routineBody) {}
};

class RoutineHead: public BasicAstNode 
{
public:
    LabelDeclList*      labelPart;
    ConstDeclList*      constPart;
    TypeDecllList*      typePart;
    VarDeclList*        varPart;
    RoutinePartList*    routinePart;
    RoutineHead(LabelDeclList* labelPart, ConstDeclList* constPart, TypeDecllList* typePart, VarDeclList* varPart, RoutinePartList* routinePart):
        labelPart(labelPart), constPart(constPart), typePart(typePart), varPart(varPart), routinePart(routinePart) {}
};

/****************program head********************/
class Parameter: public BasicAstNode
{
public:  
    Identifier* name;
    BasicType*  type;
    Parameter(Identifier* name, BasicType* type): name(name), type(type) {}
};

/****************** const ***********************/
enum class TypeKind {
    ERROR, INT, REAL, CHAR, STRING, 
    ARRAY, RECORD, BOOLEAN, RANGE,
    VOID, USERDEF,
};

class ConstDecl: public BasicAstNode 
{
public:
    Identifier* name;
    BasicConst* value;
    ConstDecl(Identifier* name, BasicConst* value): name(name), value(value) {}
};

class BasicConst: public Expression
{
public:
    TypeKind type = TypeKind::ERROR;
};

class IntegerNode: public BasicConst
{
public:
    int integerVal;
    IntegerNode(int integerVal): integerVal(integerVal) {
        type = TypeKind::INT;
    }
};

class RealNode: public BasicConst
{
public:
    double realVal;
    RealNode(double realVal): realVal(realVal) {
        type = TypeKind::REAL;
    }
};

class CharNode: public BasicConst
{
public:
    char charVal;
    CharNode(char charVal): charVal(charVal) {
        type = TypeKind::CHAR;
    }
};

class StringNode: public BasicConst
{
public:
    string stringVal;
    StringNode(string stringVal): stringVal(stringVal) {
        type = TypeKind::STRING;
    }
};

class BooleanNode: public BasicConst 
{
public:
    bool boolVal;
    BooleanNode(bool boolVal): boolVal(boolVal) {
        type = TypeKind::BOOLEAN;
    }
};

class MaxIntNode: public BasicConst
{
public:
    int maxintVal;
    MaxIntNode() {
        maxintVal = 32767;
        type = TypeKind::INT;
    }
};

/******************* TYPE ***********************/


class TypeDecl: public BasicAstNode
{
public:  
    Identifier*  name;
    BasicType*   type;

};

class BasicType: public BasicAstNode
{
public:  
    TypeKind type = TypeKind::ERROR;
    BasicType() {}
};

class SimpleType: public BasicType
{
public:  
    SimpleType() {}
};

class ArrayType: public BasicType
{
public: 
    SimpleType* range;
    BasicType* elementType;
    ArrayType(SimpleType* range, BasicType* elementType): range(range), elementType(elementType) { 
        type = TypeKind:: ARRAY;
    }
};

class RecordType: public BasicType
{
public:  
    VarDeclList* fieldList;
    RecordType(VarDeclList* fieldList): fieldList(fieldList) { 
        type = TypeKind::RECORD;
    }

};

class BooleanType: public SimpleType
{
public:
    BooleanType() { type = TypeKind::BOOLEAN; }
};

class CharType: public SimpleType
{
public:
    CharType() { type = TypeKind::CHAR; }
};

class IntegerType: public SimpleType 
{
public: 
    IntegerType() { type = TypeKind::INT; }
};

class RealType: public SimpleType
{
public: 
    RealType() { type = TypeKind::REAL; }
};

class StringType: public SimpleType
{
public: 
    StringType() { type = TypeKind::STRING; }
};

class RangeType: public SimpleType
{
public:
    Expression* lowerB, *upperB;
    RangeType(Expression* lowerB, Expression* upperB): lowerB(lowerB), upperB(upperB) {}
};

//这个可能会有点问题
class UserDefType: public SimpleType
{

};

/******************** VAR ***********************/

class VarDecl: public BasicAstNode
{
public:  
    Identifier* name;
    BasicType*  type;
    VarDecl(Identifier* name, BasicType* type): name(name), type(type) {}
};

/***************** routine body ****************/
enum class Direction {
    TO, DOWNTO
};

class AssignStmt: public Stmt
{
public:
    Expression* name;   //ID, arrayref, recordref都继承了expression
    Expression* value;
    AssignStmt(Expression* name, Expression* value): name(name), value(value) {}

};

class IfStmt: public Stmt
{
public: 
    Expression* cond;
    StmtList* thenStmts;
    StmtList* elseStmts;
    
    //with else clause
    IfStmt(Expression* cond, StmtList* thenStmts, StmtList* elseStmts): cond(cond), thenStmts(thenStmts), elseStmts(elseStmts) {}
    //miss else clause
    IfStmt(Expression* cond, StmtList* thenStmts): cond(cond), thenStmts(thenStmts) {}

};

class RepeatStmt: public Stmt
{
public:
    Expression* cond;
    StmtList* loopStmts;
    RepeatStmt(Expression* cond, StmtList* loopStmts): cond(cond), loopStmts(loopStmts) {}
};

class WhileStmt: public Stmt
{
public:
    Expression* cond;
    StmtList* loopStmts;
    WhileStmt(Expression* cond, StmtList* loopStmts): cond(cond), loopStmts(loopStmts) {}

};

class ForStmt: public Stmt
{
public:  
    Identifier* name;
    Expression* start;
    Direction direction;
    Expression* end;
    StmtList* loopStmts;
    ForStmt(Identifier* name, Expression* start, Direction direction, Expression* end, StmtList* loopStmts): 
        name(name), start(start), direction(direction), end(end), loopStmts(loopStmts) {}
};

class CaseStmt: public Stmt
{
public:
    Expression* exp;
    CaseExprList* caseList;
    CaseStmt(Expression* exp, CaseExprList* caseList): exp(exp), caseList(caseList) {}

};

class CaseExpr: public Stmt
{
public:
    Expression* cond;
    StmtList*   exeStmts;
    CaseExpr(Expression* cond, StmtList* exeStmts): cond(cond), exeStmts(exeStmts) {}
};

class GotoStmt: public Stmt
{
public: 
    int label;
    GotoStmt(int label): label(label) {}
};

enum class SYS_PROC {
    WRITE, WRITELN,
};

enum class SYS_FUNCT {
    ABS,  CHR, ODD,  ORD, 
    PRED, SQR, SQRT, SUCC,
};

class ProcCallStmt: public Stmt
{

};

class SysProcCall: public ProcCallStmt
{
public:  
    SYS_PROC procName;
    ArgList* args;
    //有参数
    SysProcCall(SYS_PROC procName, ArgList* args): procName(procName), args(args) {}
    //无参数
    SysProcCall(SYS_PROC procName): procName(procName) {}
};

class SysFuncCall: public ProcCallStmt
{
    SYS_FUNCT functName;
    ArgList* args;
    SysFuncCall(SYS_FUNCT functName, ArgList* args): functName(functName), args(args) {}
    SysFuncCall(SYS_FUNCT functName): functName(functName) {}
};

class UserDefProcCall: public ProcCallStmt
{
public:
    Identifier* procName;
    ArgList*    args;
    //有参数
    UserDefProcCall(Identifier* procName, ArgList* args): procName(procName), args(args) {}
    //无参数
    UserDefProcCall(Identifier* procName): procName(procName) {}

};

//有问题
class ReadProcCall: public ProcCallStmt
{
public:

};

/******************** expr **********************/
enum class BinaryOperator {
    GE, GT, LE, LT, EQUAL, UNEQUAL,
    PLUS, MINUS, MUL, DIV, MOD,
    OR, AND
};
enum class UnaryOperator {
    NOT,
};

class BinaryExpr: public Expression
{
public:  
    BinaryOperator bOp;
    Expression* leftOperand, *rightOperand;
    BinaryExpr(Expression* leftOperand, BinaryOperator bOp, Expression* rightOperand): leftOperand(leftOperand), bOp(bOp), rightOperand(rightOperand) {}
};

class UnaryExpr: public Expression
{
public:  
    UnaryOperator uOp;
    Expression* operand;
    UnaryExpr(UnaryOperator uOp, Expression* operand): uOp(uOp), operand(operand) {}

};

class Identifier: public Expression
{
public: 
    string name;
    Identifier(const string& name): name(name) {}
};

class ArrayElementRef: public Expression
{
public:
    Identifier* arrayName;
    Expression* index;
    ArrayElementRef(Identifier* arrayName, Expression* index): arrayName(arrayName), index(index) {}
};

class RecordElementRef: public Expression
{
public:
    Identifier* recordName;
    Identifier* field;
    RecordElementRef(Identifier* recordName, Identifier* field): recordName(recordName), field(field) {}
}