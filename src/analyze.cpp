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
	Scope currentScope = sc_top();
	if(node->nodeType == "Program") {
		ast::childrenList* children = node->getChildrenList();
		string progName;
		int progLineNo;
		string progDataType;
		for (auto child : *children) {
			if (child->nodeType == "Identifier") {
				//sc_create(child->id);
				progName = child->id;
				progLineNo = child->lineNo;
				//st_insert(progName, child->lineNo, 0, "Function", )
			}
			else if (child->nodeType != "Parameter") {
				progDataType = child->nodeType;
			}
		}
		st_insert(progName, progLineNo, 0, "Function", progDataType);
		sc_create(progName);
		for (auto child : *children) {
			if(child->nodeType == "Parameter")
		}
	}
}

static void popScope(ast::BasicAstNode *node)
{

}

void typeCheck(ast::BasicAstNode *Tree)
{
    
}

