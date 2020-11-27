/* A Bison parser, made by GNU Bison 3.7.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "hash.h"
    #include "ast.h"
    #include "semantic.h"
    #include "tac.h"
    #include "asm.h"

    int yyerror();
    int getLineNumber();
    int yylex();

    int has_syntatic_error = 0;

    AST *finalAST;


    void syntax_error(char* error_message){
        fprintf(stderr, "Syntax error at line %d: %s\n", getLineNumber(), error_message);
        return;
    }


#line 94 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_BOOL = 261,                 /* KW_BOOL  */
    KW_IF = 262,                   /* KW_IF  */
    KW_THEN = 263,                 /* KW_THEN  */
    KW_ELSE = 264,                 /* KW_ELSE  */
    KW_WHILE = 265,                /* KW_WHILE  */
    KW_LOOP = 266,                 /* KW_LOOP  */
    KW_READ = 267,                 /* KW_READ  */
    KW_PRINT = 268,                /* KW_PRINT  */
    KW_RETURN = 269,               /* KW_RETURN  */
    OPERATOR_LE = 270,             /* OPERATOR_LE  */
    OPERATOR_GE = 271,             /* OPERATOR_GE  */
    OPERATOR_EQ = 272,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 273,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 274,           /* TK_IDENTIFIER  */
    LIT_INTEGER = 275,             /* LIT_INTEGER  */
    LIT_FLOAT = 276,               /* LIT_FLOAT  */
    LIT_TRUE = 277,                /* LIT_TRUE  */
    LIT_FALSE = 278,               /* LIT_FALSE  */
    LIT_CHAR = 279,                /* LIT_CHAR  */
    LIT_STRING = 280,              /* LIT_STRING  */
    TOKEN_ERROR = 281              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_BOOL 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_WHILE 265
#define KW_LOOP 266
#define KW_READ 267
#define KW_PRINT 268
#define KW_RETURN 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_DIF 273
#define TK_IDENTIFIER 274
#define LIT_INTEGER 275
#define LIT_FLOAT 276
#define LIT_TRUE 277
#define LIT_FALSE 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    HASH_NODE *symbol;
    AST *ast;

