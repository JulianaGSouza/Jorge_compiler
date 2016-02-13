/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "Jorge_parser.y" /* yacc.c:339  */


#include "Jorge_t_define.h"
#include "Jorge_parser.tab.h"

extern char bf_linha_scanner[500];
extern unsigned yycolumn;

void yyerror (std::shared_ptr<T_exp> raiz,char const *s){
	std::cerr <<"\033[1;31m"  << "Erro sintatico (coluna " << yycolumn << "\033[1;0m" << ")" << std::endl;
};

int yylex();


#line 82 "Jorge_parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Jorge_parser.tab.h".  */
#ifndef YY_YY_JORGE_PARSER_TAB_H_INCLUDED
# define YY_YY_JORGE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE = 258,
    ARRAY = 259,
    OF = 260,
    VAR = 261,
    FUNCTION = 262,
    LET = 263,
    IN = 264,
    END = 265,
    NIL = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    IGUAL = 270,
    DIFERENTE = 271,
    MAIOR = 272,
    MENOR = 273,
    MAIORIG = 274,
    MENORIG = 275,
    AND = 276,
    OR = 277,
    PONTO = 278,
    ATRIBUICAO = 279,
    ADICAO = 280,
    SUBTRACAO = 281,
    MULTIPLICACAO = 282,
    DIVISAO = 283,
    RETORNA = 284,
    INT = 285,
    FLOAT = 286,
    STRING = 287,
    ID = 288,
    SUBUNARIO = 289,
    ARRAY_PREC = 290,
    IF_PREC = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 28 "Jorge_parser.y" /* yacc.c:355  */

	char* i_id;
	T_exp* i_exp;
	T_int* i_int;
	T_float* i_float;
	T_string* i_string;
	T_nil* i_nil;
	T_declist* i_declist;
	T_dec* i_dec;
	T_ty* i_ty;	
	T_tylist* i_tylist;
	T_tyfields* i_tyfields;
	T_lvalue* i_lvalue;
	T_operacao* i_operacao;
	T_exp_list* i_exp_list;
	T_chamada* i_chamada;
	T_exp_seq* i_exp_seq;
	T_rec_enum* i_rec_enum;
	T_enum_it* i_enum_it;
	T_def_array* i_def_array;
	T_def_rec* i_def_rec;
	T_subunario* i_subunario;
	T_if * i_if;
	T_if_else* i_if_else;
	T_let* i_let;

#line 186 "Jorge_parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<T_exp> raiz);

