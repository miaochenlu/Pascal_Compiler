#ifndef _ANALYZE_H_
#define _ANALYZE_H_


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include "ast/ast.h"
#include "symTab.h"
using namespace std;

void buildSymTable(ast::BasicAstNode *Tree);
void typeCheck(ast::BasicAstNode *Tree);
static void traverse(ast::BasicAstNode * node, void(*preProc) (ast::BasicAstNode *), void(*postProc) (ast::BasicAstNode *));
static void insertNode(ast::BasicAstNode *node);
static void checkNode(ast::BasicAstNode *node);
static void popScope(ast::BasicAstNode *node);
static void pushScope(ast::BasicAstNode *node);
static bool canChange(string type1, string type2);

static map<string, int> varSize{ {"Integer", 2}, {"String", 255}, {"Real", 4}, {"Char", 1}, {"Boolean", 1} };

#endif