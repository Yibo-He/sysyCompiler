#pragma once
#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <list>
using namespace std;

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUEs
#define TRUE 1
#endif

#ifndef Debug
#define Debug 0
#endif

//区域号，0号代表全局区域
extern int blockNum;
//行号，主要用于运行时库
extern int lineno;

extern int labelNum; //l,用于计数，label
extern int paraNum; //p，函数参数当前的数目
extern int tempVarNum; //t，临时变量当前的数目
extern int nativeVarNum; //T，原生变量当前的数目

/*************************************************/
/*******************   strTab ********************/
/*************************************************/
//全局字符表，词法分析中碰到的identifier均插入其中（最前方）
extern list<string> strtab;

typedef list<string>::iterator strIt;
inline strIt insertStrtab(const char* c){
    string tmp = c;
    strtab.push_front(move(tmp));//右值引用
    return strtab.begin();
}

/***************************************************/
/******************   基本的AST  *******************/
/***************************************************/
typedef enum{
    Base, Define, FunDef, FunCall, Block,
    Assign, If, While, Break, Continue, Return,
    BinaryExp, UnaryExp, Lval,
    ArrAST, ListTree_
} ASTtype;

class BaseAST{
    public:
        ASTtype type;
        string addr;
        string true_; //true branche of control
        string false_; //false branche of control
        string begin;
        string next;

        BaseAST():type(Base){};
        ~BaseAST(){};
        virtual void generator(){};
        virtual void setVal(int){};
        virtual int getVal(){return -1;};
        virtual int cal(){return -1;};
        virtual bool isConst(){ return false; };
        virtual bool isNumber(){return false;} //提前判断一个节点是否是一个数
};

/*************************************************/
/****************   control flow *****************/
/*************************************************/
//用链表构成一个栈
extern list<BaseAST*> whileStack;

inline BaseAST* topWhileStack() {return whileStack.back();}
inline bool isEmptyWhileStack() {return whileStack.empty();}
inline void pushWhileStack(BaseAST* p) {whileStack.push_back(p); }
inline void popWhileStack() {whileStack.pop_back();}

extern BaseAST* currentFun;
/**************************************************/
/******************   tokenType *******************/
/**************************************************/

/*typedef enum{
   //260-268
   //part1: keywords
   CONST=258, INT, VOID, IF,
   ELSE, WHILE, BREAK, CONTINUE,
   RETURN,
   //269
   //part2: identifier
   IDENT,
   //270-279
   //part3: operator
   AND, OR,
   EQ, GorEQ, LorEQ, NEQ,
   PLUandA, MINandA, MULandA, DIVandA,
   ASSIGN, GREAT, LESS,
   PLUS, MINUS, MULTI, DIVI,
   MOD, NOT,
   //280-287
   //part4: delimiter
   LXKH, RXKH, // '('  ')'
   LZKH, RZKH, // '['  ']'
   LDKH, RDKH, // '{'  '}'
   SEMI, COMMA, // ';'  ','
   //288-290
   //part5: literal
   HEX_INT, OCT_INT, DIGIT_INT, INT_CONST,
   //Unrecognized 
   OTHER, 
   Minus_Not, Minus_Not_Not//used in UnaryExpAST
} tokenType;*/
#define tokenType int

const string token2string[] = {
   "const", "int", "void", "if",
   "else", "while", "break", "continue",
   "return","ident","&&", "||",
   "==", ">=", "<=", "!=",
   "+=", "-=", "*=", "/=",
   "=", ">", "<",
   "+", "-", "*", "/",
   "%", "!","(", ")",
   "[", "]",
   "{", "}",
   ";", ",",
   "HEX_INT", "OCT_INT", "DIGIT_INT","INT_CONST"
   "OTHER", "Minus_Not","Minus_Not_Not"
};


/**************************************************/
/********************* Token **********************/
/**************************************************/
//词法分析获得token
class Token{
    public:
      tokenType type;
      int val; //const int
      strIt strPtr; //identifier
      int lineNum;

      Token(tokenType type_):type(type_){};
      Token(tokenType type_, int val_):type(type_),val(val_){};
      Token(tokenType type_, const char* c):type(type_),strPtr(insertStrtab(c)){};
      Token(tokenType type_, const char* c, int lineno):type(type_),strPtr(insertStrtab(c)),lineNum(lineno){};

      /*void printToken(){
         printf("Get a Token: %s,  ",token2string[type-260].c_str());
         if(type==HEX_INT||OCT_INT||DIGIT_INT||INT_CONST) printf("val = %d  ",val);
         if(type==IDENT) printf("id = %s", strPtr->c_str());
         printf("\n");
      }*/
};

/**************************************************/
/****************** 多维数组处理 *******************/
/**************************************************/
/*
获得多维数组的width，计算公式Width(k-1)=width(k)*arr(k)
例如给定arr[2][3][4][5]，返回的数组为{1,5,20,60,120}
*/
vector<int> getArrWidth(const vector<int> &arrDef);

//计算数组引用的地址，公式addr=(base)+sigma( i*width(i) )
/*
例如给定width{1,5,20,60,120}，indexs{1,2,3,4}
返回 1*60+2*20+3*5+4 = 119
*/
int getArrAddr(const vector<int> &width, const vector<int> &indexs);

//将数字转化为字符
string num2string(int num);

void stringListPushBack(list<string> &List_, const string &ss);

extern BaseAST* mainptr;

#endif