//#pragma once
#ifndef AST_TIGGER_HPP
#define AST_TIGGER_HPP

#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <iostream>
using namespace std;

#ifndef Debug
#define Debug 1
#endif

typedef enum{
    variable, function, num, reg, op, keyWord, label
}tokenType;

typedef enum{
    Plus, Minus, Multi, Divi, Mod, Not, More, Less, MorEq, LorEq, \
    And, Or, Neq, Eq
}opType;
int op2int(string op);

const string tokenType2string[] = {"variable", \
    "function", "num", "reg", "op", "keyword", "label"};

class Token{
    public:
        int type;
        string name;
        int op;
        bool isOp;
        void Print(){
            printf("Get token, type:%s, text:%s\n",tokenType2string[type].c_str(),name.c_str());
        }
        Token(int type_):type(type_){
            if(Debug) Print();
        }
        Token(int type_, const char* s):type(type_),name(s){
            if(Debug) Print();
        }
        /*Token(int type_, int op_, bool isOp_):type(type_),op(op_),isOp(isOp_){
            if(Debug) Print();
        }*/
};

static list<string> riscvCode;
int string2num(const string s);
string num2string(int num);

class BaseTiggerAST;
class ProgramAST; class GlobalVarDeclAST; class FunctionDefAST; 
class FunctionHeaderAST;class ExpressionsAST;class FunctionEndAST;class ExpressionAST;

typedef enum{
    BaseTigger, Program, GlobalVarDecl, FunctionDef, FunctionHeader, Expressions, FunctionEnd, Expression
} tiggerASTtype;

class BaseTiggerAST{
    public:
        list<string> riscvAction; // used in ExpressionAST
        int n1; // used in FunctionHeaderAST
        int n2; // used in FunctionHeaderAST
        int STK;
        tiggerASTtype type;
        BaseTiggerAST(){type=BaseTigger;}
        virtual void generator(){};
};
class ProgramAST : public BaseTiggerAST{
    public:
        vector<BaseTiggerAST*> varDecls;
        vector<BaseTiggerAST*> funDefs;
        ProgramAST(){type=Program;}
        virtual void generator();
};
class GlobalVarDeclAST : public BaseTiggerAST{
    public:
        string varName;
        string num;
        bool isMalloc;
        virtual void generator();
        GlobalVarDeclAST(string name, int num_, bool isMalloc_): \
        varName(name), num(num2string(num_)), isMalloc(isMalloc_){type=GlobalVarDecl;};
};
class FunctionDefAST : public BaseTiggerAST{
    public:
        BaseTiggerAST* funHead;
        BaseTiggerAST* exps;
        BaseTiggerAST* funEnd;
        virtual void generator();
        FunctionDefAST(BaseTiggerAST* p1, BaseTiggerAST* p2, BaseTiggerAST* p3): \
        funHead(p1), exps(p2), funEnd(p3){type=FunctionDef;};
        ~FunctionDefAST(){
            if(funHead) delete funHead;
            if(exps) delete exps;
            if(funEnd) delete funEnd;
        }
};
class FunctionHeaderAST : public BaseTiggerAST{
    public:
        string funName;
        BaseTiggerAST* funDef;
        virtual void generator();
        FunctionHeaderAST(string name, int a, int b):funName(name){type=FunctionHeader;n1=a;n2=b;};
};
//语句集：Expressions
class ExpressionsAST : public BaseTiggerAST{
    public:
        vector<BaseTiggerAST*> exp;
        virtual void generator();
        ExpressionsAST(){type=Expressions;};
        ~ExpressionsAST(){
            for(auto i:exp){
                if(i) delete i;
            }
        }
};
class FunctionEndAST : public BaseTiggerAST{
    public:
        string funName;
        virtual void generator();
        FunctionEndAST(string s):funName(s){type=FunctionEnd;};
};
class ExpressionAST : public BaseTiggerAST{
    public:
        virtual void generator();
        ExpressionAST(){type=Expression;};
};

#endif
