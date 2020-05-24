#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "pch.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define TABLE_SIZE 571
#define SHIFT 4

class BucketListRec {
public:
	string id;
	vector<int> lines;
	int memloc;
	string recType; // function, variable
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

	ScopeRec(string _scopeName) { 
        scopeName = _scopeName; 
    }
};
typedef ScopeRec* Scope;

static int hash(string str);
Scope sc_create(string scopeName);
void sc_pop();
Scope sc_top();

void st_insert(string id, int lineNo, int loc, string recType, string dataType);
int st_lookup(string id);
void st_print();

#endif