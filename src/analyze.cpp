#include "analyze.h"

void buildSymTable(ast::BasicAstNode *Tree)
{
	Scope global = sc_create("global");
	Tree->scope = global;
	traverse(Tree, insertNode, popScope);
	sc_pop();
	st_print();
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

static void insertNode(ast::BasicAstNode *node)
{
	if(node->nodeType == "ProgramHead") { // program head
		ast::childrenList* children = node->getChildrenList();
		string progName, progDataType, paraName, paraType, progArrayType, paraArrayType;
		int progLineNo, paraLineNo, progArrayBegin, progArrayEnd, paraArrayBegin, paraArrayEnd, size;
		int isProgRecord = 0;
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
					isProgRecord = 1;
					sc_create(progName+"Rec");
				}
			}
		}
		if (isProgRecord) {
			sc_pop();
		}
		st_insert(progName, progLineNo, size, "Function", progDataType);
		if (isProgRecord) {
			sc_push(progName + "Rec");
		}
		sc_create(progName);
		for (auto child : *children) {
			if (child->nodeType == "Parameter") {
				ast::childrenList* gchildren = child->getChildrenList();
				int isParaRecord = 0;
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
							isParaRecord = 1;
							sc_create(paraName);
						}
					}
				}
				if (isParaRecord) {
					sc_pop();
				}
				st_insert(paraName, paraLineNo, size, "Variable", paraType);
				if (isParaRecord) {
					sc_push(paraName);
				}
			}
		}
	}
	else if (node->nodeType == "Decl") { 
		string declName, declType, arrayType;
		int declLineNo, arrayBegin, arrayEnd;
		map<string, string> recordMember;
		ast::childrenList* children = node->getChildrenList();
		ast::BasicAstNode* fchild = (*(node->getChildrenList()))[0];
		ast::BasicAstNode* lchild = (*(node->getChildrenList()))[1];


		if (node->subType == "const") {
			declName = fchild->id;
			declLineNo = fchild->lineNo;
			fchild->scope = sc_top();
			declType = lchild->subType;
			if (sc_top()->userDefType[declType] != "") {
				declType = sc_top()->userDefType[declType];
			}
			fchild->exprType = declType;
			st_insert(declName, declLineNo, varSize[declType], "Const", declType);
		}
		else if (node->subType == "type") {
			int isRecord = 0;
			declName = fchild->id;
			declLineNo = fchild->lineNo;
			fchild->scope = sc_top();
			declType = lchild->subType;
			if (declType == "Array") {
				arrayBegin = (*((*(lchild->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
				arrayEnd = (*((*(lchild->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
				arrayType = (*(lchild->getChildrenList()))[1]->subType;
				arrayRec newArray = arrayRec(declName, arrayBegin, arrayEnd, arrayType);
				sc_top()->arrayList.push_back(newArray);
			}
			else if (declType == "Record") {
				sc_create(declName);
				sc_pop();
				isRecord = 1;
			}
			fchild->exprType = declType;
			sc_top()->userDefType.insert(pair<string, string>(declName, declType));
			if (isRecord) {
				sc_push(declName);
			}
		}
		else if (node->subType == "var") {
			int size;
			int isRecord = 0;
			declName = fchild->id;
			declLineNo = fchild->lineNo;
			fchild->scope = sc_top();

			declType = lchild->subType;
			size = varSize[declType];
			if (declType == "Array") {
				arrayBegin = (*((*(lchild->getChildrenList()))[0]->getChildrenList()))[0]->intVal;
				arrayEnd = (*((*(lchild->getChildrenList()))[0]->getChildrenList()))[1]->intVal;
				arrayType = (*(lchild->getChildrenList()))[1]->subType;
				arrayRec newArray = arrayRec(declName, arrayBegin, arrayEnd, arrayType);
				sc_top()->arrayList.push_back(newArray);
				size = (arrayEnd - arrayBegin) * varSize[arrayType];
			}
			else if (declType == "Record") {
				isRecord = 1;
				sc_create(declName);
			}
			if (sc_top()->userDefType[declType] != "") {
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
					sc_create(declName, sc_find(declType));
					declType = "Record";
					size = 0;
					sc_push(declName);
					for (auto hash : sc_top()->hashTable) {
						for (auto item : hash) {
							size += varSize[item.dataType];
						}
					}
					sc_pop();
				}
				else {
					declType = sc_top()->userDefType[declType];
				}
			}
			fchild->exprType = declType;
			if (isRecord) {
				sc_pop();
			}
			st_insert(declName, declLineNo, size, "Variable", declType);
			if (isRecord) {
				sc_push(declName);
			}
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
					cout << "Error in line[" << lineNo << "]: Undefined expression: '" << idName << "'." << endl;
					exit(-1);
				}
			}
		}
	}
	if (node->subType == "ProcCall") {
		node->exprType = st_lookup(node->id);
	}
	if (node->nodeType == "Stmt") {
		if (node->subType == "Assign") {
			ast::BasicAstNode *child = (*(node->getChildrenList()))[0];
			string idName = child->id;
			int lineNo = child->lineNo;
			string idType = st_lookup(idName);
			if ((*(node->getChildrenList()))[1]->exprType == "") {
				(*(node->getChildrenList()))[1]->exprType = st_lookup((*(node->getChildrenList()))[1]->id);
			}
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
			if (stmtType == "") {
				stmtType = st_lookup(fchild->id);
			}
			for (auto child : *children) {
				if (child->subType == "CaseExpr") {
					string caseType = (*(child->getChildrenList()))[0]->exprType;
					int lineNo = (*(child->getChildrenList()))[0]->lineNo;
					if (!canChange(caseType, stmtType) && (caseType != stmtType)) {
						cout << "Error in line[" << lineNo << "]: Case type does not match <" << stmtType << ", " << caseType << ">." << endl;
						exit(-1);
					}
				}
			}
		}
	}
	else if (node->nodeType == "Expr") {
		if (node->subType == "ArrayElementRef") {
			string arrayName = (*(node->getChildrenList()))[0]->id;
			int lineNo = node->lineNo;
			string dataType;
			int begin, end;
			for (auto array : sc_top()->arrayList) {
				if (array.arrayName == arrayName) {
					dataType = array.arrayType;
					begin = array.arrayBegin;
					end = array.arrayEnd;
					break;
				}
			}
			int index = (*(node->getChildrenList()))[1]->intVal;
			if (index >= end || index < begin) {
				cout << "Error in line[" << lineNo << "]: Array reference out of bounds." << endl;
				exit(-1);
			}
			node->exprType = dataType;
		}
		else if (node->subType == "RecordElementRef") {
			string recordName = (*(node->getChildrenList()))[0]->id;
			string memberName = (*(node->getChildrenList()))[1]->id;
			string memberType;
			int lineNo = node->lineNo;
			sc_push(recordName);
			memberType = st_lookupCurr(memberName);
			if (memberType == "") {
				cout << "Error in line[" << lineNo << "]: No member named '" << memberName << "' in '" << recordName << "'." << endl;
				exit(-1);
			}
			node->exprType = memberType;
			sc_pop();
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
	}
}