#line 203 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_BOOL = 6,                    /* KW_BOOL  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_THEN = 8,                    /* KW_THEN  */
  YYSYMBOL_KW_ELSE = 9,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 10,                  /* KW_WHILE  */
  YYSYMBOL_KW_LOOP = 11,                   /* KW_LOOP  */
  YYSYMBOL_KW_READ = 12,                   /* KW_READ  */
  YYSYMBOL_KW_PRINT = 13,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 14,                 /* KW_RETURN  */
  YYSYMBOL_OPERATOR_LE = 15,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 16,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 17,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 18,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 19,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INTEGER = 20,               /* LIT_INTEGER  */
  YYSYMBOL_LIT_FLOAT = 21,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_TRUE = 22,                  /* LIT_TRUE  */
  YYSYMBOL_LIT_FALSE = 23,                 /* LIT_FALSE  */
  YYSYMBOL_LIT_CHAR = 24,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 25,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 26,               /* TOKEN_ERROR  */
  YYSYMBOL_27_ = 27,                       /* '|'  */
  YYSYMBOL_28_ = 28,                       /* '^'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '~'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* ':'  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_programa = 47,                  /* programa  */
  YYSYMBOL_dec_lst = 48,                   /* dec_lst  */
  YYSYMBOL_dec = 49,                       /* dec  */
  YYSYMBOL_var_dec = 50,                   /* var_dec  */
  YYSYMBOL_var_type = 51,                  /* var_type  */
  YYSYMBOL_init_lits = 52,                 /* init_lits  */
  YYSYMBOL_vec_dec = 53,                   /* vec_dec  */
  YYSYMBOL_vec_dec_lst = 54,               /* vec_dec_lst  */
  YYSYMBOL_foo_dec = 55,                   /* foo_dec  */
  YYSYMBOL_foo_header = 56,                /* foo_header  */
  YYSYMBOL_foo_header_lst = 57,            /* foo_header_lst  */
  YYSYMBOL_foo_arg = 58,                   /* foo_arg  */
  YYSYMBOL_block = 59,                     /* block  */
  YYSYMBOL_cmd_lst = 60,                   /* cmd_lst  */
  YYSYMBOL_cmd = 61,                       /* cmd  */
  YYSYMBOL_printable = 62,                 /* printable  */
  YYSYMBOL_print_lst = 63,                 /* print_lst  */
  YYSYMBOL_flow_cmd = 64,                  /* flow_cmd  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_foo_call = 66,                  /* foo_call  */
  YYSYMBOL_foo_call_args = 67,             /* foo_call_args  */
  YYSYMBOL_foo_call_args_lst = 68          /* foo_call_args_lst  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    34,    32,    43,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    36,
      29,    37,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,    27,    45,    31,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    92,    92,   124,   125,   126,   129,   130,   133,   134,
     135,   136,   137,   139,   140,   141,   144,   145,   146,   147,
     150,   151,   152,   153,   154,   157,   158,   161,   162,   165,
     168,   169,   170,   171,   175,   176,   179,   182,   183,   186,
     187,   190,   191,   192,   193,   194,   195,   196,   197,   200,
     201,   204,   205,   208,   209,   210,   211,   212,   213,   214,
     215,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   242,   243,   246,   249,   250
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_BOOL", "KW_IF", "KW_THEN", "KW_ELSE", "KW_WHILE",
  "KW_LOOP", "KW_READ", "KW_PRINT", "KW_RETURN", "OPERATOR_LE",
  "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_DIF", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_FLOAT", "LIT_TRUE", "LIT_FALSE", "LIT_CHAR",
  "LIT_STRING", "TOKEN_ERROR", "'|'", "'^'", "'<'", "'>'", "'~'", "'+'",
  "'-'", "'*'", "'/'", "';'", "'='", "':'", "'['", "']'", "'('", "')'",
  "','", "'{'", "'}'", "$accept", "programa", "dec_lst", "dec", "var_dec",
  "var_type", "init_lits", "vec_dec", "vec_dec_lst", "foo_dec",
  "foo_header", "foo_header_lst", "foo_arg", "block", "cmd_lst", "cmd",
  "printable", "print_lst", "flow_cmd", "expr", "foo_call",
  "foo_call_args", "foo_call_args_lst", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   124,    94,    60,
      62,   126,    43,    45,    42,    47,    59,    61,    58,    91,
      93,    40,    41,    44,   123,   125
};
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,     7,    43,   -75,    10,   -75,   -75,   -15,    81,    93,
      -9,   -75,    23,    23,    48,   -75,   -75,   -75,   -75,   -75,
      85,   -22,   -17,    12,    32,    56,    20,   -75,   -75,     8,
      59,    66,    89,   313,   326,    29,   -75,     2,    48,   -75,
     -75,   209,    96,   209,   106,   209,   209,    14,    85,    85,
     108,    86,   122,   326,     4,    13,   -75,    78,   -75,   -75,
     -75,   -75,   -75,   -75,   326,   326,    88,   343,   -75,   343,
     326,   326,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   104,   -75,   105,   -75,   -75,   109,   114,   -75,   -75,
      20,   111,    48,   186,   121,   207,   125,   126,   326,   101,
      79,   228,   313,   -75,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   343,   270,   127,   127,
     127,   127,   -75,   100,   137,   160,    48,    48,    48,   326,
     291,   -75,   123,   128,   -75,    88,    79,    79,    79,    79,
     364,   371,    79,    79,    22,    22,   -75,   -75,   132,   209,
     -75,   -75,   -75,   -75,   -75,   -75,    48,    48,   -75,   -75,
     -75,   144,   -75,   326,   -75,   -75,   -75,   326,   209,   -75,
     166,   326,   123,   343,   209,   -75,    48,   165,   -75,   -75,
     -75,   326,   249,    48,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     2,     0,     6,     7,     0,     0,     0,
       0,     1,     5,     5,    48,    29,    19,    17,    18,    16,
       0,     0,     0,     0,     0,     0,    35,     4,     3,     0,
       0,     0,     0,     0,     0,     0,    47,     0,    40,    46,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    61,    63,    64,
      66,    65,    67,    49,     0,     0,    52,    50,    82,    45,
       0,     0,    38,    37,    39,    24,    23,    22,    21,    20,
       9,     0,    10,     0,    11,     8,     0,     0,    36,    30,
      35,     0,    48,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    26,    26,
      26,    26,    34,     0,    54,     0,    48,    48,    48,     0,
       0,    83,    87,     0,    81,    52,    74,    73,    72,    75,
      79,    78,    77,    76,    68,    69,    70,    71,     0,     0,
      13,    14,    15,    12,    31,    33,    48,    48,    58,    57,
      60,     0,    62,     0,    85,    84,    51,     0,    28,    56,
      53,     0,    87,    42,    28,    25,    48,     0,    86,    27,
      55,     0,     0,    48,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,    26,   -75,   -75,    -8,   -39,    15,    11,   -75,
     -75,    94,   136,   181,   151,   -74,   103,    55,   -75,   -34,
     -75,   -75,    19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    21,   174,   150,   175,     6,
       7,    51,    26,    36,    37,    38,    66,   103,    39,    67,
      68,   133,   164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    23,    80,    72,    82,    94,    84,    85,     8,    52,
      24,    12,    40,    45,    96,    86,    41,    42,   124,    93,
      95,    43,    44,    57,    58,    59,    60,    61,    62,    14,
     100,   101,    97,    25,    87,    64,   116,   117,    27,    28,
      88,    89,     1,    11,     9,    65,    13,    73,    10,    53,
      46,    47,   158,   159,   160,    29,   114,   115,    30,    31,
      32,    33,    34,    50,   130,   132,    70,    35,    71,    48,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   169,   170,    16,    17,    18,    19,    16,    17,
      18,    19,    14,    49,    22,   161,    16,    17,    18,    19,
      54,   154,   180,    16,    17,    18,    19,    55,    56,   184,
     168,   112,   113,   114,   115,   155,    81,    98,    20,    99,
      57,    58,    59,    60,    61,    62,    83,    24,    91,   172,
      92,   102,    64,   173,   151,   152,   153,   177,   104,   105,
     106,   107,    65,   131,   118,   119,   156,   182,   123,   120,
     108,   109,   110,   111,   121,   112,   113,   114,   115,   104,
     105,   106,   107,   126,   129,   149,   163,   128,   157,   167,
     165,   108,   109,   110,   111,   176,   112,   113,   114,   115,
     104,   105,   106,   107,   122,   179,    90,   171,    15,    74,
     166,   178,   108,   109,   110,   111,     0,   112,   113,   114,
     115,   104,   105,   106,   107,   135,     0,     0,   181,     0,
       0,     0,     0,   108,   109,   110,   111,     0,   112,   113,
     114,   115,   104,   105,   106,   107,     0,     0,   125,    75,
      76,    77,    78,    79,   108,   109,   110,   111,     0,   112,
     113,   114,   115,   104,   105,   106,   107,     0,     0,   127,
       0,     0,     0,     0,     0,   108,   109,   110,   111,     0,
     112,   113,   114,   115,   104,   105,   106,   107,     0,     0,
     134,     0,     0,     0,     0,     0,   108,   109,   110,   111,
       0,   112,   113,   114,   115,   104,   105,   106,   107,     0,
       0,   183,     0,     0,     0,     0,     0,   108,   109,   110,
     111,     0,   112,   113,   114,   115,   104,   105,   106,   107,
     148,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,     0,   112,   113,   114,   115,     0,     0,     0,
       0,   162,    57,    58,    59,    60,    61,    62,    63,     0,
       0,     0,     0,     0,    64,    57,    58,    59,    60,    61,
      62,     0,     0,     0,    65,     0,     0,    64,   104,   105,
     106,   107,     0,     0,     0,     0,     0,    65,     0,     0,
     108,   109,   110,   111,     0,   112,   113,   114,   115,   104,
     105,   106,   107,     0,     0,     0,   104,   105,   106,   107,
       0,     0,   109,   110,   111,     0,   112,   113,   114,   115,
     110,   111,     0,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
      34,     9,    41,     1,    43,     1,    45,    46,     1,     1,
      19,     1,    20,     1,     1,     1,    38,    39,    92,    53,
      54,    38,    39,    19,    20,    21,    22,    23,    24,    44,
      64,    65,    19,    42,    20,    31,    70,    71,    12,    13,
      48,    49,    19,     0,    37,    41,    36,    45,    41,    41,
      38,    39,   126,   127,   128,     7,    34,    35,    10,    11,
      12,    13,    14,    43,    98,    99,    37,    19,    39,    37,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   156,   157,     3,     4,     5,     6,     3,     4,
       5,     6,    44,    37,     1,   129,     3,     4,     5,     6,
      41,     1,   176,     3,     4,     5,     6,    41,    19,   183,
     149,    32,    33,    34,    35,   123,    20,    39,    37,    41,
      19,    20,    21,    22,    23,    24,    20,    19,    42,   163,
       8,    43,    31,   167,   119,   120,   121,   171,    15,    16,
      17,    18,    41,    42,    40,    40,     9,   181,    37,    40,
      27,    28,    29,    30,    40,    32,    33,    34,    35,    15,
      16,    17,    18,    42,    38,    38,    43,    42,     8,    37,
      42,    27,    28,    29,    30,     9,    32,    33,    34,    35,
      15,    16,    17,    18,    90,   174,    50,    43,     7,    38,
     135,   172,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    15,    16,    17,    18,   102,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    15,    16,    17,    18,    -1,    -1,    42,    20,
      21,    22,    23,    24,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    15,    16,    17,    18,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    15,    16,    17,    18,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    15,    16,    17,    18,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    15,    16,    17,    18,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    31,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    41,    -1,    -1,    31,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    15,
      16,    17,    18,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    28,    29,    30,    -1,    32,    33,    34,    35,
      29,    30,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    47,    48,    49,    50,    55,    56,     1,    37,
      41,     0,     1,    36,    44,    59,     3,     4,     5,     6,
      37,    51,     1,    51,    19,    42,    58,    48,    48,     7,
      10,    11,    12,    13,    14,    19,    59,    60,    61,    64,
      51,    38,    39,    38,    39,     1,    38,    39,    37,    37,
      43,    57,     1,    41,    41,    41,    19,    19,    20,    21,
      22,    23,    24,    25,    31,    41,    62,    65,    66,    65,
      37,    39,     1,    45,    60,    20,    21,    22,    23,    24,
      52,    20,    52,    20,    52,    52,     1,    20,    51,    51,
      58,    42,     8,    65,     1,    65,     1,    19,    39,    41,
      65,    65,    43,    63,    15,    16,    17,    18,    27,    28,
      29,    30,    32,    33,    34,    35,    65,    65,    40,    40,
      40,    40,    57,    37,    61,    42,    42,    42,    42,    38,
      65,    42,    65,    67,    42,    62,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    40,    38,
      53,    53,    53,    53,     1,    51,     9,     8,    61,    61,
      61,    65,    40,    43,    68,    42,    63,    37,    52,    61,
      61,    43,    65,    65,    52,    54,     9,    65,    68,    54,
      61,    43,    65,    42,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    51,    51,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     1,     1,     5,     5,
       5,     5,     7,     7,     7,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     2,     0,     2,
       5,     7,     4,     7,     3,     0,     3,     3,     3,     2,
       1,     3,     6,     2,     3,     2,     1,     1,     0,     1,
       1,     3,     0,     6,     4,     8,     6,     5,     5,    11,
       5,     1,     4,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     3,     4,     2,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
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
  case 2: /* programa: dec_lst  */
