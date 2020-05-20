#include<iostream>
#include<vector>
using namespace std;
class Identifier;
class Program;
class ProgramHead;
class Routine;
class RoutineHead; ///
class RoutineBody;
class LabelDecl;
typedef vector<LabelDecl*> LabelDeclList;
class ConstDecl;
typedef vector<ConstDecl*> ConstDeclList;
class TypeDecl;
class TypeDefinition;
typedef vector<TypeDefinition*> TypeDeflList;
class VarDecl;
typedef vector<VarDecl*> VarDeclList;
class RoutinePart;

//for const_part
class ConstExprList;
class ConstValue;
//for type_part
class SimpleTypeDecl;
class ArrayTypeDecl;
class RecordTypeDecl;
class FieldDecl;
typedef vector<FieldDecl*> FieldDeclList;
class NameList;
//for routine_part
class FuncDecl;
class FuncHead;
class SubRoutine;
class Parameters;
class ParaDeclList;
class ParaTypeList;
class VarParaList;
class ProcDecl;
class ProcHead;
//for routine_body
class CompoundStmt;
class StmtList;
class Stmt;
class NonLabelStmt;
class AssignStmt;
class ProcStmt;
class IfStmt;
class ElseClause;
class RepeatStmt;
class WhileStmt;
class ForStmt;
class Direction;
class CaseStmt;
typedef vector<CaseStmt*> CaseExprList;
class CaseExpr;
class GotoStmt;
class Expression;
typedef vector<Expression*> ExpressionList;
class Expr;
class Term;
class Factor;
class ArgsList;


class BasicAstNode
{ 
public:  
    BasicAstNode(){};
    ~BasicAstNode(){};
}; 

class Program: public BasicAstNode
{
public:
    ProgramHead* program_head;
    Routine* routine;
};

class ProgramHead: public BasicAstNode 
{
public: 

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
    TypeDeflList    type_part;
    VarDeclList     var_part;
    RoutinePart*    routine_part;

};

class LabelDecl: public BasicAstNode {};

class ConstDecl: public BasicAstNode 
{
public:  
    Identifier* name;
    ConstValue* const_value;

};

/************************** TYPE ************************/
enum class TypeKind {
    DEFAULT, INT, REAL, CHAR, STRING, ARRAY, RECORD, BOOLEAN,
};

class TypeDefinition: public BasicAstNode
{
public:  
    Identifier* name;
    TypeDecl*   type_decl;

};

class TypeDecl: public BasicAstNode
{
public:  

};

class BasicTypeNode: public BasicAstNode
{
public:  
    TypeKind type = TypeKind::DEFAULT;
};

class ArrayType: public BasicTypeNode
{
public: 

};
class RecordType: public BasicTypeNode
{
public:  
    FieldDeclList* field_list;
    RecordType() { this->type = TypeKind::RECORD;}
};

class FieldDecl: public BasicAstNode
{
public: 
    Identifier* name;
    
}
