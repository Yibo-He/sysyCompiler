#include "ast_tigger.hpp"

int string2num(const string s){
    return atoi(s.c_str());
}
string num2string(int num){
    string ans = to_string(num);
    return ans;
}
int op2int(string op){
    if(!strcmp(op.c_str(),"+")) return Plus;
    if(!strcmp(op.c_str(),"-")) return Minus;
    if(!strcmp(op.c_str(),"*")) return Multi;
    if(!strcmp(op.c_str(),"/")) return Divi;
    if(!strcmp(op.c_str(),"%")) return Mod;
    if(!strcmp(op.c_str(),"!")) return Not;

    if(!strcmp(op.c_str(),">")) return More;
    if(!strcmp(op.c_str(),"<")) return Less;
    if(!strcmp(op.c_str(),">=")) return MorEq;
    if(!strcmp(op.c_str(),"<=")) return LorEq;

    if(!strcmp(op.c_str(),"&&")) return And;
    if(!strcmp(op.c_str(),"||")) return Or;
    if(!strcmp(op.c_str(),"!=")) return Neq;
    if(!strcmp(op.c_str(),"==")) return Eq;
    return -1;
}

void ProgramAST::generator(){
    for(auto i:varDecls) i->generator();
    riscvCode.push_back(" ");
    for(auto i:funDefs) i->generator();
    for(auto &i: riscvCode)
		cout << i << endl;
	cout << endl;
}
void GlobalVarDeclAST::generator(){
    if(isMalloc){
        riscvCode.push_back("  .comm     "+ varName +", "+ num +", 4");
    }else{
        riscvCode.push_back("  .global   " + varName);
        riscvCode.push_back("  .section  .sdata");
        riscvCode.push_back("  .align    2");
        riscvCode.push_back("  .type     " + varName + ", @object");
        riscvCode.push_back("  .size     " + varName + ", 4");
        riscvCode.push_back(varName + ":");
        riscvCode.push_back("  .word     " + num);
    }
}
void FunctionDefAST::generator(){
    funHead->generator();
    exps->generator();
    funEnd->generator();
}
void FunctionHeaderAST::generator(){
    riscvCode.push_back("  .text");
    riscvCode.push_back("  .align  2");
    riscvCode.push_back("  .global " + funName);
    riscvCode.push_back("  .type   " + funName + ", @function");
    riscvCode.push_back(funName + ":");
    int STK = (n2 / 4 + 1) * 16;
    vector<BaseTiggerAST*>::iterator itBegin = dynamic_cast<ExpressionsAST*>(dynamic_cast<FunctionDefAST*>(funDef)->exps)->exp.begin();
    vector<BaseTiggerAST*>::iterator itEnd = dynamic_cast<ExpressionsAST*>(dynamic_cast<FunctionDefAST*>(funDef)->exps)->exp.end();
    for(itBegin;itBegin!=itEnd;++itBegin){
        (*itBegin)->STK = STK;
    }
    if(STK<=2047 && STK>=-2048){
        riscvCode.push_back("  addi    sp, sp, -" + num2string(STK));
        riscvCode.push_back("  sw      ra, " + num2string(STK-4) + "(sp)");
    }else {
        riscvCode.push_back("  li    s0, " + num2string(STK));
        riscvCode.push_back("  sub    sp, sp, s0");
        riscvCode.push_back("  add    s0, s0, sp");
        riscvCode.push_back("  sw    ra, -4(s0)");
    }
}
void ExpressionsAST::generator(){
    for(auto i: exp){
        i->generator();
    }
}

void FunctionEndAST::generator(){
    riscvCode.push_back("  .size   " + funName + ", .-" + funName);
}
void ExpressionAST::generator(){
    list<string>::iterator it = riscvAction.begin();
    if(!strcmp(it->c_str(), "ret")){
        if(STK<=2047 && STK>=-2048){
            string tmp;
            tmp = "  lw ra, "+num2string(STK-4)+"(sp)";
            riscvCode.push_back(tmp);
            tmp = "  addi sp, sp, "+num2string(STK);
            riscvCode.push_back(tmp);
            tmp = "  ret";
            riscvCode.push_back(tmp);
        }else {
            riscvCode.push_back("  li    s0, " + num2string(STK));
            riscvCode.push_back("  add    s0, s0, sp");
            riscvCode.push_back("  lw    ra, -4(s0)");
            riscvCode.push_back("  li    s0, " + num2string(STK));
            riscvCode.push_back("  add    sp, sp, s0");
            riscvCode.push_back("  ret");
        }
    } else {
        riscvCode.splice(riscvCode.end(), riscvAction);
    }
}