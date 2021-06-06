#include <iostream>
#include <fstream>
#include <unistd.h>
#include "ast_eeyore.hpp"
#include "parser_hyb_2.tab.hpp"
extern FILE * e2tin;
extern FILE * e2tout;

using namespace std;

inline void myassert_fail(int line, const char* fn){
    printf("error: assertion failed\n%s (line %d)\n",fn, line);
    exit(5+line%100);
}

#define assert(x) do {if(!x) myassert_fail(__LINE__, __FILE__);}  while(0);

void Compile2(){
  BaseEeyoreAST* root;
  e2tparse(&root);
  dynamic_cast<ProgramAST_2 *>(root)->generator();
}

void Compile_eeyore2tigger(FILE* f1, FILE* f2) {

  if(f2 == nullptr){
    cerr<<"Error, no output file!"<<endl;
    return ;
  }

  if(f1 == nullptr){
    cerr<<"Error, no input file!"<<endl;
    return ;
  } 
  e2tin = f1;
  e2tout = f2;
  //cout重定向
  streambuf* coutBuf = cout.rdbuf();
  ofstream of("ir2.tigger");
  streambuf* fileBuf = of.rdbuf();
  cout.rdbuf(fileBuf);

  Compile2();
  
  //恢复cout重定向
  cout.rdbuf(coutBuf);

  fclose(f1);
  fclose(f2);
}

