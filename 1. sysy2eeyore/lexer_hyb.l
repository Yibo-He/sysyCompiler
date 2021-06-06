%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include <iostream>
    #include <sstream>
    #include "global.hpp"
    #include "parser_hyb.tab.hpp"
    using namespace::std;
    extern "C" int input();

    #ifndef Debug
    #define Debug 1
    #endif

    /*inline void handleComments(){
        int c1 = 0, c2 = input();
        for(;;){
            printf("c1=%x, c2=%x \n",c1,c2);
            if(c2 == EOF)
                break;
            if(c1 == '*' && c2 == '/')
                break;
            c1 = c2;
            c2 = input();
        }
    }*/

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
/*There six kinds of Token*/
/*1. comment, including comment line and comments*/
/*2. identifier*/
/*3. keyword; const,int,void,if,else,while,break,continue,return*/
/*4. operator*/
/*5. delimiter;*/
/*6. literal*/

%x COMMENT
comments_begin "/*"
comments_element .|\n
comments_end "*/"

comment_char    [^/*"]
comments        \/\*((comment_char|\/)*|\**"(comment_char|\/|\*)*"|\*+comment_char)*\**\*\/

letter_         [a-zA-Z_]
digit           [0-9]
id              letter_(letter_|digit)*
_space           " "|\t

_const          "const"
_int            "int"
_void           "void"
_if             "if"
_else           "else"
_while          "while"
_break          "break"
_continue       "continue"
_return         "return"

_and            "&&"
_or             "||"
_eq             "=="
_greatOReq      ">="
_lessOReq       "<="
_neq            "!="
_plusANDassign  "+="
_minusANDassign "-="
_multiANDassign "*="
_diviANDassign  "/="

_assign         "="
_great          ">"
_less           "<"
_plus           "+"
_minus          "-"
_multi          "*"
_divi           "/"
_mod            "%"
_not            "!"

_lxkh           "("
_rxkh           ")"
_lzkh           "["
_rzkh           "]"
_ldkh           "{"
_rdkh           "}"
_semi           ";"
_comma          ","

hex_int       (0[Xx][0-9a-fA-F]+)
oct_int       (0[0-7]*)
digit_int     ([1-9][0-9]*)

%%

{_space}    {;}
"\n"    {if(Debug) printf("above yylineno = %d.\n",yylineno); yylineno++;}
"\r"    {if(Debug) printf("above yylineno = %d.\n",yylineno); yylineno++;}

{comments_begin} {printf("Begin: there are some comments.\n");BEGIN COMMENT;}
<COMMENT>{comments_element} { handleCommentLine(); }
<COMMENT>{comments_end} {BEGIN INITIAL;printf("End: comments.\n");}

\/\/.*\n?   {
    if(Debug) printf("there is a comment line.\n");
    handleCommentLine();
}


{_const}    {
    if(Debug) printf("find keyword: %s\n",yytext);
    return CONST;
}
{_int}    {
    if(Debug) printf("find keyword: %s\n",yytext);
    return INT;
}
{_void}    {
    if(Debug) printf("find keyword: %s\n",yytext);
    return VOID;
}
{_if}    {
    if(Debug) printf("find keyword: %s\n",yytext);
    return IF;
}
{_else}   {
    if(Debug) printf("find keyword: %s\n",yytext);
    return ELSE;
}
{_while}    {
    if(Debug) printf("find keyword: %s\n",yytext);
    return WHILE;
}
{_break}   {
    if(Debug) printf("find keyword: %s\n",yytext);
    return BREAK;
}
{_continue}    {
    if(Debug) printf("find keyword: %s\n",yytext);
    return CONTINUE;
}
{_return}   {
    if(Debug) printf("find keyword: %s\n",yytext);
    return RETURN;
}



[a-zA-Z_][a-zA-Z0-9_]*    {
    if(Debug) printf("find identifier: %s\n",yytext);
    yylval.token = new Token(IDENT, yytext, yylineno);
    lineno = yylineno;
    return IDENT;
}



{_and}  {
    yylval.token = new Token(AND);
    if(Debug) printf("find operator: %s\n",yytext);
    return AND;
}
{_or}  {
    yylval.token = new Token(OR);
    if(Debug) printf("find operator: %s\n",yytext);
    return OR;
}
{_eq}  {
    yylval.token = new Token(EQ);
    if(Debug) printf("find operator: %s\n",yytext);
    return EQ;
}
{_greatOReq}  {
    yylval.token = new Token(GorEQ);
    if(Debug) printf("find operator: %s\n",yytext);
    return GorEQ;
}
{_lessOReq} {
    yylval.token = new Token(LorEQ);
    if(Debug) printf("find operator: %s\n",yytext);
    return LorEQ;
}
{_neq} {
    yylval.token = new Token(NEQ);
    if(Debug) printf("find operator: %s\n",yytext);
    return NEQ;
}
{_plusANDassign} {
    yylval.token = new Token(PLUandA);
    if(Debug) printf("find operator: %s\n",yytext);
    return PLUandA;
}
{_minusANDassign} {
    yylval.token = new Token(MINandA);
    if(Debug) printf("find operator: %s\n",yytext);
    return MINandA;
}
{_multiANDassign} {
    yylval.token = new Token(MULandA);
    if(Debug) printf("find operator: %s\n",yytext);
    return MULandA;
}
{_diviANDassign} {
    yylval.token = new Token(DIVandA);
    if(Debug) printf("find operator: %s\n",yytext);
    return DIVandA;
}
{_assign} {
    yylval.token = new Token(ASSIGN);
    if(Debug) printf("find operator: %s\n",yytext);
    return ASSIGN;
}
{_great} {
    yylval.token = new Token(GREAT);
    if(Debug) printf("find operator: %s\n",yytext);
    return GREAT;
}
{_less} {
    yylval.token = new Token(LESS);
    if(Debug) printf("find operator: %s\n",yytext);
    return LESS;
}
{_plus} {
    yylval.token = new Token(PLUS);
    if(Debug) printf("find operator: %s\n",yytext);
    return PLUS;
}
{_minus} {
    yylval.token = new Token(MINUS);
    if(Debug) printf("find operator: %s\n",yytext);
    return MINUS;
}
{_multi} {
    yylval.token = new Token(MULTI);
    if(Debug) printf("find operator: %s\n",yytext);
    return MULTI;
}
{_divi} {
    yylval.token = new Token(DIVI);
    if(Debug) printf("find operator: %s\n",yytext);
    return DIVI;
}
{_mod} {
    yylval.token = new Token(MOD);
    if(Debug) printf("find operator: %s\n",yytext);
    return MOD;
}
{_not} {
    yylval.token = new Token(NOT);
    if(Debug) printf("find operator: %s\n",yytext);
    return NOT;
}



{_lxkh} {
    if(Debug) printf("find operator: %s\n",yytext);
    return LXKH;
}
{_rxkh} {
    if(Debug) printf("find operator: %s\n",yytext);
    return RXKH;
}
{_lzkh} {
    if(Debug) printf("find operator: %s\n",yytext);
    return LZKH;
}
{_rzkh} {
    if(Debug) printf("find operator: %s\n",yytext);
    return RZKH;
}
{_ldkh} {
    if(Debug) printf("find operator: %s\n",yytext);
    return LDKH;
}
{_rdkh} {
    if(Debug) printf("find operator: %s\n",yytext);
    return RDKH;
}
{_semi} {
    if(Debug) printf("find operator: %s\n",yytext);
    return SEMI;
}
{_comma} {
    if(Debug) printf("find operator: %s\n",yytext);
    return COMMA;
}



{hex_int} {
    if(Debug) printf("find integer-const: %s\n",yytext);
    int digit_ = hex2dec(yytext);
    yylval.token = new Token(INT_CONST, digit_ );
    return INT_CONST;
}
{oct_int} {
    if(Debug) printf("find integer-const: %s\n",yytext);
    int digit_ = oct2dec(yytext);
    yylval.token = new Token(INT_CONST, digit_ );
    return INT_CONST;
}
{digit_int} {
    if(Debug) printf("find integer-const: %s\n",yytext);
    yylval.token = new Token(INT_CONST, atoi(yytext));
    return INT_CONST;
}

.   {
    printf("Unknown token: %s\n", yytext);
}
%%

