#include <iostream>
#include <fstream>
#include <unistd.h>
#include "ast_tigger.hpp"
#include "parser_hyb_3.tab.hpp"
extern FILE * yyin;
extern FILE * yyout;

using namespace std;

void Compile(){
  BaseTiggerAST* root;
  yyparse(&root);
  dynamic_cast<ProgramAST *>(root)->generator();
}

void Compile_tigger2riscv(FILE* f1, FILE* f2, char * name) {


  if(f2 == nullptr){
    cerr<<"Error, no output file!"<<endl;
    return ;
  }

  if(f1 == nullptr){
    cerr<<"Error, no input file!"<<endl;
    return ;
  } 
  yyin = f1;
  yyout = f2;
  //cout重定向
  streambuf* coutBuf = cout.rdbuf();
  ofstream of(name);
  streambuf* fileBuf = of.rdbuf();
  cout.rdbuf(fileBuf);

  Compile();
  
  //恢复cout重定向
  cout.rdbuf(coutBuf);

  fclose(f1);
  fclose(f2);
}

