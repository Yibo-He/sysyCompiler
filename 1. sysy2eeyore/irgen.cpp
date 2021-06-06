#include "irgen.hpp"

bool endPoint = false;

static list<string> labelList;
static list<string> tempVarList;
static list<string> globalVarList;
static list<BaseAST*> defVarList;
static list<string> flowsList;
static list<string> mainInitList;

//新增临时变量
static inline list<string>::iterator newTemp(){
    string tmp("t");
    tempVarList.push_front(tmp+num2string(tempVarNum));
    tempVarNum++;
    return tempVarList.begin();
}
//新增label
static inline list<string>::iterator newLabel(){
    string tmp("l");
    labelList.push_front(tmp+num2string(labelNum));
    labelNum++;
    return labelList.begin();
}


/**************************************************/
/****************   变量声明的AST  *****************/
/**************************************************/
void DefineAST::generator(){
    defVarList.push_back(this);
    auto symp = dynamic_cast<varSymEntry *>(sym);

	//非数组
	if(symp->dims.size() == 1){
		if(!mmap.empty()) {
			mmap[0]->generator();
			stringListPushBack(flowsList,  "  " + addr + " = " + mmap[0]->addr);
		}
		return;
	}

	// 数组
	for(auto i:mmap){
		i.second->generator();
		stringListPushBack(flowsList, "  " + addr + "[" + num2string(i.first * 4) + "] = " + i.second->addr);
	}
	return;
}

/**************************************************/
/****************   函数相关的AST  *****************/
/**************************************************/
void FunDefAST::generator(){
    //进入了新的作用域
    flowsList.clear();
    tempVarList.clear();
    labelList.clear();
    defVarList.clear();

    //函数开头的定义语句
    stringListPushBack(flowsList, addr + " [" + num2string(fParams.size()) + "]");

    //函数主体处理
    //main函数
	if(*(sym->strp) == "main")
		flowsList.splice(flowsList.end(), mainInitList);
	
	/* generate function body */
	body->generator();

	/* append native vars and temps */
	auto q = ++flowsList.begin();
	for(auto i: defVarList){
		DefineAST *tmpp = dynamic_cast<DefineAST *>(i);
		varSymEntry *symp = dynamic_cast<varSymEntry *>(tmpp->sym);
		if(symp->dims.size() == 1){ // a scalar
			flowsList.insert(q, "  var " + tmpp->addr);
		}
		else{ // an array
			flowsList.insert(q, "  var " + num2string(symp->dims.back() * 4) + " " + tmpp->addr);
		}
	}

    for(list<string>::reverse_iterator iter = tempVarList.rbegin(); iter != tempVarList.rend(); iter++) { 
        flowsList.insert(q, "  var " + *iter);
    } 

	if(!defVarList.empty() || !tempVarList.empty()) flowsList.insert(q, "");

    //函数定义结束
    if(dynamic_cast<funSymEntry *>(sym)->isVoid)
		stringListPushBack(flowsList, "  return");
	else
		stringListPushBack(flowsList, "  return 0");
	stringListPushBack(flowsList, "end " + addr);

    for(auto &i: flowsList)
		cout << i << endl;
	cout << endl;

    flowsList.clear();
    tempVarList.clear();
    labelList.clear();
    defVarList.clear();
}

void FunCallAST::generator(){
    // 处理运行时库函数 
	if(*(sym->strp) == "starttime"){
		stringListPushBack(flowsList, "  param " + num2string(lineno));
		stringListPushBack(flowsList, "  call f__sysy_starttime ");
		return;
	}
	if(*(sym->strp) == "stoptime"){
		stringListPushBack(flowsList, "  param " + num2string(lineno));
		stringListPushBack(flowsList, "  call f__sysy_stoptime ");
		return;
	}
    bool tmpEndPoint = endPoint;
    endPoint = false;

    for(auto i: rParams)    i->generator();
	for(auto i: rParams)    stringListPushBack(flowsList, "  param " + i->addr);
	// void function
	if(dynamic_cast<funSymEntry *>(sym)->isVoid){
        string tmp ("  call  ");
        tmp = tmp + "f_";
        tmp = tmp + *(sym->strp);
        stringListPushBack(flowsList, tmp);
    }
	// int function
	else{
		addr = *newTemp();
		stringListPushBack(flowsList, "  " + addr + " = call " + "f_" + *(sym->strp));
	}

    endPoint = tmpEndPoint;
	if(endPoint){
		stringListPushBack(flowsList, "  if " + addr + " != 0 goto " + true_);
		stringListPushBack(flowsList, "  goto " + false_);
	}
}

