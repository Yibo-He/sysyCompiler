#include <iostream>
#include <fstream>
#include <unistd.h>
#include "ast.hpp"
#include "global.hpp"
#include "irgen.hpp"
#include "parser_hyb1.tab.hpp"
extern FILE * s2ein;
extern FILE * s2eout;

using namespace std;

void Compile1();

void Compile_sysy2eeyore(FILE* f1, FILE* f2) {
  
  if(f2 == nullptr){
    cerr<<"Error, no output file!"<<endl;
    return ;
  }

  if(f1 == nullptr){
    cerr<<"Error, no input file!"<<endl;
    return ;
  } 
  
  s2ein = f1;
  s2eout = f2;
  
  //cout重定向
  streambuf* coutBuf = cout.rdbuf();
  ofstream of("ir1.eeyore");
  streambuf* fileBuf = of.rdbuf();
  cout.rdbuf(fileBuf);

  Compile1();
  
  //恢复cout重定向
  cout.rdbuf(coutBuf);

  fclose(f1);
  fclose(f2);
}

void Compile1(){
  BaseAST* root;
  //语法分析
  s2eparse(&root);
  //代码生成
  treatMain(root);
  traverseAST(root);
}
