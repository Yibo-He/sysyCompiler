%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include <iostream>
    #include <sstream>
    #include "ast_tigger.hpp"
    #include "parser_hyb_3.tab.hpp"
    using namespace::std;
    extern "C" int input();

    inline void handleCommentLine(){
        for(auto i : string(yytext_ptr)) { if (i == '\n') yylineno++; }
    }

    //八进制转十进制
    int oct2dec(const char * oct_number){
        stringstream ss;
        int decimal_number;
        ss << oct_number; // std::string oct_value
        ss >> oct >> decimal_number ; //int decimal_value;
        return decimal_number;
    }

    //十六进制转十进制
    int hex2dec(const char * hex_number){
        stringstream ss;
        int decimal_number;
        ss << hex_number; // std::string hex_value
        ss >> hex >> decimal_number ; //int decimal_value;
        return decimal_number;
    }

%}
%option noyywrap
Space          " "|\t
Variable        v[0-9]+
Reg             "x0"|s[0-9]|"s10"|"s11"|t[0-6]|a[0-7]

letter_         [a-zA-Z_]
digit           [0-9]
digit_int       (-)?[0-9]+
Function        f_[a-zA-Z_][a-zA-Z_0-9]*

op              [\+\-\!\*\/\%\>\<]

label           l[0-9]+


%%
{Space}    {;}
"\n"    {if(Debug) printf("above yylineno = %d.\n",yylineno); yylineno++;}
"\r"    {if(Debug) printf("above yylineno = %d.\n",yylineno); yylineno++;}
\/\/.*\n?   {
    if(Debug) printf("there is a comment line.\n");
    handleCommentLine();
}

{Variable}  {
    yylval.token = new Token(variable, yytext);
    return VARIABLE;
}
{Reg}       {
    yylval.token = new Token(reg, yytext);
    return Reg;
}
{Function}  {
    char tmp[64] = "";
    strcpy(tmp, yytext+2);
    yylval.token = new Token(function, tmp);
    return FUNCTION;
}

{digit_int} {
    yylval.token = new Token(num,yytext);
    return NUM;
}
{label}     {
    yylval.token = new Token(label,yytext);
    return LABEL;
}

"&&"        {
    yylval.token = new Token(op, yytext);
    return BinOp;
}
"||"        {
    yylval.token = new Token(op, yytext);
    return BinOp;
}
">="        {
    yylval.token = new Token(op, yytext);
    return BinOp;
}
"<="        {
    yylval.token = new Token(op, yytext);
    return BinOp;
}
"=="        {
    yylval.token = new Token(op, yytext);
    return BinOp;
}

"!="        {
    yylval.token = new Token(op, yytext);
    return BinOp;
}

"end"   {
    return END;
}

"malloc" {
    return MALLOC;
}

"if"    {
    return IF;
}

"goto"  {
    return GOTO;
}

"call"  {
    return CALL;
}

"return"    {
    return RETURN;
}

"store" {
    return STORE;
}

"load"  {
    return LOAD;
}

"loadaddr"  {
    return LOADADDR;
}

{op}        {
    yylval.token = new Token(op, yytext);
    return BinOp;
}
"="     {
    yylval.token = new Token(op, yytext);
    return Assign;
}

"["     { return LZKH;}
"]"     { return RZKH;}
":"     { return MaoHao;}

.   {
    printf("Unknown token: %s\n", yytext);
}

%%