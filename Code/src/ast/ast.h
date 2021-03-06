#ifndef _AST_H_
#define _AST_H_

#include<iostream>
#include<vector>
#include<llvm/IR/Value.h>
#include <llvm/Support/Casting.h>
#include <llvm/Support/raw_ostream.h>

#include "gen/llvm/GenLLVMType.h"
#include "gen/llvm/GenLLVMConstant.h"

#include <string>
#include "../symTab.h"
using namespace std;
int get_token(void);

extern int lineno;

namespace ast {

	/************************************************/
	class BasicAstNode;
	class Identifier;
	class Expression;
	class Name;
	class BasicStmt;
	typedef vector<BasicAstNode*> childrenList;
	typedef vector<Identifier*> NameList;

	/******************program***********************/
	class Program;
	class ProgramHead;
	class Routine;
	class RoutineHead;
	class StmtList;

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
	typedef vector<TypeDecl*>       TypeDeclList;
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
	class VoidType;
	class UserDefType;
	class ArrayType;
	class RecordType;

	/****************** routine body ****************/
	class LabelStmt;
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

	void astTraversal(ast::BasicAstNode* root, int blank);

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
		Scope scope;
		string nodeType;
		string subType;
		string exprType;
		string id;
		int lineNo;
		int intVal;
		BasicAstNode() {
			this->lineNo = lineno;
		}
		~BasicAstNode() {};
		virtual void printAstNode() {}

