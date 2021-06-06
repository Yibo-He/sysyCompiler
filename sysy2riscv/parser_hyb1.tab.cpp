/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         S2ESTYPE
/* Substitute the variable and function names.  */
#define yyparse         s2eparse
#define yylex           s2elex
#define yyerror         s2eerror
#define yydebug         s2edebug
#define yynerrs         s2enerrs
#define yylval          s2elval
#define yychar          s2echar


/* First part of user prologue.  */
#line 1 "parser_hyb.y"

    #include "global.hpp"
    #include "ast.hpp"
    #include "irgen.hpp"
    #include "symtab.hpp"
    extern FILE * s2ein;
    extern FILE * s2eout;
    extern int yylex();
    extern int yylineno;
    using namespace std;
    void yyerror(BaseAST**, const char *){};

#line 83 "parser_hyb1.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HYB1_TAB_HPP_INCLUDED
# define YY_YY_PARSER_HYB1_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser_hyb.y"

    Token1* token1;
    BaseAST* ast;

#line 188 "parser_hyb1.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (BaseAST* *root);

#endif /* !YY_YY_PARSER_HYB1_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,    30,     2,     2,
      41,    42,    28,    26,    48,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      25,    23,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    45,    50,    51,    52,    59,    69,   157,
     158,   161,   165,   171,   179,   207,   212,   215,   219,   223,
     229,   234,   243,   249,   257,   263,   288,   316,   321,   329,
     333,   337,   343,   349,   357,   378,   406,   426,   430,   443,
     467,   494,   502,   509,   517,   524,   531,   536,   544,   549,
     554,   562,   571,   580,   591,   604,   618,   631,   641,   648,
     654,   660,   665,   671,   675,   676,   682,   687,   695,   696,
     702,   713,   725,   726,   727,   730,   731,   735,   739,   745,
     746,   750,   755,   756,   760,   764,   768,   774,   775,   779,
     784,   785,   790,   791,   796
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "INT", "VOID", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "RETURN", "ID", "AND", "OR", "EQ", "GorEQ",
  "LorEQ", "NEQ", "PLUandA", "MINandA", "MULandA", "DIVandA", "'='", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "ASSIGN", "GREAT",
  "LESS", "PLUS", "MINUS", "MULTI", "DIVI", "MOD", "NOT", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "';'", "','", "LXKH", "RXKH", "LZKH", "RZKH",
  "LDKH", "RDKH", "SEMI", "COMMA", "HEX_INT", "OCT_INT", "DIGIT_INT",
  "IDENT", "INT_CONST", "OTHER", "Minus_Not", "Minus_Not_Not", "$accept",
  "CompUnit", "CompHead", "Decl", "ConstDecl", "ConstDefArr", "ConstDef",
  "ConstArr", "ConstInitVal", "ConstInitValArr", "VarDefArr", "VarDecl",
  "VarDef", "InitValArr", "InitVal", "FuncFParams", "FuncFParam",
  "FuncDef", "FuncDefproto", "FuncDefHead", "Block", "BlockItemArr",
  "BlockStart", "Stmt", "WhileHead", "Exp", "Cond", "ExpArr", "LVal",
  "PrimaryExp", "FuncRParams", "UnaryExp", "UnaryOp", "MulExp", "AddExp",
  "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token1 number corresponding to the
   (internal) symbol number NUM (which must be that of a token1).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    61,    62,    60,    43,    45,    42,    47,
      37,    33,   278,   279,   280,   281,   282,   283,   284,   285,
     286,    40,    41,    91,    93,   123,   125,    59,    44,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -122,     3,     7,  -122,     1,   -30,   -28,  -122,  -122,  -122,
    -122,  -122,   -17,    20,  -122,  -122,  -122,   -21,    12,    -6,
    -122,    14,  -122,   -15,  -122,   -27,  -122,  -122,    39,  -122,
    -122,   -18,  -122,     8,  -122,    79,     5,  -122,    71,   -16,
    -122,   -21,   143,   181,  -122,  -122,     8,    31,  -122,    45,
      74,   151,  -122,  -122,  -122,   181,  -122,  -122,  -122,    43,
    -122,  -122,  -122,  -122,    64,    76,    -7,  -122,  -122,   181,
      40,    62,    85,  -122,   173,  -122,   111,  -122,  -122,  -122,
      62,    86,   181,  -122,  -122,  -122,    87,    91,  -122,   179,
      92,   181,  -122,   181,  -122,   181,   181,   181,   181,   181,
    -122,   141,  -122,  -122,  -122,    30,  -122,  -122,    94,    62,
      21,    58,   132,   134,  -122,  -122,   114,  -122,  -122,   -22,
     181,   102,    98,  -122,  -122,  -122,    40,    40,   104,  -122,
    -122,    37,  -122,   143,    11,   181,   181,   181,   181,   181,
     181,   181,   181,  -122,  -122,   181,   105,    11,  -122,  -122,
     173,  -122,   149,    62,    62,    62,    62,    21,    21,    58,
     132,  -122,  -122,  -122,  -122,    11,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       8,     0,     0,     1,     0,     0,     0,     4,     2,     9,
      10,     3,     0,     0,     5,     6,     7,     0,    16,     0,
      23,     0,    44,     0,    37,     0,    33,    16,     0,    13,
      39,    25,    24,     0,    40,     0,    34,    38,     0,     0,
      11,     0,     0,     0,    16,    22,     0,     0,    57,     0,
       0,     0,    72,    73,    74,     0,    45,    36,    46,    61,
      65,    42,    49,    43,     0,     0,    64,    68,    75,     0,
      79,    58,     0,    32,     0,    12,     0,    26,    29,    64,
      94,     0,     0,    53,    54,    55,     0,     0,    44,     0,
      62,     0,    48,     0,    71,     0,     0,     0,     0,     0,
      16,     0,    14,    17,    30,     0,    28,    15,     0,    82,
      87,    90,    92,    59,    56,    63,     0,    69,    67,     0,
       0,     0,     0,    76,    77,    78,    80,    81,    35,    18,
      21,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    70,     0,     0,     0,    47,    19,
       0,    27,    50,    86,    85,    84,    83,    88,    89,    91,
      93,    66,    60,    52,    20,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,   109,  -122,  -122,   117,   -26,   -97,  -122,
    -122,  -122,   126,  -122,   -74,  -122,   123,   160,  -122,  -122,
    -122,    78,  -122,  -121,  -122,   -24,    82,  -122,   -35,  -122,
    -122,   -54,  -122,    28,   -34,    -4,    29,    38,  -122,   139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    61,     9,    28,    29,    31,   102,   131,
      19,    10,    20,   105,    77,    25,    26,    11,    12,    13,
      62,    35,    88,    63,    64,    65,   108,    90,    79,    67,
     119,    68,    69,    70,    71,   110,   111,   112,   113,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token1.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    39,   106,     3,   130,    17,     4,     5,     6,    80,
       4,     5,     6,   152,    42,    94,    74,    47,    78,    48,
      49,    50,    51,    37,    23,    93,   163,    86,   144,    38,
      18,    87,    21,    43,   145,    43,    22,   135,   136,    27,
      80,   123,   124,   125,   166,    36,    52,    53,   109,    32,
      33,    54,    78,   164,   137,   138,    72,   109,     7,   151,
      55,    30,    14,    34,    56,   118,    58,    80,    44,   122,
      24,    59,    60,   139,   128,    23,   140,    95,    96,    97,
      82,    66,     4,    46,   132,    47,   133,    48,    49,    50,
      51,   149,    89,   150,    40,    41,   146,    98,    99,    66,
      83,   153,   154,   155,   156,   109,   109,   109,   109,    78,
       8,    15,    66,    91,    52,    53,    80,     4,    46,    54,
      47,   161,    48,    49,    50,    51,   126,   127,    55,    84,
      66,    92,    56,    57,    58,   157,   158,   100,   107,    59,
      60,   115,   114,   120,   134,   141,    52,    53,   142,    52,
      53,    54,   147,   148,    54,    43,   165,   162,    75,    45,
      55,    73,    16,    55,    76,   104,   116,    56,   143,    58,
     159,    59,    60,   121,    59,    60,    52,    53,    52,    53,
     160,    54,    81,    54,     0,     0,    52,    53,     0,     0,
      55,    54,    55,     0,   101,   129,    76,     0,     0,     0,
      55,    59,    60,    59,    60,     0,    85,     0,    52,    53,
       0,    59,    60,    54,    52,    53,    52,    53,     0,    54,
       0,    54,    55,     0,     0,     0,   101,     0,    55,   117,
      55,     0,     0,    59,    60,     0,     0,     0,     0,    59,
      60,    59,    60
};

