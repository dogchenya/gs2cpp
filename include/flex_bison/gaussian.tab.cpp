/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./gaussian.y" /* yacc.c:339  */

#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

#define YYSTYPE GrammarBasePtr

#include "parse.h"
#define YYDEBUG 1
#define YYINITDEPTH 10000

#line 80 "gaussian.tab.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "gaussian.tab.hpp".  */
#ifndef YY_YY_GAUSSIAN_TAB_HPP_INCLUDED
# define YY_YY_GAUSSIAN_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GAUSSIAN_VOID = 258,
    GAUSSIAN_STRUCT = 259,
    GAUSSIAN_ROS_PARAMS = 260,
    GAUSSIAN_BOOL = 261,
    GAUSSIAN_BYTE = 262,
    GAUSSIAN_SHORT = 263,
    GAUSSIAN_INT = 264,
    GAUSSIAN_DOUBLE = 265,
    GAUSSIAN_FLOAT = 266,
    GAUSSIAN_LONG = 267,
    GAUSSIAN_STRING = 268,
    GAUSSIAN_VECTOR = 269,
    GAUSSIAN_MAP = 270,
    GAUSSIAN_NAMESPACE = 271,
    GAUSSIAN_ROS_NAMESPACE = 272,
    GAUSSIAN_INTERFACE = 273,
    GAUSSIAN_IDENTIFIER = 274,
    GAUSSIAN_OUT = 275,
    GAUSSIAN_OP = 276,
    GAUSSIAN_KEY = 277,
    GAUSSIAN_ROUTE_KEY = 278,
    GAUSSIAN_REQUIRE = 279,
    GAUSSIAN_OPTIONAL = 280,
    GAUSSIAN_CONST_INTEGER = 281,
    GAUSSIAN_CONST_FLOAT = 282,
    GAUSSIAN_FALSE = 283,
    GAUSSIAN_TRUE = 284,
    GAUSSIAN_STRING_LITERAL = 285,
    GAUSSIAN_SCOPE_DELIMITER = 286,
    GAUSSIAN_CONST = 287,
    GAUSSIAN_ENUM = 288,
    GAUSSIAN_UNSIGNED = 289,
    BAD_CHAR = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GAUSSIAN_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 167 "gaussian.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   733

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

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
      46,    43,    44,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    36,
      47,    40,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    60,    65,    64,    69,    74,    81,
      85,    89,    93,    97,   100,   104,   114,   113,   136,   149,
     160,   164,   172,   183,   188,   202,   210,   209,   243,   242,
     261,   274,   293,   292,   326,   330,   341,   344,   347,   352,
     359,   365,   382,   411,   412,   423,   425,   436,   447,   459,
     471,   483,   495,   499,   508,   519,   531,   530,   572,   576,
     582,   591,   595,   600,   607,   616,   635,   654,   673,   690,
     713,   712,   754,   758,   764,   773,   777,   782,   791,   800,
     818,   840,   862,   879,   883,   887,   891,   900,   910,   920,
     928,   936,   944,   952,   972,   990,   999,  1009,  1019,  1028,
    1033,  1037,  1046,  1055,  1061,  1065,  1074,  1078,  1082,  1086,
    1090,  1094,  1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,
    1144,  1148,  1152,  1156,  1165,  1169,  1178,  1181,  1187,  1200,
    1203,  1206,  1209,  1212,  1215,  1218,  1221,  1224,  1227,  1230,
    1233,  1236,  1239,  1242,  1245,  1248,  1251,  1254,  1257,  1260,
    1263,  1266,  1269,  1272,  1275,  1278
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GAUSSIAN_VOID", "GAUSSIAN_STRUCT",
  "GAUSSIAN_ROS_PARAMS", "GAUSSIAN_BOOL", "GAUSSIAN_BYTE",
  "GAUSSIAN_SHORT", "GAUSSIAN_INT", "GAUSSIAN_DOUBLE", "GAUSSIAN_FLOAT",
  "GAUSSIAN_LONG", "GAUSSIAN_STRING", "GAUSSIAN_VECTOR", "GAUSSIAN_MAP",
  "GAUSSIAN_NAMESPACE", "GAUSSIAN_ROS_NAMESPACE", "GAUSSIAN_INTERFACE",
  "GAUSSIAN_IDENTIFIER", "GAUSSIAN_OUT", "GAUSSIAN_OP", "GAUSSIAN_KEY",
  "GAUSSIAN_ROUTE_KEY", "GAUSSIAN_REQUIRE", "GAUSSIAN_OPTIONAL",
  "GAUSSIAN_CONST_INTEGER", "GAUSSIAN_CONST_FLOAT", "GAUSSIAN_FALSE",
  "GAUSSIAN_TRUE", "GAUSSIAN_STRING_LITERAL", "GAUSSIAN_SCOPE_DELIMITER",
  "GAUSSIAN_CONST", "GAUSSIAN_ENUM", "GAUSSIAN_UNSIGNED", "BAD_CHAR",
  "';'", "'{'", "'}'", "','", "'='", "'['", "']'", "')'", "'*'", "':'",
  "'('", "'<'", "'>'", "$accept", "start", "definitions", "$@1", "$@2",
  "definition", "enum_def", "@3", "enum_id", "enumerator_list",
  "enumerator", "namespace_def", "@4", "key_def", "$@5", "key_members",
  "interface_def", "@6", "interface_id", "interface_exports",
  "interface_export", "operation", "operation_preamble", "return_type",
  "parameters", "routekey_qualifier", "out_qualifier", "ros_params_def",
  "@7", "ros_params_id", "ros_params_exports", "ros_params_data_member",
  "ros_params_type_id", "struct_def", "@8", "struct_id", "struct_exports",
  "data_member", "struct_type_id", "const_initializer", "const_def",
  "type_id", "type", "type_no", "vector", "map", "scoped_name", "keyword", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,    59,   123,   125,    44,
      61,    91,    93,    41,    42,    58,    40,    60,    62
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -129

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     107,   -17,   394,   428,    16,   606,    -5,   516,   638,    24,
    -144,    13,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
     -10,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
      10,     9,  -144,    33,    38,    27,   205,   -33,  -144,  -144,
      37,  -144,  -144,  -144,    28,    32,    34,    35,    39,   240,
      50,   -16,  -144,   545,   574,  -144,  -144,  -144,  -144,    54,
     -27,    69,  -144,    15,    46,    82,   240,   670,   307,   341,
     273,  -144,   358,  -144,  -144,     7,  -144,    63,    74,  -144,
    -144,  -144,  -144,  -144,  -144,    78,    84,    87,  -144,  -144,
    -144,  -144,  -144,  -144,    75,    76,    79,  -144,    81,  -144,
      88,    86,  -144,    19,    99,  -144,    89,    94,  -144,   160,
     516,   516,   458,    93,    96,  -144,  -144,    95,   115,  -144,
    -144,   699,   116,   104,  -144,    54,  -144,   670,   307,  -144,
     307,  -144,  -144,     5,    85,   141,  -144,  -144,  -144,   341,
      54,    42,  -144,  -144,   516,   516,  -144,  -144,   273,  -144,
    -144,    12,    90,   106,  -144,  -144,  -144,  -144,  -144,   487,
    -144,  -144,  -144,  -144,   124,  -144,  -144,   117,   121,  -144,
     143,  -144,  -144,   516,   516,  -144,  -144,    54,    54,  -144,
    -144,  -144,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     7,    14,    16,     9,    13,    10,    32,    11,    56,
      12,    70,    15,     5,    74,   131,   129,   130,   132,   133,
     134,   135,   137,   136,   138,   139,   141,   142,   143,   144,
      72,   145,   140,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    73,    60,    58,    59,    26,    34,    35,
       0,   101,   106,   107,   109,   111,   115,   114,   113,   116,
       0,     0,   126,     0,     0,     0,   100,   104,   117,   118,
     119,    18,    19,     1,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,   127,   108,   110,   112,     0,
      95,     0,    99,     0,     0,     0,     0,    25,     0,     0,
       0,     6,     0,    28,   121,     0,   125,     0,    92,    87,
      88,    90,    91,    89,    94,     0,     0,     0,    97,   105,
     102,   103,   128,     4,    22,     0,    21,    23,     0,    44,
       0,    38,    40,     0,     0,    43,     0,    62,    64,     0,
       0,     0,     0,     0,    76,    78,    86,     0,     0,   122,
     120,     0,     0,     0,    98,     0,    17,    25,     0,    33,
       0,    55,    54,     0,     0,     0,    46,    42,    57,     0,
       0,    68,    83,    84,     0,     0,    85,    71,     0,    27,
      30,     0,     0,    93,    96,    24,    20,    37,    36,     0,
      41,    50,    48,    61,    69,    67,    66,    79,    82,    75,
       0,    29,   124,     0,     0,    47,    65,     0,     0,    31,
      51,    49,    80,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   -46,  -144,  -144,  -144,  -144,  -144,  -144,    -4,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -105,
    -144,  -144,  -144,  -144,  -144,   -35,   -34,  -144,  -144,  -144,
     -13,  -144,  -144,  -144,  -144,  -144,   -19,  -144,  -144,  -143,
    -144,    -7,   -91,  -144,  -144,  -144,   -59,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    84,    89,    11,    12,    85,    13,   135,
     136,    14,    90,    15,   158,   191,    16,    86,    17,   140,
     141,   142,   143,   144,   173,   174,   175,    18,    87,    19,
     146,   147,   148,    20,    88,    21,   153,   154,   155,   124,
      22,   149,    76,    77,    78,    79,    80,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    91,   115,   117,    53,    56,   181,    59,   159,    72,
      82,    92,   103,   104,   126,   105,   129,   145,   127,    23,
      61,    73,   195,   113,    83,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    57,    60,   204,    72,   171,
     125,   130,   172,   111,   199,    96,    97,    98,   200,    -3,
      73,   210,    95,    74,   211,   160,    94,    93,   -45,   205,
     133,   206,   -45,   197,   106,   198,   157,    99,   105,   107,
     192,   108,   109,   118,   222,   223,   110,   145,   102,   145,
     119,   120,   121,   122,   123,    73,    61,   112,   128,   131,
     125,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,   132,   161,   156,    72,  -126,   125,    -8,     1,   162,
     163,     2,     3,   164,   166,   165,    73,   168,   167,    74,
     177,   125,   170,     4,   -53,     5,   169,   178,   -53,     6,
     179,   187,   188,   189,   190,   193,   176,  -128,   212,     7,
       8,   216,    61,   182,   183,   186,   194,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,   217,   125,   125,
      72,   218,   219,   196,   213,   214,   203,   201,   202,   209,
       0,     0,    73,     0,     0,    74,     0,   207,   208,   118,
     -52,   156,     0,     0,   -52,     0,   119,   120,   121,   122,
     123,    73,   215,     0,     0,     0,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,   220,   221,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,   100,    41,     0,    42,     0,    43,
      44,    45,    46,    47,    48,    49,     0,    50,    51,    52,
      -8,     1,     0,     0,     2,     3,     0,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     4,     0,     5,     0,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    61,     0,     0,     0,    -8,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,     0,    72,     0,     0,     0,     0,   150,   151,   152,
       0,     0,     0,     0,    73,     0,     0,    74,   138,     0,
     139,   -77,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,     0,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,    74,    61,     0,     0,   -39,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,     1,
      72,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     4,    74,     5,     0,     0,   -63,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,    24,    -8,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,     0,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,    54,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    55,    41,     0,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    61,
      50,    51,    52,     0,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,     0,    72,     0,     0,
       0,     0,   184,   185,     0,     0,     0,     0,    61,    73,
       0,     0,    74,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,     0,    72,   171,     0,     0,
     172,     0,     0,     0,     0,     0,     0,    61,    73,     0,
       0,    74,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,    73,     0,     0,
      74,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,    73,     0,     0,    74,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,    74,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    58,    41,     0,    42,     0,
      43,    44,    45,    46,    47,    48,    49,     0,    50,    51,
      52,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    81,    41,     0,
      42,     0,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,   134,
      41,     0,    42,     0,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,    52,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,     0,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,    74
};

