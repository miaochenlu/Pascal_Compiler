#include "gen/GenEnv.h"
#include "ast/ast.h"
using namespace std;
namespace ast {
    void astTraversal(BasicAstNode *root, int blank) {
        int i = 0;
        for (i = 0; i <= 4 * (blank - 1); i++) {
            if (i % 4 == 0) cout << "|";
            else cout << " ";
        }
        for (; i < 4 * blank; i++) cout << "-";

        root->printAstNode();
        childrenList *children = root->getChildrenList();
        if (children->size()) {
            for (auto child: *children) {
                if (child != NULL) astTraversal(child, blank + 1);
            }
        }
    }
    void PrintType(llvm::Type* value)
    {
        llvm::Type::TypeID type_id = value->getTypeID();
        std::string data_type = "";
        switch (type_id) {
            case llvm::Type::VoidTyID: data_type = "VoidTyID"; break;
            case llvm::Type::HalfTyID: data_type = "HalfTyID"; break;
            case llvm::Type::FloatTyID: data_type = "FloatTyID"; break;
            case llvm::Type::DoubleTyID: data_type = "DoubleTyID"; break;
            case llvm::Type::FP128TyID: data_type = "FP128TyID"; break;
            case llvm::Type::PPC_FP128TyID: data_type = "PPC_FP128TyID"; break;
            case llvm::Type::X86_MMXTyID: data_type = "X86_MMXTyID"; break;
            case llvm::Type::IntegerTyID: data_type = "IntegerTyID"; break;
            case llvm::Type::FunctionTyID: data_type = "FunctionTyID"; break;
            case llvm::Type::StructTyID: data_type = "StructTyID"; break;
            case llvm::Type::ArrayTyID: data_type = "ArrayTyID"; break;
            case llvm::Type::PointerTyID: data_type = "PointerTyID"; break;
            case llvm::Type::VectorTyID: data_type = "VectorTyID"; break;

            default:
                break;
        }
        std::cout << data_type << std::endl;
    }
    llvm::Value* Program::codeGen() {
        genEnv.pushLayer();
        programHead->codeGen();

        routine->codeGen();
        genEnv.popLayer();

        return nullptr;
    }

