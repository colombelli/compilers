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



typedef struct astnode
{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);

#endif