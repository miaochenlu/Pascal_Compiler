#include"ast.h"
using namespace std;
namespace ast{

void astTraversal(ast::BasicAstNode* root, int blank) {
    int i = 0;
    for(i = 0; i <= 4 * (blank - 1); i++) {
        if(i % 4 == 0) cout << "|";
        else cout << " ";
    }
    for(; i < 4 * blank; i++) cout << "-";

    root->printAstNode();
    ast::childrenList* children= root->getChildrenList();
    if(children->size()) {
        for(auto child: *children) {
            if(child != NULL) astTraversal(child, blank + 1);
        }
    }
}
}