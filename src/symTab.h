#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "pch.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

#define TABLE_SIZE 571
#define SHIFT 4

class arrayRec {
public:
	string arrayName;
	int arrayBegin;
	int arrayEnd;
	string arrayType;
	arrayRec(string _arrayName, int _arrayBegin, int _arrayEnd, string _arrayType) {
		arrayName = _arrayName;
		arrayBegin = _arrayBegin;
		arrayEnd = _arrayEnd;
		arrayType = _arrayType;
	}
	arrayRec(string newName, arrayRec rec) {
		arrayName = newName;
		arrayBegin = rec.arrayBegin;
		arrayEnd = rec.arrayEnd;
		arrayType = rec.arrayType;
	}
};

class recordRec {
public:
	string recordName;
	map<string, string> recordMember; //name, type
	recordRec(string _recordName, map<string, string> _recordMember) {
		recordName = _recordName;
		recordMember = _recordMember;
	}
	recordRec(string newName, recordRec rec) {
		recordName = newName;
		recordMember = rec.recordMember;
	}
};

class BucketListRec {
public:
	string id;
	vector<int> lines;
	int memloc;
	string recType; // function, variable, const
	string dataType; // void, integer, char, string..
	BucketListRec *next; //TODO

	BucketListRec(string _id, int _lineno, int _memloc, string _recType, string _dataType) {
		id = _id; 
        memloc = _memloc;
		lines.push_back(_lineno);
		recType = _recType;
		dataType = _dataType;
	}
};
typedef vector<BucketListRec> BucketList;

class ScopeRec {
public:
	string scopeName;
	int depth;
	ScopeRec *parentScope;
	BucketList hashTable[TABLE_SIZE];
	map<string, string> userDefType;
	vector<arrayRec> arrayList;
	vector<recordRec> recordList;

	ScopeRec(string _scopeName) { 
        scopeName = _scopeName; 
    }
	ScopeRec(string _scopeName, ScopeRec* oriScope) {
		scopeName = _scopeName;
		depth = oriScope->depth;
		parentScope = oriScope->parentScope;
		for (int i = 0; i < TABLE_SIZE; i++) {
			hashTable[i] = oriScope->hashTable[i];
		}
		userDefType = oriScope->userDefType;
		arrayList = oriScope->arrayList;
	}
};
typedef ScopeRec* Scope;

static int hash(string str);
Scope sc_create(string scopeName);
Scope sc_create(string scopeName, Scope oriScope);
void sc_pop();
Scope sc_top();
void sc_push(string name);
Scope sc_find(string name);

void st_insert(string id, int lineNo, int loc, string recType, string dataType);
string st_lookup(string id);
void st_print();

#endif