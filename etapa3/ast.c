#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3){

    AST* newNode;
    newNode = (AST*) calloc(1, sizeof(AST));
    newNode->type = type;
    newNode->symbol = symbol;
    newNode->son[0] = s0;
    newNode->son[1] = s1;
    newNode->son[2] = s2;
    newNode->son[3] = s3;

    return newNode;
}


void astPrint(AST *node, int level){
    if (node == 0)
        return;
    
    int i;

    for (i=0; i<level; i++)
        fprintf(stderr, "  ");

    fprintf(stderr, "ast - ");
    switch(node->type){
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL"); break;
        case AST_ADD: fprintf(stderr, "AST_ADD"); break;
        case AST_SUB: fprintf(stderr, "AST_SUB"); break;
        case AST_MUL: fprintf(stderr, "AST_MUL"); break;
        case AST_DIV: fprintf(stderr, "AST_DIV"); break;
        case AST_EQ: fprintf(stderr, "AST_EQ"); break;
        case AST_GE: fprintf(stderr, "AST_GE"); break;
        case AST_LE: fprintf(stderr, "AST_LE"); break;
        case AST_DIF: fprintf(stderr, "AST_DIF"); break;
        case AST_GRE: fprintf(stderr, "AST_GRE"); break;
        case AST_LES: fprintf(stderr, "AST_LES"); break;
        case AST_AND: fprintf(stderr, "AST_AND"); break;
        case AST_OR: fprintf(stderr, "AST_OR"); break;
        case AST_NOT: fprintf(stderr, "AST_NOT"); break;
        case AST_VEC_SYMBOL: fprintf(stderr, "AST_VEC_SYMBOL"); break;
        case AST_ATTR: fprintf(stderr, "AST_ATTR"); break;
        case AST_VEC_ATTR: fprintf(stderr, "AST_VEC_ATTR"); break;
        case AST_LCMD: fprintf(stderr, "AST_LCMD"); break;
        case AST_IF: fprintf(stderr, "AST_IF"); break;
        case AST_IF_ELSE: fprintf(stderr, "AST_IF_ELSE"); break;
        case AST_WHILE: fprintf(stderr, "AST_WHILE"); break;
        case AST_LOOP: fprintf(stderr, "AST_LOOP"); break;
        default: fprintf(stderr, "AST_UNKNOWN"); break;
    }

    if (node->symbol != 0)
        fprintf(stderr, ",%s\n", node->symbol->text);
    else
        fprintf(stderr, ",0\n");

    for (i=0; i<MAX_SONS; ++i){
        astPrint(node->son[i], level+1);
    }

}


