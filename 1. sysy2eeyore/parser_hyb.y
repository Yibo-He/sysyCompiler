%{
    #include "global.hpp"
    #include "ast.hpp"
    #include "irgen.hpp"
    #include "symtab.hpp"
    extern FILE * yyin;
    extern FILE * yyout;
    extern int yylex();
    extern int yylineno;
    using namespace std;
    void yyerror(BaseAST**, const char *){};
%}

%union{
    Token* token;
    BaseAST* ast;
}

%parse-param {BaseAST* *root}

%token <token> CONST INT VOID IF ELSE WHILE BREAK CONTINUE RETURN ID
%token <token> AND OR EQ GorEQ LorEQ NEQ PLUandA MINandA MULandA DIVandA
%token <token> '=' '>' '<' '+' '-' '*' '/' '%' '!'
%token <token> ASSIGN GREAT LESS PLUS MINUS MULTI DIVI MOD NOT
%token <token> '(' ')' '[' ']' '{' '}' ';' ','
%token <token> LXKH RXKH LZKH RZKH LDKH RDKH SEMI COMMA
%token <token> HEX_INT OCT_INT DIGIT_INT
%token <token> IDENT INT_CONST
%token <token> OTHER Minus_Not Minus_Not_Not

%type <token> UnaryOp
%type <ast> CompUnit ConstDef VarDef FuncFParam FuncDef Block Stmt 
%type <ast> Exp Cond LVal PrimaryExp UnaryExp MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp
%type <ast> Decl ConstDefArr ConstDecl VarDefArr VarDecl FuncFParams BlockItemArr ExpArr FuncRParams ConstArr
%type <ast> ConstInitValArr ConstInitVal InitValArr InitVal FuncDefHead BlockStart FuncDefproto WhileHead CompHead

%%

CompUnit        : CompUnit Decl
                    {
                        BlockAST *ptr = dynamic_cast<BlockAST *>($1);
                        ptr->insertItems(move(dynamic_cast<arrAST*>($2)->exps));
                        $$ = ptr;
                    }
                | CompUnit FuncDef
                    {
                        dynamic_cast<BlockAST *>($1)->insertItem($2);
                        $$ = $1;
                    }
                | CompUnit SEMI { $$ = $1; }
                | CompHead SEMI { $$ = new BlockAST; *root=$$; }
                | CompHead Decl
                    {
                        BlockAST* ptr = new BlockAST;
                        ptr->insertItems(move(dynamic_cast<arrAST*>($2)->exps));
                        *root = ptr;
		                $$ = ptr;
                    }
                | CompHead FuncDef
                    {
                        BlockAST* ptr = new BlockAST;
                        ptr->insertItem($2);
                        *root = ptr;
		                $$ = ptr;
                    }
                ;