#endif /* !YY_YY_JORGE_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "Jorge_parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,    41,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    99,   100,   103,   104,   105,   109,   111,
     112,   113,   116,   117,   118,   119,   122,   125,   128,   131,
     132,   135,   136,   137,   142,   143,   148,   150,   155,   156,
     157,   162,   163,   164,   165,   168,   169,   172,   173,   174,
     175,   176,   177,   180,   181,   182,   185,   186,   189,   190,
     191,   194,   198,   199,   200,   203,   206,   209,   212,   215,
     219,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ARRAY", "OF", "VAR", "FUNCTION",
  "LET", "IN", "END", "NIL", "IF", "THEN", "ELSE", "IGUAL", "DIFERENTE",
  "MAIOR", "MENOR", "MAIORIG", "MENORIG", "AND", "OR", "PONTO",
  "ATRIBUICAO", "ADICAO", "SUBTRACAO", "MULTIPLICACAO", "DIVISAO",
  "RETORNA", "INT", "FLOAT", "STRING", "ID", "SUBUNARIO", "'('",
  "ARRAY_PREC", "IF_PREC", "','", "'{'", "'}'", "')'", "':'", "'['", "']'",
  "';'", "$accept", "inicio", "declist", "dec", "tydec", "tylist", "ty",
  "ty_id", "ty_rec", "ty_array", "ty_funfun", "tyfields", "vardec",
  "fundec", "lvalue", "op_arit", "op_bool", "op_comp", "exp_list",
  "chamada", "exp_seq", "def_array", "rec_enum", "enum_it", "def_rec",
  "subunario", "exp_if", "exp_if_else", "exp_let", "exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    40,   290,   291,    44,   123,
     125,    41,    58,    91,    93,    59
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     141,    86,   -84,   141,   141,   -84,   -84,   -84,    44,   141,
       2,   -17,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   186,   -26,    -8,    -2,    27,    86,   -84,   -84,
     -84,    -5,     3,   141,    24,   141,    20,    50,   -84,    29,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,    48,   -15,    45,   141,   -84,   141,
      41,   162,    71,    54,    58,    82,   -84,   141,   -84,   120,
     221,   221,   221,   221,   221,   221,   235,   207,    46,    46,
       3,     3,    47,    25,   141,    72,    73,   101,    99,   -84,
     141,   141,   -84,    24,   109,   -84,   -84,   -84,   110,   -84,
      25,    73,    89,   -84,   -84,   -84,   -84,   186,    95,    78,
      80,   -84,   141,   -84,   186,   -84,   141,    90,    83,    -1,
      85,    25,   141,    94,   -10,   -84,   -84,   -84,   100,    25,
     -84,    89,   186,    92,   141,    98,    25,   -84,    73,   186,
     113,    89,   -84,   141,   186
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    62,     0,     0,    64,    65,    66,    28,    48,
       0,    61,    69,    70,    71,    68,    72,    73,    67,    75,
      74,    76,     2,     0,     0,     0,     0,     3,     5,     6,
       7,     0,    57,    43,    52,     0,     0,    49,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,    48,     4,     0,
       0,    44,     0,     0,    53,     0,    63,    48,    29,     0,
      37,    38,    41,    39,    42,    40,    36,    35,    31,    32,
      33,    34,     0,     0,     0,     0,    21,     0,    58,    46,
      43,     0,    56,    52,     0,    50,    30,    47,     0,    16,
       9,    21,     8,    12,    13,    14,    15,    24,     0,     0,
       0,    60,     0,    45,    55,    54,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    59,    51,    18,     0,     9,
      17,    19,    25,    22,     0,     0,     0,    11,    21,    27,
       0,    20,    23,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   105,   -84,   -84,     4,   -82,   -84,   -84,   -84,
     -84,   -83,   -84,   -84,   -84,   -84,   -84,   -84,   -34,   -84,
     -33,   -84,    51,   -84,   -84,   -84,   -84,   -84,   -84,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    26,    27,    28,   118,   119,   103,   104,   105,
     106,   110,    29,    30,    11,    12,    13,    14,    60,    15,
      36,    16,    63,    64,    17,    18,    19,    20,    21,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   102,    38,    31,    32,   134,    39,    54,    59,    84,
      41,    42,    43,    44,    45,    46,    47,    48,   120,    82,
      49,    50,    51,    52,    87,    55,    40,    85,   121,    98,
      53,    56,   135,    61,    95,    65,    57,   129,    53,   131,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    61,   141,   142,   113,    62,    99,    88,
     100,    66,    68,    83,   101,    41,    42,    43,    44,    45,
      46,    47,    48,    51,    52,    49,    50,    51,    52,    33,
      86,    53,    89,    34,   107,    53,    91,    35,    97,    23,
      61,   114,    24,    25,    92,    67,    93,    41,    42,    43,
      44,    45,    46,    47,    48,   108,   109,    49,    50,    51,
      52,   111,   125,   112,   116,   117,   126,    53,   121,   122,
     123,   124,   132,   127,   128,   130,    94,   133,   143,   136,
     138,   140,    58,   137,   139,    41,    42,    43,    44,    45,
      46,    47,    48,   144,   115,    49,    50,    51,    52,     1,
       0,     0,     2,     3,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     4,     0,     0,
       0,     5,     6,     7,     8,     0,     9,    41,    42,    43,
      44,    45,    46,    47,    48,     0,     0,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,    53,     0,     0,
      90,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,    53,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    53,     0,     0,     0,    49,    50,    51,    52,
      41,    42,    43,    44,    45,    46,    53,     0,     0,     0,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
      53
};

