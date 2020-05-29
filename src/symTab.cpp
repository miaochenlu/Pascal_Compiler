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
			//cout << "SCPUSH: " << sc_top()->scopeName << endl;
		}
	}
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


				cout << iden.id << '\t' << iden.recType << '\t' << iden.dataType << '\t' << iden.memloc << '\t';
				for (auto lineNo : iden.lines) {
					cout << '\t' << lineNo << " ";
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
				else if (iden.dataType == "Record"){
					cout << '\t' << "<Record: ";
					for (auto record : item->recordList) {
						if (record.recordName == iden.id) {
							//cout << "--1" << endl;
							map<string, string>::iterator it;
							it = record.recordMember.begin();
							int isBegin = 1;
							while (it != record.recordMember.end()) {
								if (isBegin) {
									cout << it->first << " " << it->second;
									isBegin = 0;
								}
								else {
									cout << ", " << it->first << " " << it->second;
								}
								it++;
							}
						}
					}
					cout << ">";
				}
				cout << endl;
			}
		}
	}
	cout << "====================================================================" << endl;
}

Scope getscope(string name) {
    if(name == "main") return scopeStack[1];
    for (auto scope : scopes) {
        if(scope->scopeName == name) return scope;
    }
}
bool sym::getIDIsConst(string id, string scope){
    int hashValue = hashFunc(id);
    Scope currentScope = getscope(scope);
    while (currentScope) {
        for (auto item : currentScope->hashTable[hashValue]) {
            if (item.id == id) {
                return item.recType == "Const";
            }
        }
        currentScope = currentScope->parentScope;
    }
    return false;
}
string sym::getIDType(string id, string scope){
    int hashValue = hashFunc(id);
    Scope currentScope = getscope(scope);
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
string sym::getArrayType(string id, string scope){
    Scope currentScope = getscope(scope);
    while (currentScope) {
        for (auto item : currentScope->arrayList) {
            if (item.arrayName == id) {
                return item.arrayType;
            }
        }
        currentScope = currentScope->parentScope;
    }
    return "";
}

string sym::getRecordElementType(string id, string memberid, string scope){
    Scope currentScope = getscope(scope);
    while (currentScope) {
        for (auto record : currentScope->recordList) {
            if (record.recordName == id) {
                map<string, string>::iterator it;
                it = record.recordMember.begin();
                while (it != record.recordMember.end()) {
                    if(it->first == memberid) return it->second;
                    it++;
                }
            }
        }
        currentScope = currentScope->parentScope;
    }
    return "";
}

int sym::getArrayBegin(string id, string scope) {
    Scope currentScope = getscope(scope);
    while (currentScope) {
        for (auto array : currentScope->arrayList) {
            if (array.arrayName == id) {
                return array.arrayBegin;
            }
        }
        currentScope = currentScope->parentScope;
    }
     return -1;
}

int sym::getRecordNo(string id, string memberid, string scope) {
    Scope currentScope = getscope(scope);
    while (currentScope) {
        for (auto record : currentScope->recordList) {
            if (record.recordName == id) {
                map<string, string>::iterator it;
                it = record.recordMember.begin();
                int no = 0;
                while (it != record.recordMember.end()) {
                    if(it->first == memberid) return no;
                    no++;
                    it++;
                }
            }
        }
        currentScope = currentScope->parentScope;
    }
    return -1;

}