    llvm::Value* ProgramHead::codeGen() {

        llvm::Type *retype = gen::getLLVMType(returnType);
        std::vector<llvm::Type *> parameterVector;
        for (auto para : *parameters) {
            parameterVector.emplace_back(gen::getLLVMType(para->type));
        }
        llvm::FunctionType *funcType = llvm::FunctionType::get(retype, parameterVector, false);
        llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name->name,
                                                      &llvmModule);
        genEnv.getFuncEnv().setFunc(name->name, func);
        llvm::BasicBlock *routineBlock = llvm::BasicBlock::Create(llvmContext, name->name, func);
        irBuilder.SetInsertPoint(routineBlock);
        return nullptr;
    }

    llvm::Value* ast::Routine::codeGen() {
        routineHead->codeGen();
        routineBody->codeGen();
        return nullptr;
    }

    llvm::Value* ast::RoutineHead::codeGen() {
        if(constPart) {
            for (auto constdecl : *constPart) {
                constdecl->codeGen();
            }
        }
        if(typePart) {
            for (auto typedecl : *typePart) {
                typedecl->codeGen();
            }
        }
        if(varPart) {
            for (auto valdecl : *varPart) {
                valdecl->codeGen();
            }
        }
        if(routinePart) {
            for (auto prodecl : *routinePart) {
                prodecl->codeGen();
            }
        }
        return nullptr;
    }


    llvm::Value* ast::ConstDecl::codeGen() {
        llvm::Value *val = value->codeGen();
        genEnv.getValueEnv().setValue(name->name, val);
        return nullptr;
    }

    llvm::Value* ast::TypeDecl::codeGen(){
        llvm::Type* llvmType = gen::getLLVMType(type);
        genEnv.getTypeEnv().setType(name->name, llvmType);
        return nullptr;
    }

    llvm::Value* ast::VarDecl::codeGen() {
        llvm::Type *llvmType = gen::getLLVMType(type);
        llvm::Value *val = irBuilder.CreateAlloca(llvmType, nullptr, name->name);
        genEnv.getValueEnv().setValue(name->name, val);
        return nullptr;
    }

    llvm::Value* ast::Identifier::codeGen() {
        return genEnv.getValueEnv().getValue(name);
    }

    llvm::Value* ast::Name::codeGen() {
        return genEnv.getValueEnv().getValue(name);
    }




    llvm::Value* ast::BinaryExpr::codeGen() {
        llvm::Value* lval = leftOperand->codeGen();
        if(!llvm::dyn_cast<llvm::Constant>(lval))
            lval=irBuilder.CreateLoad(lval);
        llvm::Value* rval = rightOperand->codeGen();
        if(!llvm::dyn_cast<llvm::Constant>(rval))
            rval=irBuilder.CreateLoad(rval);
        if (lval->getType()->isDoubleTy() || rval->getType()->isDoubleTy()) {
            switch (bOp) {
                case BinaryOperator::GEop:
                    return irBuilder.CreateFCmpOGE(lval, rval);
                case BinaryOperator ::GTop:
                    return irBuilder.CreateFCmpOGT(lval, rval);
                case BinaryOperator ::LEop:
                    return irBuilder.CreateFCmpOLE(lval, rval);
                case BinaryOperator ::LTop:
                    return irBuilder.CreateFCmpOLT(lval, rval);
                case BinaryOperator ::EQUALop:
                    return irBuilder.CreateFCmpOEQ(lval, rval);
                case BinaryOperator ::UNEQUALop:
                    return irBuilder.CreateFCmpUNE(lval, rval);
                case BinaryOperator ::ORop:
                    return irBuilder.CreateOr(lval, rval);
                case BinaryOperator ::ANDop:
                    return irBuilder.CreateAnd(lval, rval);
                case BinaryOperator ::PLUSop:
                    return irBuilder.CreateFAdd(lval, rval);
                case BinaryOperator ::MINUSop:
                    return irBuilder.CreateFSub(lval, rval);
                case BinaryOperator ::MULop:
                    return irBuilder.CreateFMul(lval, rval);
                case BinaryOperator ::DIVop:
                    return irBuilder.CreateFDiv(lval, rval);
                case BinaryOperator ::MODop:
                default:
                    return nullptr;
            }
        }
        else {

            switch (bOp) {
                case BinaryOperator::GEop:
                    return irBuilder.CreateICmpSGE(lval, rval);
                case BinaryOperator ::GTop:
                    return irBuilder.CreateICmpSGT(lval, rval);
                case BinaryOperator ::LEop:
                    return irBuilder.CreateICmpSLE(lval, rval);
                case BinaryOperator ::LTop:
                    return irBuilder.CreateICmpSLT(lval, rval);
                case BinaryOperator ::EQUALop:
                    return irBuilder.CreateICmpEQ(lval, rval);
                case BinaryOperator ::UNEQUALop:
                    return irBuilder.CreateICmpNE(lval, rval);
                case BinaryOperator ::ORop:
                    return irBuilder.CreateOr(lval, rval);
                case BinaryOperator ::ANDop:
                    return irBuilder.CreateAnd(lval, rval);
                case BinaryOperator ::PLUSop:
                    return irBuilder.CreateAdd(lval, rval);
                case BinaryOperator ::MINUSop:
                    return irBuilder.CreateSub(lval, rval);
                case BinaryOperator ::MULop:
                    return irBuilder.CreateMul(lval, rval);
                case BinaryOperator ::DIVop:
                    return irBuilder.CreateSDiv(lval, rval);
                case BinaryOperator ::MODop:
                    return irBuilder.CreateSRem(lval, rval);
                default:
                    return nullptr;
            }
        }
    }

    llvm::Value* ast::UnaryExpr::codeGen() {
        llvm::Value* val = operand->codeGen();
        if(!llvm::dyn_cast<llvm::Constant>(val))
            val=irBuilder.CreateLoad(val);
        switch (uOp) {
            case UnaryOperator::NEGop:
                return irBuilder.CreateNeg(val);
            case UnaryOperator::NOTop:
                return irBuilder.CreateNot(val);
            case UnaryOperator::POSop:
                return val;
        }
        std::cout << ((ast::Identifier *) operand)->name <<"__"<<endl;
    }




    llvm::Value* ast::StmtList::codeGen() {
        for(auto stmt : stmtList) {
            stmt->codeGen();
        }
        return nullptr;
    }

    llvm::Value* ast::LabelStmt::codeGen() {
        if(hasLabel)
        {
            llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
            llvm::BasicBlock *blockLabel = llvm::BasicBlock::Create(llvmContext, std::to_string(label), nowFunc);
            genEnv.getLabelEnv().setLabel(label, blockLabel);
            irBuilder.CreateBr(blockLabel);
            irBuilder.SetInsertPoint(blockLabel);
        }
        stmt->codeGen();
        return nullptr;
    }

    llvm::Value* ast::AssignStmt::codeGen() {
        llvm::Value *left = name->codeGen();
        llvm::Value *right = value->codeGen();
        irBuilder.CreateStore(right, left);

        return nullptr;
    }

    llvm::Value* ast::IfStmt::codeGen() {
        llvm::Value *llvmCond = cond->codeGen();
        llvm::Function *llvmFunc = irBuilder.GetInsertBlock()->getParent();
        llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(llvmContext, "ifThen", llvmFunc);
        llvm::BasicBlock *elseBlock = llvm::BasicBlock::Create(llvmContext, "ifElse", llvmFunc);
        llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(llvmContext, "ifContinue", llvmFunc);

        irBuilder.CreateCondBr(llvmCond, thenBlock, elseBlock);
        irBuilder.SetInsertPoint(thenBlock);

        thenStmt->codeGen();
        irBuilder.CreateBr(continueBlock);
        irBuilder.SetInsertPoint(elseBlock);

        elseStmt->codeGen();
        irBuilder.CreateBr(continueBlock);
        irBuilder.SetInsertPoint(continueBlock);

        return nullptr;
    }

    llvm::Value* ast::RepeatStmt::codeGen() {
        llvm::Function *llvmFunc = irBuilder.GetInsertBlock()->getParent();
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(llvmContext, "repeatLoop", llvmFunc);
        llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(llvmContext, "repeatContinue", llvmFunc);

        irBuilder.SetInsertPoint(loopBlock);
        loopStmts->codeGen();
        llvm::Value *llvmCond = cond->codeGen();
        irBuilder.CreateCondBr(llvmCond, continueBlock, loopBlock);
        irBuilder.SetInsertPoint(continueBlock);

        return nullptr;
    }

    llvm::Value* ast::WhileStmt::codeGen() {
        llvm::Function *llvmFunc = irBuilder.GetInsertBlock()->getParent();
        llvm::BasicBlock *beginBlock = llvm::BasicBlock::Create(llvmContext, "whileBegin", llvmFunc);
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(llvmContext, "WhileLoop", llvmFunc);
        llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(llvmContext, "WhileContinue", llvmFunc);

        irBuilder.SetInsertPoint(beginBlock);
        llvm::Value *llvmCond = cond->codeGen();
        irBuilder.CreateCondBr(llvmCond, loopBlock, continueBlock);
        irBuilder.SetInsertPoint(loopBlock);
        loopStmt->codeGen();
        irBuilder.CreateBr(beginBlock);
        irBuilder.SetInsertPoint(continueBlock);

        return nullptr;
    }

    llvm::Value* ast::ForStmt::codeGen() {

        llvm::Function *llvmFunc = irBuilder.GetInsertBlock()->getParent();
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(llvmContext, "ForLoop", llvmFunc);
        llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(llvmContext, "ForContinue", llvmFunc);

        llvm::Value* id = name->codeGen();
        llvm::Value* llvmStart = start->codeGen();
        irBuilder.CreateStore(llvmStart, id);

        irBuilder.SetInsertPoint(loopBlock);
        loopStmt->codeGen();

        llvm::Value *temp;
        switch (direction) {
            case Direction::To:
                temp = irBuilder.CreateAdd(id, gen::getLLVMConstINT(1));
                break;
            case Direction ::DownTo:
                temp = irBuilder.CreateSub(id, gen::getLLVMConstINT(1));
                break;
        }
        irBuilder.CreateStore(temp, id);
        llvm::Value* llvmEnd = end->codeGen();
        llvm::Value* loadid = irBuilder.CreateLoad(id);
        llvm::Value* llvmCond = irBuilder.CreateICmpEQ(loadid, llvmEnd);
        irBuilder.CreateCondBr(llvmCond, continueBlock, loopBlock);
        irBuilder.SetInsertPoint(continueBlock);

        return nullptr;
    }

    llvm::Value* ast::CaseStmt::codeGen() {

        llvm::Value* llvmcase = exp->codeGen();
        llvm::Function *llvmFunc = irBuilder.GetInsertBlock()->getParent();
        std::vector <llvm::BasicBlock *> caseBlocks;
        std::vector <llvm::BasicBlock *> condBlocks;
        for(int i = 0; i < caseList->size(); i++) {
            condBlocks.emplace_back(llvm::BasicBlock::Create(llvmContext, "Casecond", llvmFunc));
            caseBlocks.emplace_back(llvm::BasicBlock::Create(llvmContext, "Casecase", llvmFunc));
        }
        llvm::BasicBlock *continueBlock = llvm::BasicBlock::Create(llvmContext, "CaseContinue", llvmFunc);
        int i = 0;
        for(auto caseexpr: *caseList)
        {
            irBuilder.SetInsertPoint(condBlocks[i]);
            llvm::Value *llvmcond = caseexpr->cond->codeGen();
            llvm::Value *condtrue = irBuilder.CreateICmpEQ(llvmcase, llvmcond);
            irBuilder.CreateCondBr(condtrue, caseBlocks[i], (i==caseBlocks.size()-1)?continueBlock:condBlocks[i+1]);
            irBuilder.SetInsertPoint(caseBlocks[i]);
            caseexpr->exeStmt->codeGen();
            irBuilder.CreateBr(continueBlock);
            i++;
        }
        irBuilder.SetInsertPoint(continueBlock);

        return nullptr;
    }

    llvm::Value* ast::GotoStmt::codeGen() {
        llvm::BasicBlock* gotoBlock = genEnv.getLabelEnv().getLabel(label);
        irBuilder.CreateBr(gotoBlock);
        return nullptr;
    }

    llvm::Value* ast::SysProcCall::codeGen() {


        return nullptr;
    }

    llvm::Value* ast::SysFuncCall::codeGen() {
        return nullptr;
    }



    llvm::Value* ast::UserDefProcCall::codeGen() {
        llvm::Function *func = genEnv.getFuncEnv().getFunc(procName->name);
        std::vector<llvm::Value*> llvmarg;
        if(args) {
            for (auto arg: *args) {
                llvmarg.emplace_back(arg->codeGen());
            }
        }
        return irBuilder.CreateCall(func, llvmarg);
    }
    llvm::Value* ast::ReadProcCall::codeGen() {
        return nullptr;
    }

    llvm::Value *ast::ArrayElementRef::codeGen() {
        return nullptr;
    }

    llvm::Value *ast::RecordElementRef::codeGen() {


    }


}
