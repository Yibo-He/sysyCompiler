#pragma once
#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "symtab.hpp"
#include "global.hpp"
using namespace std;

/**************************************************/
/********Abstract syntax tree for parsing *********/
/**************************************************/

/*typedef enum{
    Base, Define, FunDef, FunCall, Block,
    Assign, If, While, Break, Continue, Return,
    BinaryExp, UnaryExp, Lval,
    ArrAST, ListTree_
} ASTtype;*/

//基本的AST
//class BaseAST;
//变量声明AST
class DefineAST;
//函数相关的AST
class FunDefAST; class FunCallAST; class BlockAST;
//控制流相关的AST
class AssignAST; class IfAST; class WhileAST; class BreakAST;
class ContinueAST; class ReturnAST;
//表达式相关的AST
class BinaryExpAST; class UnaryExpAST; class LvalAST;
//辅助的AST
class arrAST; class ListTree;


/***************************************************/
/******************   基本的AST  *******************/
/***************************************************/
/*class BaseAST{
    public:
        ASTtype type;
        string addr;
        string true_; //true branche of control
        string false_; //false branche of control
        string begin;
        string next;

        BaseAST():type(Base){};
        ~BaseAST();
        virtual void generator();
        virtual void setVal(int);
        virtual int getVal();
        virtual int cal();
        virtual bool isConst();
        virtual bool isNumber(){return false;} //提前判断一个节点是否是一个数
};*/


/**************************************************/
/****************   变量声明的AST  *****************/
/**************************************************/
class DefineAST : public BaseAST{
    public:
        BaseEntry* sym;
        //有关初始值的处理，用map是因为数组的初始化可能不止一个BaseAST
        map<int, BaseAST*> mmap; 
        BaseAST* getMmap(int index);    

        DefineAST():sym(nullptr){type=Define;}
        ~DefineAST(){
            for(auto i:mmap){
                if(i.second) delete i.second;
            }
        }
        virtual void generator();
        BaseAST* getInitVal(int index);
};


/**************************************************/
/****************   函数相关的AST  *****************/
/**************************************************/
//函数定义
class FunDefAST : public BaseAST{
    public:
        BaseEntry* sym;
        string name;
        BaseAST* body;
        vector<BaseAST*> fParams; //形参

        FunDefAST():sym(nullptr),body(nullptr){type=FunDef;};
        ~FunDefAST(){
            for(auto i:fParams){
                if(i) delete i;
            }
            if(body) delete body;
        }
        virtual void generator();
};

//函数调用
class FunCallAST : public BaseAST{
    public:
        BaseEntry* sym;
        vector<BaseAST*> rParams; //实参

        FunCallAST(){type=FunCall;};
        FunCallAST(Token1* token1);
        ~FunCallAST(){
            for(auto i:rParams)
                if(i) delete i;
        }
        bool checkParaSize(); //检查实参是否与形参数目相同
        virtual void generator();
        virtual bool isConst(){return false;}
        virtual int getVal(){return 0;}
        virtual bool isNumber(); //如果是void类型则返回false，int类型返回true
};

//语句块
class BlockAST : public BaseAST{
    public:
        const int blockN;
        vector<BaseAST*> items;

        BlockAST():blockN(blockNum){type=Block;};
        ~BlockAST();
        virtual void generator();

        void insertItem(BaseAST* ptr){if(ptr) items.push_back(ptr);}
        void insertItems(vector<BaseAST*> &&ptr){
            for(auto i : ptr)
                items.push_back(i);
        }
};


/**************************************************/
/***************   控制流相关的AST  ****************/
/**************************************************/
//赋值语句
class AssignAST : public BaseAST{
    public:
        BaseAST* lval;
        BaseAST* exp;

        AssignAST():lval(nullptr),exp(nullptr){type=Assign;}
        ~AssignAST(){
            if(lval) delete lval;
            if(exp) delete exp;
        }
        virtual void generator();
};

//条件
class IfAST : public BaseAST{
    public:
        BaseAST* cond;
        BaseAST* stmt;
        BaseAST* elseStmt;

        IfAST():cond(nullptr),stmt(nullptr),elseStmt(nullptr){type=If;};
        ~IfAST(){
            if(cond) delete cond;
            if(stmt) delete stmt;
            if(elseStmt) delete elseStmt;
        }
        virtual void generator();
};

//循环
class WhileAST : public BaseAST{
    public:
        BaseAST* cond;
        BaseAST* stmt;

        WhileAST():cond(nullptr),stmt(nullptr){type=While;}
        ~WhileAST(){
            if(cond) delete cond;
            if(stmt) delete stmt;
        }
        virtual void generator();
};

