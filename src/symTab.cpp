#include "pch.h"
#include "symTab.h"
using namespace std;

static int current_depth = 0;
static vector<Scope> scopeStack; // current nested scopes
static vector<Scope> scopes; // all existing scopes

static int hashFunc(string str)
{
    int value = 0;
    for(int i=0; i<str.length(); i++){
        value = ( (value << SHIFT) + str[i] ) % TABLE_SIZE;
    }
	//cout << value << endl;
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
	scopeStack.push_back(newScope);
	scopes.push_back(newScope);
	return newScope;
}

void sc_pop()
{
	scopeStack.pop_back();
	current_depth--;
}

Scope sc_top()
{
	return scopeStack[current_depth - 1];
}

void st_insert(string id, int lineNo, int loc, string recType, string dataType)
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
		BucketListRec newRec = BucketListRec(id, lineNo, loc, recType, dataType);
		currentScope->hashTable[hashValue].push_back(newRec);
	}
}

int st_lookup(string id)
{
	int hashValue = hashFunc(id);
	Scope currentScope = sc_top();
	while (currentScope) {
		for (auto item : currentScope->hashTable[hashValue]) {
			if (item.id == id) {
				return item.memloc;
			}
		}
		currentScope = currentScope->parentScope;
	}
	return -1;
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
				
				cout << iden.id << '\t' << iden.memloc << '\t' << iden.recType << '\t' << iden.dataType << '\t';
				for (auto lineNo : iden.lines) {
					cout << '\t' << lineNo << " ";
				}
				cout << endl;
			}
		}
	}
	cout << "====================================================================" << endl;
}