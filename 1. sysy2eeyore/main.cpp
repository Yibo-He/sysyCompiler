#include <iostream>
#include <fstream>
#include <unistd.h>
#include "ast.hpp"
#include "global.hpp"
#include "irgen.hpp"
#include "parser_hyb.tab.hpp"
extern FILE * yyin;
extern FILE * yyout;

using namespace std;

void Compile();

int main(int argc, char *argv[]) {
  // read file from command line argument
  if (argc < 2) {
    cerr << "usage: " << argv[0] << " -S -e <INPUT> -o <OUTPUT> " << endl;
    return 1;
  }

  char opt;
  char *sysy_file_path = nullptr;
	char *output_file_path = nullptr;
  while( (opt = getopt(argc, argv, "e:o:S")) != -1 ){
		if(opt == 'e') sysy_file_path = optarg;
		if(opt == 'o') output_file_path = optarg;
	}

  FILE* input = fopen(sysy_file_path, "r");
  if(input == nullptr){
    cerr<<"Error, no input file!"<<endl;
    cerr << "usage: " << argv[0] << " -S -e <INPUT> -o <OUTPUT> " << endl;
    return 1;
  } 
  FILE* output = fopen(output_file_path, "w");
  if(output == nullptr){
    cerr<<"Error, no output file!"<<endl;
    cerr << "usage: " << argv[0] << " -S -e <INPUT> -o <OUTPUT> " << endl;
    return 1;
  }
  yyin = input;
  yyout = output;
  
  //cout重定向
  streambuf* coutBuf = cout.rdbuf();
  ofstream of(output_file_path);
  streambuf* fileBuf = of.rdbuf();
  cout.rdbuf(fileBuf);

  Compile();
  
  //恢复cout重定向
  cout.rdbuf(coutBuf);

  fclose(input);
  fclose(output);
}

void Compile(){
  BaseAST* root;
  //语法分析
  yyparse(&root);
  //代码生成
  treatMain(root);
  traverseAST(root);
}
