%{
    #include <string>
    #include <list>
    #include <stdlib.h>
    #include "ast_tigger.hpp"
    extern FILE * yyin;
    extern FILE * yyout;
    extern int yylex();
    extern int yylineno;
    using namespace std;
    void yyerror(BaseTiggerAST**, const char *){};
%}

%union{
    Token* token;
    BaseTiggerAST* ast;
}

%parse-param {BaseTiggerAST* *root}

%token <token> VARIABLE Reg FUNCTION BinOp NUM LABEL Assign 
%token <token> END MALLOC IF GOTO CALL RETURN STORE LOAD LOADADDR
%token <token> '(' ')' '[' ']' '{' '}' LZKH RZKH MaoHao

%type <ast> Program GlobalVarDecl FunctionDef FunctionHeader Expressions FunctionEnd Expression

%%

Program         : Program GlobalVarDecl
                    {
                        ProgramAST *ptr = dynamic_cast<ProgramAST *>($1);
                        ptr->varDecls.push_back($2);
                        $$ = ptr;
                    }
                | Program FunctionDef
                    {
                        //ProgramAST *ptr = $1;
                        ProgramAST *ptr = dynamic_cast<ProgramAST *>($1);
                        ptr->funDefs.push_back($2);
                        $$ = ptr;
                    }
                | GlobalVarDecl
                    {   
                        ProgramAST* ptr = new ProgramAST;
                        ptr->varDecls.push_back($1);
                        *root = ptr;
                        $$ = ptr; 
                    }
                | FunctionDef 
                    {   
                        ProgramAST* ptr = new ProgramAST;
                        ptr->funDefs.push_back($1);
                        *root = ptr;
                        $$ = ptr;
                    }
                ;

GlobalVarDecl   : VARIABLE Assign NUM
                    {
                        string tmp = $1->name;
                        $$ = new GlobalVarDeclAST(tmp, string2num($3->name), false);
                    }
                | VARIABLE Assign MALLOC NUM
                    {
                        string tmp = $1->name;
                        $$ = new GlobalVarDeclAST(tmp, string2num($4->name), true);
                    }
                ;

FunctionDef     : FunctionHeader Expressions FunctionEnd    
                    {
                        $$ = new FunctionDefAST($1, $2, $3);
                        dynamic_cast<FunctionHeaderAST *>($1)->funDef = $$;
                    }
                ;

FunctionHeader  : FUNCTION LZKH NUM RZKH LZKH NUM RZKH
                    {
                        string tmp = $1->name;
                        $$ = new FunctionHeaderAST(tmp, string2num($3->name), string2num($6->name));
                    }
                ;

Expressions     : Expressions Expression
                    {
                        //ExpressionsAST *ptr = $1;
                        ExpressionsAST *ptr = dynamic_cast<ExpressionsAST *>($1);
                        ptr->exp.push_back($2);
                        $$ = ptr;
                    }
                | Expression
                    { 
                        ExpressionsAST *ptr = new ExpressionsAST;
                        ptr->exp.push_back($1);
                        $$ = ptr;
                    }
                ;

FunctionEnd     : END FUNCTION
                    {
                        string tmp = $2->name;
                        $$ = new FunctionEndAST(tmp);
                    }
                ;

