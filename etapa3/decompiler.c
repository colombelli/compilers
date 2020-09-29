#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "decompiler.h"


FILE* decompilationFile;


void decompileVarDec(AST* node){
    fprintf(decompilationFile, node->symbol->text);
    fprintf(decompilationFile, " = ");
    
    char varType[6];
    switch (node->son[0]->type) {
        case AST_TBOOL: strcpy(varType, "bool"); break;
        case AST_TINT: strcpy(varType, "int"); break;
        case AST_TFLOAT: strcpy(varType, "float"); break;
        case AST_TCHAR: strcpy(varType, "char"); break;
        default: fprintf(stderr, "\nDecompilation Error! Unknown variable type: %d", node->son[0]->type); break;
    }
    fprintf(decompilationFile, varType);
    fprintf(decompilationFile, " : ");
    fprintf(decompilationFile, node->son[1]->symbol->text);
    fprintf(decompilationFile, ";");
    return;
}


void switchDecompilation(AST* node){

    switch(node->type){
        case AST_DEC: fprintf(decompilationFile, "\n"); decompileDec(node); break;

        case AST_VAR_DEC: decompileVarDec(node); break;
        default: fprintf(stderr, "Error! Unknown node type!\n"); break;
    }
    return;
}


void decompileDec(AST* node){
    if (node == NULL)
        return;
    
    for (int iSon=0; iSon<4; iSon++){
        if (node->son[iSon])
            switchDecompilation(node->son[iSon]);
    }
    return;
}


void decompile(FILE* outFile, AST* node){
    if (node == NULL)
        return;
    
    decompilationFile = outFile;
    decompileDec(node);
    


/*
    switch(finalAST->type){
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
        case AST_LPRINT: fprintf(stderr, "AST_LPRINT"); break;
        case AST_READ: fprintf(stderr, "AST_READ"); break;
        case AST_RETURN: fprintf(stderr, "AST_RETURN"); break;
        case AST_FOO_CALL: fprintf(stderr, "AST_FOO_CALL"); break;
        case AST_FOO_CALL_ARG: fprintf(stderr, "AST_FOO_CALL_ARG"); break;
        case AST_FOO_DEC: fprintf(stderr, "AST_FOO_DEC"); break;
        case AST_FOO_DEC_HEADER: fprintf(stderr, "AST_FOO_DEC_HEADER"); break;
        case AST_FOO_DEC_ARG: fprintf(stderr, "AST_FOO_DEC_ARG"); break;
        case AST_BLOCK: fprintf(stderr, "AST_BLOCK"); break;
        case AST_VAR_DEC: fprintf(stderr, "AST_VAR_DEC"); break;
        case AST_VEC_DEC: fprintf(stderr, "AST_VEC_DEC"); break;
        case AST_VEC_INIT_VAL: fprintf(stderr, "AST_VEC_INIT_VAL"); break;
        default: fprintf(stderr, "AST_UNKNOWN"); break;
    }

    if (finalAST->symbol != 0)
        fprintf(stderr, ",%s\n", finalAST->symbol->text);
    else
        fprintf(stderr, ",0\n");
*/
}