#include"ast.h"
using namespace std;
namespace ast{

void astTraversal(ast::BasicAstNode* root, int blank) {
    for(int i = 0; i < 4 * blank; i++) cout << " ";
    root->printAstNode();
    ast::childrenList* children= root->getChildrenList();

    for(ast::BasicAstNode* child: *children) {
        astTraversal(child, blank + 1);
    }
}

void VarDecl::codegen() {

    llvm::Type* llvmType = getLLVMType()
    if (genEnv.valueEnv.isGlobal())
    {

    }
    else
    {

    }

}

}