static const yytype_int16 yycheck[] =
{
       0,    83,     0,     3,     4,    15,    23,    33,    13,    24,
      15,    16,    17,    18,    19,    20,    21,    22,   101,    53,
      25,    26,    27,    28,    57,    33,    43,    42,    29,     4,
      35,    33,    42,    33,    67,    35,     9,    38,    35,   121,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   136,   138,    90,    33,    33,    59,
      35,    41,    33,    15,    39,    15,    16,    17,    18,    19,
      20,    21,    22,    27,    28,    25,    26,    27,    28,    35,
      35,    35,    41,    39,    84,    35,    15,    43,    41,     3,
      90,    91,     6,     7,    40,    45,    38,    15,    16,    17,
      18,    19,    20,    21,    22,    33,    33,    25,    26,    27,
      28,    10,   112,    14,     5,     5,   116,    35,    29,    24,
      42,    41,   122,    33,    41,    40,    44,    33,    15,    29,
      38,    33,    27,   129,   134,    15,    16,    17,    18,    19,
      20,    21,    22,   143,    93,    25,    26,    27,    28,     8,
      -1,    -1,    11,    12,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    35,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      38,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    15,    16,    17,    18,
      19,    20,    35,    -1,    -1,    -1,    25,    26,    27,    28,
      15,    16,    17,    18,    19,    20,    35,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    11,    12,    26,    30,    31,    32,    33,    35,
      47,    60,    61,    62,    63,    65,    67,    70,    71,    72,
      73,    74,    75,     3,     6,     7,    48,    49,    50,    58,
      59,    75,    75,    35,    39,    43,    66,    75,     0,    23,
      43,    15,    16,    17,    18,    19,    20,    21,    22,    25,
      26,    27,    28,    35,    33,    33,    33,     9,    48,    13,
      64,    75,    33,    68,    69,    75,    41,    45,    33,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    64,    15,    24,    42,    35,    66,    75,    41,
      38,    15,    40,    38,    44,    66,    44,    41,     4,    33,
      35,    39,    52,    53,    54,    55,    56,    75,    33,    33,
      57,    10,    14,    64,    75,    68,     5,     5,    51,    52,
      57,    29,    24,    42,    41,    75,    75,    33,    41,    38,
      40,    52,    75,    33,    15,    42,    29,    51,    38,    75,
      33,    52,    57,    15,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    51,
      51,    51,    52,    52,    52,    52,    53,    54,    55,    56,
      56,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    68,    68,    68,    69,    70,    71,    72,    73,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     4,     0,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       5,     0,     3,     5,     4,     6,     9,     7,     1,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     1,     3,     4,     4,     0,     1,
       3,     6,     0,     1,     3,     3,     4,     2,     4,     6,
       5,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (raiz, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
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
                  Type, Value, raiz); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<T_exp> raiz)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (raiz);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<T_exp> raiz)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, raiz);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, std::shared_ptr<T_exp> raiz)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , raiz);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, raiz); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::shared_ptr<T_exp> raiz)
{
  YYUSE (yyvaluep);
  YYUSE (raiz);
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
yyparse (std::shared_ptr<T_exp> raiz)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
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
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
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

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 96 "Jorge_parser.y" /* yacc.c:1646  */
    {raiz = std::shared_ptr<T_exp>(new T_exp());}
#line 1406 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_declist) = new T_declist(); (yyval.i_declist)->add(std::shared_ptr<T_dec>((yyvsp[0].i_dec)));}
#line 1412 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyvsp[0].i_declist)->add(std::shared_ptr<T_dec>((yyvsp[-1].i_dec))); (yyval.i_declist) = (yyvsp[0].i_declist);}
#line 1418 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_dec) = new T_tydec(std::string((yyvsp[-2].i_id)),std::shared_ptr<T_ty>((yyvsp[0].i_ty)));}
#line 1424 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_tylist) = new T_tylist();}
#line 1430 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 112 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_tylist) = new T_tylist(); (yyval.i_tylist)->add(std::shared_ptr<T_ty>((yyvsp[0].i_ty)));}
#line 1436 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyvsp[0].i_tylist)->add(std::shared_ptr<T_ty>((yyvsp[-2].i_ty))); (yyval.i_tylist) = (yyvsp[0].i_tylist);}
#line 1442 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_ty) = new T_ty_id(std::string((yyvsp[0].i_id)));}
#line 1448 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 125 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_ty) = new T_ty_rec(std::shared_ptr<T_tyfields>((yyvsp[-1].i_tyfields)));}
#line 1454 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_ty) = new T_ty_array(std::string((yyvsp[0].i_id)));}
#line 1460 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_ty) = new T_ty_funfun(std::shared_ptr<T_ty>((yyvsp[-2].i_ty)),std::shared_ptr<T_ty>((yyvsp[0].i_ty)));}
#line 1466 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 132 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_ty) = new T_ty_funfun(std::shared_ptr<T_tylist>((yyvsp[-3].i_tylist)),std::shared_ptr<T_ty>((yyvsp[0].i_ty)));}
#line 1472 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 135 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_tyfields) = new T_tyfields();}
#line 1478 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 136 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_tyfields) = new T_tyfields(); (yyval.i_tyfields)->add(std::string((yyvsp[-2].i_id)),std::string((yyvsp[0].i_id)));}
#line 1484 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 137 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyvsp[0].i_tyfields)->add(std::string((yyvsp[-4].i_id)),std::string((yyvsp[-2].i_id))); (yyval.i_tyfields) = (yyvsp[0].i_tyfields);}
#line 1490 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 142 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_dec) = new T_vardec(std::string((yyvsp[-2].i_id)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1496 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 143 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_dec) = new T_vardec(std::string((yyvsp[-4].i_id)),std::string((yyvsp[-2].i_id)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1502 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_dec) = new T_fundec(std::string((yyvsp[-7].i_id)),
								std::shared_ptr<T_tyfields>((yyvsp[-5].i_tyfields)), std::string((yyvsp[-2].i_id)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1509 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 150 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_dec) = new T_fundec(std::string((yyvsp[-5].i_id)),
								std::shared_ptr<T_tyfields>((yyvsp[-3].i_tyfields)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1516 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 155 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_lvalue) = new T_lvalue(std::string((yyvsp[0].i_id)));}
#line 1522 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_lvalue) = new T_lvalue(std::shared_ptr<T_lvalue>((yyvsp[-2].i_lvalue)), std::string((yyvsp[0].i_id)));}
#line 1528 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 157 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_lvalue) = new T_lvalue(std::shared_ptr<T_lvalue>((yyvsp[-3].i_lvalue)), std::shared_ptr<T_exp>((yyvsp[-1].i_exp)));}
#line 1534 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("+", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1540 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 163 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("-", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1546 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 164 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("*", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1552 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 165 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("/", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1558 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 168 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("|", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1564 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 169 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("&", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1570 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 172 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("=", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1576 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 173 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("<>", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1582 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 174 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("<", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1588 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 175 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao("<=", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1594 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 176 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao(">", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1600 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 177 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_operacao) = new T_operacao(">=", std::shared_ptr<T_exp>((yyvsp[-2].i_exp)), std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1606 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 180 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp_list) = new T_exp_list();}
#line 1612 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp_list) = new T_exp_list(); (yyval.i_exp_list)->add(std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1618 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 182 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyvsp[0].i_exp_list)->add(std::shared_ptr<T_exp>((yyvsp[-2].i_exp))); (yyval.i_exp_list) = (yyvsp[0].i_exp_list);}
#line 1624 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 185 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_chamada) = new T_chamada(std::string((yyvsp[-3].i_id)),std::shared_ptr<T_exp_list>((yyvsp[-1].i_exp_list)));}
#line 1630 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 186 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_chamada) = new T_chamada(std::shared_ptr<T_exp>((yyvsp[-3].i_exp)),std::shared_ptr<T_exp_list>((yyvsp[-1].i_exp_list)));}
#line 1636 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 189 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp_seq) = new T_exp_seq();}
#line 1642 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 190 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp_seq) = new T_exp_seq(); (yyval.i_exp_seq)->add(std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1648 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 191 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyvsp[0].i_exp_seq)->add(std::shared_ptr<T_exp>((yyvsp[-2].i_exp))); (yyval.i_exp_seq) = (yyvsp[0].i_exp_seq);}
#line 1654 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 194 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_def_array) = new T_def_array(std::string((yyvsp[-5].i_id)),
						std::shared_ptr<T_exp>((yyvsp[-3].i_exp)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1661 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 198 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_rec_enum) = new T_rec_enum();}
