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
        if(!(programHead->returnType->type == TypeKind::VOIDtype)) {
            llvm::Value *llvmRet = genEnv.getValueEnv().getValue(programHead->name->name);
            if(llvmRet != nullptr)
                irBuilder.CreateRet(llvmRet);
            else
                irBuilder.CreateRet(gen::getLLVMConstINT(0));
        }
        else irBuilder.CreateRetVoid();


        genEnv.popLayer();



        return nullptr;
    }

    llvm::Value* ProgramHead::codeGen() {

        llvm::Type *retype = gen::getLLVMType(returnType);
        std::vector<llvm::Type *> parameterVector;
        for (auto para : *parameters) {
            parameterVector.emplace_back(gen::getLLVMType(para->type));
        }
        llvm::Function *func = nullptr;
        if(genEnv.isGlobal())
        {
            llvm::FunctionType *funcType = llvm::FunctionType::get(retype, parameterVector, false);
            func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main",
                                                          &llvmModule);
            genEnv.getFuncEnv().setFunc("main", func);
        }
        else {
            llvm::FunctionType *funcType = llvm::FunctionType::get(retype, parameterVector, false);
            func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name->name,
                                                          &llvmModule);
            genEnv.getFuncEnv().setFunc(name->name, func);
        }
        llvm::BasicBlock *routineBlock = llvm::BasicBlock::Create(llvmContext, name->name, func);
        irBuilder.CreateBr(routineBlock);
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
        if(!llvm::isa<llvm::Constant>(lval))
            lval=irBuilder.CreateLoad(lval);
        llvm::Value* rval = rightOperand->codeGen();
        if(!llvm::isa<llvm::Constant>(rval))
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
                    cout <<llvm::isa<llvm::Constant>(lval) << llvm::isa<llvm::Constant>(rval)<<endl;
                    PrintType(rval->getType());
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
        if(!llvm::isa<llvm::Constant>(val))
            val=irBuilder.CreateLoad(val);
        switch (uOp) {
            case UnaryOperator::NEGop:
                return irBuilder.CreateNeg(val);
            case UnaryOperator::NOTop:
                return irBuilder.CreateNot(val);
            case UnaryOperator::POSop:
                return val;
        }
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

        irBuilder.CreateBr(loopBlock);
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

        irBuilder.CreateBr(beginBlock);
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

        irBuilder.CreateBr(loopBlock);
        irBuilder.SetInsertPoint(loopBlock);
        loopStmt->codeGen();

        llvm::Value *temp = nullptr;
        PrintType(id->getType());
        llvm::Value *loadid = irBuilder.CreateLoad(id);
        PrintType(loadid->getType());
        switch (direction) {
            case Direction::To:
                temp = irBuilder.CreateAdd(loadid, gen::getLLVMConstINT(1));
                break;
            case Direction ::DownTo:
                temp = irBuilder.CreateSub(loadid, gen::getLLVMConstINT(1));
                break;
        }
        irBuilder.CreateStore(temp, id);
        llvm::Value* llvmEnd = end->codeGen();
        loadid = irBuilder.CreateLoad(id);
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
        irBuilder.CreateBr(condBlocks[0]);
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
        llvm::Function *llvmFunc = irBuilder.GetInsertBlock()->getParent();
        llvm::BasicBlock* gotoBlock = genEnv.getLabelEnv().getLabel(label);
        irBuilder.CreateBr(gotoBlock);
        llvm::BasicBlock* gotoContinue = llvm::BasicBlock::Create(llvmContext, "gotocontinue", llvmFunc);
        irBuilder.SetInsertPoint(gotoContinue);

        return nullptr;
    }

    llvm::Value* ast::SysProcCall::codeGen() {

        std::string printString;
        std::vector<llvm::Value*> argVector;
        for(auto arg : *args) {
            llvm::Value *llvmArg = arg->codeGen();


            if (arg->nodeType == "BasicConst") {
                if(((BasicConst*)arg)->type == TypeKind::INTtype) printString+="%d ";
                else if(((BasicConst*)arg)->type == TypeKind::REALtype) printString+="%lf ";
                else if(((BasicConst*)arg)->type == TypeKind::CHARtype) printString+="%c ";
                else if(((BasicConst*)arg)->type == TypeKind::BOOLEANtype) printString+="%d ";
                else if(((BasicConst*)arg)->type == TypeKind::STRINGtype) printString+="%s ";
                argVector.emplace_back(llvmArg);
            }
            else if(llvm::isa<llvm::Constant>(llvmArg)) {
                if(llvmArg->getType()->isIntegerTy()) printString+="%d ";
                else if(llvmArg->getType()->isDoubleTy()) printString+="%lf ";
                argVector.emplace_back(llvmArg);
            }
            else if(arg->nodeType == "Name") {
                string type = sym::getIDType(((Name*)arg)->name);
                if(type == "Integer") printString+="%d ";
                else if (type == "Char")printString+="%c ";
                else if (type == "Real")printString+="%lf ";
                else if (type == "String")printString+="%s ";
                else if (type == "Boolean")printString+="%d ";
                argVector.emplace_back(irBuilder.CreateLoad(llvmArg));
            }
            else if(arg->subType == "ArrayElementRef") {
                string type = sym::getArrayType(((ArrayElementRef*)arg)->arrayName->name);
                if(type == "Integer") printString+="%d ";
                else if (type == "Char")printString+="%c ";
                else if (type == "Real")printString+="%lf ";
                else if (type == "String")printString+="%s ";
                else if (type == "Boolean")printString+="%d ";
                argVector.emplace_back(irBuilder.CreateLoad(llvmArg));
            }
            else if(arg->subType == "RecordElementRef") {
                string type = sym::getRecordElementType(((RecordElementRef*)arg)->recordName->name, ((RecordElementRef*)arg)->field->name);
                if(type == "Integer") printString+="%d ";
                else if (type == "Char")printString+="%c ";
                else if (type == "Real")printString+="%lf ";
                else if (type == "String")printString+="%s ";
                else if (type == "Boolean")printString+="%d ";
                argVector.emplace_back(irBuilder.CreateLoad(llvmArg));
            }
            else {
                if(llvmArg->getType()==llvm::Type::getInt32Ty(llvmContext))  printString+="%d ";
                if(llvmArg->getType()==llvm::Type::getInt8Ty(llvmContext))  printString+="%d ";
                else if(llvmArg->getType()->isDoubleTy())  printString+="%lf ";
                else printString+="%d ";
                argVector.emplace_back(irBuilder.CreateLoad(llvmArg));
            }

        }

        if(procName == SYSPROC::WRITELN) printString+="\n";
        argVector.insert(argVector.begin(), irBuilder.CreateGlobalStringPtr(printString, "printstring"));

        irBuilder.CreateCall(genEnv.getFuncEnv().getFunc("WRITE"), argVector, "write");
        return nullptr;
    }

    llvm::Value* ast::SysFuncCall::codeGen() {
        std::vector<llvm::Value *> argVector;
        for (auto arg: *args) {
            llvm::Value* llvmArg = arg->codeGen();
            if(!llvm::isa<llvm::Constant>(llvmArg))
                llvmArg=irBuilder.CreateLoad(llvmArg);
            argVector.emplace_back(llvmArg);
        }
        switch (functName) {
            case SYSFUNCT ::ABS:
                return irBuilder.CreateCall(genEnv.getFuncEnv().getFunc("ABS"), argVector, "abs");
            case SYSFUNCT ::CHR:
                return irBuilder.CreateIntCast(argVector[0], llvm::Type::getInt8Ty(llvmContext), true);
            case SYSFUNCT ::ODD:
                return irBuilder.CreateICmpEQ(irBuilder.CreateSRem(argVector[0], gen::getLLVMConstINT(2)), gen::getLLVMConstINT(1));
            case SYSFUNCT ::ORD:
                return irBuilder.CreateIntCast(argVector[0], llvm::Type::getInt32Ty(llvmContext), true);
            case SYSFUNCT ::PRED:
                if(argVector[0]->getType()==llvm::Type::getInt32Ty(llvmContext))
                    return irBuilder.CreateSub(argVector[0], gen::getLLVMConstINT(1));
                else if(argVector[0]->getType()==llvm::Type::getInt8Ty(llvmContext))
                    return irBuilder.CreateSub(argVector[0], gen::getLLVMConstCHAR(1));
                else return nullptr;
            case SYSFUNCT ::SQR:
                if(argVector[0]->getType()->isDoubleTy())
                    return irBuilder.CreateFMul(argVector[0], argVector[0]);
                else
                    return irBuilder.CreateMul(argVector[0], argVector[0]);
            case SYSFUNCT ::SQRT:
                if(argVector[0]->getType()->isIntegerTy())
                    argVector[0] = irBuilder.CreateSIToFP(argVector[0], llvm::Type::getDoubleTy(llvmContext));
                return irBuilder.CreateCall(genEnv.getFuncEnv().getFunc("SQRT"), argVector, "sqrt");
            case SYSFUNCT ::SUCC:
                if(argVector[0]->getType()==llvm::Type::getInt32Ty(llvmContext))
                    return irBuilder.CreateAdd(argVector[0], gen::getLLVMConstINT(1));
                else if(argVector[0]->getType()==llvm::Type::getInt8Ty(llvmContext))
                    return irBuilder.CreateAdd(argVector[0], gen::getLLVMConstCHAR(1));
                else return nullptr;
        }

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

        llvm::Value* llvmArrayName = arrayName->codeGen();
        llvm::Value* llvmIndex = index->codeGen();
        int lowBound = sym::getArrayBegin(arrayName->name);
        llvm::Value* llvmLowBound = gen::getLLVMConstINT(lowBound);
        llvm::Value* indexReal = irBuilder.CreateSub(llvmIndex, llvmLowBound);
        std::vector<llvm::Value* >array;
        array.emplace_back(gen::getLLVMConstINT(0));
        array.emplace_back(indexReal);
        return irBuilder.CreateGEP(llvmArrayName, array, "arrayElementRef");
    }

    llvm::Value *ast::RecordElementRef::codeGen() {
        llvm::Value* llvmRecordName = recordName->codeGen();
        int index = sym::getRecordNo(recordName->name, field->name);
        std::vector<llvm::Value* >array;
        array.emplace_back(gen::getLLVMConstINT(0));
        array.emplace_back(gen::getLLVMConstINT(index));
        return irBuilder.CreateGEP(llvmRecordName, array, "RecordElementRef");
    }


}