//break
class BreakAST : public BaseAST{
    public:
        BaseAST* nextCode;

        BreakAST():nextCode(topWhileStack()){type=Break;}
        ~BreakAST();
        virtual void generator();
};

//continue
class ContinueAST : public BaseAST{
    public:
        BaseAST* nextCode;

        ContinueAST():nextCode(topWhileStack()){type=Continue;}
        ~ContinueAST();
        virtual void generator();
};
 
//返回
class ReturnAST : public BaseAST{
    public:
        BaseAST* nextCode;
        BaseAST* exp;

        ReturnAST():nextCode(currentFun),exp(nullptr){type=Return;}
        ~ReturnAST();
        virtual void generator();
};


/**************************************************/
/***************   表达式相关的AST  ****************/
/**************************************************/
//二元表达式
class BinaryExpAST : public BaseAST{
    public:
        BaseAST* firstExp;
        BaseAST* secExp;
        int op;
        int val;
        bool isConst_;
        bool isCaled_;

        BinaryExpAST(){type=BinaryExp;}
        BinaryExpAST(Token1* token1);
        BinaryExpAST(BaseAST* a, BaseAST*b, Token1* token1);
        ~BinaryExpAST();
        virtual void generator();
        virtual void setVal(int a){val = a;}
        virtual bool isConst(){return isConst_;}
        virtual bool isNumber();
        virtual int getVal(){return val;}
        virtual int cal();
};

//一元表达式
class UnaryExpAST : public BaseAST{
    public:
        BaseAST* firstExp;
        int op;
        int val;
        bool isConst_;
        bool isCaled_;

        UnaryExpAST(){type=UnaryExp;}
        UnaryExpAST(BaseAST* a, Token1* token1);
        ~UnaryExpAST();
        void dealOp(Token1* token1);
        virtual void generator();
        virtual void setVal(int a){val = a;}
        virtual bool isConst(){return isConst_;}
        virtual bool isNumber();
        virtual int getVal(){return val;}
        virtual int cal();
};

//变量引用
class LvalAST : public BaseAST{
    public:
        BaseEntry* sym;
        //如果引用数组，这个vector记录方括号内的exp
        vector<BaseAST*> indexs;
        int val;
        bool isConst_;
        bool isCaled_;
        /* eeyore: left value */
	    bool isLeft_;

        LvalAST(){type=Lval;}
        LvalAST(Token1* token1, BaseAST* ast);
        ~LvalAST(){
            for(auto i:indexs){
                if(i) delete i;
            }
        }

        //检查是否有过多index（例如声明了2维数组，却使用了大于二维的引用）
        bool checkTooManyIndex();

        //检查index是否有负数
        bool checkNegIndex();

        //检查index是否越界
        bool checkIfOutOfBound();

        virtual void generator();
        virtual void setVal(int a){val = a;}
        virtual bool isConst(){return isConst_;}
        virtual bool isNumber();
        virtual int getVal(){return val;}
        virtual int cal();
};

/*************************************************/
/*****************   辅助的AST  ******************/
/*************************************************/
//处理数组引用、函数参数等
class arrAST: public BaseAST{
    public:
        arrAST(){type=ArrAST;}
        ~arrAST(){};
        //用于存储的vector
        vector<BaseAST*> exps;
        void insertArrAst(BaseAST* ast){ exps.push_back(ast); }
        vector<BaseAST*> output(){ return move(exps); }
        //计算exp的值并清空exps
        vector<int> calExps(){
            vector<int> ans;
            for(auto ptr :exps){
                ans.push_back(ptr->getVal());
            }
            for(auto ptr :exps){
                if(ptr) delete ptr;     
            }
            exps.clear();
            return ans;
        }
};

//处理多维数组的初始化
class ListTree: public BaseAST{
    public:
        BaseAST* astptr; // 如果数组声明含有表达式，则指向这个exp
        
        ListTree():BaseAST(),astptr(nullptr) { type=ListTree_; } 
        ListTree(Token1* l, Token1* r):BaseAST(), astptr(nullptr) { type=ListTree_; }// '{' '}', 空
        ListTree(BaseAST* astptr):BaseAST(), astptr(astptr) { type=ListTree_; } // 叶子节点

        ~ListTree() {
            if(!astptr) {
                for(auto p: sublist) delete p;
                sublist.clear();
            }
	    }

        vector<BaseAST* > sublist; // 高维的大括号指向低维的大括号
        void insertSublist(BaseAST* p){ sublist.push_back(p); } 
        map<int, BaseAST* > Flatten(const vector<int> &dims); 
        void _Flatten_(vector<int> &dim, map<int, BaseAST* > &res, int ind, int upper); 

};

#endif