#line 1667 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 199 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_rec_enum) = new T_rec_enum(); (yyval.i_rec_enum)->add(std::shared_ptr<T_enum_it>((yyvsp[0].i_enum_it)));}
#line 1673 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 200 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyvsp[0].i_rec_enum)->add(std::shared_ptr<T_enum_it>((yyvsp[-2].i_enum_it))); (yyval.i_rec_enum) = (yyvsp[0].i_rec_enum);}
#line 1679 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 203 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_enum_it) = new T_enum_it(std::string((yyvsp[-2].i_id)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1685 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 206 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_def_rec) = new T_def_rec(std::string((yyvsp[-3].i_id)), std::shared_ptr<T_rec_enum>((yyvsp[-1].i_rec_enum)));}
#line 1691 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 209 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_subunario) = new T_subunario(std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1697 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 212 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_if) = new T_if(std::shared_ptr<T_exp>((yyvsp[-2].i_exp)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1703 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 215 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_if_else) = new T_if_else(std::shared_ptr<T_exp>((yyvsp[-4].i_exp)),
						std::shared_ptr<T_exp>((yyvsp[-2].i_exp)),std::shared_ptr<T_exp>((yyvsp[0].i_exp)));}
#line 1710 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 219 "Jorge_parser.y" /* yacc.c:1646  */
    { (yyval.i_let) = new T_let(std::shared_ptr<T_declist>((yyvsp[-3].i_declist)),std::shared_ptr<T_exp_seq>((yyvsp[-1].i_exp_seq)));}
#line 1716 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 223 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp) = new T_nil();}
#line 1722 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 224 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp) = (yyvsp[-1].i_exp_seq);}
#line 1728 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 225 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp) = new T_int(*(yyvsp[0].i_int));}
#line 1734 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 226 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp) = new T_float(*(yyvsp[0].i_float));}
#line 1740 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 227 "Jorge_parser.y" /* yacc.c:1646  */
    {(yyval.i_exp) = new T_string(*(yyvsp[0].i_string));}
#line 1746 "Jorge_parser.tab.c" /* yacc.c:1646  */
    break;


#line 1750 "Jorge_parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
      yyerror (raiz, YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (raiz, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval, raiz);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, raiz);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
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
  yyerror (raiz, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, raiz);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, raiz);
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
#line 240 "Jorge_parser.y" /* yacc.c:1906  */

