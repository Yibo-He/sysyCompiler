/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_HYB1_TAB_HPP_INCLUDED
# define YY_YY_PARSER_HYB1_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int s2edebug;
#endif

/* Token1 type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONST = 258,
    INT = 259,
    VOID = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    BREAK = 264,
    CONTINUE = 265,
    RETURN = 266,
    ID = 267,
    AND = 268,
    OR = 269,
    EQ = 270,
    GorEQ = 271,
    LorEQ = 272,
    NEQ = 273,
    PLUandA = 274,
    MINandA = 275,
    MULandA = 276,
    DIVandA = 277,
    ASSIGN = 278,
    GREAT = 279,
    LESS = 280,
    PLUS = 281,
    MINUS = 282,
    MULTI = 283,
    DIVI = 284,
    MOD = 285,
    NOT = 286,
    LXKH = 287,
    RXKH = 288,
    LZKH = 289,
    RZKH = 290,
    LDKH = 291,
    RDKH = 292,
    SEMI = 293,
    COMMA = 294,
    HEX_INT = 295,
    OCT_INT = 296,
    DIGIT_INT = 297,
    IDENT = 298,
    INT_CONST = 299,
    OTHER = 300,
    Minus_Not = 301,
    Minus_Not_Not = 302
  };
#endif

/* Value type.  */
#if ! defined S2ESTYPE && ! defined YYSTYPE_IS_DECLARED
union S2ESTYPE
{
#line 14 "parser_hyb.y"

    Token1* token1;
    BaseAST* ast;

#line 110 "parser_hyb1.tab.hpp"

};
typedef union S2ESTYPE S2ESTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern S2ESTYPE s2elval;

int s2eparse (BaseAST* *root);

#endif /* !YY_YY_PARSER_HYB1_TAB_HPP_INCLUDED  */