void BlockAST::generator(){
    for(auto i: items){
        i->generator();
    }
}

/**************************************************/
/***************   控制流相关的AST  ****************/
/**************************************************/
void AssignAST::generator(){
    dynamic_cast<LvalAST *>(lval)->isLeft_ = true;
	lval->generator();
	exp->generator();
	stringListPushBack(flowsList, "  " + lval->addr + " = " + exp->addr);
}

void IfAST::generator(){
    cond->true_ = *newLabel();
	cond->false_ = *newLabel();
	next = *newLabel();

	endPoint = true;
	cond->generator();
	endPoint = false;
	
	stringListPushBack(flowsList, cond->true_+":");
	if(stmt) stmt->generator();
	stringListPushBack(flowsList, "  goto " + next);
	
	stringListPushBack(flowsList, cond->false_+":");
	if(elseStmt) elseStmt->generator();
	stringListPushBack(flowsList, next + ":");
}
void WhileAST::generator(){
    begin = *newLabel();
	cond->true_ = *newLabel();
	cond->false_ = *newLabel();
	next = cond->false_;
	stringListPushBack(flowsList, begin + ": // begin of 'while'");
	
	endPoint = true;
	cond->generator();
	endPoint = false;

	stringListPushBack(flowsList, cond->true_ + ":");
	if(stmt) stmt->generator();
	stringListPushBack(flowsList, "  goto " + begin + " ");
	stringListPushBack(flowsList, next + ":");
}
void BreakAST::generator(){
    stringListPushBack(flowsList, "  goto " + nextCode->next);
}
void ContinueAST::generator(){
    stringListPushBack(flowsList, "  goto " + nextCode->begin);
}
void ReturnAST::generator(){
    if(exp){
		exp->generator();
		stringListPushBack(flowsList, "  return " + exp->addr);
	}
	else stringListPushBack(flowsList, "  return");
}

/*************************************************/
/*****************   表达式相关  ******************/
/*************************************************/
//二元表达式AST
void BinaryExpAST::generator(){
    //如果是声明const
    if(isConst_){
        addr = num2string(val);
        if(endPoint){
            if(val) stringListPushBack(flowsList, "  goto "+true_);
            else stringListPushBack(flowsList, "  goto "+false_);
        }
        return ;
    }

    addr = *newTemp();
    //处理first和second时可能更改endPoint，先临时储存一下
    bool tmpEndPoint = endPoint;
    endPoint = false;

    switch (op){
        case PLUS:
        case MINUS:
        case MULTI:
        case DIVI:
        case MOD:
        {
            firstExp->generator();
            secExp->generator();
            stringListPushBack(flowsList, "  " + addr+" = "+firstExp->addr+" "+token2string[op-258].c_str()+" "+secExp->addr);
            endPoint = tmpEndPoint;
            if(endPoint){
                stringListPushBack(flowsList, "  if "+addr+" !=0  goto "+ true_);
                stringListPushBack(flowsList, "  goto "+false_);
            }
            return ;
        }   

        case EQ:
        case GorEQ:
        case LorEQ:
        case NEQ:
        case LESS:
        case GREAT:
        {
            firstExp->generator();
            secExp->generator();

            list<string>::iterator expTrue = newLabel(), next = newLabel();
			stringListPushBack(flowsList, "  if " + firstExp->addr + " " + token2string[op-258].c_str() + \
            " " + secExp->addr + " goto " + *expTrue);
			stringListPushBack(flowsList, "  " + addr + " = 0");
			stringListPushBack(flowsList, "  goto " + *next);
			stringListPushBack(flowsList, *expTrue + ":");
			stringListPushBack(flowsList, "  " + addr + " = 1");
			stringListPushBack(flowsList, *next + ":");

            endPoint = tmpEndPoint;
            if(endPoint){
                stringListPushBack(flowsList, "  if "+addr+" != 0  goto "+ true_);
                stringListPushBack(flowsList, "  goto "+false_);
            }
            return ;
        }

    }

    endPoint = tmpEndPoint;
    if(endPoint){
        switch (op)
        { 
            case OR:
            {
                firstExp->true_ = true_;
                firstExp->false_ = *newLabel();
                secExp->true_ = true_;
                secExp->false_ = false_;
                firstExp->generator();
                stringListPushBack(flowsList, firstExp->false_ + ":");
                secExp->generator();
                return ;
            }

            case AND:
            {
                firstExp->true_ = *newLabel();
                firstExp->false_ = false_;
                secExp->true_ = true_;
                secExp->false_ = false_;
                firstExp->generator();
                stringListPushBack(flowsList, firstExp->true_ + ":");
                secExp->generator();
                return ;
            }
        }
    }
    if(Debug) printf("Error in irgen->BinaryExpAST::generator()\n");
}

