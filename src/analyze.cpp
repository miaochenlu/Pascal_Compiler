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

//TODO:  loc
static void insertNode(ast::BasicAstNode *node)
{
	//Scope currentScope = sc_top();
	if(node->nodeType == "ProgramHead") { // program head
		ast::childrenList* children = node->getChildrenList();
		string progName, progDataType, paraName, paraType, progArrayType, paraArrayType;
		int progLineNo, paraLineNo, progArrayBegin, progArrayEnd, paraArrayBegin, paraArrayEnd, size;
		map<string, string> progRecordMember, paraRecordMember; // TODO
		for (auto child : *children) {
			if (child->nodeType == "Identifier") {
				progName = child->id;
				progLineNo = child->lineNo;
				child->scope = sc_top();
			}
			else if (child->nodeType == "BasicType") {
				progDataType = child->subType;
				size = varSize[progDataType];
				if (progDataType == "Array") {
					progArrayBegin = (*((*(child->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
					progArrayEnd = (*((*(child->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
					progArrayType = (*(child->getChildrenList()))[1]->subType;
					arrayRec newArray = arrayRec(progName, progArrayBegin, progArrayEnd, progArrayType);
					sc_top()->arrayList.push_back(newArray);
					size = (progArrayEnd - progArrayBegin) * varSize[progArrayType];
				}
				else if (progDataType == "Record") {
					map<string, string> recMem;
					ast::childrenList* gchildren = child->getChildrenList();
					size = 0;
					for (auto gchild : *gchildren) {
						string id = (*(gchild->getChildrenList()))[0]->id;
						string type = (*(gchild->getChildrenList()))[1]->subType;
						recMem.insert(pair<string, string>(id, type));
						size += varSize[type];
					}
					recordRec newRecord = recordRec(progName, recMem);
				}
			}
		}
		st_insert(progName, progLineNo, size, "Function", progDataType);
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
						size = varSize[paraType];
						if (progDataType == "Array") {
							paraArrayBegin = (*((*(gchild->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
							paraArrayEnd = (*((*(gchild->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
							paraArrayType = (*(gchild->getChildrenList()))[1]->subType;
							arrayRec newArray = arrayRec(paraName, paraArrayBegin, paraArrayEnd, paraArrayType);
							sc_top()->arrayList.push_back(newArray);
							size = (paraArrayEnd - paraArrayBegin) * varSize[paraArrayType];
						}
						else if (paraType == "Record") {
							map<string, string> recMem;
							ast::childrenList* ggchildren = gchild->getChildrenList();
							size = 0;
							for (auto ggchild : *ggchildren) {
								string id = (*(ggchild->getChildrenList()))[0]->id;
								string type = (*(ggchild->getChildrenList()))[1]->subType;
								recMem.insert(pair<string, string>(id, type));
								size += varSize[type];
							}
							recordRec newRecord = recordRec(paraName, recMem);
						}
					}
				}
				st_insert(paraName, paraLineNo, size, "Variable", paraType);
			}
		}
	}
	else if (node->nodeType == "Decl") { 
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
			st_insert(declName, declLineNo, varSize[declType], "Const", declType);
		}
		else if (node->subType == "type") {
			int isRecord = 0;
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
						//map<string, string> recMem;
						//ast::childrenList* gchildren = child->getChildrenList();
						//for (auto gchild : *gchildren) {
						//	string id = (*(gchild->getChildrenList()))[0]->id;
						//	string type = (*(gchild->getChildrenList()))[1]->subType;
						//	recMem.insert(pair<string, string>(id, type));
						//}
						//recordRec newRecord = recordRec(declName, recMem);
						//sc_top()->recordList.push_back(newRecord);
						sc_create(declName);
						sc_pop();
						isRecord = 1;
					}
				}
			}
			sc_top()->userDefType.insert(pair<string, string>(declName, declType));
			//cout << declName << " : " << declType << " - " << sc_top()->scopeName << endl;
			if (isRecord) {
				sc_push(declName);
			}
		}
		else if (node->subType == "var") {
			int size;
			for (auto child : *children) {
				if (child->nodeType == "Identifier") {
					declName = child->id;
					declLineNo = child->lineNo;
					child->scope = sc_top();
				}
				else if (child->nodeType == "BasicType") {
					declType = child->subType;
					size = varSize[declType];
					if (declType == "Array") {
						arrayBegin = (*((*(child->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
						arrayEnd = (*((*(child->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
						arrayType = (*(child->getChildrenList()))[1]->subType;
						arrayRec newArray = arrayRec(declName, arrayBegin, arrayEnd, arrayType);
						sc_top()->arrayList.push_back(newArray);
						size = (arrayEnd - arrayBegin) * varSize[arrayType];
					}
					else if (declType == "Record") {
						//map<string, string> recMem;
						//ast::childrenList* gchildren = child->getChildrenList();
						//size = 0;
						//for (auto gchild : *gchildren) {
						//	string id = (*(gchild->getChildrenList()))[0]->id;
						//	string type = (*(gchild->getChildrenList()))[1]->subType;
						//	recMem.insert(pair<string, string>(id, type));
						//	size += varSize[type];
						//}
						//recordRec newRecord = recordRec(declName, recMem);
						sc_create(declName);
					}
					//cout << sc_top()->scopeName << endl;
					if (sc_top()->userDefType[declType] != "") {
						//cout << declType << " : " << sc_top()->userDefType[declType] << endl;
						//declType = sc_top()->userDefType[declType];
						if (sc_top()->userDefType[declType] == "Array") {
							for (auto array : sc_top()->arrayList) {
								if (array.arrayName == declType) {
									arrayRec newArray = arrayRec(declName, array);
									sc_top()->arrayList.push_back(newArray);
									size = (newArray.arrayEnd - newArray.arrayBegin) * varSize[newArray.arrayType];
								}
							}
							declType = "Array";
						}
						else if (sc_top()->userDefType[declType] == "Record") {
							cout << declName << " : " << declType << endl;
							sc_create(declName, sc_find(declType));
							declType = "Record";
							//cout << sc_top()->scopeName << endl;
							//for (auto record : sc_top()->recordList) {
							//	if (record.recordName == declType) {
							//		size = 0;
							//		//cout << "---2" << endl;
							//		recordRec newRecord = recordRec(declName, record);
							//		sc_top()->recordList.push_back(newRecord);
							//		for (auto rec : newRecord.recordMember) {
							//			size += varSize[rec.second];
							//		}
							//	}
							//}
						}
						else {
							declType = sc_top()->userDefType[declType];
						}
						
					}
				}
			}
			//cout << declType << endl;
			st_insert(declName, declLineNo, size, "Variable", declType);
		}
		
	}
}

static bool canChange(string type1, string type2)
{
	if ((type1 == "Integer" || type1 == "Real" || type1 == "Boolean") && (type2 == "Integer" || type2 == "Real" || type2 == "Boolean") ) {
		return true;
	}
	else {
		return false;
	}
}

static void checkNode(ast::BasicAstNode *node)
{
	if (node->nodeType != "Decl" && node->nodeType != "ProgramHead" && node->nodeType != "Parameter") {
		ast::childrenList *children = node->getChildrenList();
		for (auto child : *children) {
			if (child->nodeType == "Name" || child->nodeType == "Identifier") {
				int lineNo = child->lineNo;
				string idName = child->id;
				if (st_lookup(idName) == "") {
					//cout << sc_top()->scopeName << endl;
					cout << "Error in line[" << lineNo << "]: Undefined expression: '" << idName << "'." << endl;
					exit(-1);
				}
			}
		}
	}
	if (node->subType == "ProcCall") {
		//cout << node->id << endl;
		node->exprType = st_lookup(node->id);
	}
	/*else if (node->subType == "ArrayElementRef") {
		string arrayName = (*(node->getChildrenList()))[0]->id;
		string dataType;
		for (auto array : sc_top()->arrayList) {
			if (array.arrayName == arrayName) {
				dataType = array.arrayType;
			}
		}
		node->exprType = dataType;
	}
	else if (node->subType == "RecordElementRef") {
		string recordName = (*(node->getChildrenList()))[0]->id;
		string memberName = (*(node->getChildrenList()))[1]->id;
		string memberType;
		for (auto rec : sc_top()->recordList) {
			if (rec.recordName == recordName) {
				memberType = rec.recordMember[memberName];
			}
		}
		node->exprType = memberType;
	}*/
	if (node->nodeType == "Stmt") {
		if (node->subType == "Assign") {
			ast::BasicAstNode *child = (*(node->getChildrenList()))[0];
			string idName = child->id;
			int lineNo = child->lineNo;
			string idType = st_lookup(idName);
			string assignType = (*(node->getChildrenList()))[1]->exprType;
			if (idType == "") {
				idType = child->exprType;
			}
			if (!canChange(idType,assignType) && idType != assignType) {
				cout << "Error in line[" << lineNo << "]: Assignment type does not match <" << idType << ", " << assignType << ">." << endl;
				exit(-1);
			}
			child->exprType = assignType;
			node->exprType = assignType;
		}
		else if (node->subType == "For") {
			ast::BasicAstNode *child = (*(node->getChildrenList()))[0];
			string idName = child->id;
			int lineNo = (*(node->getChildrenList()))[1]->lineNo;
			string idType = st_lookup(idName);
			if (idType != "Integer" || (*(node->getChildrenList()))[1]->exprType != "Integer" || (*(node->getChildrenList()))[2]->exprType != "Integer") {
				cout << "Error in line[" << lineNo << "]: Condition in 'For' statement must be integer." << endl;
				exit(-1);
			}

		}
		else if (node->subType == "Case") {
			ast::childrenList *children = node->getChildrenList();
			ast::BasicAstNode *fchild = (*(node->getChildrenList()))[0];
			string stmtType = fchild->exprType;
			for (auto child : *children) {
				if (child->subType == "CaseExpr") {
					string caseType = (*(child->getChildrenList()))[0]->exprType;
					int lineNo = (*(child->getChildrenList()))[0]->lineNo;
					if (!canChange(caseType, stmtType) && (caseType != stmtType)) {
						cout << "Error in line[" << lineNo << "]: Case type does not match <" << caseType << ", " << stmtType << ">." << endl;
						exit(-1);
					}
				}
			}
		}
	}
	else if (node->nodeType == "Expr") {
		if (node->subType == "ArrayElementRef") {
			string arrayName = (*(node->getChildrenList()))[0]->id;
			string dataType;
			for (auto array : sc_top()->arrayList) {
				if (array.arrayName == arrayName) {
					dataType = array.arrayType;
				}
			}
			node->exprType = dataType;
		}
		else if (node->subType == "RecordElementRef") {
			string recordName = (*(node->getChildrenList()))[0]->id;
			string memberName = (*(node->getChildrenList()))[1]->id;
			string memberType;
			//cout << "BEFORE PUSH: " << sc_top()->scopeName << endl;
			//cout << recordName << endl;
			sc_push(recordName);
			memberType = st_lookup(memberName);
			//for (auto rec : sc_top()->recordList) {
			//	if (rec.recordName == recordName) {
			//		memberType = rec.recordMember[memberName];
			//	}
			//}
			node->exprType = memberType;
			//cout << "AFTER PUSH:" << sc_top()->scopeName << endl;
			sc_pop();
			//cout << "AFTER POP:" << sc_top()->scopeName << endl;
		}
		else if (node->subType == "Binary") {
			ast::BasicAstNode *fchild = (*(node->getChildrenList()))[0];
			ast::BasicAstNode *lchild = (*(node->getChildrenList()))[1];
			if (fchild->nodeType == "Name" || fchild->nodeType == "Identifier") {
				if (lchild->nodeType == "Name" || lchild->nodeType == "Identifier") {
					string fidName = fchild->id;
					string lidName = lchild->id;
					int lineNo = fchild->lineNo;
					string fidType = st_lookup(fidName);
					string lidType = st_lookup(lidName);
					if (!canChange(fidType, lidType) && fidType != lidType) {
						cout << "Error in line[" << lineNo << "]: Expression type does not match <" << fidType << ", " << lidType << ">." << endl;
						exit(-1);
					}
					node->exprType = fidType;
				}
				else {
					string fidName = fchild->id;
					int lineNo = fchild->lineNo;
					string fidType = st_lookup(fidName);
					string exprType = lchild->exprType;
					if (!canChange(fidType, exprType) && fidType != exprType) {
						cout << "Error in line[" << lineNo << "]: Expression type does not match <" << fidType << ", " << exprType << ">." << endl;
						exit(-1);
					}
					fchild->exprType = exprType;
					node->exprType = exprType;
				}
			}
			else {
				if (lchild->nodeType == "Name" || lchild->nodeType == "Identifier") {
					string exprType = fchild->exprType;
					string lidName = lchild->id;
					int lineNo = fchild->lineNo;
					string lidType = st_lookup(lidName);
					if (!canChange(exprType, lidType) && exprType != lidType) {
						cout << "Error in line[" << lineNo << "]: Expression type does not match <" << exprType << ", " << lidType << ">." << endl;
						exit(-1);
					}
					lchild->exprType = exprType;
					node->exprType = exprType;
				}
				else {
					int lineNo = fchild->lineNo;
					if (!canChange(fchild->exprType, lchild->exprType) && fchild->exprType != lchild->exprType) {
						cout << "Error in line[" << lineNo << "]: Expression type does not match <" << fchild->exprType << ", " << lchild->exprType << ">." << endl;
						exit(-1);
					}
					node->exprType = fchild->exprType;
				}
			}
		}
		else {
			ast::BasicAstNode *child = (*(node->getChildrenList()))[0];
			if (child->nodeType == "Name" || child->nodeType == "Identifier") {
				node->exprType = st_lookup(child->id);
			}
			else {
				node->exprType = (*(node->getChildrenList()))[0]->exprType;
			}
		}
	}
}

static void popScope(ast::BasicAstNode *node)
{
	if (node->nodeType == "Program" || node->subType == "Record") {
		sc_pop();
	}
}

static void pushScope(ast::BasicAstNode *node)
{
	if (node->nodeType == "ProgramHead") {
		ast::childrenList* children = node->getChildrenList();
		string progName;
		for (auto child : *children) {
			if (child->nodeType == "Identifier") {
				progName = child->id;
				break;
			}
		}
		sc_push(progName);
		//cout << "PUSH: " << progName << endl;
	}
}


