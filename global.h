#include<iostream>
#include<vector>
using namespace std;

/************************************************/
class Identifier;
class Stmt;
typedef vector<Identifier*> NameList;
/******************program***********************/
class Program;
class ProgramHead;
class Routine;
class RoutineHead;
typedef vector<Stmt*> RoutineBody;

/****************program head********************/
class Parameter;
typedef vector<Parameter*> ParamList;

/****************** routine head ****************/
class LabelDecl;
class ConstDecl;
class TypeDecl;
class VarDecl;
class RoutinePart;
typedef vector<LabelDecl*>      LabelDeclList;
typedef vector<ConstDecl*>      ConstDeclList;
typedef vector<TypeDecl*>       TypeDecllList;
typedef vector<VarDecl*>        VarDeclList;
typedef vector<Program*>        RoutinePartlList;

/****************** const ***********************/
class BasicConst;
class IntegerNode;
class RealNode;
class CharNode;
class StringNode;
class BooleanNode;
class RangeNode;

/****************** type ************************/
class BasicType;
class SimpleType;
class IntegerType;
class RealType;
class StringType;
class BooleanType;
class ArrayType;
class RecordType;
class FieldDecl;

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

/****************** expr ************************/
class Expression;
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

/******************program***********************/
class Program: public BasicAstNode
{
public:
    ProgramHead* program_head;
    Routine* routine;
};

class ProgramHead: public BasicAstNode 
{
public: 
    Identifier* name;
    ParamList*  parameters;
    BasicType*  returnType;

};

class Routine: public BasicAstNode 
{
public: 
    RoutineHead* routine_head;
    RoutineBody* routine_body;

};

class RoutineHead: public BasicAstNode 
{
public:
    LabelDeclList   label_part;
    ConstDeclList   const_part;
    TypeDecllList   type_part;
    VarDeclList     var_part;
    RoutinePart*    routine_part;

};

/****************program head********************/
class Parameter: public BasicAstNode
{
public:  
    Identifier* name;
    BasicType*  type;

};



/******************* TYPE ***********************/
enum class TypeKind {
    DEFAULT, INT, REAL, CHAR, STRING, ARRAY, RECORD, BOOLEAN,
};


class TypeDecl: public BasicAstNode
{
public:  
    Identifier*  name;
    BasicType*   type;

};

class BasicType: public BasicAstNode
{
public:  
    TypeKind type = TypeKind::DEFAULT;
};

class ArrayType: public BasicType
{
public: 
/**
 * initialization
 **/ 
    ArrayType() { 
        this->type = TypeKind:: ARRAY;
    }
};
class RecordType: public BasicType
{
public:  
    RecordType() { this->type = TypeKind::RECORD;}

    VarDeclList* field_decl_list;
};

class IntegerType: public BasicType 
{
public: 
    IntegerType() { this->type = TypeKind::INT; }
};

class RealType: public BasicType 
{
public: 
    RealType() { this->type = TypeKind::REAL; }
};

class StringType: public BasicType
{
public: 
    StringType() { this->type = TypeKind::STRING; }
};

/******************** VAR ***********************/

class VarDecl: public BasicAstNode
{
public:  
    NameList* name_list;
    BasicType* type;
};

/***************** routine body ****************/
class Stmt: public BasicAstNode 
{
public:

};

class AssignStmt: public Stmt
{

};
class ProcCallStmt: public Stmt
{

};
class IfStmt: public Stmt
{

};
class RepeatStmt: public Stmt
{

};
class WhileStmt: public Stmt
{

};
class ForStmt: public Stmt
{

};
class CaseStmt: public Stmt
{

};
class GotoStmt: public Stmt
{

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

class Expression: public BasicAstNode
{

};
class BinaryExpr: public Expression
{

};
class UnaryExpr: public Expression
{

};