//一元表达式AST
void UnaryExpAST::generator(){
    //如果是声明const
    if(isConst_){
        addr = num2string(val);
        if(endPoint){
            if(val) stringListPushBack(flowsList, "  goto "+true_);
            else stringListPushBack(flowsList, "  goto "+false_);
        }
        return ;
    }
    
    //处理first和second时可能更改endPoint，先临时储存一下
    bool tmpEndPoint = endPoint;
    endPoint = false;
    firstExp->generator();
    addr = firstExp->addr;

    if( op==PLUS ){;}
    else if( op==MINUS ){
        strIt ptr = newTemp();
        stringListPushBack(flowsList, "  " + *ptr+" = - "+addr);
        addr = *ptr;
    }else if(op==NOT){
        strIt ptr = newTemp();
        stringListPushBack(flowsList, "  " + *ptr + " = ! "+addr);
        addr = *ptr;
    }else if(op==Minus_Not){
        strIt ptr1 = newTemp();
        strIt ptr2 = newTemp();
        stringListPushBack(flowsList, "  " + *ptr1+" = ! "+addr);
        addr = *ptr1;
        stringListPushBack(flowsList, "  " + *ptr2+" = - "+addr);
        addr = *ptr2;
    }else if(op==Minus_Not_Not){
        strIt ptr1 = newTemp();
        strIt ptr2 = newTemp();
        strIt ptr3 = newTemp();
        stringListPushBack(flowsList, "  " + *ptr1+" = ! "+addr);
        addr = *ptr1;
        stringListPushBack(flowsList, "  " + *ptr2+" = ! "+addr);
        addr = *ptr2;
        stringListPushBack(flowsList, "  " + *ptr3+" = - "+addr);
        addr = *ptr3;
    }
    /*switch (op){
            strIt ptr1 = newTemp();
            strIt ptr2 = newTemp();
            strIt ptr3 = newTemp();
            case PLUS:
                break;
            case MINUS:
                //strIt ptr = newTemp();
                stringListPushBack(flowsList, *ptr1+" = - "+addr);
                addr = *ptr1;
                break;
            case NOT:
                //strIt ptr = newTemp();
                stringListPushBack(flowsList, *ptr1 + " = ! "+addr);
                addr = *ptr1;
                break;
            case Minus_Not://"-!"
                //strIt ptr1 = newTemp();
                //strIt ptr2 = newTemp();
                stringListPushBack(flowsList, *ptr1+" = ! "+addr);
                addr = *ptr1;
                stringListPushBack(flowsList, *ptr2+" = - "+addr);
                addr = *ptr2;
                break;
            case Minus_Not_Not://"-!!"
                //strIt ptr1 = newTemp();
                //strIt ptr2 = newTemp();
                //strIt ptr3 = newTemp();
                stringListPushBack(flowsList, *ptr1+" = ! "+addr);
                addr = *ptr1;
                stringListPushBack(flowsList, *ptr2+" = ! "+addr);
                addr = *ptr2;
                stringListPushBack(flowsList, *ptr3+" = - "+addr);
                addr = *ptr3;
                break;
            default:
                break;
    }*/

    endPoint = tmpEndPoint;
    if(endPoint){
        stringListPushBack(flowsList, "  if "+addr+" !=0  goto "+ true_);
        stringListPushBack(flowsList, "  goto "+false_);
    }
}

