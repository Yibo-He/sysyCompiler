#include "global.hpp"

//区域号，0号代表全局区域
int blockNum = 0;
//行号，主要用于运行时库
int lineno = 1;

int labelNum = 0; //l,用于计数，label
int paraNum = 0; //p，函数参数当前的数目
int tempVarNum = 0; //t，临时变量当前的数目
int nativeVarNum = 0; //T，原生变量当前的数目

//用链表构成一个栈
list<BaseAST*> whileStack;
BaseAST* currentFun;

BaseAST* mainptr = nullptr;

list<string> strtab; //全局字符表，词法分析中碰到的identifier均插入其中（最前方）


/**************************************************/
/****************** 多维数组处理 *******************/
/**************************************************/
/*
获得多维数组的width，计算公式Width(k-1)=width(k)*arr(k)
例如给定arr[2][3][4][5]，返回的数组为{1,5,20,60,120}
*/
vector<int> getArrWidth(const vector<int> &arrDef){
   //如果是空数组，返回只有1的数组
   vector<int> tmp (1,1);
   if(arrDef.size()==0) return tmp;
   int k = 1;
   //从后向前计算Wk*Nk
   for( auto i = arrDef.rbegin(); i!= arrDef.rend(); ++i){
      k *= *i;
      tmp.push_back(k);
   }
   return tmp;
}
//计算数组引用的地址，公式addr=(base)+sigma( i*width(i) )
/*
例如给定width{1,5,20,60,120}，indexs{1,2,3,4}
返回 1*60+2*20+3*5+4 = 119
*/
int getArrAddr(const vector<int> &width, const vector<int> &indexs){
   int ans = 0;
   int widthLen = width.size();
   int indexsLen = indexs.size();
   if(widthLen==1) return ans;
   for(int i = 0; i<indexsLen; ++i){
      ans += (indexs[i]*width[widthLen-2-i]);
   }
   return ans;
}

//将数字转化为字符
string num2string(int num){
    string ans = to_string(num);
    return ans;
}

void stringListPushBack(list<string> &List_, const string &ss){
    List_.push_back(ss);
}