Expression      : Reg Assign Reg BinOp Reg
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int op = op2int($4->name);
                        switch(op){
                            case(Plus):
                                //reg1 = reg2 + reg3
                                tmp ="	add "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Minus):
                                //reg1 = reg2 - reg3
                                tmp ="	sub "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Multi):
                                //reg1 = reg2 * reg3
                                tmp ="	mul "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Divi):
                                //reg1 = reg2 / reg3
                                tmp ="	div "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Mod):
                                //reg1 = reg2 % reg3
                                tmp ="	rem "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(More):
                                //reg1 = reg2 > reg3
                                tmp ="	sgt "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Less):
                                //reg1 = reg2 < reg3
                                tmp ="	slt "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(LorEq):
                                //reg1 = reg2 <= reg3
                                tmp ="	sgt "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	seqz "+ $1->name+", "+$1->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(MorEq):
                                //reg1 = reg2 >= reg3
                                tmp ="	slt "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	seqz "+ $1->name+", "+$1->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(And):
                                //reg1 = reg2 && reg3
                                tmp ="	snez "+$1->name+", "+$3->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	snez s0, "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	and "+$1->name+", "+$1->name+", s0";
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Or):
                                //reg1 = reg2 || reg3
                                tmp ="	or "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	snez "+ $1->name+", "+$1->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Neq):
                                //reg1 = reg2 != reg3
                                tmp ="	xor "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	snez "+ $1->name+", "+$1->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Eq):
                                //reg1 = reg2 == reg3
                                tmp ="	xor "+$1->name+", "+$3->name+", "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	seqz "+ $1->name+", "+$1->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            default:
                                $$->riscvAction.push_back("Error: Reg = Reg BinOp Reg");
                                break;
                        }                          
                    }

                | Reg Assign Reg BinOp NUM
                    {
                        $$ = new ExpressionAST;
                        int number = string2num($5->name.c_str());
                        string tmp;
                        int op = op2int($4->name);
                        switch(op){
                            case Plus:
                                if(number<=2047 && number>-2048){
                                    tmp ="	addi "+$1->name+", "+$3->name+", "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                }else{
                                    tmp ="	li s0, "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	add "+$1->name+", "+$3->name+", s0";
                                    $$->riscvAction.push_back(tmp);
                                }
                                break;
                            case Less:
                                if(number<=2047 && number>-2048){
                                    tmp ="	slti "+$1->name+", "+$3->name+", "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                }else{
                                    tmp ="	li s0, "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	slt "+$1->name+", "+$3->name+", s0";
                                    $$->riscvAction.push_back(tmp);
                                }
                                break;
                            case Minus:
                                if(number<=2047 && number>-2048){
                                    tmp ="	addi "+$1->name+", "+$3->name+", "+num2string(0-number);
                                    $$->riscvAction.push_back(tmp);
                                }else{
                                    tmp ="	li s0, "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	sub "+$1->name+", "+$3->name+", s0";
                                    $$->riscvAction.push_back(tmp);
                                }
                                break;
                            case Multi:
                                //reg1 = reg2 * int
                                tmp ="	li s0, "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	mul "+$1->name+", "+$3->name+", s0";
                                $$->riscvAction.push_back(tmp);
                                break;
                            case Divi:
                                //reg1 = reg2 / int
                                tmp ="	li s0, "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	div "+$1->name+", "+$3->name+", s0";
                                $$->riscvAction.push_back(tmp);
                                break;
                            case Mod:
                                //reg1 = reg2 % int
                                tmp ="	li s0, "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	rem "+$1->name+", "+$3->name+", s0";
                                $$->riscvAction.push_back(tmp);
                                break;
                            case And:
                                //reg1 = reg2 && int
                                tmp ="	li s0, "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	snez "+$1->name+", "+$3->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	snez s0, s0";
                                $$->riscvAction.push_back(tmp);
                                tmp ="	and "+$1->name+", "+$1->name+", s0";
                                $$->riscvAction.push_back(tmp);
                                break;
                            case Or:
                                //reg1 = reg2 || int
                                if(number<=2047 && number>-2048){
                                    tmp ="	ori "+$1->name+", "+$3->name+", "+ $5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	snez "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }else{
                                    tmp ="	li s0, "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	or "+$1->name+", "+$3->name+", s0";
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	snez "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }
                                break;
                            case More:
                                //reg1 = reg2 > int
                                tmp ="	li s0, "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	sgt "+$1->name+", "+$3->name+", s0";
                                $$->riscvAction.push_back(tmp);
                                break;
                            case LorEq:
                                //reg1 = reg2 <= int
                                tmp ="	li s0, "+$5->name;
                                $$->riscvAction.push_back(tmp);
                                tmp ="	sgt "+$1->name+", "+$3->name+", s0";
                                $$->riscvAction.push_back(tmp);
                                tmp ="	seqz "+ $1->name+", "+$1->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case MorEq:
                                //reg1 = reg2 >= int
                                if(number<=2047 && number>-2048){
                                    tmp ="	slti "+$1->name+", "+$3->name+", "+ $5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	seqz "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }else{
                                    tmp ="	li s0, "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	slt "+$1->name+", "+$3->name+", s0";
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	seqz "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }
                                break;
                            case Eq:
                                //reg1 = reg2 == int
                                if(number<=2047 && number>-2048){
                                    tmp ="	xori "+$1->name+", "+$3->name+", "+ $5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	seqz "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }else{
                                    tmp ="	li s0, "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	xor "+$1->name+", "+$3->name+", s0";
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	seqz "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }
                                break;
                            case Neq:
                                //reg1 = reg2 != int
                                if(number<=2047 && number>-2048){
                                    tmp ="	xori "+$1->name+", "+$3->name+", "+ $5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	snez "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }else{
                                    tmp ="	li s0, "+$5->name;
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	xor "+$1->name+", "+$3->name+", s0";
                                    $$->riscvAction.push_back(tmp);
                                    tmp ="	snez "+ $1->name+", "+$1->name;
                                    $$->riscvAction.push_back(tmp);
                                }
                                break;
                            default:
                                $$->riscvAction.push_back("Error: Reg = Reg BinOp NUM");
                                break;
                        }
                    }
                | Reg Assign BinOp Reg
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int op = op2int($3->name);
                        switch(op){
                            case(Plus):
                                //reg1 = +reg2
                                tmp ="	mv " + $1->name + ", " + $4->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Minus):
                                //reg1 = -reg2
                                tmp ="	neg "+$1->name+ ", "+$4->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Not):
                                //reg1 = !reg2
                                tmp ="	seqz "+$1->name+ ", "+$4->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            default:
                                break;
                        }
                    }
                | Reg Assign Reg
                    {
                        string tmp ="	mv " + $1->name + ", " + $3->name;
                        $$ = new ExpressionAST;
                        $$->riscvAction.push_back(tmp);
                    }
                | Reg Assign NUM
                    {
                        string tmp ="	li " + $1->name + ", " + $3->name;
                        $$ = new ExpressionAST;
                        $$->riscvAction.push_back(tmp);
                    }
                
                | Reg LZKH NUM RZKH Assign Reg
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int number = string2num($3->name.c_str());
                        if(number<=2047 && number>=-2048){
                            tmp ="	sw "+$6->name+", "+$3->name+"("+$1->name+")";
                            $$->riscvAction.push_back(tmp);
                        } else {
                            tmp ="	li s0, " + $3->name;
                            $$->riscvAction.push_back(tmp);
                            tmp ="	add s0, sp, s0";
                            $$->riscvAction.push_back(tmp);
                            tmp ="	sw "+$6->name+", 0(s0)";
                            $$->riscvAction.push_back(tmp);
                        }
                    }
                | Reg Assign Reg LZKH NUM RZKH
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int number = string2num($5->name.c_str());
                        if(number<=2047 && number>=-2048){
                            tmp ="	lw "+$1->name+", "+$5->name+"("+$3->name+")";
                            $$->riscvAction.push_back(tmp);
                        } else {
                            tmp ="	li s0, " + $5->name;
                            $$->riscvAction.push_back(tmp);
                            tmp ="	add s0, sp, s0";
                            $$->riscvAction.push_back(tmp);
                            tmp ="	lw "+$1->name+", 0(s0)";
                            $$->riscvAction.push_back(tmp);
                        }
                    }
                | IF Reg BinOp Reg GOTO LABEL
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int op = op2int($3->name);
                        switch(op){
                            case(Less):
                                tmp ="	blt "+$2->name+", "+$4->name+", ."+$6->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(More):
                                tmp ="	bgt "+$2->name+", "+$4->name+", ."+$6->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(LorEq):
                                tmp ="	ble "+$2->name+", "+$4->name+", ."+$6->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(MorEq):
                                tmp ="	bge "+$2->name+", "+$4->name+", ."+$6->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Neq):
                                tmp ="	bne "+$2->name+", "+$4->name+", ."+$6->name;
                                $$->riscvAction.push_back(tmp);
                                break;
                            case(Eq):
                                tmp ="	beq "+$2->name+", "+$4->name+", ."+$6->name;
                                $$->riscvAction.push_back(tmp);
                                break;    
                            default:
                                $$->riscvAction.push_back("Error: IF Reg BinOp Reg GOTO LABEL");
                                break;
                        }                          
                    }
                | GOTO LABEL
                    {
                        $$ = new ExpressionAST;
                        string tmp ="	j ."+$2->name;
                        $$->riscvAction.push_back(tmp);
                    }
                | LABEL MaoHao
                    {
                        $$ = new ExpressionAST;
                        string tmp ="."+$1->name+":";
                        $$->riscvAction.push_back(tmp);
                    }
                | CALL FUNCTION
                    {
                        $$ = new ExpressionAST;
                        string tmp ="	call "+$2->name;
                        $$->riscvAction.push_back(tmp);
                    }
                | RETURN
                    {
                        $$ = new ExpressionAST;
                        string tmp;
                        tmp = "ret";
                        $$->riscvAction.push_back(tmp);
                    }
                | STORE Reg NUM
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int number = string2num($3->name.c_str());
                        if(number<=511 && number>=-512){
                            tmp ="	sw "+$2->name+", "+num2string(number*4)+"(sp)";
                            $$->riscvAction.push_back(tmp);
                        }else{
                            tmp ="	li s0, " + num2string(number*4);
                            $$->riscvAction.push_back(tmp);
                            tmp ="	add s0, sp, s0";
                            $$->riscvAction.push_back(tmp);
                            tmp ="	sw "+$2->name+",0(s0)";
                            $$->riscvAction.push_back(tmp);
                        }
                    }
                | LOAD NUM Reg
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int number = string2num($2->name.c_str());
                        if(number<=511 && number>=-512){
                            tmp ="	lw "+$3->name+", "+num2string(number*4)+"(sp)";
                            $$->riscvAction.push_back(tmp);
                        }else{
                            tmp ="	li s0, " + num2string(number*4);
                            $$->riscvAction.push_back(tmp);
                            tmp ="	add s0, sp, s0";
                            $$->riscvAction.push_back(tmp);
                            tmp ="	lw "+$3->name+",0(s0)";
                            $$->riscvAction.push_back(tmp);
                        }
                    }
                | LOAD VARIABLE Reg
                    {
                        $$ = new ExpressionAST;
                        string tmp;
                        tmp ="	lui "+$3->name+", %hi("+$2->name+")";
                        $$->riscvAction.push_back(tmp);
                        tmp.clear();
                        tmp ="	lw " +$3->name+ ", %lo(";
                        tmp = tmp + $2->name + ")(";
                        tmp = tmp + $3->name + ")";
                        //todo
                        //tmp ="	lw " +$3->name+ ", %lo"+"(" +$2->name+ ")"+"(" $3->name ")";
                        $$->riscvAction.push_back(tmp);
                    }
                | LOADADDR NUM Reg
                    {
                        string tmp;
                        $$ = new ExpressionAST;
                        int number = string2num($2->name.c_str());
                        if(number<=511 && number>=-512){
                            tmp ="	addi "+$3->name+", sp, "+num2string(number*4);
                            $$->riscvAction.push_back(tmp);
                        }else{
                            tmp ="	li s0, " + num2string(number*4);
                            $$->riscvAction.push_back(tmp);
                            tmp ="	add "+ $3->name +", s0, sp";
                            $$->riscvAction.push_back(tmp);
                        }
                    }
                | LOADADDR VARIABLE Reg
                    {
                        $$ = new ExpressionAST;
                        string tmp;
                        tmp ="	la "+$3->name+", "+$2->name;
                        $$->riscvAction.push_back(tmp);
                    }
                ;

%%

/*int main(){
    yyparse();
    return 0;
}*/