void LvalAST::generator(){
    //如果是声明const
    if(isConst_){
        addr = num2string(val);
        if(endPoint){
            if(val) stringListPushBack(flowsList, "  goto "+true_);
            else stringListPushBack(flowsList, "  goto "+false_);
        }
        return ;
    }
    bool tmpEndPoint = endPoint;
    endPoint = false;

    // 非const
	auto sym_ = dynamic_cast<varSymEntry *>(sym);
	const int arrWidthSize = sym_->dims.size();
	const int indexSize = indexs.size();
	// 普通变量，不管是不是左值(非数组)
	if(arrWidthSize == 1 || indexSize == 0){
		addr = sym_->father->addr;
		endPoint = tmpEndPoint;
		if(endPoint){
			stringListPushBack(flowsList, "  if " + addr + " != 0 goto " + true_);
			stringListPushBack(flowsList, "  goto " + false_);
		}
		return;
	}
    // 数组或指针
	list<string>::iterator p1, p2, p3;
	p1 = newTemp();
	indexs[0]->generator();
	stringListPushBack(flowsList, "  " + *p1 + " = " + \
		indexs[0]->addr + " * " + num2string(sym_->dims[arrWidthSize - 2]));
	for(int i = 1;i < indexSize;++i){
		p2 = newTemp();
		p3 = newTemp();
		indexs[i]->generator();
		stringListPushBack(flowsList, "  " + *p2 + " = " + \
		indexs[i]->addr + " * " + num2string(sym_->dims[arrWidthSize - 2 - i]));
		stringListPushBack(flowsList, "  " + *p3 + " = " + *p1 + " + " + *p2);
		p1 = p3;
	}

	p2 = newTemp();
	stringListPushBack(flowsList, "  " + *p2 + " = " + *p1 + " * 4");

	if(!isLeft_){
		addr = *newTemp();
		// 使用标量
		if(arrWidthSize == indexSize + 1){
			stringListPushBack(flowsList, "  " + addr + " = " + sym_->father->addr + \
				+ "[" + *p2 + "]");
		}
		// 使用指针（给出的index数目比多维数组声明要少）
		else
			stringListPushBack(flowsList, "  " + addr + " = " + sym_->father->addr + " + " + *p2);
		
		endPoint = tmpEndPoint;
		if(endPoint){
			stringListPushBack(flowsList, "  if " + addr + " != 0 goto " + true_);
			stringListPushBack(flowsList, "  goto " + false_);
		}
		
		return;
	}
	else{
		endPoint = tmpEndPoint;
		addr = sym->father->addr + "[" + *p2 + "]";
		return;
	}
}

void treatMain(BaseAST* root){
    if(root==nullptr){
        printf("Error in irgen->treatMain, root is NULL!\n");
        return ;
    }
	for(auto i:dynamic_cast<BlockAST *>(root)->items){
		if(i->type != ASTtype::Define) continue;
		auto p = dynamic_cast<DefineAST *>(i);
		auto symp = dynamic_cast<varSymEntry *>(p->sym);
		//非数组
		if(symp->dims.size() == 1){
			globalVarList.push_back(p->addr);
			if(!p->mmap.empty()) {
				/* initialize */
				p->mmap[0]->generator();
				mainInitList.splice(mainInitList.end(), flowsList);
				mainInitList.push_back("  " + p->addr + " = " + p->mmap[0]->addr);
			}
			continue;
		}
		globalVarList.push_back(num2string(symp->dims.back() * 4) + " " + p->addr);
		// 数组
		for(auto i:p->mmap){
			/* initialize */
			i.second->generator();
			mainInitList.splice(mainInitList.end(), flowsList);
			mainInitList.push_back("  " + p->addr + "[" + num2string(i.first * 4) + "] = " + i.second->addr);
		}
	}

	globalVarList.splice(globalVarList.end(), tempVarList);
	for(auto &i: globalVarList)
		cout << "var " << i << endl;
	if(!globalVarList.empty()) cout << endl;
	globalVarList.clear();
}

void traverseAST(BaseAST* root){
    if(root==nullptr){
        printf("Error in irgen->traverseAST, root is NULL!\n");
        return ;
    }
	for(auto i: dynamic_cast<BlockAST *>(root)->items){
		if(i->type == ASTtype::FunDef) i->generator();
	}
}