        virtual llvm::Value* codeGen() {}
		virtual childrenList* getChildrenList() {
			return new childrenList();
		}
	};


	class Expression : public BasicAstNode
	{
	public:
		Expression() {}
	};

	class Identifier : public Expression
	{
	public:
		string name;
		Identifier(const string& name) : name(name) {
			nodeType = "Identifier";
			id = name;
		}

		void printAstNode() {
			cout << "Identifier:" << name << endl;
		}
        llvm::Value *codeGen();
	};

	class Name : public Expression
	{
	public:
		string name;
		Name(const string& name) : name(name) {
			nodeType = "Name";
			id = name;
		}
		void printAstNode() {
			cout << "Name:" << name << endl;
		}
        llvm::Value *codeGen();
	};

	class BasicStmt : public BasicAstNode
	{
	public:
		BasicStmt() {
			nodeType = "Stmt";
		}
	};

	class StmtList : public BasicStmt
	{
	public:
		vector<BasicStmt*> stmtList;
		StmtList() {}
		void stmtPushBack(BasicStmt* stmt) {
			stmtList.push_back(stmt);
		}
		vector<BasicStmt*>* getStmtList() {
			return &stmtList;
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			for (auto stmt : stmtList) {
				children->push_back((BasicAstNode*)stmt);
			}
			return children;
		}

        llvm::Value *codeGen();
		void printAstNode() {
			cout << "StmtList" << endl;
		}
	};

	/******************program***********************/
	class Program : public BasicAstNode
	{
	public:
		ProgramHead* programHead;
		Routine* routine;
		Program(ProgramHead* programHead, Routine* routine) : programHead(programHead), routine(routine) {
			nodeType = "Program";
		}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)programHead);
			children->push_back((BasicAstNode*)routine);
			return children;
		}
		void printAstNode() {
			cout << "Program" << endl;
		}
        llvm::Value *codeGen();
	};

	class ProgramHead : public BasicAstNode
	{
	public:
		Identifier* name;
		ParamList*  parameters;
		BasicType*  returnType;
		ProgramHead(Identifier* name, ParamList* parameters, BasicType* returnType) :
			name(name), parameters(parameters), returnType(returnType) {
			nodeType = "ProgramHead";
		}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)name);
			for (auto param : *parameters) {
				children->push_back((BasicAstNode*)param);
			}
			children->push_back((BasicAstNode*)returnType);
			return children;
		}
		void printAstNode() {
			cout << "ProgramHead" << endl;
		}
        llvm::Value *codeGen();
	};

	class Routine : public BasicAstNode
	{
	public:
		RoutineHead* routineHead;
		StmtList* routineBody;
		Routine(RoutineHead* routineHead, StmtList* routineBody) : routineHead(routineHead), routineBody(routineBody) {}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)routineHead);
			for (auto stmt : *(routineBody->getStmtList())) {
				children->push_back((BasicAstNode*)stmt);
			}
			return children;
		}
		void printAstNode() {
			cout << "Routine" << endl;
		}
        llvm::Value *codeGen();
	};

	class RoutineHead : public BasicAstNode
	{
	public:
		ConstDeclList*      constPart;
		TypeDeclList*       typePart;
		VarDeclList*        varPart;
		RoutinePartList*    routinePart;
		RoutineHead(ConstDeclList* constPart, TypeDeclList* typePart, VarDeclList* varPart, RoutinePartList* routinePart) :
			constPart(constPart), typePart(typePart), varPart(varPart), routinePart(routinePart) {}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			if (constPart) {
				for (auto constdecl : *constPart) {
					children->push_back((BasicAstNode*)constdecl);
				}
			}
			if (typePart) {
				for (auto typedecl : *typePart) {
					children->push_back((BasicAstNode*)typedecl);
				}
			}
			if (varPart) {
				for (auto vardecl : *varPart) {
					children->push_back((BasicAstNode*)vardecl);
				}
			}
			if (routinePart) {
				for (auto routine : *routinePart) {
					children->push_back((BasicAstNode*)routine);
				}
			}
			return children;
		}
		void printAstNode() {
			cout << "RoutineHead" << endl;
		}
        llvm::Value *codeGen();
	};

	/****************program head********************/
	class Parameter : public BasicAstNode
	{
	public:
		Identifier* name;
		BasicType*  type;
		Parameter(Identifier* name, BasicType* type) : name(name), type(type) {
			nodeType = "Parameter";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)name);
			children->push_back((BasicAstNode*)type);
			return children;
		}
		void printAstNode() {
			cout << "Parameter" << endl;
		}
	};

	/****************** const ***********************/
	enum class TypeKind {
		ERRORtype, INTtype, REALtype, CHARtype, STRINGtype,
		ARRAYtype, RECORDtype, BOOLEANtype, RANGEtype,
		VOIDtype, USERDEFtype,
	};

	class ConstDecl : public BasicAstNode
	{
	public:
		Name* name;
		BasicConst* value;
		ConstDecl(Name* name, BasicConst* value) : name(name), value(value) {
			nodeType = "Decl";
			subType = "const";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)name);
			children->push_back((BasicAstNode*)value);
			return children;
		}
		void printAstNode() {
			cout << "ConstDecl" << endl;
		}
        llvm::Value *codeGen();
	};

	class BasicConst : public Expression
	{
	public:
		TypeKind type = TypeKind::ERRORtype;
		BasicConst() {
			nodeType = "BasicConst";
		}
	};

	class IntegerNode : public BasicConst
	{
	public:
		int integerVal;
		IntegerNode(int integerVal) : integerVal(integerVal) {
			type = TypeKind::INTtype;
			intVal = integerVal;
			subType = "Integer";
			exprType = "Integer";
		}
		void printAstNode() {
			cout << "IntegerNode: " << integerVal << endl;
		}
        llvm::Value *codeGen() override{
            return gen::getLLVMConstINT(integerVal);
        }
	};

	class RealNode : public BasicConst
	{
	public:
		double realVal;
		RealNode(double realVal) : realVal(realVal) {
			type = TypeKind::REALtype;
			subType = "Real";
			exprType = "Real";
		}
		void printAstNode() {
			cout << "ReadNode: " << realVal << endl;
		}
        llvm::Value *codeGen() override {
            return gen::getLLVMConstREAL(realVal);
        }
	};

	class CharNode : public BasicConst
	{
	public:
		char charVal;
		CharNode(char charVal) : charVal(charVal) {
			type = TypeKind::CHARtype;
			subType = "Char";
			exprType = "Char";
		}
		void printAstNode() {
			cout << "CharNode: " << charVal << endl;
		}
        llvm::Value *codeGen() override{
            return gen::getLLVMConstCHAR(charVal);
        }
	};

	class StringNode : public BasicConst
	{
	public:
		string stringVal;
		StringNode(string stringVal) : stringVal(stringVal) {
			type = TypeKind::STRINGtype;
			subType = "String";
			exprType = "String";
		}
		void printAstNode() {
			cout << "StringNode: " << stringVal << endl;
		}
        llvm::Value *codeGen() override{
            return gen::getLLVMConstSTRING(stringVal);
        }
	};

	class BooleanNode : public BasicConst
	{
	public:
		bool boolVal;
		BooleanNode(bool boolVal) : boolVal(boolVal) {
			type = TypeKind::BOOLEANtype;
			subType = "Boolean";
			exprType = "Boolean";
		}
		void printAstNode() {
			cout << "BooleanNode: " << boolVal << endl;
		}
        llvm::Value *codeGen() override{
            return gen::getLLVMConstBOOL(boolVal);
        }
	};

	class MaxIntNode : public BasicConst
	{
	public:
		int maxintVal;
		MaxIntNode() {
			maxintVal = 32767;
			type = TypeKind::INTtype;
			subType = "MaxInt";
			exprType = "MaxInt";
		}
		void printAstNode() {
			cout << "MaxIntNode: " << maxintVal << endl;
		}
        llvm::Value *codeGen() override{
            return gen::getLLVMConstINT(maxintVal);
        }
	};

	/******************* TYPE ***********************/


	class TypeDecl : public BasicAstNode
	{
	public:
		Name*       name;
		BasicType*  type;
		TypeDecl(Name* name, BasicType* type) : name(name), type(type) {
			nodeType = "Decl";
			subType = "type";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)name);
			children->push_back((BasicAstNode*)type);
			return children;
		}
		void printAstNode() {
			cout << "TypeDecl" << endl;
		}
        llvm::Value* codeGen();
	};

	class BasicType : public BasicAstNode
	{
	public:
		TypeKind type = TypeKind::ERRORtype;
		BasicType() {
			nodeType = "BasicType";
		}
	};

	class SimpleType : public BasicType
	{
	public:
		SimpleType() {}
	};

	class ArrayType : public BasicType
	{
	public:
		BasicType* range;
		BasicType* elementType;
		ArrayType(BasicType* range, BasicType* elementType) : range(range), elementType(elementType) {
			type = TypeKind::ARRAYtype;
			subType = "Array";
			exprType = "Array";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)range);
			children->push_back((BasicAstNode*)elementType);
			return children;
		}
		void printAstNode() {
			cout << "Array" << endl;
		}
	};

	class RecordType : public BasicType
	{
	public:
		VarDeclList* fieldList;
		RecordType(VarDeclList* fieldList) : fieldList(fieldList) {
			type = TypeKind::RECORDtype;
			subType = "Record";
			exprType = "Record";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			for (auto field : *fieldList) {
				children->push_back((BasicAstNode*)field);
			}
			return children;
		}
		void printAstNode() {
			cout << "Record" << endl;
		}
	};

	class BooleanType : public SimpleType
	{
	public:
		BooleanType() { type = TypeKind::BOOLEANtype; subType = "Boolean"; exprType = "Boolean";}
		void printAstNode() {
			cout << "Boolean" << endl;
		}
	};

	class CharType : public SimpleType
	{
	public:
		CharType() { type = TypeKind::CHARtype; subType = "Char"; exprType = "Char"; }
		void printAstNode() {
			cout << "Char" << endl;
		}
	};

	class IntegerType : public SimpleType
	{
	public:
		IntegerType() { type = TypeKind::INTtype; subType = "Integer"; exprType = "Integer"; }
		void printAstNode() {
			cout << "Integer" << endl;
		}
	};

	class RealType : public SimpleType
	{
	public:
		RealType() { type = TypeKind::REALtype; subType = "Real"; exprType = "Real"; }
		void printAstNode() {
			cout << "Real" << endl;
		}
	};

	class StringType : public SimpleType
	{
	public:
		StringType() { type = TypeKind::STRINGtype; subType = "String"; exprType = "String"; }
		void printAstNode() {
			cout << "String" << endl;
		}
	};

	class RangeType : public SimpleType
	{
	public:
		Expression* lowerB, *upperB;
		Name* lowerBName, *upperBName;
		enum ValOrName { val, name };
		int type;
		RangeType(Name* lowerBName, Name* upperBName) : lowerBName(lowerBName), upperBName(upperBName) {
			type = ValOrName::name;
			subType == "Range";
			exprType = "Range";
		}
		RangeType(Expression* lowerB, Expression* upperB) : lowerB(lowerB), upperB(upperB) {
			type = ValOrName::val;
			subType == "Range";
			exprType = "Range";
		}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			if (type == ValOrName::name) {
				children->push_back((BasicAstNode*)lowerBName);
				children->push_back((BasicAstNode*)upperBName);
			}
			else if (type == ValOrName::val) {
				children->push_back((BasicAstNode*)lowerB);
				children->push_back((BasicAstNode*)upperB);
			}
			return children;
		}
		void printAstNode() {
			cout << "Range" << endl;
		}
	};

	class VoidType : public SimpleType
	{
	public:
		VoidType() { type = TypeKind::VOIDtype; subType = "Void"; exprType = "Void"; }
		void printAstNode() {
			cout << "VOID" << endl;
		}
	};

	//这个可能会有点问题
	class UserDefType : public BasicType
	{
	public:
		Name* typeName;
		UserDefType(Name* typeName) : typeName(typeName) {
			type = TypeKind::USERDEFtype;
			//subType = "UserDef";
			subType = typeName->name;
		}
		void printAstNode() {
			cout << "UserDefType: " << typeName->name << endl;
		}
	};

	/******************** VAR ***********************/

	class VarDecl : public BasicAstNode
	{
	public:
		Identifier* name;
		BasicType*  type;
		VarDecl(Identifier* name, BasicType* type) : name(name), type(type) { 
			nodeType = "Decl"; 
			subType = "var";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)name);
			children->push_back((BasicAstNode*)type);
			return children;
		}
		void printAstNode() {
			cout << "VarDecl" << endl;
		}
        llvm::Value* codeGen();
	};

	/***************** routine body ****************/
	enum class Direction {
		To, DownTo
	};

	class LabelStmt : public BasicStmt
	{
	public:
		int label;
		BasicStmt* stmt;
		bool hasLabel;
		LabelStmt(int label, BasicStmt* stmt) : label(label), stmt(stmt) {
			hasLabel = true;
			subType = "Label";
		}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)stmt);
			return children;
		}

		void printAstNode() {
			cout << "LabelStmt: " << label << endl;
		}

        llvm::Value* codeGen();
	};

	class AssignStmt : public BasicStmt
	{
	public:
		Expression* name;   //ID, arrayref, recordref都继承了expression
		Expression* value;
		AssignStmt(Expression* name, Expression* value) : name(name), value(value) { subType = "Assign"; }

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)name);
			children->push_back((BasicAstNode*)value);
			return children;
		}
		void printAstNode() {
			cout << "AssignStmt" << endl;
		}
        llvm::Value* codeGen();

	};

	class IfStmt : public BasicStmt
	{
	public:
		Expression* cond;
		BasicStmt* thenStmt;
		BasicStmt* elseStmt;

		//with else clause
		IfStmt(Expression* cond, BasicStmt* thenStmt, BasicStmt* elseStmt) : cond(cond), thenStmt(thenStmt), elseStmt(elseStmt) { subType = "If"; }
		//miss else clause
		IfStmt(Expression* cond, BasicStmt* thenStmt) : cond(cond), thenStmt(thenStmt) {}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)cond);
			children->push_back((BasicAstNode*)thenStmt);
			if (elseStmt) {
				children->push_back((BasicAstNode*)elseStmt);
			}
			return children;
		}
		void printAstNode() {
			cout << "IfStmt" << endl;
		}
        llvm::Value* codeGen();

	};

	class RepeatStmt : public BasicStmt
	{
	public:
		Expression* cond;
		StmtList* loopStmts;
		RepeatStmt(Expression* cond, StmtList* loopStmts) : cond(cond), loopStmts(loopStmts) { subType = "Repeat"; }
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)cond);
			for (auto stmt : *(loopStmts->getStmtList())) {
				children->push_back((BasicAstNode*)stmt);
			}
			return children;
		}
		void printAstNode() {
			cout << "RepeatStmt" << endl;
		}
        llvm::Value* codeGen();
	};

	class WhileStmt : public BasicStmt
	{
	public:
		Expression* cond;
		BasicStmt* loopStmt;
		WhileStmt(Expression* cond, BasicStmt* loopStmt) : cond(cond), loopStmt(loopStmt) { subType = "While"; }
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)cond);
			children->push_back((BasicAstNode*)loopStmt);
			return children;
		}
		void printAstNode() {
			cout << "WhileStmt" << endl;
		}
        llvm::Value* codeGen();
	};

	class ForStmt : public BasicStmt
	{
	public:
		Identifier* name;
		Expression* start;
		Direction direction;
		Expression* end;
		BasicStmt* loopStmt;
		ForStmt(Identifier* name, Expression* start, Direction direction, Expression* end, BasicStmt* loopStmt) :
			name(name), start(start), direction(direction), end(end), loopStmt(loopStmt) { subType = "For";	}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)name);
			children->push_back((BasicAstNode*)start);
			children->push_back((BasicAstNode*)end);
			children->push_back((BasicAstNode*)loopStmt);
			return children;
		}
		void printAstNode() {
			cout << "ForStmt" << endl;
		}
        llvm::Value* codeGen();
	};

	class CaseStmt : public BasicStmt
	{
	public:
		Expression* exp;
		CaseExprList* caseList;
		CaseStmt(Expression* exp, CaseExprList* caseList) : exp(exp), caseList(caseList) { subType = "Case"; }
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)exp);
			for (auto caseexpr : *caseList) {
				children->push_back((BasicAstNode*)caseexpr);
			}
			return children;
		}
		void printAstNode() {
			cout << "CaseStmt" << endl;
		}
        llvm::Value* codeGen();

	};

	class CaseExpr : public BasicStmt
	{
	public:
		Expression* cond;
		BasicStmt* exeStmt;
		CaseExpr(Expression* cond, BasicStmt* exeStmt) : cond(cond), exeStmt(exeStmt) { subType = "CaseExpr"; }
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)cond);
			children->push_back((BasicAstNode*)exeStmt);
			return children;
		}
		void printAstNode() {
			cout << "CaseExpr" << endl;
		}
	};

	class GotoStmt : public BasicStmt
	{
	public:
		int label;
		GotoStmt(int label) : label(label) { subType = "Goto"; }
		void printAstNode() {
			cout << "GOTO: " << label << endl;
		}
        llvm::Value* codeGen();
	};

	enum class SYSPROC {
		WRITE, WRITELN,
	};

	enum class SYSFUNCT {
		ABS, CHR, ODD, ORD,
		PRED, SQR, SQRT, SUCC,
	};

	class ProcCallStmt : public BasicStmt
	{
	public:
		ProcCallStmt() { subType = "ProcCall";  }
	};

	class SysProcCall : public ProcCallStmt
	{
	public:
		SYSPROC procName;
		ArgList* args;
		//有参数
		SysProcCall(SYSPROC procName, ArgList* args) : procName(procName), args(args) {}
		//无参数
		SysProcCall(SYSPROC procName) : procName(procName) {}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			for (auto arg : *args) {
				children->push_back((BasicAstNode*)arg);
			}
			return children;
		}
		void printAstNode() {
			cout << "SysProcCall: ";
			if (procName == SYSPROC::WRITE) cout << "WRITE" << endl;
			else if (procName == SYSPROC::WRITELN) cout << "WRITELN" << endl;
		}
        llvm::Value* codeGen();
	};

	class SysFuncCall : public ProcCallStmt, public Expression
	{
	public:
		SYSFUNCT functName;
		ArgList* args;
		SysFuncCall(SYSFUNCT functName, ArgList* args) : functName(functName), args(args) {}
		SysFuncCall(SYSFUNCT functName) : functName(functName) {}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			for (auto arg : *args) {
				children->push_back((BasicAstNode*)arg);
			}
			return children;
		}
		void printAstNode() {
			cout << "SysFuncCall: ";
			if (functName == SYSFUNCT::ABS) cout << "ABS" << endl;
			else if (functName == SYSFUNCT::CHR) cout << "CHR" << endl;
			else if (functName == SYSFUNCT::ODD) cout << "ODD" << endl;
			else if (functName == SYSFUNCT::ORD) cout << "ORD" << endl;
			else if (functName == SYSFUNCT::PRED) cout << "PRED" << endl;
			else if (functName == SYSFUNCT::SQR) cout << "SQR" << endl;
			else if (functName == SYSFUNCT::SQRT) cout << "SQRT" << endl;
			else if (functName == SYSFUNCT::SUCC) cout << "SUCC" << endl;

		}
        llvm::Value* codeGen();
	};

	class UserDefProcCall : public ProcCallStmt, public Expression
	{
	public:
		Name*    procName;
		ArgList* args;
		//有参数
		UserDefProcCall(Name* procName, ArgList* args) : procName(procName), args(args) { 
			ProcCallStmt::subType = "ProcCall"; 
			Expression::subType = "ProcCall";  
			ProcCallStmt::id = procName->name; 
			Expression::id = procName->name; 
		}
		//无参数
		UserDefProcCall(Name* procName) : procName(procName) {}

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			if (args) {
				for (auto arg : *args) {
					children->push_back((BasicAstNode*)arg);
				}
			}
			return children;
		}
		void printAstNode() {
			cout << "UserDefProcCall: " << procName->name << endl;
		}

        llvm::Value* codeGen();
	};

	class ReadProcCall : public ProcCallStmt
	{
	public:
		Expression* readElement;
		ReadProcCall(Expression* readElement) : readElement(readElement) { subType = "ReadProcCall"; }

		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)readElement);
			return children;
		}
		void printAstNode() {
			cout << "ReadProcCall" << endl;
		}
        llvm::Value* codeGen();
	};

	/******************** expr **********************/
	enum class BinaryOperator {
		GEop, GTop, LEop, LTop, EQUALop, UNEQUALop,
		PLUSop, MINUSop, MULop, DIVop, MODop,
		ORop, ANDop
	};
	enum class UnaryOperator {
		NOTop, NEGop, POSop,
	};

	class BinaryExpr : public Expression
	{
	public:
		BinaryOperator bOp;
		Expression* leftOperand, *rightOperand;
		BinaryExpr(Expression* leftOperand, BinaryOperator bOp, Expression* rightOperand) : leftOperand(leftOperand), bOp(bOp), rightOperand(rightOperand) {
			nodeType = "Expr";
			subType = "Binary";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)leftOperand);
			children->push_back((BasicAstNode*)rightOperand);
			return children;
		}
		void printAstNode() {
			cout << "BinaryExpr:";
			if (bOp == BinaryOperator::GEop) cout << ">=" << endl;
			else if (bOp == BinaryOperator::GTop) cout << ">" << endl;
			else if (bOp == BinaryOperator::LEop) cout << "<=" << endl;
			else if (bOp == BinaryOperator::LTop) cout << "<" << endl;
			else if (bOp == BinaryOperator::EQUALop) cout << "=" << endl;
			else if (bOp == BinaryOperator::UNEQUALop) cout << "!=" << endl;
			else if (bOp == BinaryOperator::PLUSop) cout << "+" << endl;
			else if (bOp == BinaryOperator::MINUSop) cout << "-" << endl;
			else if (bOp == BinaryOperator::MULop) cout << "*" << endl;
			else if (bOp == BinaryOperator::DIVop) cout << "/" << endl;
			else if (bOp == BinaryOperator::MODop) cout << "%" << endl;
			else if (bOp == BinaryOperator::ORop) cout << "OR" << endl;
			else if (bOp == BinaryOperator::ANDop) cout << "AND" << endl;
		}
        llvm::Value* codeGen();
	};

	class UnaryExpr : public Expression
	{
	public:
		UnaryOperator uOp;
		Expression* operand;
		UnaryExpr(UnaryOperator uOp, Expression* operand) : uOp(uOp), operand(operand) {
			nodeType = "Expr";
			subType = "Unary";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)operand);
			return children;
		}
		void printAstNode() {
			cout << "UnaryExpr:";
			if (uOp == UnaryOperator::NEGop) cout << "-" << endl;
			else if (uOp == UnaryOperator::NOTop) cout << "NOT" << endl;
		}
        llvm::Value* codeGen();
	};


	class ArrayElementRef : public Expression
	{
	public:
		Identifier* arrayName;
		Expression* index;
		ArrayElementRef(Identifier* arrayName, Expression* index) : arrayName(arrayName), index(index) {
			nodeType = "Expr";
			subType = "ArrayElementRef";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)arrayName);
			children->push_back((BasicAstNode*)index);
			return children;
		}
		void printAstNode() {
			cout << "ArrayElementRef" << endl;
		}
        llvm::Value* codeGen();
	};

	class RecordElementRef : public Expression
	{
	public:
		Identifier* recordName;
		Identifier* field;
		RecordElementRef(Identifier* recordName, Identifier* field) : recordName(recordName), field(field) {
			nodeType = "Expr";
			subType = "RecordElementRef";
		}
		childrenList* getChildrenList() {
			childrenList* children = new childrenList();
			children->push_back((BasicAstNode*)recordName);
			children->push_back((BasicAstNode*)field);
			return children;
		}
		void printAstNode() {
			cout << "RecordElementRef" << endl;
		}
        llvm::Value* codeGen();
	};

}

#endif