static const yytype_int16 yycheck[] =
{
       7,    60,    93,    94,     2,     3,   149,     5,     1,    19,
       8,     1,    45,    46,    41,    31,     1,   108,    45,    36,
       1,    31,   165,    39,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    19,    41,   180,    19,    20,
      99,    26,    23,    89,    39,     7,     8,     9,    43,    36,
      31,    39,    19,    34,    42,    48,    47,    47,    39,    17,
     106,    19,    43,   168,    36,   170,   112,    40,    31,    37,
     161,    37,    37,    19,   217,   218,    37,   168,    76,   170,
      26,    27,    28,    29,    30,    31,     1,    37,    19,    43,
     149,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    19,    39,   110,    19,    31,   165,     0,     1,    31,
      26,     4,     5,    26,    38,    40,    31,    36,    39,    34,
      21,   180,    36,    16,    39,    18,    38,    38,    43,    22,
      36,    38,    36,    38,    19,    19,   143,    31,    48,    32,
      33,    17,     1,   150,   151,   152,    42,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    40,   217,   218,
      19,    40,    19,   167,   199,   199,   179,   174,   175,   188,
      -1,    -1,    31,    -1,    -1,    34,    -1,   184,   185,    19,
      39,   188,    -1,    -1,    43,    -1,    26,    27,    28,    29,
      30,    31,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,   213,   214,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
       0,     1,    -1,    -1,     4,     5,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,     1,    -1,    -1,    -1,    38,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,     1,    -1,
       3,    38,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,     1,    -1,    -1,    38,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,     1,
      19,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    16,    34,    18,    -1,    -1,    38,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,     1,    38,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,     1,
      32,    33,    34,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,     1,    31,
      -1,    -1,    34,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,     1,    31,    -1,
      -1,    34,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    31,    -1,    -1,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    31,    -1,    -1,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,    16,    18,    22,    32,    33,    50,
      51,    54,    55,    57,    60,    62,    65,    67,    76,    78,
      82,    84,    89,    36,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    13,    14,    15,    16,    17,    18,
      19,    20,    22,    24,    25,    26,    27,    28,    29,    30,
      32,    33,    34,    96,     1,    19,    96,    19,    19,    96,
      41,     1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    19,    31,    34,    90,    91,    92,    93,    94,
      95,    19,    96,     0,    52,    56,    66,    77,    83,    53,
      61,    95,     1,    47,    47,    19,     7,     8,     9,    40,
      19,    44,    96,    45,    46,    31,    36,    37,    37,    37,
      37,    51,    37,    39,     1,    91,     1,    91,    19,    26,
      27,    28,    29,    30,    88,    95,    41,    45,    19,     1,
      26,    43,    19,    51,    19,    58,    59,    96,     1,     3,
      68,    69,    70,    71,    72,    91,    79,    80,    81,    90,
      24,    25,    26,    85,    86,    87,    90,    51,    63,     1,
      48,    39,    31,    26,    26,    40,    38,    39,    36,    38,
      36,    20,    23,    73,    74,    75,    90,    21,    38,    36,
      40,    88,    90,    90,    24,    25,    90,    38,    36,    38,
      19,    64,    91,    19,    42,    88,    58,    68,    68,    39,
      43,    90,    90,    79,    88,    17,    19,    90,    90,    85,
      39,    42,    48,    74,    75,    90,    17,    40,    40,    19,
      90,    90,    88,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    52,    51,    53,    51,    51,    51,    54,
      54,    54,    54,    54,    54,    54,    56,    55,    57,    57,
      58,    58,    59,    59,    59,    59,    61,    60,    63,    62,
      64,    64,    66,    65,    67,    67,    68,    68,    68,    68,
      69,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    75,    77,    76,    78,    78,
      78,    79,    79,    79,    80,    81,    81,    81,    81,    81,
      83,    82,    84,    84,    84,    85,    85,    85,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    89,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    93,    94,    94,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     0,     4,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     2,     2,
       3,     1,     1,     1,     3,     0,     0,     6,     0,     7,
       1,     3,     0,     5,     2,     2,     3,     3,     1,     0,
       1,     3,     2,     1,     1,     0,     1,     3,     2,     4,
       2,     4,     1,     1,     1,     1,     0,     5,     2,     2,
       2,     3,     1,     0,     1,     4,     3,     3,     2,     3,
       0,     5,     2,     2,     2,     3,     1,     0,     1,     3,
       5,     5,     3,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     2,     5,     3,     4,     2,
       1,     1,     3,     3,     1,     3,     1,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     4,     2,     6,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
yyparse (void)
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
        case 3:
#line 61 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1525 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 65 "./gaussian.y" /* yacc.c:1646  */
    {
    yyerrok;
}
#line 1533 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("`;' missing after definition");
}
#line 1541 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1548 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "./gaussian.y" /* yacc.c:1646  */
    {
    assert((yyvsp[0]) == 0 || std::dynamic_pointer_cast<Namespace>((yyvsp[0])));
}
#line 1556 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "./gaussian.y" /* yacc.c:1646  */
    {
    assert((yyvsp[0]) == 0 || std::dynamic_pointer_cast<Interface>((yyvsp[0])));
}
#line 1564 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 90 "./gaussian.y" /* yacc.c:1646  */
    {
    assert((yyvsp[0]) == 0 || std::dynamic_pointer_cast<RosParams>((yyvsp[0])));
}
#line 1572 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 94 "./gaussian.y" /* yacc.c:1646  */
    {
    assert((yyvsp[0]) == 0 || std::dynamic_pointer_cast<Struct>((yyvsp[0])));
}
#line 1580 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1587 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 101 "./gaussian.y" /* yacc.c:1646  */
    {
    assert((yyvsp[0]) == 0 || std::dynamic_pointer_cast<Enum>((yyvsp[0])));
}
#line 1595 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "./gaussian.y" /* yacc.c:1646  */
    {
    assert((yyvsp[0]) == 0 || std::dynamic_pointer_cast<Const>((yyvsp[0])));
}
#line 1603 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1611 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "./gaussian.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2]))
    {
        g_parse->popContainer();
        (yyval) = (yyvsp[-2]);
    }
    else
    {
        (yyval) = 0;
    }

    (yyval) = (yyvsp[-3]);
}
#line 1629 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "./gaussian.y" /* yacc.c:1646  */
    {
    NamespacePtr c = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(!c)
    {
        g_parse->error("enum must define in namespace");
    }
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    EnumPtr e = c->createEnum(ident->v);
    g_parse->pushContainer(e);

    (yyval) = e;
}
#line 1646 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 150 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    g_parse->error("keyword `" + ident->v + "' cannot be used as enumeration name");
    (yyval) = (yyvsp[0]);
}
#line 1656 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 161 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
}
#line 1664 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 165 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1671 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 173 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr type        = std::dynamic_pointer_cast<Type>(g_parse->createBuiltin(Builtin::KindLong));
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    TypeIdPtr tPtr      = std::make_shared<TypeId>(type, ident->v);
    tPtr->disableDefault();
    EnumPtr e = std::dynamic_pointer_cast<Enum>(g_parse->currentContainer());
    assert(e);
    e->addMember(tPtr);
    (yyval) = e;
}
#line 1686 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 184 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    g_parse->error("keyword `" + ident->v + "' cannot be used as enumerator");
}
#line 1695 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr type        = std::dynamic_pointer_cast<Type>(g_parse->createBuiltin(Builtin::KindLong));
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>((yyvsp[-2]));
    TypeIdPtr tPtr      = std::make_shared<TypeId>(type, ident->v);
    ConstGrammarPtr sPtr    = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[0]));
    g_parse->checkConstValue(tPtr, sPtr->t);
    tPtr->setDefault(sPtr->v);
    EnumPtr e = std::dynamic_pointer_cast<Enum>(g_parse->currentContainer());
    assert(e);
    e->addMember(tPtr);
    (yyval) = e;
}
#line 1712 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 202 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1719 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 210 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    ContainerPtr c      = g_parse->currentContainer();
    NamespacePtr n      = c->createNamespace(ident->v);
    if(n)
    {
        g_parse->pushContainer(n);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>(n);
    }
    else
    {
        (yyval) = 0;
    }
}
#line 1738 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "./gaussian.y" /* yacc.c:1646  */
    {
    if((yyvsp[-3]))
    {
        g_parse->popContainer();
        (yyval) = (yyvsp[-3]);
    }
    else
    {
        (yyval) = 0;
    }
}
#line 1754 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 243 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[-1]));
    StructPtr sp = std::dynamic_pointer_cast<Struct>(g_parse->findUserType(ident->v));
    if(!sp)
    {
        g_parse->error("struct '" + ident->v + "' undefined!");
    }

    g_parse->setKeyStruct(sp);
}
#line 1769 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 254 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1776 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 262 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    StructPtr np = g_parse->getKeyStruct();
    if(np)
    {
        np->addKey(ident->v);
    }
    else
    {
        (yyval) = 0;
    }
}
#line 1793 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 275 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    StructPtr np = g_parse->getKeyStruct();
    if(np)
    {
        np->addKey(ident->v);
    }
    else
    {
        (yyval) = 0;
    }   
}
#line 1810 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 293 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));

    NamespacePtr c = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());

    InterfacePtr cl = c->createInterface(ident->v);
    if(cl)
    {
        g_parse->pushContainer(cl);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>(cl);
    }
    else
    {
        (yyval) = 0;
    }
}
#line 1831 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 310 "./gaussian.y" /* yacc.c:1646  */
    {
    if((yyvsp[-3]))
    {
       g_parse->popContainer();
       (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-3]));
    }
    else
    {
       (yyval) = 0;
    }
}
#line 1847 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 327 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1855 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 331 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    g_parse->error("keyword `" + ident->v + "' cannot be used as interface name");
    (yyval) = (yyvsp[0]);
}
#line 1865 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 342 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1872 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 345 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1879 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 348 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("`;' missing after definition");
}
#line 1887 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 352 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1894 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 366 "./gaussian.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2]))
    {
        g_parse->popContainer();
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-2]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 1910 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 383 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr returnType = std::dynamic_pointer_cast<Type>((yyvsp[-1]));
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    string name        = ident->v;
    InterfacePtr cl    = std::dynamic_pointer_cast<Interface>(g_parse->currentContainer());
    if(cl)
    {
         OperationPtr op = cl->createOperation(name, returnType);
         if(op)
         {
             g_parse->pushContainer(op);
             (yyval) = std::dynamic_pointer_cast<GrammarBase>(op);
         }
         else
         {
             (yyval) = 0;
         }
    }
    else
    {
        (yyval) = 0;
    }
}
#line 1938 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 413 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = 0;
}
#line 1946 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 423 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 1953 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 426 "./gaussian.y" /* yacc.c:1646  */
    {
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, false, false);
    }
}
#line 1968 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 437 "./gaussian.y" /* yacc.c:1646  */
    {
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, false, false);
    }
}
#line 1983 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 448 "./gaussian.y" /* yacc.c:1646  */
    {
    BoolGrammarPtr isOutParam  = std::dynamic_pointer_cast<BoolGrammar>((yyvsp[-1]));
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, isOutParam->v, false);
    }
}
#line 1999 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 460 "./gaussian.y" /* yacc.c:1646  */
    {
    BoolGrammarPtr isOutParam  = std::dynamic_pointer_cast<BoolGrammar>((yyvsp[-1]));
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, isOutParam->v, false);
    }
}
#line 2015 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 472 "./gaussian.y" /* yacc.c:1646  */
    {
    BoolGrammarPtr isRouteKeyParam  = std::dynamic_pointer_cast<BoolGrammar>((yyvsp[-1]));
    TypeIdPtr  tsp              = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
         op->createParamDecl(tsp, false, isRouteKeyParam->v);
    }
}
#line 2031 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 484 "./gaussian.y" /* yacc.c:1646  */
    {
    BoolGrammarPtr isRouteKeyParam = std::dynamic_pointer_cast<BoolGrammar>((yyvsp[-1]));
    TypeIdPtr  tsp             = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
         op->createParamDecl(tsp, false, isRouteKeyParam->v);
    }
}
#line 2047 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 496 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("'out' must be defined with a type");
}
#line 2055 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 500 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("'routekey' must be defined with a type");
}
#line 2063 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 509 "./gaussian.y" /* yacc.c:1646  */
    {
    BoolGrammarPtr routekey = std::make_shared<BoolGrammar>();
    routekey->v = true;
    (yyval) = std::dynamic_pointer_cast<GrammarBase>(routekey);
}
#line 2073 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 520 "./gaussian.y" /* yacc.c:1646  */
    {
    BoolGrammarPtr out = std::make_shared<BoolGrammar>();
    out->v = true;
    (yyval) = std::dynamic_pointer_cast<GrammarBase>(out);
}
#line 2083 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 531 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    NamespacePtr np = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(np)
    {
         RosParamsPtr sp = np->createRosParams(ident->v);
         if(sp)
         {
             g_parse->pushContainer(sp);
             (yyval) = std::dynamic_pointer_cast<GrammarBase>(sp);
         }
         else
         {
             (yyval) = 0;
         }
    }
    else
    {
       g_parse->error("ros_params '" + ident->v + "' must definition in namespace");
    }
}
#line 2109 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 553 "./gaussian.y" /* yacc.c:1646  */
    {
    if((yyvsp[-3]))
    {
        g_parse->popContainer();
    }
    (yyval) = (yyvsp[-3]);

    RosParamsPtr st = std::dynamic_pointer_cast<RosParams>((yyval));
    assert(st);
    if(st->getAllMemberPtr().size() == 0)
    {
        g_parse->error("ros_params `" + st->getSid() + "' must have at least one member");
    }
}
#line 2128 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 573 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2136 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 577 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));

    g_parse->error("keyword `" + ident->v + "' cannot be used as ros_params name");
}
#line 2146 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 583 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("abstract declarator '<anonymous ros_params>' used as declaration");
}
#line 2154 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 592 "./gaussian.y" /* yacc.c:1646  */
    {

}
#line 2162 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 596 "./gaussian.y" /* yacc.c:1646  */
    {
   g_parse->error("';' missing after definition");
}
#line 2170 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 600 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2177 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 608 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[0]));
}
#line 2185 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 617 "./gaussian.y" /* yacc.c:1646  */
    {
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>((yyvsp[-3]));
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[-1]));
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-3]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2208 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 636 "./gaussian.y" /* yacc.c:1646  */
    {
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>((yyvsp[-2]));
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[-1]));
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-2]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2231 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 655 "./gaussian.y" /* yacc.c:1646  */
    {
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>((yyvsp[-2]));
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[-1]));
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-2]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2254 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 674 "./gaussian.y" /* yacc.c:1646  */
    {
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>((yyvsp[-1]));
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[0]));
        g_parse->checkConstValue(tPtr, sPtr->t);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-1]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2275 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 691 "./gaussian.y" /* yacc.c:1646  */
    {
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>((yyvsp[-2]));
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[0]));
        g_parse->checkConstValue(tPtr, sPtr->t);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-2]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2296 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 713 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    NamespacePtr np = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(np)
    {
         StructPtr sp = np->createStruct(ident->v);
         if(sp)
         {
             g_parse->pushContainer(sp);
             (yyval) = std::dynamic_pointer_cast<GrammarBase>(sp);
         }
         else
         {
             (yyval) = 0;
         }
    }
    else
    {
       g_parse->error("struct '" + ident->v + "' must definition in namespace");
    }
}
#line 2322 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 735 "./gaussian.y" /* yacc.c:1646  */
    {
    if((yyvsp[-3]))
    {
        g_parse->popContainer();
    }
    (yyval) = (yyvsp[-3]);

    StructPtr st = std::dynamic_pointer_cast<Struct>((yyval));
    assert(st);
    if(st->getAllMemberPtr().size() == 0)
    {
        g_parse->error("struct `" + st->getSid() + "' must have at least one member");
    }
}
#line 2341 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 755 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2349 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 759 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));

    g_parse->error("keyword `" + ident->v + "' cannot be used as struct name");
}
#line 2359 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 765 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("abstract declarator '<anonymous struct>' used as declaration");
}
#line 2367 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 774 "./gaussian.y" /* yacc.c:1646  */
    {

}
#line 2375 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 778 "./gaussian.y" /* yacc.c:1646  */
    {
   g_parse->error("';' missing after definition");
}
#line 2383 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 782 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2390 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 792 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[0]));
}
#line 2398 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 801 "./gaussian.y" /* yacc.c:1646  */
    {
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[-2]));
        g_parse->checkTag(iPtr->v);

        TypeIdPtr tPtr  = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));
        tPtr->setRequire(iPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[0]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2420 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 819 "./gaussian.y" /* yacc.c:1646  */
    {
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[-4]));
        g_parse->checkTag(iPtr->v);

        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>((yyvsp[-2]));
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[0]));
        g_parse->checkConstValue(tPtr, sPtr->t);

        tPtr->setRequire(iPtr->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-2]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2446 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 841 "./gaussian.y" /* yacc.c:1646  */
    {
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[-4]));
        g_parse->checkTag(iPtr->v);

        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>((yyvsp[-2]));
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[0]));
        g_parse->checkConstValue(tPtr, sPtr->t);

        tPtr->setOptional(iPtr->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[-2]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2472 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 863 "./gaussian.y" /* yacc.c:1646  */
    {
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[-2]));
        g_parse->checkTag(iPtr->v);
        TypeIdPtr tPtr = std::dynamic_pointer_cast<TypeId>((yyvsp[0]));
        tPtr->setOptional(iPtr->v);
        np->addTypeId(tPtr);
        (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[0]));
    }
    else
    {
        (yyval) = 0;
    }
}
#line 2493 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 880 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("struct member need 'tag'");
}
#line 2501 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 884 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("struct member need 'tag'");
}
#line 2509 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 888 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("struct member need 'require' or 'optional'");
}
#line 2517 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 892 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("struct member need 'tag' or 'require' or 'optional'");
}
#line 2525 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 901 "./gaussian.y" /* yacc.c:1646  */
    {
    IntergerGrammarPtr intVal = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[0]));
    ostringstream sstr;
    sstr << intVal->v;
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::VALUE;
    c->v = sstr.str();
    (yyval) = c;
}
#line 2539 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 911 "./gaussian.y" /* yacc.c:1646  */
    {
    FloatGrammarPtr floatVal = std::dynamic_pointer_cast<FloatGrammar>((yyvsp[0]));
    ostringstream sstr;
    sstr << floatVal->v;
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::VALUE;
    c->v = sstr.str();
    (yyval) = c;
}
#line 2553 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 921 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::STRING;
    c->v = ident->v;
    (yyval) = c;
}
#line 2565 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 929 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::BOOL;
    c->v = ident->v;
    (yyval) = c;
}
#line 2577 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 937 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::BOOL;
    c->v = ident->v;
    (yyval) = c;
}
#line 2589 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 945 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::STRING;
    c->v = ident->v;
    (yyval) = c;
}
#line 2601 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 953 "./gaussian.y" /* yacc.c:1646  */
    {

    StringGrammarPtr scoped = std::dynamic_pointer_cast<StringGrammar>((yyvsp[-2]));
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    
    if (g_parse->checkEnum(ident->v) == false)
    {
        g_parse->error("error enum default value, not defined yet");
    }
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::ENUM;
    c->v = scoped->v + "::" + ident->v;
    (yyval) = c;
}
#line 2620 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 973 "./gaussian.y" /* yacc.c:1646  */
    {
    NamespacePtr np = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(!np)
    {
        g_parse->error("const type must define in namespace");
    }

    TypeIdPtr t   = std::dynamic_pointer_cast<TypeId>((yyvsp[-2]));
    ConstGrammarPtr c = std::dynamic_pointer_cast<ConstGrammar>((yyvsp[0]));
    ConstPtr cPtr = np->createConst(t, c);
    (yyval) = cPtr;
}
#line 2637 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 991 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr type = std::dynamic_pointer_cast<Type>((yyvsp[-1]));
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));

    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);

    (yyval) = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