#line 92 "parser.y"
                    { 
                        (yyval.ast) = (yyvsp[0].ast);  finalAST = (yyval.ast); 
                        
                        if (has_syntatic_error)
                            exit(3);

                        TAC* code;
                        // semantic checks
                        check_and_set_declarations((yyvsp[0].ast));
                        set_expr_ast_datatype((yyvsp[0].ast));
                        check_undeclared((yyvsp[0].ast));
                        check_operands((yyvsp[0].ast));
                        check_nature((yyvsp[0].ast));
                        check_foo_call_arguments((yyvsp[0].ast));
                        check_last_function_return();
                        int semanticErrors = get_semantic_errors();
                        if (semanticErrors > 0){
                            fprintf(stderr, "Semantic Errors: %d\n", semanticErrors);
                            exit(4);
                        }

                        // tac generation
                        code = generate_code((yyvsp[0].ast));
                        tac_print_backwards(code);
                        
                        code = tac_reverse(code);
                        generate_asm(code);


                    }
#line 1437 "y.tab.c"
    break;

  case 3: /* dec_lst: dec ';' dec_lst  */
#line 124 "parser.y"
                            { (yyval.ast) = astCreate(AST_DEC,0,(yyvsp[-2].ast),0,0,0); (yyval.ast)->son[1] = (yyvsp[0].ast); }
