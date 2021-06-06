%{
    #include <string>
    #include <list>
    #include <stdlib.h>
    #include "ast_eeyore.hpp"
    extern FILE * yyin;
    extern FILE * yyout;
    extern int yylex();
    extern int yylineno;
    using namespace std;
    void yyerror(BaseEeyoreAST**, const char *){};
%}

%union{
    Token* token;
    BaseEeyoreAST* ast;
}

%parse-param {BaseEeyoreAST* *root}

%token <token> FUNCTION OP NUM LABEL Assign 
%token <token> VAR PARAM SYMBOL
%token <token> END IF GOTO CALL RETURN
%token <token> LZKH RZKH MaoHao

%type <ast> Program Declaration Initialization FunctionDef 
%type <ast> FunctionHeader Statements FunctionEnd 
%type <ast> Expression RightValue

%%

Program         : Program Declaration
                    {
                        ProgramAST *ptr = dynamic_cast<ProgramAST *>($1);
                        ptr->globalDecl.push_back($2);
                        $$ = ptr;
                    }
                | Program Initialization 
                    {
                        ProgramAST *ptr = dynamic_cast<ProgramAST *>($1);
                        ptr->globalInit.push_back($2);
                        $$ = ptr;
                    }
                | Program FunctionDef
                    {
                        ProgramAST *ptr = dynamic_cast<ProgramAST *>($1);
                        ptr->funDefs.push_back($2);
                        $$ = ptr;
                    }
                | Declaration 
                    {
                        ProgramAST* ptr = new ProgramAST;
                        ptr->globalDecl.push_back($1);
                        *root = ptr;
                        $$ = ptr;
                    }
                | Initialization 
                    {
                        ProgramAST* ptr = new ProgramAST;
                        ptr->globalInit.push_back($1);
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

Declaration     : VAR NUM SYMBOL
                {
                    $$ = new DeclAST($3->tokenString,$2->tokenString,$3->isTemp);
                }
                | VAR SYMBOL
                {
                    $$ = new DeclAST($2->tokenString,$2->isTemp);
                }
                ;

Initialization  : SYMBOL Assign NUM
                {
                    $$ = new InitAST($1->tokenString, string2num($3->tokenString));
                }
                | SYMBOL LZKH NUM RZKH Assign NUM
                {
                    $$ = new InitAST($1->tokenString, string2num($3->tokenString), string2num($6->tokenString));
                }
                ;

FunctionDef     : FunctionHeader Statements FunctionEnd
                    {
                        $$ = new FunDefAST($1,$2,$3);
                        dynamic_cast<FunDefAST* >($$)->head->funcName = dynamic_cast<FunDefAST* >($$);
                        dynamic_cast<FunDefAST* >($$)->StmtsASTptr->funcName = dynamic_cast<FunDefAST* >($$);
                        dynamic_cast<FunDefAST* >($$)->end->funcName = dynamic_cast<FunDefAST* >($$);
                        for(auto i : dynamic_cast<StmtsAST* >(dynamic_cast<FunDefAST* >($$)->StmtsASTptr)->stmts){
                            i->funcName = dynamic_cast<FunDefAST* >($$);
                        }
                    }
                ;

FunctionHeader  : FUNCTION LZKH NUM RZKH
                    {
                        $$ = new FunHeadAST($1->tokenString, string2num($3->tokenString));
                    }
                ;

Statements      : Statements Expression 
                    {
                        StmtsAST *ptr = dynamic_cast<StmtsAST*>($1);
                        ptr->stmts.push_back($2);
                        $$ = ptr;
                    }
                | Statements Declaration
                    {
                        StmtsAST *ptr = dynamic_cast<StmtsAST*>($1);
                        ptr->stmts.push_back($2);
                        $$ = ptr;
                    }
                | Expression 
                    {
                        StmtsAST* ptr = new StmtsAST;
                        ptr->stmts.push_back($1);
                        $$ = ptr;
                    }
                | Declaration
                    {
                        StmtsAST* ptr = new StmtsAST;
                        ptr->stmts.push_back($1);
                        $$ = ptr;
                    }
                ;

FunctionEnd     : END FUNCTION
                    {
                        $$ = new FunEndAST($2->tokenString);
                    }
                ;

Expression      : SYMBOL Assign RightValue OP RightValue
                    {
                        $$ = new BinaryAST($1->tokenString, dynamic_cast<RightValueAST*>($3), \
                        $4->tokenString, dynamic_cast<RightValueAST*>($5));
                    }
                | SYMBOL Assign OP RightValue
                    {
                        $$ = new UnaryAST($1->tokenString, $3->tokenString, dynamic_cast<RightValueAST*>($4));
                    }
                | SYMBOL Assign RightValue
                    {
                        $$ = new AssignAST($1->tokenString, dynamic_cast<RightValueAST*>($3), 1);
                    }
                | SYMBOL LZKH RightValue RZKH Assign RightValue
                    {
                        $$ = new AssignAST($1->tokenString, dynamic_cast<RightValueAST*>($3), dynamic_cast<RightValueAST*>($6), 2);
                    }
                | SYMBOL Assign SYMBOL LZKH RightValue RZKH
                    {
                        $$ = new AssignAST($1->tokenString, $3->tokenString, dynamic_cast<RightValueAST*>($5), 3);
                    }
                | IF RightValue OP RightValue GOTO LABEL
                    {
                        $$ = new IfAST(dynamic_cast<RightValueAST*>($2), $3->tokenString, dynamic_cast<RightValueAST*>($4), $6->tokenString);
                    }
                | GOTO LABEL
                    {
                        $$ = new GotoAST($2->tokenString);
                    }
                | LABEL MaoHao
                    {
                        $$ = new LabelAST($1->tokenString);
                    }
                | PARAM RightValue
                    {
                        $$ = new ParamAST(dynamic_cast<RightValueAST*>($2));
                    }
                | CALL FUNCTION
                    {
                        $$ = new CallAST($2->tokenString);
                    }
                | SYMBOL Assign CALL FUNCTION
                    {
                        $$ = new CallAST($1->tokenString, $4->tokenString);
                    }
                | RETURN RightValue
                    {
                        $$ = new RetAST(dynamic_cast<RightValueAST*>($2), false);
                    }
                | RETURN
                    {
                        $$ = new RetAST(nullptr, true);
                    }
                ;

RightValue      : SYMBOL 
                    {
                        $$ = new RightValueAST($1->tokenString,false);
                    }
                | NUM
                    {
                        $$ = new RightValueAST($1->tokenString,true);
                    }
                ;


%%

/*int main(){
    yyparse();
    return 0;
}*/