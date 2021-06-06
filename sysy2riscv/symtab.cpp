#include "symtab.hpp"

//全局符号表
symTab* const globalSymTab = new symTab(blockNum);
//当前符号表
static symTab* currentSymTab = globalSymTab;

void varSymEntry::setDims(vector<int> && arr) {dims = arr;}
void funSymEntry::insertParams(BaseEntry* ptr) { fParams.push_back(ptr); }

//创建新的变量表项
BaseEntry* newVarEntry(bool isConst, Token1* token1, BaseAST* ast){
    BaseEntry* newEntry = new varSymEntry(isConst, token1, ast);

    BaseEntry* temp = checkIfDecl(newEntry);
    if(temp){
        if(Debug) printf("Error in function 'symtab.cpp->newVarEntry', statement conflict!\n");
        if(Debug) printf("id = %s\n", token1->strPtr->c_str());
        delete newEntry;
        return nullptr;
    }

    return newEntry;
}

//创建新的函数表项
BaseEntry* newFunEntry(bool isVoid, Token1* token1, BaseAST* ast){
    BaseEntry* newEntry = new funSymEntry(isVoid, token1, ast);

    BaseEntry* temp = checkIfDecl(newEntry);
    if(temp){
        if(Debug) printf("Error in function 'symtab.cpp->newFunEntry', statement conflict!\n");
        if(Debug) printf("id = %s\n", token1->strPtr->c_str());
        delete newEntry;
        return nullptr;
    }

    return newEntry;
}

//new一个新的符号表，
//将刚产生的符号表加入当前符号表的children数组中，并更新当前符号表
//（有点类似进程线程模型）
void pushSymtab(){
    blockNum++;
    symTab* tmp = new symTab(blockNum, currentSymTab);
    currentSymTab->children.push_back(tmp);
    currentSymTab = tmp;
}

//返回当前符号表的父表
void popSymtab(){
    blockNum--;
    currentSymTab = currentSymTab->father;
    if(!currentSymTab){
        if(Debug) printf("Error in function 'symtab.cpp->popSymtab', no father symTab!\n");
    }
}

//插入表项的函数
void insertEntry(BaseEntry* entry){
    if(entry) currentSymTab->table.insert(entry);
    if(Debug){
        printf("insert entry: %s\n",entry->strp->c_str());
        //cout<<"insert entry:"<<*(entry->strp)<<endl;
    }
}

//从当前的符号表一直上溯，直到全局符号表，查找是否有同名变量已经声明
//如果有，返回该表项的指针
BaseEntry* findString(strIt strp){
    BaseEntry* tmp = new BaseEntry(strp, nullptr);
    for(auto i=currentSymTab; i; i = i->father){
        i->printSymtab();
        if( i==nullptr ){
            if(Debug) printf("Error in findString!\n");
            return nullptr;
        }
        auto j = i->table.find(tmp);
        if( j != i->table.end() ) {
            delete tmp;
            return *j;
        }
    }
    delete tmp;
    return nullptr;
}

//无上溯，只查找当前区域是否已经有该变量声明
//如果有，说明变量声明产生了冲突
BaseEntry* checkIfDecl(BaseEntry* entry){
    auto j = currentSymTab->table.find(entry);
    if( j!=currentSymTab->table.end() )
        return *j;
    return nullptr;
}

hash<string> hashstr;