#line 2650 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1000 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr type = g_parse->createVector(std::dynamic_pointer_cast<Type>((yyvsp[-4])));
    IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[-1]));
    g_parse->checkArrayVaid(type,iPtrSize->v);
    type->setArray(iPtrSize->v);
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[-3]));
    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);
    (yyval) = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
#line 2664 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1010 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr type = g_parse->createVector(std::dynamic_pointer_cast<Type>((yyvsp[-2])));
    //IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>($4);
    g_parse->checkPointerVaid(type);
    type->setPointer(true);
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);
    (yyval) = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
#line 2678 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1020 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr type = std::dynamic_pointer_cast<Type>((yyvsp[-3]));
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[-2]));
    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);
    IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[-1]));
    g_parse->checkArrayVaid(type,iPtrSize->v);
    (yyval) = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
#line 2691 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1029 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    g_parse->error("keyword `" + ident->v + "' cannot be used as data member name");
}
#line 2700 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1034 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("missing data member name");
}
#line 2708 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1038 "./gaussian.y" /* yacc.c:1646  */
    {
    g_parse->error("unkown type");
}
#line 2716 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1047 "./gaussian.y" /* yacc.c:1646  */
    {

    TypePtr type = std::dynamic_pointer_cast<Type>((yyvsp[-2]));
    IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>((yyvsp[0]));
    g_parse->checkArrayVaid(type,iPtrSize->v);
    type->setArray(iPtrSize->v);
    (yyval) = type;
}
#line 2729 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1056 "./gaussian.y" /* yacc.c:1646  */
    {
    TypePtr type = std::dynamic_pointer_cast<Type>((yyvsp[-2]));
    type->setArray(100);
    (yyval) = type;
}
#line 2739 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1062 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2747 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1066 "./gaussian.y" /* yacc.c:1646  */
    {
   g_parse->error("array missing size");
}
#line 2755 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1075 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindBool);
}
#line 2763 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1079 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindByte);
}
#line 2771 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1083 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindShort,true);
}
#line 2779 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1087 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindShort);
}
#line 2787 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1091 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindInt,true);
}
#line 2795 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1095 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindInt);
}
#line 2803 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1099 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindLong,true);
}
#line 2811 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1103 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindLong);
}
#line 2819 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1107 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindFloat);
}
#line 2827 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1111 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindDouble);
}
#line 2835 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1115 "./gaussian.y" /* yacc.c:1646  */
    {
    (yyval) = g_parse->createBuiltin(Builtin::KindString);
}
#line 2843 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1119 "./gaussian.y" /* yacc.c:1646  */
    {
   (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[0]));
}
#line 2851 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1123 "./gaussian.y" /* yacc.c:1646  */
    {
   (yyval) = std::dynamic_pointer_cast<GrammarBase>((yyvsp[0]));
}
#line 2859 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1127 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    TypePtr sp = g_parse->findUserType(ident->v);
    if(sp)
    {
        (yyval) = std::dynamic_pointer_cast<GrammarBase>(sp);
    }
    else
    {
        g_parse->error("'" + ident->v + "' undefined!");
    }
}
#line 2876 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1145 "./gaussian.y" /* yacc.c:1646  */
    {
   (yyval) = std::dynamic_pointer_cast<GrammarBase>(g_parse->createVector(std::dynamic_pointer_cast<Type>((yyvsp[-1]))));
}
#line 2884 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1149 "./gaussian.y" /* yacc.c:1646  */
    {
   g_parse->error("vector error");
}
#line 2892 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1153 "./gaussian.y" /* yacc.c:1646  */
    {
   g_parse->error("vector missing '>'");
}
#line 2900 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1157 "./gaussian.y" /* yacc.c:1646  */
    {
   g_parse->error("vector missing type");
}
#line 2908 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1166 "./gaussian.y" /* yacc.c:1646  */
    {
   (yyval) = std::dynamic_pointer_cast<GrammarBase>(g_parse->createMap(std::dynamic_pointer_cast<Type>((yyvsp[-3])), std::dynamic_pointer_cast<Type>((yyvsp[-1]))));
}
#line 2916 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1170 "./gaussian.y" /* yacc.c:1646  */
    {
   g_parse->error("map error");
}
#line 2924 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1179 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2931 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1182 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    ident->v = "::" + ident->v;
    (yyval) = std::dynamic_pointer_cast<GrammarBase>(ident);
}
#line 2941 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1188 "./gaussian.y" /* yacc.c:1646  */
    {
    StringGrammarPtr scoped = std::dynamic_pointer_cast<StringGrammar>((yyvsp[-2]));
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>((yyvsp[0]));
    scoped->v += "::";
    scoped->v += ident->v;
    (yyval) = std::dynamic_pointer_cast<GrammarBase>(scoped);
}
#line 2953 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1201 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2960 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1204 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2967 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1207 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2974 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1210 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2981 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1213 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2988 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1216 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 2995 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1219 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3002 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1222 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3009 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1225 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3016 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1228 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3023 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1231 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3030 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1234 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3037 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1237 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3044 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1240 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3051 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1243 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3058 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1246 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3065 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1249 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3072 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1252 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3079 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1255 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3086 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1258 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3093 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1261 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3100 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1264 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3107 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1267 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3114 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1270 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3121 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1273 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3128 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1276 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3135 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1279 "./gaussian.y" /* yacc.c:1646  */
    {
}
#line 3142 "gaussian.tab.cpp" /* yacc.c:1646  */
    break;


#line 3146 "gaussian.tab.cpp" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 1283 "./gaussian.y" /* yacc.c:1906  */



