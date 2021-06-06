#include <iostream>
#include <fstream>
#include <unistd.h>

extern void Compile_sysy2eeyore(FILE*, FILE*);
extern void Compile_eeyore2tigger(FILE*, FILE*);
extern void Compile_tigger2riscv(FILE*, FILE* , char*);

using namespace std;

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
    if(sysy_file_path==nullptr){
        cerr<<"Error, no input file!"<<endl;
        cerr << "usage: " << argv[0] << " -S <INPUT> -o <OUTPUT> " << endl;
        return 1;
    }
    if(output_file_path==nullptr){
        cerr<<"Error, no output file!"<<endl;
        cerr << "usage: " << argv[0] << " -S <INPUT> -o <OUTPUT> " << endl;
        return 1;
    }
    
    FILE* fun1in = fopen(sysy_file_path,"r"); FILE* fun1out = fopen("ir1.eeyore","w");
    FILE* fun2in = fopen("ir1.eeyore","r"); FILE* fun2out = fopen("ir2.tigger","w");
    FILE* fun3in = fopen("ir2.tigger","r"); FILE* fun3out = fopen(output_file_path,"w");

    //cout重定向
    streambuf* coutBuf = cout.rdbuf();
    ofstream of(output_file_path);
    streambuf* fileBuf = of.rdbuf();
    cout.rdbuf(fileBuf);

    Compile_sysy2eeyore(fun1in, fun1out);
    Compile_eeyore2tigger(fun2in, fun2out);
    Compile_tigger2riscv(fun3in, fun3out, output_file_path);
    
    //恢复cout重定向
    cout.rdbuf(coutBuf);
    return 0;
}