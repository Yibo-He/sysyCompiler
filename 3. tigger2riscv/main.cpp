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

int main(int argc, char *argv[]) {
  // read file from command line argument
  if (argc < 2) {
    cerr << "usage: " << argv[0] << " -S <INPUT> -o <OUTPUT> " << endl;
    return 1;
  }

  char opt;
  char *sysy_file_path = nullptr;
	char *output_file_path = nullptr;
  while( (opt = getopt(argc, argv, "S:o:")) != -1 ){
		if(opt == 'S') sysy_file_path = optarg;
		if(opt == 'o') output_file_path = optarg;
	}

  FILE* input = fopen(sysy_file_path, "r");
  if(input == nullptr){
    cerr<<"Error, no input file!"<<endl;
    cerr << "usage: " << argv[0] << " -S <INPUT> -o <OUTPUT> " << endl;
    return 1;
  } 
  FILE* output = fopen(output_file_path, "w");
  if(output == nullptr){
    cerr<<"Error, no output file!"<<endl;
    cerr << "usage: " << argv[0] << " -S <INPUT> -o <OUTPUT> " << endl;
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

