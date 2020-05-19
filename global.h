#include<iostream>
#include<vector>



class AstNode
{ 
}; 

class Statement: public AstNode 
{};

class StatementList: public Statement
{};

class Program: public AstNode
{};

class Routine: public Program
{};

class Expression: public AstNode 
{};

class LabelDecl: public Statement
{};

class ArrayType: public Statement
{};

class FieldDecl: public Statement
{};

class RecordType: public Statement
{};

class Identifier: public Expression
{};

class ArrayRef: public Expression
{};

class RecordRef: public Expression
{};

class ConstValue: public Expression
{};

class TypeCosnt: public Statement 
{};

class ConstDecl: public Statement
{};

class VarDecl: public Statement
{};

class IntegerType: public ConstValue
{};

class RealType: public ConstValue
{};

class CharType: public ConstValue
{};

class BooleanType: public ConstValue
{};

class RangeType: public Expression
{};

class FuncCall: public Expression, Statement
{};

class ProcCall: public Statement
{};

class SysProcCall: public ProcCall
{};

class SysFuncCall: public FuncCall
{};

class Operator: public Expression
{};

class AssignmentStmt: public Statement
{};

class IfStmt: public Statement
{};

class WhileStmt: public Statement
{};

class RepeatStmt: public Statement
{};

class ForStmt: public Statement
{};

class CaseStmt: public Statement
{};

class SwitchStmt: public Statement
{};

class LabelStmt: public Statement
{};

class GotoStmt: public Statement
{};