static const yytype_int16 yycheck[] =
{
      35,    27,    76,     0,   101,     4,     3,     4,     5,    43,
       3,     4,     5,   134,    32,    69,    32,     6,    42,     8,
       9,    10,    11,    50,     4,    32,   147,    51,    50,    56,
      60,    55,    60,    51,    56,    51,    53,    16,    17,    60,
      74,    95,    96,    97,   165,    60,    35,    36,    82,    55,
      56,    40,    76,   150,    33,    34,    51,    91,    55,   133,
      49,    49,    55,    49,    53,    89,    55,   101,    60,    93,
      50,    60,    61,    15,   100,     4,    18,    37,    38,    39,
      49,   116,     3,     4,    54,     6,    56,     8,     9,    10,
      11,    54,    49,    56,    55,    56,   120,    35,    36,   134,
      55,   135,   136,   137,   138,   139,   140,   141,   142,   133,
       1,     2,   147,    49,    35,    36,   150,     3,     4,    40,
       6,   145,     8,     9,    10,    11,    98,    99,    49,    55,
     165,    55,    53,    54,    55,   139,   140,    52,    52,    60,
      61,    50,    55,    51,    50,    13,    35,    36,    14,    35,
      36,    40,    50,    55,    40,    51,     7,    52,    41,    33,
      49,    38,     2,    49,    53,    54,    88,    53,    54,    55,
     141,    60,    61,    91,    60,    61,    35,    36,    35,    36,
     142,    40,    43,    40,    -1,    -1,    35,    36,    -1,    -1,
      49,    40,    49,    -1,    53,    54,    53,    -1,    -1,    -1,
      49,    60,    61,    60,    61,    -1,    55,    -1,    35,    36,
      -1,    60,    61,    40,    35,    36,    35,    36,    -1,    40,
      -1,    40,    49,    -1,    -1,    -1,    53,    -1,    49,    50,
      49,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    60,
      61,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,    67,     0,     3,     4,     5,    55,    68,    69,
      76,    82,    83,    84,    55,    68,    82,     4,    60,    75,
      77,    60,    53,     4,    50,    80,    81,    60,    70,    71,
      49,    72,    55,    56,    49,    86,    60,    50,    56,    72,
      55,    56,    32,    51,    60,    77,     4,     6,     8,     9,
      10,    11,    35,    36,    40,    49,    53,    54,    55,    60,
      61,    68,    85,    88,    89,    90,    93,    94,    96,    97,
      98,    99,    51,    81,    32,    71,    53,    79,    90,    93,
      99,   104,    49,    55,    55,    55,    90,    90,    87,    49,
      92,    49,    55,    32,    96,    37,    38,    39,    35,    36,
      52,    53,    73,   104,    54,    78,    79,    52,    91,    99,
     100,   101,   102,   103,    55,    50,    86,    50,    90,    95,
      51,    91,    90,    96,    96,    96,    98,    98,    72,    54,
      73,    74,    54,    56,    50,    16,    17,    33,    34,    15,
      18,    13,    14,    54,    50,    56,    90,    50,    55,    54,
      56,    79,    88,    99,    99,    99,    99,   100,   100,   101,
     102,    90,    52,    88,    73,     7,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    66,    67,    68,
      68,    69,    70,    70,    71,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    81,    81,    82,    83,    83,    84,
      84,    85,    86,    86,    86,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    90,    91,
      92,    92,    93,    94,    94,    94,    95,    95,    96,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     0,     1,
       1,     4,     3,     1,     4,     4,     0,     1,     2,     3,
       3,     1,     3,     1,     3,     2,     4,     3,     1,     1,
       2,     3,     3,     1,     2,     5,     4,     2,     3,     3,
       3,     4,     2,     2,     0,     0,     1,     4,     2,     1,
       5,     7,     5,     2,     2,     2,     3,     1,     1,     1,
       4,     0,     2,     3,     1,     1,     3,     1,     1,     3,
       4,     2,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token1, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token1);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (root, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token1 number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, BaseAST* *root)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (root);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, BaseAST* *root)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token1" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, root);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, BaseAST* *root)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, root); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token1 YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token1 to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token1 list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token1 list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token1 that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, BaseAST* *root)
{
  YYUSE (yyvaluep);
  YYUSE (root);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (BaseAST* *root)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token1 as an internal (translated) token1 number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token1 to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token1 if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token1.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token1 if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token1: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token1 is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token1 YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token1.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token1.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 40 "parser_hyb.y"
                    {
                        BlockAST *ptr = dynamic_cast<BlockAST *>((yyvsp[-1].ast));
                        ptr->insertItems(move(dynamic_cast<arrAST*>((yyvsp[0].ast))->exps));
                        (yyval.ast) = ptr;
                    }
#line 1509 "parser_hyb1.tab.cpp"
    break;

  case 3:
#line 46 "parser_hyb.y"
                    {
                        dynamic_cast<BlockAST *>((yyvsp[-1].ast))->insertItem((yyvsp[0].ast));
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 1518 "parser_hyb1.tab.cpp"
    break;

  case 4:
#line 50 "parser_hyb.y"
                                { (yyval.ast) = (yyvsp[-1].ast); }
#line 1524 "parser_hyb1.tab.cpp"
    break;

  case 5:
#line 51 "parser_hyb.y"
                                { (yyval.ast) = new BlockAST; *root=(yyval.ast); }
#line 1530 "parser_hyb1.tab.cpp"
    break;

  case 6:
#line 53 "parser_hyb.y"
                    {
                        BlockAST* ptr = new BlockAST;
                        ptr->insertItems(move(dynamic_cast<arrAST*>((yyvsp[0].ast))->exps));
                        *root = ptr;
		                (yyval.ast) = ptr;
                    }
#line 1541 "parser_hyb1.tab.cpp"
    break;

  case 7:
#line 60 "parser_hyb.y"
                    {
                        BlockAST* ptr = new BlockAST;
                        ptr->insertItem((yyvsp[0].ast));
                        *root = ptr;
		                (yyval.ast) = ptr;
                    }
#line 1552 "parser_hyb1.tab.cpp"
    break;

  case 8:
#line 69 "parser_hyb.y"
                    {
                        /*添加库函数*/
                        Token1* p; BaseEntry* q;

                        // starttime
                        p = new Token1(IDENT,"starttime");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        // stoptime
                        p = new Token1(IDENT,"stoptime");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        // getint
                        p = new Token1(IDENT, "getint");
                        q = newFunEntry(false, p, nullptr);
                        insertEntry(q);
                        
                        // getch
                        p = new Token1(IDENT, "getch");
                        q = newFunEntry(false, p, nullptr);
                        insertEntry(q);
                        
                        // getarray
                        p = new Token1(IDENT,"getarray");
                        q = newFunEntry(false, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        Token1* r = new Token1(IDENT,"a");
                        BaseEntry* s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(0);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                        popSymtab();

                        // putint
                        p = new Token1(IDENT,"putint");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        r = new Token1(IDENT,"a");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                        popSymtab();

                        // putch
                        p = new Token1(IDENT,"putch");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        r = new Token1(IDENT,"a");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                        popSymtab();  

                        // putarray
                        p = new Token1(IDENT,"putarray");
                        q = newFunEntry(true, p, nullptr);
                        insertEntry(q);

                        pushSymtab();
                        r = new Token1(IDENT,"a");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                 
                        r = new Token1(IDENT,"b");
                        s = newVarEntry(false, r, nullptr);
                        insertEntry(s);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(1);
                        dynamic_cast<varSymEntry *>(s)->dims.push_back(0);
                        dynamic_cast<funSymEntry *>(q)->insertParams(s);
                  
                        popSymtab();
                    }
#line 1642 "parser_hyb1.tab.cpp"
    break;

  case 11:
#line 162 "parser_hyb.y"
                    {
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 1650 "parser_hyb1.tab.cpp"
    break;

  case 12:
#line 166 "parser_hyb.y"
                    {
                        arrAST* p = dynamic_cast<arrAST*>((yyvsp[-2].ast));
                        p->insertArrAst((yyvsp[0].ast));
                        (yyval.ast) = p;
                    }
#line 1660 "parser_hyb1.tab.cpp"
    break;

  case 13:
#line 172 "parser_hyb.y"
                    {
                        arrAST* ptr = new arrAST;
                        ptr->insertArrAst((yyvsp[0].ast));
                        (yyval.ast) = ptr;
                    }
#line 1670 "parser_hyb1.tab.cpp"
    break;

  case 14:
#line 180 "parser_hyb.y"
                    {
                        vector<int> tmp = dynamic_cast<arrAST*>((yyvsp[-2].ast))->calExps();
                        tmp = getArrWidth(tmp);

                        map<int, BaseAST*> t = dynamic_cast<ListTree*>((yyvsp[0].ast))->Flatten(tmp); // Move constructor

                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(true, (yyvsp[-3].token1), p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry *>(newsym)->setDims(move(tmp));
                        
                        /* Update DeclSYM */
                        p->sym = newsym;
                        p->mmap = move(t);
                        (yyval.ast) = p;

                        /* eeyore: nativeVarNum */
                        string tmp2 = ("T");
                        tmp2 = tmp2 + num2string(nativeVarNum);
                        p->addr = tmp2;
                        nativeVarNum++;
                    }
#line 1700 "parser_hyb1.tab.cpp"
    break;

  case 15:
#line 208 "parser_hyb.y"
                    {
                        dynamic_cast<arrAST*>((yyvsp[-3].ast))->insertArrAst((yyvsp[-1].ast));
                        (yyval.ast) = (yyvsp[-3].ast);
                    }
#line 1709 "parser_hyb1.tab.cpp"
    break;

  case 16:
#line 212 "parser_hyb.y"
                  { (yyval.ast)=new arrAST; }
#line 1715 "parser_hyb1.tab.cpp"
    break;

  case 17:
#line 216 "parser_hyb.y"
                    {
                        (yyval.ast) = new ListTree((yyvsp[0].ast));
                    }
#line 1723 "parser_hyb1.tab.cpp"
    break;

  case 18:
#line 220 "parser_hyb.y"
                    {
                        (yyval.ast) = new ListTree((yyvsp[-1].token1), (yyvsp[0].token1));
                    }
#line 1731 "parser_hyb1.tab.cpp"
    break;

  case 19:
#line 224 "parser_hyb.y"
                    {
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 1739 "parser_hyb1.tab.cpp"
    break;

  case 20:
#line 230 "parser_hyb.y"
                    {
                        dynamic_cast<ListTree*>((yyvsp[-2].ast))->insertSublist((yyvsp[0].ast));
                        (yyval.ast) = (yyvsp[-2].ast);
                    }
#line 1748 "parser_hyb1.tab.cpp"
    break;

  case 21:
#line 235 "parser_hyb.y"
                    {
                        ListTree* tmp = new ListTree;
                        tmp->insertSublist((yyvsp[0].ast));
                        (yyval.ast) = tmp;
                    }
#line 1758 "parser_hyb1.tab.cpp"
    break;

  case 22:
#line 244 "parser_hyb.y"
                    {
                        arrAST* p = dynamic_cast<arrAST*>((yyvsp[-2].ast));
                        p->insertArrAst((yyvsp[0].ast));
                        (yyval.ast) = p;
                    }
#line 1768 "parser_hyb1.tab.cpp"
    break;

  case 23:
#line 250 "parser_hyb.y"
                    {
                        arrAST* p = new arrAST;
                        p->insertArrAst((yyvsp[0].ast));
                        (yyval.ast) = p;                      
                    }
#line 1778 "parser_hyb1.tab.cpp"
    break;

  case 24:
#line 258 "parser_hyb.y"
                    {
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 1786 "parser_hyb1.tab.cpp"
    break;

  case 25:
#line 264 "parser_hyb.y"
                    {
                        /* VarDef: DefineAST */
                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* array type */
                        vector<int> arrtype = dynamic_cast<arrAST*>((yyvsp[0].ast))->calExps();
                        arrtype = getArrWidth(arrtype);
                    
                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(false, (yyvsp[-1].token1), p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry *>(newsym)->setDims(move(arrtype));

                        /* Update info */
                        p->sym = newsym;
                        (yyval.ast) = p;

                        /* eeyore: nativeVarNum */
                        string tmp2 = ("T");
                        tmp2 = tmp2 + num2string(nativeVarNum);
                        p->addr = tmp2;
                        nativeVarNum++;
                    }
#line 1815 "parser_hyb1.tab.cpp"
    break;

  case 26:
#line 289 "parser_hyb.y"
                    {
                        /* type check */
                        vector<int> arrtype = dynamic_cast<arrAST*>((yyvsp[-2].ast))->calExps();
                        arrtype = getArrWidth(arrtype);

                        map<int, BaseAST*> t = dynamic_cast<ListTree*>((yyvsp[0].ast))->Flatten(arrtype);

                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(false, (yyvsp[-3].token1), p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry *>(newsym)->setDims( move(arrtype));
                        
                        /* Update DefineAST */
                        p->sym = newsym;
                        p->mmap = move(t);
                        (yyval.ast) = p;

                        string tmp2 = ("T");
                        tmp2 = tmp2 + num2string(nativeVarNum);
                        p->addr = tmp2;
                        nativeVarNum++;
                    }
#line 1845 "parser_hyb1.tab.cpp"
    break;

  case 27:
#line 317 "parser_hyb.y"
                    {
                        dynamic_cast<ListTree*>((yyvsp[-2].ast))->insertSublist((yyvsp[0].ast));
                        (yyval.ast) = (yyvsp[-2].ast);
                    }
#line 1854 "parser_hyb1.tab.cpp"
    break;

  case 28:
#line 322 "parser_hyb.y"
                    {
                        ListTree* p = new ListTree;
                        p->insertSublist((yyvsp[0].ast)); 
                        (yyval.ast) = p;
                    }
#line 1864 "parser_hyb1.tab.cpp"
    break;

  case 29:
#line 330 "parser_hyb.y"
                    {
                        (yyval.ast) = new ListTree((yyvsp[0].ast));
                    }
#line 1872 "parser_hyb1.tab.cpp"
    break;

  case 30:
#line 334 "parser_hyb.y"
                    {
                        (yyval.ast) = new ListTree((yyvsp[-1].token1), (yyvsp[0].token1));
                    }
#line 1880 "parser_hyb1.tab.cpp"
    break;

  case 31:
#line 338 "parser_hyb.y"
                    {
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 1888 "parser_hyb1.tab.cpp"
    break;

  case 32:
#line 344 "parser_hyb.y"
                    {
                        /* FuncFParams: arrAST* */
                        dynamic_cast<arrAST* >((yyvsp[-2].ast))->insertArrAst((yyvsp[0].ast));
                        (yyval.ast) = (yyvsp[-2].ast);
                    }
#line 1898 "parser_hyb1.tab.cpp"
    break;

  case 33:
#line 350 "parser_hyb.y"
                    {
                        /* FuncFParams: arrAST* */
                        arrAST* p = new arrAST;
                        p->insertArrAst((yyvsp[0].ast));
                        (yyval.ast) = p;
                    }
#line 1909 "parser_hyb1.tab.cpp"
    break;

  case 34:
#line 358 "parser_hyb.y"
                    {
                        /* FuncFParam: DefineAST */
                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new varSymEntry */
                        BaseEntry* newsym = newVarEntry(false, (yyvsp[0].token1), p);
                        insertEntry(newsym);
                        dynamic_cast<varSymEntry*>(newsym)->setDims(vector<int> (1,1));

                        /* Update DefineAST */
                        p->sym = newsym;
                        (yyval.ast) = p;

                        /* eeyore: paraNum */
                        string tmp2 = ("p");
                        tmp2 = tmp2 + num2string(paraNum);
                        p->addr = tmp2;
                        paraNum++;
                    }
#line 1934 "parser_hyb1.tab.cpp"
    break;

  case 35:
#line 379 "parser_hyb.y"
                    {
                        /* FuncFParam: DefineAST */
                        /* new DefineAST */
                        DefineAST *p = new DefineAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newVarEntry(false, (yyvsp[-3].token1), p);
                        insertEntry(newsym);

                        vector<int> arrtype = dynamic_cast<arrAST* >((yyvsp[0].ast))->calExps();

                        /* If ConstArr is empty, update positioning info */
                        arrtype = getArrWidth(arrtype);
                        arrtype.push_back(0); // pointer
                        dynamic_cast<varSymEntry* >(newsym)->setDims(move(arrtype));

                        p->sym = newsym;
                        (yyval.ast) = p;

                        /* eeyore: paraNum */
                        string tmp2 = ("p");
                        tmp2 = tmp2 + num2string(paraNum);
                        p->addr = tmp2;
                        paraNum++;

                    }
#line 1965 "parser_hyb1.tab.cpp"
    break;

  case 36:
#line 407 "parser_hyb.y"
                    {   
                        /* FuncDef: FunDefAST */
                        FunDefAST *p = dynamic_cast<FunDefAST *>((yyvsp[-3].ast));
                        p->body = (yyvsp[-1].ast);
                        (yyval.ast) = (yyvsp[-3].ast);

                        /* Check main */
                        if(*(p->sym->strp) == "main"){
                            mainptr = p;
                        }

                        /* End of the scope */
                        popSymtab();

                        /* eeyore: reset paramno */
                        paraNum = 0;

                    }
#line 1988 "parser_hyb1.tab.cpp"
    break;

  case 37:
#line 427 "parser_hyb.y"
                    {
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 1996 "parser_hyb1.tab.cpp"
    break;

  case 38:
#line 431 "parser_hyb.y"
                    {
                        /* FuncDefproto: FunDefAST */
                        FunDefAST *p = dynamic_cast<FunDefAST *>((yyvsp[-2].ast));
                        p->fParams = dynamic_cast<arrAST* >((yyvsp[-1].ast))->output(); // Move assignment

                        /* bind SYMs of fParams to FunDefAST */
                        for(auto i: p->fParams)
                            dynamic_cast<funSymEntry *>(p->sym)->fParams.push_back(dynamic_cast<DefineAST *>(i)->sym);
                        (yyval.ast) = (yyvsp[-2].ast);

                    }
#line 2012 "parser_hyb1.tab.cpp"
    break;

  case 39:
#line 444 "parser_hyb.y"
                    {
                        /* FuncDefHead: FunDefAST */
                        /* new FunDefAST */
                        FunDefAST *p = new FunDefAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newFunEntry(false, (yyvsp[-1].token1), p);
                        insertEntry(newsym);

                        /* Update FunDefAST */
                        p->sym = newsym;
                        (yyval.ast) = p;

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
#line 2040 "parser_hyb1.tab.cpp"
    break;

  case 40:
#line 468 "parser_hyb.y"
                    {
                        /* FuncDefHead: FunDefAST */
                        /* new FunDefAST */
                        FunDefAST *p = new FunDefAST;

                        /* new BaseEntry */
                        BaseEntry* newsym = newFunEntry(true, (yyvsp[-1].token1), p);
                        insertEntry(newsym);

                        /* Update FunDefAST */
                        p->sym = newsym;
                        (yyval.ast) = p;

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
#line 2069 "parser_hyb1.tab.cpp"
    break;

  case 41:
#line 495 "parser_hyb.y"
                    {
                        /* BlockItemArr: BlockAST */
                        popSymtab();
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2079 "parser_hyb1.tab.cpp"
    break;

  case 42:
#line 503 "parser_hyb.y"
                    {
                        /* BlockItemArr: BlockAST */
                        BlockAST *p = dynamic_cast<BlockAST *>((yyvsp[-1].ast));
                        p->insertItems(move(dynamic_cast<arrAST*>((yyvsp[0].ast))->exps));
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2090 "parser_hyb1.tab.cpp"
    break;

  case 43:
#line 510 "parser_hyb.y"
                    {
                        /* BlockItemArr: BlockAST */
                        BlockAST *p = dynamic_cast<BlockAST *>((yyvsp[-1].ast));
                        p->insertItem((yyvsp[0].ast));
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2101 "parser_hyb1.tab.cpp"
    break;

  case 44:
#line 517 "parser_hyb.y"
                    {
                        /* BlockItemArr: BlockAST */
                        (yyval.ast) = new BlockAST;
                    }
#line 2110 "parser_hyb1.tab.cpp"
    break;

  case 45:
#line 524 "parser_hyb.y"
                    {
                        /* BlockStart: null */
                        pushSymtab();
                        (yyval.ast) = nullptr;
                    }
#line 2120 "parser_hyb1.tab.cpp"
    break;

  case 46:
#line 532 "parser_hyb.y"
                    {
                        /* Stmt: polymorphism */
                        (yyval.ast) = nullptr;
                    }
#line 2129 "parser_hyb1.tab.cpp"
    break;

  case 47:
#line 537 "parser_hyb.y"
                    {
                        /* Stmt: AssignAST */
                        AssignAST *p = new AssignAST;
                        p->lval = (yyvsp[-3].ast);
                        p->exp = (yyvsp[-1].ast);
                        (yyval.ast) = p;
                    }
#line 2141 "parser_hyb1.tab.cpp"
    break;

  case 48:
#line 545 "parser_hyb.y"
                    {
                        /* Stmt: polymorphism */
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2150 "parser_hyb1.tab.cpp"
    break;

  case 49:
#line 550 "parser_hyb.y"
                    {
                        /* Stmt: BlockAST */
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 2159 "parser_hyb1.tab.cpp"
    break;

  case 50:
#line 555 "parser_hyb.y"
                    {
                        /* Stmt: IfAST */
                        IfAST *p = new IfAST;                      
                        p->cond = (yyvsp[-2].ast);
                        p->stmt = (yyvsp[0].ast);
                        (yyval.ast) = p;
                    }
#line 2171 "parser_hyb1.tab.cpp"
    break;

  case 51:
#line 563 "parser_hyb.y"
                    {
                        /* Stmt: IfAST */
                        IfAST *p = new IfAST;
                        p->cond = (yyvsp[-4].ast);
                        p->stmt = (yyvsp[-2].ast);
                        p->elseStmt = (yyvsp[0].ast);
                        (yyval.ast) = p;
                    }
#line 2184 "parser_hyb1.tab.cpp"
    break;

  case 52:
#line 572 "parser_hyb.y"
                    {
                        /* Stmt: WhileAST */
                        WhileAST *p = dynamic_cast<WhileAST *>((yyvsp[-4].ast));
                        p->cond = (yyvsp[-2].ast);
                        p->stmt = (yyvsp[0].ast);
                        (yyval.ast) = p;
                        popWhileStack();
                    }
#line 2197 "parser_hyb1.tab.cpp"
    break;

  case 53:
#line 581 "parser_hyb.y"
                    {
                        /* Stmt: BreakAST */
                        if(isEmptyWhileStack()){
                            (yyval.ast) = nullptr;
                        }
                        else{
                            BreakAST *p = new BreakAST;
                            (yyval.ast) = p;
                        }
                    }
#line 2212 "parser_hyb1.tab.cpp"
    break;

  case 54:
#line 592 "parser_hyb.y"
                    {
                        /* Stmt: ContinueAST */
                        /* No while to continue */
                        if(whileStack.empty()){
                            (yyval.ast) = nullptr;
                        }
                        else{
                            ContinueAST *p = new ContinueAST;
                            (yyval.ast) = p;
                        }

                    }
#line 2229 "parser_hyb1.tab.cpp"
    break;

  case 55:
#line 605 "parser_hyb.y"
                    {
                        /* Stmt: ReturnAST */
                        ReturnAST *p = new ReturnAST;
                        /* Check ret value */
                        funSymEntry *q = dynamic_cast<funSymEntry *>(dynamic_cast<FunDefAST *>(p->nextCode)->sym);
                        if(!q->isVoid){
                            /* return 0 by default */
                            Token1* r = new Token1(INT_CONST, 0);
                            BinaryExpAST *s = new BinaryExpAST(r);
                            p->exp = s;
                        }
                        (yyval.ast) = p;
                    }
#line 2247 "parser_hyb1.tab.cpp"
    break;

  case 56:
#line 619 "parser_hyb.y"
                    {
                        /* Stmt: ReturnAST */
                        ReturnAST *p = new ReturnAST;
                        /* Check ret value */
                        funSymEntry *q = dynamic_cast<funSymEntry *>(dynamic_cast<FunDefAST *>(p->nextCode)->sym);
                        if(q->isVoid){
                        }
                        else p->exp = (yyvsp[-1].ast);
                        (yyval.ast) = p;
                    }
#line 2262 "parser_hyb1.tab.cpp"
    break;

  case 57:
#line 632 "parser_hyb.y"
                    {
                        /* WhileHead: WhileAST */
                        WhileAST *p = new WhileAST;
                        (yyval.ast) = p;
                        /* Update WhileStack */
                        pushWhileStack(p);
                    }
#line 2274 "parser_hyb1.tab.cpp"
    break;

  case 58:
#line 642 "parser_hyb.y"
                    {
                        (yyvsp[0].ast)->cal();
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 2283 "parser_hyb1.tab.cpp"
    break;

  case 59:
#line 649 "parser_hyb.y"
                    {
                        (yyvsp[0].ast)->cal();
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 2292 "parser_hyb1.tab.cpp"
    break;

  case 60:
#line 655 "parser_hyb.y"
                    {
                        dynamic_cast<arrAST*>((yyvsp[-3].ast))->insertArrAst((yyvsp[-1].ast));
                        (yyval.ast) = (yyvsp[-3].ast);
                    }
#line 2301 "parser_hyb1.tab.cpp"
    break;

  case 61:
#line 660 "parser_hyb.y"
                    {
                        (yyval.ast) = new arrAST;
                    }
#line 2309 "parser_hyb1.tab.cpp"
    break;

  case 62:
#line 666 "parser_hyb.y"
                    {
                        (yyval.ast) = new LvalAST((yyvsp[-1].token1), (yyvsp[0].ast));
                    }
#line 2317 "parser_hyb1.tab.cpp"
    break;

  case 63:
#line 672 "parser_hyb.y"
                    {
                        (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2325 "parser_hyb1.tab.cpp"
    break;

  case 65:
#line 677 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[0].token1));
                    }
#line 2333 "parser_hyb1.tab.cpp"
    break;

  case 66:
#line 683 "parser_hyb.y"
                    {
                        /* FuncRParams: arrAST */
                        dynamic_cast<arrAST *>((yyvsp[-2].ast))->insertArrAst((yyvsp[0].ast));                     
                    }
#line 2342 "parser_hyb1.tab.cpp"
    break;

  case 67:
#line 688 "parser_hyb.y"
                    {
                        arrAST *p = new arrAST;
                        p->insertArrAst((yyvsp[0].ast));
                        (yyval.ast) = p;
                    }
#line 2352 "parser_hyb1.tab.cpp"
    break;

  case 69:
#line 697 "parser_hyb.y"
                    {                      
                        FunCallAST *ptr = new FunCallAST((yyvsp[-2].token1));
                        (yyval.ast) = ptr;
                        ptr->checkParaSize();
                    }
#line 2362 "parser_hyb1.tab.cpp"
    break;

  case 70:
#line 703 "parser_hyb.y"
                    {
                        FunCallAST *ptr = new FunCallAST((yyvsp[-3].token1));

                        ptr->rParams = dynamic_cast<arrAST* >((yyvsp[-1].ast))->output();
                        (yyval.ast) = ptr;

                        /* Check the params list */
                        ptr->checkParaSize();

                    }
#line 2377 "parser_hyb1.tab.cpp"
    break;

  case 71:
#line 714 "parser_hyb.y"
                    {
                        /* Only when UnaryExp is a unaryexp should coalesce be called */
                        if((yyvsp[0].ast)->type == ASTtype::UnaryExp) {
                            dynamic_cast<UnaryExpAST *>((yyvsp[0].ast))->dealOp((yyvsp[-1].token1));
                            (yyval.ast) = (yyvsp[0].ast);
                        }
                        /* Only when UnaryExp is not a unaryexp should constructor be called */
                        else (yyval.ast) = new UnaryExpAST((yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2391 "parser_hyb1.tab.cpp"
    break;

  case 76:
#line 732 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2399 "parser_hyb1.tab.cpp"
    break;

  case 77:
#line 736 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2407 "parser_hyb1.tab.cpp"
    break;

  case 78:
#line 740 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2415 "parser_hyb1.tab.cpp"
    break;

  case 80:
#line 747 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2423 "parser_hyb1.tab.cpp"
    break;

  case 81:
#line 751 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2431 "parser_hyb1.tab.cpp"
    break;

  case 83:
#line 757 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2439 "parser_hyb1.tab.cpp"
    break;

  case 84:
#line 761 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2447 "parser_hyb1.tab.cpp"
    break;

  case 85:
#line 765 "parser_hyb.y"
                    {   
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2455 "parser_hyb1.tab.cpp"
    break;

  case 86:
#line 769 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2463 "parser_hyb1.tab.cpp"
    break;

  case 88:
#line 776 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2471 "parser_hyb1.tab.cpp"
    break;

  case 89:
#line 780 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2479 "parser_hyb1.tab.cpp"
    break;

  case 91:
#line 786 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2487 "parser_hyb1.tab.cpp"
    break;

  case 93:
#line 792 "parser_hyb.y"
                    {
                        (yyval.ast) = new BinaryExpAST((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].token1));
                    }
#line 2495 "parser_hyb1.tab.cpp"
    break;

  case 94:
#line 797 "parser_hyb.y"
                    {
                        (yyvsp[0].ast)->cal();
                        (yyval.ast) = (yyvsp[0].ast);
                    }
#line 2504 "parser_hyb1.tab.cpp"
    break;


#line 2508 "parser_hyb1.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (root, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (root, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token1 after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, root);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token1 after shifting the error
     token1.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token1 shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token1.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token1.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 803 "parser_hyb.y"


/*int main(){
    yyparse();
    return 0;
}*/