CompHead        :   
                    {
                        /*添加库函数*/
                        Token* p; BaseEntry* q;

                        // starttime
                        p = new Token(IDENT,"starttime");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        // stoptime
                        p = new Token(IDENT,"stoptime");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        // getint
                        p = new Token(IDENT, "getint");
                        q = newFunEntry(false, p, nullptr);
                        insertEntry(q);
                        
                        // getch
                        p = new Token(IDENT, "getch");
                        q = newFunEntry(false, p, nullptr);
                        insertEntry(q);
                        
                        // getarray
                        p = new Token(IDENT,"getarray");
                        q = newFunEntry(false, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        Token* r = new Token(IDENT,"a");
                        BaseEntry* s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(0);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                        popSymtab();

                        // putint
                        p = new Token(IDENT,"putint");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        r = new Token(IDENT,"a");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                        popSymtab();

                        // putch
                        p = new Token(IDENT,"putch");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        r = new Token(IDENT,"a");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                        popSymtab();  

                        // putarray
                        p = new Token(IDENT,"putarray");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        r = new Token(IDENT,"a");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                 
                        r = new Token(IDENT,"b");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(0);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                  
                        popSymtab();
                    }
                    ;


Decl            : ConstDecl 
                | VarDecl
                ;

ConstDecl	    : CONST INT ConstDefArr SEMI
                    {
                        $$ = $3;
                    }
ConstDefArr	    : ConstDefArr COMMA ConstDef
                    {
                        arrAST* p = dynamic_cast<arrAST*>($1);
                        p->insertArrAst($3);
                        $$ = p;
                    }
                | ConstDef
                    {
                        arrAST* ptr = new arrAST;
                        ptr->insertArrAst($1);
                        $$ = ptr;
                    }
                ;

ConstDef	    : IDENT ConstArr ASSIGN ConstInitVal
                    {
                        vector<int> tmp = dynamic_cast<arrAST*>($2)->calExps();
                        tmp = getArrWidth(tmp);

                        map<int, BaseAST*> t = dynamic_cast<ListTree*>($4)->Flatten(tmp); // Move constructor

                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(true, $1, p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry *>(newsym)->setDims(move(tmp));
                        
                        /* Update DeclSYM */
                        p->sym = newsym;
                        p->mmap = move(t);
                        $$ = p;

                        /* eeyore: nativeVarNum */
                        string tmp2 = ("T");
                        tmp2 = tmp2 + num2string(nativeVarNum);
                        p->addr = tmp2;
                        nativeVarNum++;
                    }
                ;

ConstArr	    : ConstArr LZKH ConstExp RZKH
                    {
                        dynamic_cast<arrAST*>($1)->insertArrAst($3);
                        $$ = $1;
                    }
                | { $$=new arrAST; }
                ;

ConstInitVal	: ConstExp
                    {
                        $$ = new ListTree($1);
                    }
				| LDKH RDKH
                    {
                        $$ = new ListTree($1, $2);
                    }
				| LDKH ConstInitValArr RDKH
                    {
                        $$ = $2;
                    }
				;

ConstInitValArr	: ConstInitValArr COMMA ConstInitVal
                    {
                        dynamic_cast<ListTree*>($1)->insertSublist($3);
                        $$ = $1;
                    }
				| ConstInitVal
                    {
                        ListTree* tmp = new ListTree;
                        tmp->insertSublist($1);
                        $$ = tmp;
                    }
				;


VarDefArr	    : VarDefArr COMMA VarDef
                    {
                        arrAST* p = dynamic_cast<arrAST*>($1);
                        p->insertArrAst($3);
                        $$ = p;
                    }
			    | VarDef
                    {
                        arrAST* p = new arrAST;
                        p->insertArrAst($1);
                        $$ = p;                      
                    }
			    ;

VarDecl		    : INT VarDefArr SEMI
                    {
                        $$ = $2;
                    }
			    ;

VarDef		    : IDENT ConstArr
                    {
                        /* VarDef: DefineAST */
                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* array type */
                        vector<int> arrtype = dynamic_cast<arrAST*>($2)->calExps();
                        arrtype = getArrWidth(arrtype);
                    
                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(false, $1, p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry *>(newsym)->setDims(move(arrtype));

                        /* Update info */
                        p->sym = newsym;
                        $$ = p;

                        /* eeyore: nativeVarNum */
                        string tmp2 = ("T");
                        tmp2 = tmp2 + num2string(nativeVarNum);
                        p->addr = tmp2;
                        nativeVarNum++;
                    }
			    | IDENT ConstArr ASSIGN InitVal
                    {
                        /* type check */
                        vector<int> arrtype = dynamic_cast<arrAST*>($2)->calExps();
                        arrtype = getArrWidth(arrtype);

                        map<int, BaseAST*> t = dynamic_cast<ListTree*>($4)->Flatten(arrtype);

                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(false, $1, p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry *>(newsym)->setDims( move(arrtype));
                        
                        /* Update DefineAST */
                        p->sym = newsym;
                        p->mmap = move(t);
                        $$ = p;

                        string tmp2 = ("T");
                        tmp2 = tmp2 + num2string(nativeVarNum);
                        p->addr = tmp2;
                        nativeVarNum++;
                    }
			    ;

InitValArr      : InitValArr COMMA InitVal
                    {
                        dynamic_cast<ListTree*>($1)->insertSublist($3);
                        $$ = $1;
                    }
			    | InitVal
                    {
                        ListTree* p = new ListTree;
                        p->insertSublist($1); 
                        $$ = p;
                    }
			    ;

InitVal		    : Exp
                    {
                        $$ = new ListTree($1);
                    }
			    | LDKH RDKH
                    {
                        $$ = new ListTree($1, $2);
                    }
			    | LDKH InitValArr RDKH
                    {
                        $$ = $2;
                    }
			    ;             

FuncFParams	    : FuncFParams COMMA FuncFParam
                    {
                        /* FuncFParams: arrAST* */
                        dynamic_cast<arrAST* >($1)->insertArrAst($3);
                        $$ = $1;
                    }
			    | FuncFParam
                    {
                        /* FuncFParams: arrAST* */
                        arrAST* p = new arrAST;
                        p->insertArrAst($1);
                        $$ = p;
                    }
			    ;
FuncFParam	    : INT IDENT
                    {
                        /* FuncFParam: DefineAST */
                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new varSymEntry */
                        BaseEntry* newsym = newVarEntry(false, $2, p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry*>(newsym)->setDims(vector<int> (1,1));

                        /* Update DefineAST */
                        p->sym = newsym;
                        $$ = p;

                        /* eeyore: paraNum */
                        string tmp2 = ("p");
                        tmp2 = tmp2 + num2string(paraNum);
                        p->addr = tmp2;
                        paraNum++;
                    }
			    | INT IDENT LZKH RZKH ConstArr
                    {
                        /* FuncFParam: DefineAST */
                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(false, $2, p);
                        insertEntry(newsym);

                        vector<int> arrtype = dynamic_cast<arrAST* >($5)->calExps();

                        /* If ConstArr is empty, update positioning info */
                        arrtype = getArrWidth(arrtype);
                        arrtype.push_back(0); // pointer
                        dynamic_cast<varSymEntry* >(newsym)->setDims(move(arrtype));

                        p->sym = newsym;
                        $$ = p;

                        /* eeyore: paraNum */
                        string tmp2 = ("p");
                        tmp2 = tmp2 + num2string(paraNum);
                        p->addr = tmp2;
                        paraNum++;

                    }
			    ;
FuncDef		    : FuncDefproto LDKH BlockItemArr RDKH
                    {   
                        /* FuncDef: FunDefAST */
                        FunDefAST *p = dynamic_cast<FunDefAST *>($1);
                        p->body = $3;
                        $$ = $1;

                        /* Check main */
                        if(*(p->sym->strp) == "main"){
                            mainptr = p;
                        }

                        /* End of the scope */
                        popSymtab();

                        /* eeyore: reset paramno */
                        paraNum = 0;

                    }
			    ;
FuncDefproto	: FuncDefHead RXKH
                    {
                        $$ = $1;
                    }
				| FuncDefHead FuncFParams RXKH
                    {
                        /* FuncDefproto: FunDefAST */
                        FunDefAST *p = dynamic_cast<FunDefAST *>($1);
                        p->fParams = dynamic_cast<arrAST* >($2)->output(); // Move assignment

                        /* bind SYMs of fParams to FunDefAST */
                        for(auto i: p->fParams)
                            dynamic_cast<funSymEntry *>(p->sym)->fParams.push_back(dynamic_cast<DefineAST *>(i)->sym);
                        $$ = $1;

                    }
				;
FuncDefHead	    : INT IDENT LXKH
                    {
                        /* FuncDefHead: FunDefAST */
                        /* new FunDefAST */
                        FunDefAST *p = new FunDefAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newFunEntry(false, $2, p);
                        insertEntry(newsym);

                        /* Update FunDefAST */
                        p->sym = newsym;
                        $$ = p;

                        /* New scope for its formal parameters */
                        pushSymtab();
                        currentFun = p;
                        /* eeyore: reset paramno */
                        paraNum = 0;
                        /* eeyore: set func addr */
                        string tmp2 = ("f_");
                        tmp2 = tmp2 + *p->sym->strp;
                        p->addr = tmp2;
                    }
			    | VOID IDENT LXKH
                    {
                        /* FuncDefHead: FunDefAST */
                        /* new FunDefAST */
                        FunDefAST *p = new FunDefAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newFunEntry(true, $2, p);
                        insertEntry(newsym);

                        /* Update FunDefAST */
                        p->sym = newsym;
                        $$ = p;

                        /* New scope for its formal parameters */
                        pushSymtab();
                        currentFun = p;

                        /* eeyore: reset paramno */
                        paraNum = 0;
                        /* eeyore: set func addr */
                        string tmp2 = ("f_");
                        tmp2 = tmp2 + *p->sym->strp;
                        p->addr = tmp2;
                    }
			    ;

Block		    : LDKH BlockStart BlockItemArr RDKH
                    {
                        /* BlockItemArr: BlockAST */
                        popSymtab();
                        $$ = $3;
                    }
			    ;

BlockItemArr	: BlockItemArr Decl
                    {
                        /* BlockItemArr: BlockAST */
                        BlockAST *p = dynamic_cast<BlockAST *>($1);
                        p->insertItems(move(dynamic_cast<arrAST*>($2)->exps));
                        $$ = $1;
                    }
				| BlockItemArr Stmt
                    {
                        /* BlockItemArr: BlockAST */
                        BlockAST *p = dynamic_cast<BlockAST *>($1);
                        p->insertItem($2);
                        $$ = $1;
                    }
				|
                    {
                        /* BlockItemArr: BlockAST */
                        $$ = new BlockAST;
                    }
				;

BlockStart	    :
                    {
                        /* BlockStart: null */
                        pushSymtab();
                        $$ = nullptr;
                    }
			    ;

Stmt		    : SEMI
                    {
                        /* Stmt: polymorphism */
                        $$ = nullptr;
                    }
			    | LVal ASSIGN Exp SEMI
                    {
                        /* Stmt: AssignAST */
                        AssignAST *p = new AssignAST;
                        p->lval = $1;
                        p->exp = $3;
                        $$ = p;
                    }
			    | Exp SEMI
                    {
                        /* Stmt: polymorphism */
                        $$ = $1;
                    }
			    | Block
                    {
                        /* Stmt: BlockAST */
                        $$ = $1;
                    }
			    | IF LXKH Cond RXKH Stmt
                    {
                        /* Stmt: IfAST */
                        IfAST *p = new IfAST;                      
                        p->cond = $3;
                        p->stmt = $5;
                        $$ = p;
                    }
			    | IF LXKH Cond RXKH Stmt ELSE Stmt
                    {
                        /* Stmt: IfAST */
                        IfAST *p = new IfAST;
                        p->cond = $3;
                        p->stmt = $5;
                        p->elseStmt = $7;
                        $$ = p;
                    }
			    | WhileHead LXKH Cond RXKH Stmt
                    {
                        /* Stmt: WhileAST */
                        WhileAST *p = dynamic_cast<WhileAST *>($1);
                        p->cond = $3;
                        p->stmt = $5;
                        $$ = p;
                        popWhileStack();
                    }
			    | BREAK SEMI
                    {
                        /* Stmt: BreakAST */
                        if(isEmptyWhileStack()){
                            $$ = nullptr;
                        }
                        else{
                            BreakAST *p = new BreakAST;
                            $$ = p;
                        }
                    }
			    | CONTINUE SEMI
                    {
                        /* Stmt: ContinueAST */
                        /* No while to continue */
                        if(whileStack.empty()){
                            $$ = nullptr;
                        }
                        else{
                            ContinueAST *p = new ContinueAST;
                            $$ = p;
                        }

                    }
			    | RETURN SEMI
                    {
                        /* Stmt: ReturnAST */
                        ReturnAST *p = new ReturnAST;
                        /* Check ret value */
                        funSymEntry *q = dynamic_cast<funSymEntry *>(dynamic_cast<FunDefAST *>(p->nextCode)->sym);
                        if(!q->isVoid){
                            /* return 0 by default */
                            Token* r = new Token(INT_CONST, 0);
                            BinaryExpAST *s = new BinaryExpAST(r);
                            p->exp = s;
                        }
                        $$ = p;
                    }
			    | RETURN Exp SEMI
                    {
                        /* Stmt: ReturnAST */
                        ReturnAST *p = new ReturnAST;
                        /* Check ret value */
                        funSymEntry *q = dynamic_cast<funSymEntry *>(dynamic_cast<FunDefAST *>(p->nextCode)->sym);
                        if(q->isVoid){
                        }
                        else p->exp = $2;
                        $$ = p;
                    }
			    ;

WhileHead	    : WHILE
                    {
                        /* WhileHead: WhileAST */
                        WhileAST *p = new WhileAST;
                        $$ = p;
                        /* Update WhileStack */
                        pushWhileStack(p);
                    }
			    ;                

Exp			    : AddExp
                    {
                        $1->cal();
                        $$ = $1;
                    }
			    ;

Cond		    : LOrExp
                    {
                        $1->cal();
                        $$ = $1;
                    }
			    ;
ExpArr		    : ExpArr LZKH Exp RZKH
                    {
                        dynamic_cast<arrAST*>($1)->insertArrAst($3);
                        $$ = $1;
                    }
			    |
                    {
                        $$ = new arrAST;
                    }
			    ;

LVal		    : IDENT ExpArr
                    {
                        $$ = new LvalAST($1, $2);
                    }
			    ;

PrimaryExp	    : LXKH Exp RXKH
                    {
                        $$ = $2;
                    }
			    |	LVal
			    |	INT_CONST
                    {
                        $$ = new BinaryExpAST($1);
                    }
			    ;

FuncRParams	    : FuncRParams COMMA Exp
                    {
                        /* FuncRParams: arrAST */
                        dynamic_cast<arrAST *>($1)->insertArrAst($3);                     
                    }
			    | Exp
                    {
                        arrAST *p = new arrAST;
                        p->insertArrAst($1);
                        $$ = p;
                    }
			    ;
                
UnaryExp	    :	PrimaryExp
			    |	IDENT LXKH RXKH
                    {                      
                        FunCallAST *ptr = new FunCallAST($1);
                        $$ = ptr;
                        ptr->checkParaSize();
                    }
			    |	IDENT LXKH FuncRParams RXKH
                    {
                        FunCallAST *ptr = new FunCallAST($1);

                        ptr->rParams = dynamic_cast<arrAST* >($3)->output();
                        $$ = ptr;

                        /* Check the params list */
                        ptr->checkParaSize();

                    }
			    |	UnaryOp UnaryExp
                    {
                        /* Only when UnaryExp is a unaryexp should coalesce be called */
                        if($2->type == ASTtype::UnaryExp) {
                            dynamic_cast<UnaryExpAST *>($2)->dealOp($1);
                            $$ = $2;
                        }
                        /* Only when UnaryExp is not a unaryexp should constructor be called */
                        else $$ = new UnaryExpAST($2, $1);
                    }
			    ;

UnaryOp		    :	PLUS
                |	MINUS
                |	NOT
                ;
                
MulExp		    :	UnaryExp
			    |	MulExp MULTI UnaryExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    |	MulExp DIVI UnaryExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    |	MulExp MOD UnaryExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    ;

AddExp		    :	MulExp
			    |	AddExp PLUS MulExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    |	AddExp MINUS MulExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    ;
RelExp		    :	AddExp
			    |	RelExp LESS AddExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    |	RelExp GREAT AddExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    |	RelExp LorEQ AddExp
                    {   
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    |	RelExp GorEQ AddExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    ;

EqExp		    :	RelExp
			    |	EqExp EQ RelExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    |	EqExp NEQ RelExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    ;
LAndExp		    :	EqExp
			    |	LAndExp AND EqExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
			    ;
LOrExp		    :	LAndExp
			    |	LOrExp OR LAndExp
                    {
                        $$ = new BinaryExpAST($1, $3, $2);
                    }
		    	;
ConstExp	    :	AddExp
                    {
                        $1->cal();
                        $$ = $1;
                    }
			    ;

%%

/*int main(){
    yyparse();
    return 0;
}*/