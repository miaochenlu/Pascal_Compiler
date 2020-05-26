#include "pch.h"
#include "analyze.h"

//Scope global;

void buildSymTable(ast::BasicAstNode *Tree)
{
	Scope global = sc_create("global");
	Tree->scope = global;
	traverse(Tree, insertNode, popScope);
	sc_pop();
	st_print();
	//cout << sc_top()->scopeName << endl;
	//map<string, string>::iterator it;
	//it = userDefType.begin();
	//while (it != userDefType.end()) {
	//	cout << it->first << " : " << it->second << endl;
	//	it++;
	//}
}

void typeCheck(ast::BasicAstNode *Tree)
{
	traverse(Tree, pushScope, checkNode);
	
}

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
		string progName, progDataType, paraName, paraType, progArrayType, paraArrayType;
		int progLineNo, paraLineNo, progArrayBegin, progArrayEnd, paraArrayBegin, paraArrayEnd;
		map<string, string> progRecordMember, paraRecordMember; // TODO
		for (auto child : *children) {
			if (child->nodeType == "Identifier") {
				progName = child->id;
				progLineNo = child->lineNo;
				child->scope = sc_top();
			}
			else if (child->nodeType == "BasicType") {
				progDataType = child->subType;
				if (progDataType == "Array") {
					progArrayBegin = (*((*(child->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
					progArrayEnd = (*((*(child->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
					progArrayType = (*(child->getChildrenList()))[1]->subType;
					arrayRec newArray = arrayRec(progName, progArrayBegin, progArrayEnd, progArrayType);
					sc_top()->arrayList.push_back(newArray);
				}
				else if (progDataType == "Record") {
					map<string, string> recMem;
					ast::childrenList* gchildren = child->getChildrenList();
					for (auto gchild : *gchildren) {
						string id = (*(gchild->getChildrenList()))[0]->id;
						string type = (*(gchild->getChildrenList()))[1]->subType;
						recMem.insert(pair<string, string>(id, type));
					}
					recordRec newRecord = recordRec(progName, recMem);
				}
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
						if (progDataType == "Array") {
							paraArrayBegin = (*((*(gchild->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
							paraArrayEnd = (*((*(gchild->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
							paraArrayType = (*(gchild->getChildrenList()))[1]->subType;
							arrayRec newArray = arrayRec(paraName, paraArrayBegin, paraArrayEnd, paraArrayType);
							sc_top()->arrayList.push_back(newArray);
						}
						else if (paraType == "Record") {
							map<string, string> recMem;
							ast::childrenList* ggchildren = gchild->getChildrenList();
							for (auto ggchild : *ggchildren) {
								string id = (*(ggchild->getChildrenList()))[0]->id;
								string type = (*(ggchild->getChildrenList()))[1]->subType;
								recMem.insert(pair<string, string>(id, type));
							}
							recordRec newRecord = recordRec(paraName, recMem);
						}
					}
				}
				st_insert(paraName, paraLineNo, 0, "Variable", paraType);
			}
		}
	}
	else if (node->nodeType == "Decl") { //TODO: record, array
		string declName, declType, arrayType;
		int declLineNo, arrayBegin, arrayEnd;
		map<string, string> recordMember;
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
					if (sc_top()->userDefType[declType] != "") {
						declType = sc_top()->userDefType[declType];
					}
				}
			}
			st_insert(declName, declLineNo, 0, "Const", declType);
		}
		else if (node->subType == "type") {
			for (auto child : *children) {
				if (child->nodeType == "Name") {
					declName = child->id;
					declLineNo = child->lineNo;
					child->scope = sc_top();
				}
				else if (child->nodeType == "BasicType") {
					declType = child->subType;
					if (declType == "Array") {
						arrayBegin = (*((*(child->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
						arrayEnd = (*((*(child->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
						arrayType = (*(child->getChildrenList()))[1]->subType;
						arrayRec newArray = arrayRec(declName, arrayBegin, arrayEnd, arrayType);
						sc_top()->arrayList.push_back(newArray);
					}
					else if (declType == "Record") {
						map<string, string> recMem;
						ast::childrenList* gchildren = child->getChildrenList();
						for (auto gchild : *gchildren) {
							string id = (*(gchild->getChildrenList()))[0]->id;
							string type = (*(gchild->getChildrenList()))[1]->subType;
							recMem.insert(pair<string, string>(id, type));
						}
						recordRec newRecord = recordRec(declName, recMem);
						sc_top()->recordList.push_back(newRecord);
					}
				}
			}
			sc_top()->userDefType.insert(pair<string, string>(declName, declType));
			//cout << declName << " : " << declType << " - " << sc_top()->scopeName << endl;
		}
		else if (node->subType == "var") {
			for (auto child : *children) {
				if (child->nodeType == "Identifier") {
					declName = child->id;
					declLineNo = child->lineNo;
					child->scope = sc_top();
				}
				else if (child->nodeType == "BasicType") {
					declType = child->subType;
					if (declType == "Array") {
						arrayBegin = (*((*(child->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
						arrayEnd = (*((*(child->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
						arrayType = (*(child->getChildrenList()))[1]->subType;
						arrayRec newArray = arrayRec(declName, arrayBegin, arrayEnd, arrayType);
						sc_top()->arrayList.push_back(newArray);
					}
					else if (declType == "Record") {
						map<string, string> recMem;
						ast::childrenList* gchildren = child->getChildrenList();
						for (auto gchild : *gchildren) {
							string id = (*(gchild->getChildrenList()))[0]->id;
							string type = (*(gchild->getChildrenList()))[1]->subType;
							recMem.insert(pair<string, string>(id, type));
						}
						recordRec newRecord = recordRec(declName, recMem);
					}
					//cout << sc_top()->scopeName << endl;
					if (sc_top()->userDefType[declType] != "") {
						//cout << sc_top()->userDefType[declType] << endl;
						//declType = sc_top()->userDefType[declType];
						if (sc_top()->userDefType[declType] == "Array") {
							for (auto array : sc_top()->arrayList) {
								if (array.arrayName == declType) {
									arrayRec newArray = arrayRec(declName, array);
									sc_top()->arrayList.push_back(newArray);
								}
							}
						}
						else if (sc_top()->userDefType[declType] == "Record") {
							//cout << declType << endl;
							for (auto record : sc_top()->recordList) {
								if (record.recordName == declType) {
									//cout << "---2" << endl;
									recordRec newRecord = recordRec(declName, record);
									sc_top()->recordList.push_back(newRecord);
								}
							}
						}
						declType = sc_top()->userDefType[declType];
					}
				}
			}
			st_insert(declName, declLineNo, 0, "Variable", declType);
		}
		
	}
}

static void checkNode(ast::BasicAstNode *node)
{

}

static void popScope(ast::BasicAstNode *node)
{
	if (node->nodeType == "Program") {
		sc_pop();
	}
}

static void pushScope(ast::BasicAstNode *node)
{
	if (node->nodeType == "Program") {
		ast::childrenList* children = node->getChildrenList();
		string progName;
		for (auto child : *children) {
			if (child->nodeType == "Identifier") {
				progName = child->id;
				break;
			}
		}

		//sc_push(node->)
	}
}


