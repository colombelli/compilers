#include "hash.h"

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4  // Hardcoded. this limits funtions to have only 4 parameters

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5


typedef struct astnode
{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node);

#endif