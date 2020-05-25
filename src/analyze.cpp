#include "pch.h"
#include "analyze.h"

//Scope global;

void buildSymTable(ast::BasicAstNode *Tree)
{
	//initSymTable();
	Scope global = sc_create("global");
	Tree->scope = global;
	traverse(Tree, insertNode, popScope);
	sc_pop();
	st_print();
}

//void initSymTable()
//{
//	global = sc_create("global");
//}

static void traverse(ast::BasicAstNode * node, void(*preProc) (ast::BasicAstNode *), void(*postProc) (ast::BasicAstNode *)) {
	ast::childrenList* children = node->getChildrenList();
	if (children->size()) {
		for (auto child : *children) {
			if (child != NULL) {
				preProc(child);
				traverse(child, preProc, postProc);
				postProc(child);
			}
		}
	}
}

//TODO: lineno, loc
static void insertNode(ast::BasicAstNode *node)
{
	//Scope currentScope = sc_top();
	if(node->nodeType == "ProgramHead") { // program head
		ast::childrenList* children = node->getChildrenList();
		string progName, progDataType, paraName, paraType;
		int progLineNo, paraLineNo;
		for (auto child : *children) {
			if (child->nodeType == "Identifier") {
				progName = child->id;
				progLineNo = child->lineNo;
				child->scope = sc_top();
			}
			else if (child->nodeType == "BasicType") {
				progDataType = child->subType;
			}
		}
		st_insert(progName, progLineNo, 0, "Function", progDataType);
		sc_create(progName);
		for (auto child : *children) {
			if (child->nodeType == "Parameter") {
				ast::childrenList* gchildren = child->getChildrenList();
				for (auto gchild : *gchildren) {
					if (gchild->nodeType == "Identifier") { // name
						paraName = gchild->id;
						paraLineNo = gchild->lineNo;
						gchild->scope = sc_top();
					}
					else { // type
						paraType = gchild->subType;
					}
				}
				st_insert(paraName, paraLineNo, 0, "Variable", paraType);
			}
		}
	}
	else if (node->nodeType == "Decl") { //TODO: record, array
		string declName, declType;
		int declLineNo;
		ast::childrenList* children = node->getChildrenList();
		if (node->subType == "const") {
			for (auto child : *children) {
				if (child->nodeType == "Name") {
					declName = child->id;
					declLineNo = child->lineNo;
					child->scope = sc_top();
				}
				else if (child->nodeType == "BasicConst") {
					declType = child->subType;
				}
			}
			st_insert(declName, declLineNo, 0, "Const", declType);
		}
		//else if (node->subType == "type") {
		//	for (auto child : *children) {
		//		if (child->nodeType == "Name") {
		//			declName = child->id;
		//			declLineNo = child->lineNo;
		//			child->scope = sc_top();
		//		}
		//		else if (child->nodeType == "BasicType") {
		//			declType = child->subType;
		//		}
		//	}
		//}
		else if (node->subType == "var") {
			for (auto child : *children) {
				if (child->nodeType == "Identifier") {
					declName = child->id;
					declLineNo = child->lineNo;
					child->scope = sc_top();
				}
				else if (child->nodeType == "BasicType") {
					declType = child->subType;
				}
			}
			st_insert(declName, declLineNo, 0, "Variable", declType);
		}
		
	}
}

static void popScope(ast::BasicAstNode *node)
{
	if (node->nodeType == "Program") {
		sc_pop();
	}
}

void typeCheck(ast::BasicAstNode *Tree)
{
    
}

