#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#include "pch.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include "ast/ast.h"
#include "symTab.h"
using namespace std;

void buildSymTable(ast::BasicAstNode *Tree);
void typeCheck(ast::BasicAstNode *Tree);
//void initSymTable();
static void traverse(ast::BasicAstNode * node, void(*preProc) (ast::BasicAstNode *), void(*postProc) (ast::BasicAstNode *));
static void insertNode(ast::BasicAstNode *node);
static void checkNode(ast::BasicAstNode *node);
static void popScope(ast::BasicAstNode *node);
static void pushScope(ast::BasicAstNode *node);

#endif