#line 1443 "y.tab.c"
    break;

  case 4: /* dec_lst: dec error dec_lst  */
#line 125 "parser.y"
                            { (yyval.ast) = 0; syntax_error("expecting ;"); }
#line 1449 "y.tab.c"
    break;

  case 5: /* dec_lst: %empty  */
#line 126 "parser.y"
                            { (yyval.ast) = 0; }
#line 1455 "y.tab.c"
    break;

  case 6: /* dec: var_dec  */
#line 129 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 1461 "y.tab.c"
    break;

  case 7: /* dec: foo_dec  */
#line 130 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 1467 "y.tab.c"
    break;

  case 8: /* var_dec: TK_IDENTIFIER '=' var_type ':' init_lits  */
#line 133 "parser.y"
                                                                { (yyval.ast) = astCreate(AST_VAR_DEC,(yyvsp[-4].symbol),(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1473 "y.tab.c"
    break;

  case 9: /* var_dec: TK_IDENTIFIER error var_type ':' init_lits  */
#line 134 "parser.y"
                                                                {(yyval.ast)=0; syntax_error("wrong variable declaration");}
#line 1479 "y.tab.c"
    break;

  case 10: /* var_dec: TK_IDENTIFIER '=' error ':' init_lits  */
#line 135 "parser.y"
                                                                {(yyval.ast)=0; syntax_error("unknown type for variable declaration");}
#line 1485 "y.tab.c"
    break;

  case 11: /* var_dec: TK_IDENTIFIER '=' var_type error init_lits  */
#line 136 "parser.y"
                                                                {(yyval.ast)=0; syntax_error("wrong variable declaration");}
#line 1491 "y.tab.c"
    break;

  case 12: /* var_dec: TK_IDENTIFIER '=' var_type '[' LIT_INTEGER ']' vec_dec  */
#line 137 "parser.y"
                                                                { AST* vecSizeLit = astCreate(AST_SYMBOL,(yyvsp[-2].symbol),0,0,0,0);
                                                                  (yyval.ast) = astCreate(AST_VEC_DEC,(yyvsp[-6].symbol),(yyvsp[-4].ast),vecSizeLit,(yyvsp[0].ast),0); }
#line 1498 "y.tab.c"
    break;

  case 13: /* var_dec: TK_IDENTIFIER error var_type '[' LIT_INTEGER ']' vec_dec  */
#line 139 "parser.y"
                                                                {(yyval.ast)=0; syntax_error("wrong vector declaration");}
#line 1504 "y.tab.c"
    break;

  case 14: /* var_dec: TK_IDENTIFIER '=' error '[' LIT_INTEGER ']' vec_dec  */
#line 140 "parser.y"
                                                                {(yyval.ast)=0; syntax_error("unknown type for vector declaration");}
#line 1510 "y.tab.c"
    break;

  case 15: /* var_dec: TK_IDENTIFIER '=' var_type '[' error ']' vec_dec  */
#line 141 "parser.y"
                                                                {(yyval.ast)=0; syntax_error("wrong size in vector declaration");}
#line 1516 "y.tab.c"
    break;

  case 16: /* var_type: KW_BOOL  */
#line 144 "parser.y"
                    { (yyval.ast) = astCreate(AST_TBOOL,0,0,0,0,0); }
#line 1522 "y.tab.c"
    break;

  case 17: /* var_type: KW_INT  */
#line 145 "parser.y"
                    { (yyval.ast) = astCreate(AST_TINT,0,0,0,0,0); }
#line 1528 "y.tab.c"
    break;

  case 18: /* var_type: KW_FLOAT  */
#line 146 "parser.y"
                    { (yyval.ast) = astCreate(AST_TFLOAT,0,0,0,0,0); }
#line 1534 "y.tab.c"
    break;

  case 19: /* var_type: KW_CHAR  */
#line 147 "parser.y"
                    { (yyval.ast) = astCreate(AST_TCHAR,0,0,0,0,0); }
#line 1540 "y.tab.c"
    break;

  case 20: /* init_lits: LIT_CHAR  */
#line 150 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1546 "y.tab.c"
    break;

  case 21: /* init_lits: LIT_FALSE  */
#line 151 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1552 "y.tab.c"
    break;

  case 22: /* init_lits: LIT_TRUE  */
#line 152 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1558 "y.tab.c"
    break;

  case 23: /* init_lits: LIT_FLOAT  */
#line 153 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1564 "y.tab.c"
    break;

  case 24: /* init_lits: LIT_INTEGER  */
#line 154 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1570 "y.tab.c"
    break;

  case 25: /* vec_dec: ':' init_lits vec_dec_lst  */
#line 157 "parser.y"
                                    { (yyval.ast) = astCreate(AST_VEC_INIT_VAL,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1576 "y.tab.c"
    break;

  case 26: /* vec_dec: %empty  */
#line 158 "parser.y"
                                    { (yyval.ast) = 0; }
#line 1582 "y.tab.c"
    break;

  case 27: /* vec_dec_lst: init_lits vec_dec_lst  */
#line 161 "parser.y"
                                        { (yyval.ast) = astCreate(AST_VEC_INIT_VAL,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0);  }
#line 1588 "y.tab.c"
    break;

  case 28: /* vec_dec_lst: %empty  */
#line 162 "parser.y"
                                        { (yyval.ast) = 0; }
#line 1594 "y.tab.c"
    break;

  case 29: /* foo_dec: foo_header block  */
#line 165 "parser.y"
                                { (yyval.ast) = astCreate(AST_FOO_DEC,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1600 "y.tab.c"
    break;

  case 30: /* foo_header: TK_IDENTIFIER '(' ')' '=' var_type  */
#line 168 "parser.y"
                                                                    { (yyval.ast) = astCreate(AST_FOO_DEC_HEADER,(yyvsp[-4].symbol),(yyvsp[0].ast),0,0,0); }
#line 1606 "y.tab.c"
    break;

  case 31: /* foo_header: TK_IDENTIFIER '(' foo_arg foo_header_lst ')' '=' error  */
#line 169 "parser.y"
                                                                    { (yyval.ast)=0; syntax_error("unknown type for funtion declaration");}
#line 1612 "y.tab.c"
    break;

  case 32: /* foo_header: TK_IDENTIFIER error '=' var_type  */
#line 170 "parser.y"
                                                                    { (yyval.ast)=0; syntax_error("wrong function declaration");}
#line 1618 "y.tab.c"
    break;

  case 33: /* foo_header: TK_IDENTIFIER '(' foo_arg foo_header_lst ')' '=' var_type  */
#line 171 "parser.y"
                                                                    { (yyval.ast) = astCreate(AST_FOO_DEC_HEADER,(yyvsp[-6].symbol),(yyvsp[0].ast),(yyvsp[-4].ast),0,0); 
                                                                      (yyvsp[-4].ast)->son[1] = (yyvsp[-3].ast); }
#line 1625 "y.tab.c"
    break;

  case 34: /* foo_header_lst: ',' foo_arg foo_header_lst  */
#line 175 "parser.y"
                                            { (yyval.ast) = (yyvsp[-1].ast); (yyval.ast)->son[1] = (yyvsp[0].ast); }
#line 1631 "y.tab.c"
    break;

  case 35: /* foo_header_lst: %empty  */
#line 176 "parser.y"
                                            { (yyval.ast) = 0; }
#line 1637 "y.tab.c"
    break;

  case 36: /* foo_arg: TK_IDENTIFIER '=' var_type  */
#line 179 "parser.y"
                                        { (yyval.ast) = astCreate(AST_FOO_DEC_ARG,(yyvsp[-2].symbol),(yyvsp[0].ast),0,0,0); }
#line 1643 "y.tab.c"
    break;

  case 37: /* block: '{' cmd_lst '}'  */
#line 182 "parser.y"
                        { (yyval.ast) = astCreate(AST_BLOCK,0,(yyvsp[-1].ast),0,0,0); }
#line 1649 "y.tab.c"
    break;

  case 38: /* block: '{' cmd_lst error  */
#line 183 "parser.y"
                          { (yyval.ast)=0; syntax_error("missing }");}
#line 1655 "y.tab.c"
    break;

  case 39: /* cmd_lst: cmd cmd_lst  */
#line 186 "parser.y"
                        { (yyval.ast) = astCreate(AST_LCMD,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1661 "y.tab.c"
    break;

  case 40: /* cmd_lst: cmd  */
#line 187 "parser.y"
                        { (yyval.ast) = astCreate(AST_LCMD,0,(yyvsp[0].ast),0,0,0); }
#line 1667 "y.tab.c"
    break;

  case 41: /* cmd: TK_IDENTIFIER '=' expr  */
#line 190 "parser.y"
                                                { (yyval.ast) = astCreate(AST_ATTR,(yyvsp[-2].symbol),(yyvsp[0].ast),0,0,0); }
#line 1673 "y.tab.c"
    break;

  case 42: /* cmd: TK_IDENTIFIER '[' expr ']' '=' expr  */
#line 191 "parser.y"
                                                { (yyval.ast) = astCreate(AST_VEC_ATTR,(yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0,0); }
#line 1679 "y.tab.c"
    break;

  case 43: /* cmd: KW_READ TK_IDENTIFIER  */
#line 192 "parser.y"
                                                { (yyval.ast) = astCreate(AST_READ,(yyvsp[0].symbol),0,0,0,0); }
#line 1685 "y.tab.c"
    break;

  case 44: /* cmd: KW_PRINT printable print_lst  */
#line 193 "parser.y"
                                                { (yyval.ast) = astCreate(AST_LPRINT,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1691 "y.tab.c"
    break;

  case 45: /* cmd: KW_RETURN expr  */
#line 194 "parser.y"
                                                { (yyval.ast) = astCreate(AST_RETURN,0,(yyvsp[0].ast),0,0,0); }
#line 1697 "y.tab.c"
    break;

  case 46: /* cmd: flow_cmd  */
#line 195 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1703 "y.tab.c"
    break;

  case 47: /* cmd: block  */
#line 196 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1709 "y.tab.c"
    break;

  case 48: /* cmd: %empty  */
#line 197 "parser.y"
                                                { (yyval.ast) = 0; }
#line 1715 "y.tab.c"
    break;

  case 49: /* printable: LIT_STRING  */
#line 200 "parser.y"
                        { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1721 "y.tab.c"
    break;

  case 50: /* printable: expr  */
#line 201 "parser.y"
                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1727 "y.tab.c"
    break;

  case 51: /* print_lst: ',' printable print_lst  */
#line 204 "parser.y"
                                        { (yyval.ast) = astCreate(AST_LPRINT,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1733 "y.tab.c"
    break;

  case 52: /* print_lst: %empty  */
#line 205 "parser.y"
                                        { (yyval.ast) = 0; }
#line 1739 "y.tab.c"
    break;

  case 53: /* flow_cmd: KW_IF '(' expr ')' KW_THEN cmd  */
#line 208 "parser.y"
                                                                    { (yyval.ast) = astCreate(AST_IF,0,(yyvsp[-3].ast),(yyvsp[0].ast),0,0); }
#line 1745 "y.tab.c"
    break;

  case 54: /* flow_cmd: KW_IF error KW_THEN cmd  */
#line 209 "parser.y"
                                                                    { (yyval.ast)=0; syntax_error("wrong if expression"); }
#line 1751 "y.tab.c"
    break;

  case 55: /* flow_cmd: KW_IF '(' expr ')' KW_THEN cmd KW_ELSE cmd  */
#line 210 "parser.y"
                                                                    { (yyval.ast) = astCreate(AST_IF_ELSE,0,(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0); }
#line 1757 "y.tab.c"
    break;

  case 56: /* flow_cmd: KW_IF error KW_THEN cmd KW_ELSE cmd  */
#line 211 "parser.y"
                                                                    { (yyval.ast)=0; syntax_error("wrong if expression"); }
#line 1763 "y.tab.c"
    break;

  case 57: /* flow_cmd: KW_WHILE '(' expr ')' cmd  */
#line 212 "parser.y"
                                                                    { (yyval.ast) = astCreate(AST_WHILE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1769 "y.tab.c"
    break;

  case 58: /* flow_cmd: KW_WHILE '(' error ')' cmd  */
#line 213 "parser.y"
                                                                    { (yyval.ast)=0; syntax_error("wrong expression for command while"); }
#line 1775 "y.tab.c"
    break;

  case 59: /* flow_cmd: KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr ',' expr ')' cmd  */
#line 214 "parser.y"
                                                                    { (yyval.ast) = astCreate(AST_LOOP,(yyvsp[-8].symbol),(yyvsp[-6].ast),(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 1781 "y.tab.c"
    break;

  case 60: /* flow_cmd: KW_LOOP '(' error ')' cmd  */
#line 215 "parser.y"
                                 { (yyval.ast)=0; syntax_error("wrong expression for command loop"); }
#line 1787 "y.tab.c"
    break;

  case 61: /* expr: TK_IDENTIFIER  */
#line 218 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1793 "y.tab.c"
    break;

  case 62: /* expr: TK_IDENTIFIER '[' expr ']'  */
#line 219 "parser.y"
                                    { (yyval.ast) = astCreate(AST_VEC_SYMBOL,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0); }
#line 1799 "y.tab.c"
    break;

  case 63: /* expr: LIT_INTEGER  */
#line 220 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1805 "y.tab.c"
    break;

  case 64: /* expr: LIT_FLOAT  */
#line 221 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1811 "y.tab.c"
    break;

  case 65: /* expr: LIT_FALSE  */
#line 222 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1817 "y.tab.c"
    break;

  case 66: /* expr: LIT_TRUE  */
#line 223 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1823 "y.tab.c"
    break;

  case 67: /* expr: LIT_CHAR  */
#line 224 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0); }
#line 1829 "y.tab.c"
    break;

  case 68: /* expr: expr '+' expr  */
#line 225 "parser.y"
                                    { (yyval.ast) = astCreate(AST_ADD,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1835 "y.tab.c"
    break;

  case 69: /* expr: expr '-' expr  */
#line 226 "parser.y"
                                    { (yyval.ast) = astCreate(AST_SUB,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1841 "y.tab.c"
    break;

  case 70: /* expr: expr '*' expr  */
#line 227 "parser.y"
                                    { (yyval.ast) = astCreate(AST_MUL,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1847 "y.tab.c"
    break;

  case 71: /* expr: expr '/' expr  */
#line 228 "parser.y"
                                    { (yyval.ast) = astCreate(AST_DIV,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1853 "y.tab.c"
    break;

  case 72: /* expr: expr OPERATOR_EQ expr  */
#line 229 "parser.y"
                                    { (yyval.ast) = astCreate(AST_EQ,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1859 "y.tab.c"
    break;

  case 73: /* expr: expr OPERATOR_GE expr  */
#line 230 "parser.y"
                                    { (yyval.ast) = astCreate(AST_GE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1865 "y.tab.c"
    break;

  case 74: /* expr: expr OPERATOR_LE expr  */
#line 231 "parser.y"
                                    { (yyval.ast) = astCreate(AST_LE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1871 "y.tab.c"
    break;

  case 75: /* expr: expr OPERATOR_DIF expr  */
#line 232 "parser.y"
                                    { (yyval.ast) = astCreate(AST_DIF,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1877 "y.tab.c"
    break;

  case 76: /* expr: expr '>' expr  */
#line 233 "parser.y"
                                    { (yyval.ast) = astCreate(AST_GRE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1883 "y.tab.c"
    break;

  case 77: /* expr: expr '<' expr  */
#line 234 "parser.y"
                                    { (yyval.ast) = astCreate(AST_LES,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1889 "y.tab.c"
    break;

  case 78: /* expr: expr '^' expr  */
#line 235 "parser.y"
                                    { (yyval.ast) = astCreate(AST_AND,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1895 "y.tab.c"
    break;

  case 79: /* expr: expr '|' expr  */
#line 236 "parser.y"
                                    { (yyval.ast) = astCreate(AST_OR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0); }
#line 1901 "y.tab.c"
    break;

  case 80: /* expr: '~' expr  */
#line 237 "parser.y"
                                    { (yyval.ast) = astCreate(AST_NOT,0,(yyvsp[0].ast),0,0,0); }
#line 1907 "y.tab.c"
    break;

  case 81: /* expr: '(' expr ')'  */
#line 238 "parser.y"
                                    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1913 "y.tab.c"
    break;

  case 82: /* expr: foo_call  */
#line 239 "parser.y"
                                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1919 "y.tab.c"
    break;

  case 83: /* foo_call: TK_IDENTIFIER '(' ')'  */
#line 242 "parser.y"
                                            { (yyval.ast) = astCreate(AST_FOO_CALL,(yyvsp[-2].symbol),0,0,0,0); }
#line 1925 "y.tab.c"
    break;

  case 84: /* foo_call: TK_IDENTIFIER '(' foo_call_args ')'  */
#line 243 "parser.y"
                                            { (yyval.ast) = astCreate(AST_FOO_CALL,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0); }
#line 1931 "y.tab.c"
    break;

  case 85: /* foo_call_args: expr foo_call_args_lst  */
#line 246 "parser.y"
                                            { (yyval.ast) = astCreate(AST_FOO_CALL_ARG,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1937 "y.tab.c"
    break;

  case 86: /* foo_call_args_lst: ',' expr foo_call_args_lst  */
#line 249 "parser.y"
                                                { (yyval.ast) = astCreate(AST_FOO_CALL_ARG,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0); }
#line 1943 "y.tab.c"
    break;

  case 87: /* foo_call_args_lst: %empty  */
#line 250 "parser.y"
                                                { (yyval.ast) = 0; }
#line 1949 "y.tab.c"
    break;


#line 1953 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 253 "parser.y"


#include <stdio.h>
#include <stdlib.h>

int yyerror() {
    has_syntatic_error = 1;
    return 0;
}
