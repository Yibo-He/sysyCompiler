#pragma once
#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <string>
#include <vector>
#include <list>
#include <set>
#include "global.hpp"
#include <iostream>
#include <unordered_set>
using namespace std;

/***************************************************/
/****************** Symbol table *******************/
/***************************************************/

//使用到符号表的AST节点有：FunDefAST, FunCallAST, LvalAST, DefineAST
//符号表有两种：变量符号表和函数表
class varSymEntry; class funSymEntry;
class symTab;

extern symTab* const globalSymTab;
extern hash<string> hashstr;
typedef enum{varSym, funSym} entryType;
//基类空表项
class BaseEntry{
    public:
        BaseAST* father; //指向创建符号表的AST node
        entryType type;
        BaseEntry(strIt str, BaseAST* ast):strp(str),father(ast),fngprnt(hashstr(*str)){};
        ~BaseEntry(){};
        list<string>::iterator strp; //表项名
        bool operator != (const BaseEntry* tmp){
            return (strp->c_str() != tmp->strp->c_str());
        }
        bool operator == (const BaseEntry* tmp){
            return (strp->c_str() == tmp->strp->c_str());
        }
        bool operator < (const BaseEntry* tmp){
            return *strp < *(tmp->strp);
        }
        //没卵用的虚函数，形成多态以使用强制类型转换
        virtual void justAVirtual(){};
        const size_t fngprnt; // Fingerprint of the token1 name. Compute it once for all.
};
class BaseEntryCompare{
    public:
        bool operator()(const BaseEntry* entry1, const BaseEntry* entry2) const {
            return ( entry1->strp->c_str() < entry2->strp->c_str());
        }
};

//变量表项
class varSymEntry:public BaseEntry{
    public:
        //BaseAST* father; //指向创建符号表的AST node
        const bool isConst;
        vector<int> dims; //记录数组width，例如a[3][2],为1,2,6
        void setDims(vector<int> && a);

        varSymEntry(bool isConst_, Token1* token1, BaseAST* ast): \
        BaseEntry(token1->strPtr, ast),isConst(isConst_){
            type = varSym;
        };
        ~varSymEntry();
};

//函数表项
class funSymEntry:public BaseEntry{
    public:
        //BaseAST* father; //指向创建符号表的AST node
        const bool isVoid;
        vector<BaseEntry*> fParams;
        void insertParams(BaseEntry*);

        funSymEntry(bool isVoid_,Token1* token1, BaseAST* ast): \
        BaseEntry(token1->strPtr, ast),isVoid(isVoid_){
            type = funSym;
        };
        ~funSymEntry();
};

// Just functional Class
class EqualSYM{
public:
	bool operator () (BaseEntry* p, BaseEntry* q) const {
		return *(p->strp) == *(q->strp);
	}
};

// Just functional class
class HashSYM{
public:
	size_t operator () (BaseEntry* p) const {return p->fngprnt;}
};

//符号表
class symTab{
    public:
        symTab(int blockN_, symTab* father_ = nullptr): father(father_), blockN(blockN_) {}
	    ~symTab(){for(auto i: table) delete i; for(auto i: children) delete i;}; 
        unordered_set<BaseEntry*, HashSYM, EqualSYM> table;
        vector<symTab*> children;
        symTab* father;
        int blockN;
        void printSymtab(){
            if(Debug){
                printf("symTab blockN = %d :\n",blockN);
                int entryNum = 0;
                for(auto i: table){
                    printf("%d: enrty name is: %s\n",entryNum++,i->strp->c_str());
                }
            }else return ;
        }
};


/*** 以下是相关函数 ***/
//新建表项，并检查是否已经存在
BaseEntry* newVarEntry(bool isConst, Token1* token1, BaseAST* ast);
BaseEntry* newFunEntry(bool isVoid, Token1* token1, BaseAST* ast);

void pushSymtab();
void popSymtab();

void insertEntry(BaseEntry*);

BaseEntry* findString(strIt strp);
BaseEntry* checkIfDecl(BaseEntry* entry);

#endif