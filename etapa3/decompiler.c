#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "decompiler.h"


FILE* decompilationFile;


void getStringType(int codeType, char* typeString){
    switch (codeType) {
        case AST_TBOOL: strcpy(typeString, "bool"); break;
        case AST_TINT: strcpy(typeString, "int"); break;
        case AST_TFLOAT: strcpy(typeString, "float"); break;
        case AST_TCHAR: strcpy(typeString, "char"); break;
        default: fprintf(stderr, "\nDecompilation Error! Unknown type: %d", codeType); break;
    }
    return;
}


void decompileVarDec(AST* node){
    fprintf(decompilationFile, node->symbol->text);
    fprintf(decompilationFile, "=");
    
    char varType[6]; 
    getStringType(node->son[0]->type, varType);
    fprintf(decompilationFile, varType);

    fprintf(decompilationFile, ":");
    fprintf(decompilationFile, node->son[1]->symbol->text);
    fprintf(decompilationFile, ";");
    return;
}

void decompileVecInitVal(AST* node){
    if (node==NULL)
        return;

    fprintf(decompilationFile, " %s", node->son[0]->symbol->text);
    decompileVecInitVal(node->son[1]);
    return;
}


void decompileVecDec(AST* node){
    fprintf(decompilationFile, node->symbol->text);
    fprintf(decompilationFile, "=");

    char vecType[6]; 
    getStringType(node->son[0]->type, vecType);
    fprintf(decompilationFile, vecType);

    fprintf(decompilationFile, "[");
    fprintf(decompilationFile, node->son[1]->symbol->text);
    fprintf(decompilationFile, "]");

    if (node->son[2]){ // Then it is being initialized
        fprintf(decompilationFile, ":");
        decompileVecInitVal(node->son[2]);
    }
    
    fprintf(decompilationFile, ";");
    return;
}


void decompileFooDecArg(AST* node, int first){
    if (node == NULL)
        return;

    if (!first){
        fprintf(decompilationFile, ", ");
    }

    fprintf(decompilationFile, node->symbol->text);
    fprintf(decompilationFile, "=");
    char argType[6]; 
    getStringType(node->son[0]->type, argType);
    fprintf(decompilationFile, argType);

    decompileFooDecArg(node->son[1], 0);
    return;
}


void decompileBlock(AST* node){
    fprintf(decompilationFile,"{");
    switchDecompilation(node->son[0]);
    fprintf(decompilationFile,"};\n");
}


void decompileFooDecHeader(AST* node){
    fprintf(decompilationFile, node->symbol->text);
    fprintf(decompilationFile, "(");
    decompileFooDecArg(node->son[1], 1);
    fprintf(decompilationFile, ")");
    fprintf(decompilationFile, "=");
    char fooType[6]; 
    getStringType(node->son[0]->type, fooType);
    fprintf(decompilationFile, fooType);
    fprintf(decompilationFile, "\n");
    return;
}


void decompileFooDec(AST* node){
    decompileFooDecHeader(node->son[0]);
    decompileBlock(node->son[1]);
    return;
}


void decompileAttr(AST* node){
    fprintf(decompilationFile, node->symbol->text);
    fprintf(decompilationFile, "=");
    switchDecompilation(node->son[0]);
    return;
}


void decompileExprBinaryOp(AST* node, char* operation){
    decompileExpr(node->son[0]);
    fprintf(decompilationFile, operation);
    decompileExpr(node->son[1]);
    return;
}


void decompileExprUnaryOp(AST* node, char* operation){
    fprintf(decompilationFile, operation);
    decompileExpr(node->son[0]);
    return;
}


void decompileExpr(AST* node){

    if (node == NULL)
        return;

    if (node->type == AST_SYMBOL)
        fprintf(decompilationFile, node->symbol->text);
        

    else {
        fprintf(decompilationFile,"(");
        switch(node->type){
            case AST_ADD: decompileExprBinaryOp(node, "+"); break;
            case AST_SUB: decompileExprBinaryOp(node, "-"); break;
            case AST_MUL: decompileExprBinaryOp(node, "*"); break;
            case AST_DIV: decompileExprBinaryOp(node, "/"); break;

            case AST_EQ: decompileExprBinaryOp(node, "=="); break;
            case AST_GE: decompileExprBinaryOp(node, ">="); break;
            case AST_LE: decompileExprBinaryOp(node, "<="); break;
            case AST_DIF: decompileExprBinaryOp(node, "!="); break;
            case AST_GRE: decompileExprBinaryOp(node, ">"); break;
            case AST_LES: decompileExprBinaryOp(node, "<"); break;
            case AST_AND: decompileExprBinaryOp(node, "^"); break;
            case AST_OR: decompileExprBinaryOp(node, "|"); break;

            case AST_NOT: decompileExprUnaryOp(node, "~"); break;
            default: fprintf(stderr, "Error! Unknown expression operator!\n"); break;
        }
        fprintf(decompilationFile,")");
    }
    return;
}


void switchDecompilation(AST* node){
    if (node == NULL)
        return;

    switch(node->type){
        case AST_DEC: fprintf(decompilationFile, "\n"); decompileDec(node); break;

        case AST_VAR_DEC: decompileVarDec(node); break;
        case AST_VEC_DEC: decompileVecDec(node); break;
        case AST_FOO_DEC: decompileFooDec(node); break;
        case AST_BLOCK: decompileBlock(node); break;
        case AST_LCMD: fprintf(decompilationFile, "\n"); switchDecompilation(node->son[0]); break;
        case AST_ATTR: decompileAttr(node); break;
        case AST_SYMBOL: fprintf(decompilationFile, node->symbol->text);
        case AST_ADD ... AST_NOT: decompileExpr(node); break;
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
}    


/*

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
        case AST_VEC_ATTR: fprintf(stderr, "AST_VEC_ATTR"); break;
        case AST_IF: fprintf(stderr, "AST_IF"); break;
        case AST_IF_ELSE: fprintf(stderr, "AST_IF_ELSE"); break;
        case AST_WHILE: fprintf(stderr, "AST_WHILE"); break;
        case AST_LOOP: fprintf(stderr, "AST_LOOP"); break;
        case AST_LPRINT: fprintf(stderr, "AST_LPRINT"); break;
        case AST_READ: fprintf(stderr, "AST_READ"); break;
        case AST_RETURN: fprintf(stderr, "AST_RETURN"); break;
        case AST_FOO_CALL: fprintf(stderr, "AST_FOO_CALL"); break;
        case AST_FOO_CALL_ARG: fprintf(stderr, "AST_FOO_CALL_ARG"); break;


*/