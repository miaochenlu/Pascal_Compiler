#include "symTab.h"
using namespace std;

static int current_depth = 0;
static int memloc[1024];
static vector<Scope> scopeStack; // current nested scopes
static vector<Scope> scopes; // all existing scopes

static int hashFunc(string str)
{
    int value = 0;
    for(int i=0; i<str.length(); i++){
        value = ( (value << SHIFT) + str[i] ) % TABLE_SIZE;
    }
    return value;
}

Scope sc_create(string scopeName)
{
    Scope newScope = new ScopeRec(scopeName);
	newScope->depth = current_depth;
	if (current_depth != 0) {
		newScope->parentScope = scopeStack[current_depth - 1];
	}
	else {
		newScope->parentScope = nullptr;
	}
	current_depth++;
	if (newScope->parentScope == NULL || newScope->parentScope->scopeName == "global") {
		memloc[current_depth - 1] = 0;
	}
	else {
		memloc[current_depth - 1] = memloc[current_depth - 2];
	}
	scopeStack.push_back(newScope);
	scopes.push_back(newScope);
	return newScope;
}

Scope sc_create(string scopeName, Scope oriScope)
{
	Scope newScope = new ScopeRec(scopeName, oriScope);
	scopes.push_back(newScope);
	return newScope;
}

void sc_pop()
{
	scopeStack.pop_back();
	current_depth--;
}

void sc_push(string name)
{
	for (auto scope : scopes) {
		if (scope->scopeName == name) {
			scopeStack.push_back(scope);
			current_depth++;
		}
	}
}

Scope sc_find(string name) 
{
	for (auto scope : scopes) {
		if (scope->scopeName == name) {
			return scope;
		}
	}
	return sc_find("global");
}

Scope sc_top()
{
	return scopeStack[current_depth - 1];
}

void st_insert(string id, int lineNo, int size, string recType, string dataType)
{
	Scope currentScope = sc_top();
	int hashValue = hashFunc(id);
	int found = 0;
	BucketList currentTable = currentScope->hashTable[hashValue];
	for (auto item : currentTable) {
		if (item.id == id) {
			item.lines.push_back(lineNo);
			found = 1;
			break;
		}
	}
	if (!found) {
		BucketListRec newRec = BucketListRec(id, lineNo, memloc[current_depth-1], recType, dataType);
		memloc[current_depth - 1] += size;
		currentScope->hashTable[hashValue].push_back(newRec);
	}
	else {
		cout << "Error in line[" << lineNo << "]: Variable '" << id << "' is already defined." << endl;
		exit(-1);
	}
}

string st_lookup(string id)
{
	int hashValue = hashFunc(id);
	Scope currentScope = sc_top();
	while (currentScope) {
		for (auto item : currentScope->hashTable[hashValue]) {
			if (item.id == id) {
				return item.dataType;
			}
		}
		currentScope = currentScope->parentScope;
	}
	return "";
}

string st_lookupCurr(string id)
{
	int hashValue = hashFunc(id);
	Scope currentScope = sc_top();
	for (auto item : currentScope->hashTable[hashValue]) {
		if (item.id == id) {
			return item.dataType;
		}
	}
	return "";
}

void st_print()
{
	for (auto item : scopes) {
		cout << "====================================================================" << endl;
		cout << "Scope Name: " << item->scopeName <<  " <depth: " << item->depth << ">" << endl;
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (item->hashTable[i].size() == 0) {
				continue;
			}
			for (auto iden : item->hashTable[i]) {
				cout.setf(ios::left);
				cout.width(12);
				cout << iden.id;
				cout.setf(ios::left);
				cout.width(12);
				cout << iden.recType;
				cout.setf(ios::left);
				cout.width(12);
				cout << iden.dataType;
				cout.setf(ios::left);
				cout.width(12); 
				cout << iden.memloc;
				for (auto lineNo : iden.lines) {
					cout << lineNo << " ";
				}
				if (iden.dataType == "Array") {
					int begin, end;
					string type;
					for (auto array : item->arrayList) {
						if (array.arrayName == iden.id) {
							begin = array.arrayBegin;
							end = array.arrayEnd;
							type = array.arrayType;
							break;
						}
					}
					cout << '\t' << "<Array: range [" << begin << ":" << end << "], type " << type << " >" ;
				}
				cout << endl;
			}
		}
	}
	cout << "====================================================================" << endl;
}
