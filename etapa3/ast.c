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


