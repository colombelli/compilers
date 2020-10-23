#include "hash.h"

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4

#define AST_SYMBOL 1

#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_EQ 6
#define AST_GE 7
#define AST_LE 8
#define AST_DIF 9
#define AST_GRE 10
#define AST_LES 11
#define AST_AND 12
#define AST_OR 13
#define AST_NOT 14

#define AST_ATTR 15
#define AST_VEC_ATTR 16
#define AST_VEC_SYMBOL 17
#define AST_LCMD 18

#define AST_IF 19
#define AST_IF_ELSE 20
#define AST_WHILE 21
#define AST_LOOP 22

#define AST_LPRINT 23
#define AST_READ 24
#define AST_RETURN 25

#define AST_FOO_CALL 26
#define AST_FOO_CALL_ARG 27
#define AST_FOO_DEC 28
#define AST_FOO_DEC_HEADER 29
#define AST_FOO_DEC_ARG 30

#define AST_BLOCK 31

#define AST_TBOOL 32
#define AST_TINT 33
#define AST_TFLOAT 34
#define AST_TCHAR 35

#define AST_DEC 36
#define AST_VAR_DEC 37
#define AST_VEC_DEC 38
#define AST_VEC_INIT_VAL 39


#define RESULT_NOT_SET 0
#define RESULT_IN_INT 1
#define RESULT_IN_FLOAT 2
#define RESULT_IN_CHAR 3
#define RESULT_IN_BOOL 4

typedef struct astnode
{
    int type;
    int datatype;  //useful to annotate resulting node type for arithmetic operands
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);

#endif