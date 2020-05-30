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
                irBuilder.CreateRet(irBuilder.CreateLoad(llvmRet));
            else
                irBuilder.CreateRet(gen::getLLVMConstINT(0));
        }
        else irBuilder.CreateRetVoid();


        genEnv.popLayer();



        return nullptr;
    }

    llvm::Value* ProgramHead::codeGen() {

        std::vector<llvm::Type *> parameterVector;
        for (auto para : *parameters) {
            llvm::Type *paraType = gen::getLLVMType(para->type);
            parameterVector.emplace_back(paraType);
        }
        llvm::Type *retype = gen::getLLVMType(returnType);


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
        auto arg_it = func->arg_begin();

        llvm::BasicBlock *routineBlock = llvm::BasicBlock::Create(llvmContext, name->name, func);
        irBuilder.SetInsertPoint(routineBlock);
        if(returnType->type != TypeKind::VOIDtype) {
            llvm::Value *val = irBuilder.CreateAlloca(retype, nullptr, name->name);
            genEnv.getValueEnv().setValue(name->name, val);
        }
        for (auto para : *parameters) {
            llvm::Type *paraType = gen::getLLVMType(para->type);
            llvm::Value *val = irBuilder.CreateAlloca(paraType, nullptr, para->name->name);
            genEnv.getValueEnv().setValue(para->name->name, val);
        }
        for (auto para : *parameters) {
            arg_it->setName(para->name->name);
            irBuilder.CreateStore(arg_it, genEnv.getValueEnv().getValue(para->name->name));
            arg_it++;
        }
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
        llvm::BasicBlock *now = irBuilder.GetInsertBlock();
        if(routinePart) {
            for (auto prodecl : *routinePart) {
                prodecl->codeGen();
            }
        }
        irBuilder.SetInsertPoint(now);
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
        llvm::Value *val = nullptr;
        if (genEnv.isGlobal()) {
            val = new llvm::GlobalVariable(
                    llvmModule, llvmType, false, llvm::GlobalValue::InternalLinkage,
                    llvm::ConstantAggregateZero::get(llvmType), id
            );
        }
        else
            val = irBuilder.CreateAlloca(llvmType, nullptr, name->name);
        genEnv.getValueEnv().setValue(name->name, val);
        return nullptr;
    }

    llvm::Value* ast::Identifier::codeGen() {
        return genEnv.getValueEnv().getValue(name);
    }

    llvm::Value* ast::Name::codeGen() {

        llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
        if(sym::getIDIsConst(name, nowFunc->getName())) return genEnv.getValueEnv().getValue(name);
        else return irBuilder.CreateLoad(genEnv.getValueEnv().getValue(name));
    }

    llvm::Value* ast::BinaryExpr::codeGen() {
        llvm::Value* lval = leftOperand->codeGen();
        llvm::Value* rval = rightOperand->codeGen();
        if(leftOperand->subType == "ArrayElementRef" || leftOperand->subType == "RecordElementRef")
            lval = irBuilder.CreateLoad(lval, "load");
        if(rightOperand->subType == "ArrayElementRef" || rightOperand->subType == "RecordElementRef")
            rval = irBuilder.CreateLoad(rval, "load");

        if (lval->getType()->isDoubleTy() || rval->getType()->isDoubleTy()) {
            if(lval->getType()->isIntegerTy())
                lval = irBuilder.CreateSIToFP(lval, llvm::Type::getDoubleTy(llvmContext));
            if(rval->getType()->isIntegerTy())
                rval = irBuilder.CreateSIToFP(rval, llvm::Type::getDoubleTy(llvmContext));

            switch (bOp) {
                case BinaryOperator::GEop:
                    return irBuilder.CreateFCmpOGE(lval, rval, "fge");
                case BinaryOperator ::GTop:
                    return irBuilder.CreateFCmpOGT(lval, rval, "fgt");
                case BinaryOperator ::LEop:
                    return irBuilder.CreateFCmpOLE(lval, rval, "fle");
                case BinaryOperator ::LTop:
                    return irBuilder.CreateFCmpOLT(lval, rval, "flt");
                case BinaryOperator ::EQUALop:
                    return irBuilder.CreateFCmpOEQ(lval, rval, "feq");
                case BinaryOperator ::UNEQUALop:
                    return irBuilder.CreateFCmpUNE(lval, rval, "fneq");
                case BinaryOperator ::ORop:
                    return irBuilder.CreateOr(lval, rval, "or");
                case BinaryOperator ::ANDop:
                    return irBuilder.CreateAnd(lval, rval, "and");
                case BinaryOperator ::PLUSop:
                    return irBuilder.CreateFAdd(lval, rval, "fadd");
                case BinaryOperator ::MINUSop:
                    return irBuilder.CreateFSub(lval, rval, "fsub");
                case BinaryOperator ::MULop:
                    return irBuilder.CreateFMul(lval, rval, "fmul");
                case BinaryOperator ::DIVop:
                    return irBuilder.CreateFDiv(lval, rval, "fdiv");
                case BinaryOperator ::MODop:
                default:
                    return nullptr;
            }
        }
        else {

            switch (bOp) {
                case BinaryOperator::GEop:
                    return irBuilder.CreateICmpSGE(lval, rval, "ige");
                case BinaryOperator ::GTop:
                    return irBuilder.CreateICmpSGT(lval, rval, "igt");
                case BinaryOperator ::LEop:
                    return irBuilder.CreateICmpSLE(lval, rval, "ile");
                case BinaryOperator ::LTop:
                    return irBuilder.CreateICmpSLT(lval, rval, "ilt");
                case BinaryOperator ::EQUALop:
                    return irBuilder.CreateICmpEQ(lval, rval, "ieq");
                case BinaryOperator ::UNEQUALop:
                    return irBuilder.CreateICmpNE(lval, rval, "ineq");
                case BinaryOperator ::ORop:
                    return irBuilder.CreateOr(lval, rval, "or");
                case BinaryOperator ::ANDop:
                    return irBuilder.CreateAnd(lval, rval, "and");
                case BinaryOperator ::PLUSop:
                    return irBuilder.CreateAdd(lval, rval, "iadd");
                case BinaryOperator ::MINUSop:
                    return irBuilder.CreateSub(lval, rval, "isub");
                case BinaryOperator ::MULop:
                    return irBuilder.CreateMul(lval, rval, "imul");
                case BinaryOperator ::DIVop:
                    return irBuilder.CreateSDiv(lval, rval, "idiv");
                case BinaryOperator ::MODop:
                    return irBuilder.CreateSRem(lval, rval, "mod");
                default:
                    return nullptr;
            }
        }
    }

    llvm::Value* ast::UnaryExpr::codeGen() {
        llvm::Value* val = operand->codeGen();
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
            llvm::BasicBlock *blockLabel = genEnv.getLabelEnv().getLabel(label) ;
            if(blockLabel == nullptr) {
                llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
                blockLabel = llvm::BasicBlock::Create(llvmContext, std::to_string(label), nowFunc);
                genEnv.getLabelEnv().setLabel(label, blockLabel);
            }
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
        if(llvm::isa<llvm::ConstantInt>(llvmCond)) {
            if(((llvm::ConstantInt*)llvmCond)->getValue() == 0) {
                elseStmt->codeGen();
            }
            else {
                thenStmt->codeGen();
            }
        }
        else {
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
        }

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
        llvm::Value *loadid = irBuilder.CreateLoad(id);
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

        if (llvm::isa<llvm::ConstantInt>(llvmcase)) {
            for(auto caseexpr: *caseList)
            {
                llvm::Value *llvmcond = caseexpr->cond->codeGen();
                if ( llvm::isa<llvm::ConstantInt>(llvmcond)) {
                    if (((llvm::ConstantInt*)llvmcond)->getValue() ==((llvm::ConstantInt*)llvmcase)->getValue()) {
                        caseexpr->exeStmt->codeGen();
                        return nullptr;
                    }
                }
                else break;
            }
        }

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
        if (gotoBlock == nullptr) {
            llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
            llvm::BasicBlock *blockLabel = llvm::BasicBlock::Create(llvmContext, std::to_string(label), nowFunc);
            genEnv.getLabelEnv().setLabel(label, blockLabel);
            irBuilder.CreateBr(blockLabel);
        }
        else irBuilder.CreateBr(gotoBlock);
        llvm::BasicBlock* gotoContinue = llvm::BasicBlock::Create(llvmContext, "gotocontinue", llvmFunc);
        irBuilder.SetInsertPoint(gotoContinue);

        return nullptr;
    }

    llvm::Value* ast::SysProcCall::codeGen() {

        std::string printString;
        std::vector<llvm::Value*> argVector;
        for(auto arg : *args) {

            if(arg->nodeType == "BasicConst" && ((BasicConst*)arg)->type == TypeKind::STRINGtype)
            {
                printString += "%s ";
                argVector.emplace_back(irBuilder.CreateGlobalString(((StringNode*)arg)->stringVal));
            }
            else {
                llvm::Value *llvmArg = arg->codeGen();
                if (arg->nodeType == "BasicConst") {
                    if (((BasicConst *) arg)->type == TypeKind::INTtype) printString += "%d ";
                    else if (((BasicConst *) arg)->type == TypeKind::REALtype) printString += "%lf ";
                    else if (((BasicConst *) arg)->type == TypeKind::CHARtype) printString += "%c ";
                    else if (((BasicConst *) arg)->type == TypeKind::BOOLEANtype) printString += "%d ";
                    argVector.emplace_back(llvmArg);
                } else if (arg->subType == "ArrayElementRef") {

                    llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
                    string type = sym::getArrayType(((ArrayElementRef *) arg)->arrayName->name, nowFunc->getName());
                    if (type == "String") {
                        printString += "%s ";
                        argVector.emplace_back(llvmArg);
                    } else {
                        if (type == "Integer") printString += "%d ";
                        else if (type == "Char")printString += "%c ";
                        else if (type == "Real")printString += "%lf ";
                        else if (type == "Boolean")printString += "%d ";
                        argVector.emplace_back(irBuilder.CreateLoad(llvmArg, "array"));

                    }
                } else if (arg->subType == "RecordElementRef") {
                    llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
                    string type = sym::getRecordElementType(((RecordElementRef *) arg)->recordName->name,
                                                            ((RecordElementRef *) arg)->field->name,
                                                            nowFunc->getName());
                    if (type == "String") {
                        printString += "%s ";
                        argVector.emplace_back(llvmArg);
                    } else {
                        if (type == "Integer") printString += "%d ";
                        else if (type == "Char")printString += "%c ";
                        else if (type == "Real")printString += "%lf ";
                        else if (type == "Boolean")printString += "%d ";
                        llvm::Value *temp = irBuilder.CreateLoad(llvmArg, "record");
                        argVector.emplace_back(temp);
                    }
                }
                else if (llvm::isa<llvm::Constant>(llvmArg)) {
                    if (llvmArg->getType()->isIntegerTy()) printString += "%d ";
                    else if (llvmArg->getType()->isDoubleTy()) printString += "%lf ";
                    argVector.emplace_back(llvmArg);
                } else if (arg->nodeType == "Name") {
                    llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
                    string type = sym::getIDType(((Name *) arg)->name, nowFunc->getName());
                    if (type == "String") {
                        printString += "%s ";
                        argVector.emplace_back(genEnv.getValueEnv().getValue(((Name *) arg)->name));
                    } else {
                        if (type == "Integer") printString += "%d ";
                        else if (type == "Char")printString += "%c ";
                        else if (type == "Real")printString += "%lf ";
                        else if (type == "Boolean")printString += "%d ";
                        argVector.emplace_back(llvmArg);
                    }

                }
                else {
                    if (llvmArg->getType() == llvm::Type::getInt32Ty(llvmContext)) printString += "%d ";
                    else if (llvmArg->getType() == llvm::Type::getInt8Ty(llvmContext)) printString += "%c ";
                    else if (llvmArg->getType()->isDoubleTy()) printString += "%lf ";
                    else printString += "%d ";
                    argVector.emplace_back(llvmArg);
                }
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
            argVector.emplace_back(llvmArg);
        }
        switch (functName) {
            case SYSFUNCT ::ABS:
                if(argVector[0]->getType()->isDoubleTy())
                    return irBuilder.CreateCall(genEnv.getFuncEnv().getFunc("ABSREAL"), argVector, "abs");
                else
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
        std::string printString;
        std::vector<llvm::Value*> argVector;
        llvm::Value *llvmArg = readElement->codeGen();

         if(readElement->nodeType == "Name") {
             llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
             string type = sym::getIDType(((Name*)readElement)->name, nowFunc->getName());
             if(type == "Integer") printString+="%d";
             else if (type == "Char")printString+="%c";
             else if (type == "Real")printString+="%lf";
             else if (type == "String")printString+="%s";
             else if (type == "Boolean")printString+="%d";
             argVector.emplace_back(genEnv.getValueEnv().getValue(((Name*)readElement)->name));
         }
         else if(readElement->subType == "ArrayElementRef") {
             llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
             string type = sym::getArrayType(((ArrayElementRef*)readElement)->arrayName->name, nowFunc->getName());
             if(type == "Integer") printString+="%d";
             else if (type == "Char")printString+="%c";
             else if (type == "Real")printString+="%lf";
             else if (type == "String")printString+="%s";
             else if (type == "Boolean")printString+="%d";
             argVector.emplace_back(llvmArg);
         }
         else if(readElement->subType == "RecordElementRef") {
             llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
             string type = sym::getRecordElementType(((RecordElementRef*)readElement)->recordName->name, ((RecordElementRef*)readElement)->field->name, nowFunc->getName());
             if(type == "Integer") printString+="%d";
             else if (type == "Char")printString+="%c";
             else if (type == "Real")printString+="%lf";
             else if (type == "String")printString+="%s";
             else if (type == "Boolean")printString+="%d";
             argVector.emplace_back(llvmArg);
         }
        argVector.insert(argVector.begin(), irBuilder.CreateGlobalStringPtr(printString, "scanfstring"));

        irBuilder.CreateCall(genEnv.getFuncEnv().getFunc("READ"), argVector, "read");

        return nullptr;
    }

    llvm::Value *ast::ArrayElementRef::codeGen() {

        llvm::Value* llvmArrayName = arrayName->codeGen();
        llvm::Value* llvmIndex = index->codeGen();
        llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
        int lowBound = sym::getArrayBegin(arrayName->name, nowFunc->getName());
        llvm::Value* llvmLowBound = gen::getLLVMConstINT(lowBound);
        llvm::Value* indexReal = irBuilder.CreateSub(llvmIndex, llvmLowBound);
        std::vector<llvm::Value* >array;
        array.emplace_back(gen::getLLVMConstINT(0));
        array.emplace_back(indexReal);
        llvm::Value* re =  irBuilder.CreateGEP(llvmArrayName, array, "arrayElementRef");
        return re;
    }

    llvm::Value *ast::RecordElementRef::codeGen() {
        llvm::Value* llvmRecordName = recordName->codeGen();
        llvm::Function *nowFunc = irBuilder.GetInsertBlock()->getParent();
        int index = sym::getRecordNo(recordName->name, field->name, nowFunc->getName());
        std::vector<llvm::Value* >array;
        array.emplace_back(gen::getLLVMConstINT(0));
        array.emplace_back(gen::getLLVMConstINT(index));
        return irBuilder.CreateGEP(llvmRecordName, array, "RecordElementRef");
    }


}
