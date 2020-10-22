#include <stdio.h>
#include "semantic.h"

int SemanticErrors = 0;


void check_double_dec_and_set(HASH_NODE* symbol, AST* typeSon, int value){
    if (symbol) { //double check
        if (symbol->type != SYMBOL_IDENTIFIER) {
            fprintf(stderr, "Semantic ERROR: identifier %s already declared\n", 
                symbol->text);
            ++SemanticErrors;
        }
        symbol->type = value;

        if (typeSon){
            switch (typeSon->type){
                case AST_TINT: symbol->datatype = DATATYPE_INT; break;
                case AST_TFLOAT: symbol->datatype = DATATYPE_FLOAT; break;
                case AST_TCHAR: symbol->datatype = DATATYPE_CHAR; break;
                case AST_TBOOL: symbol->datatype = DATATYPE_BOOL; break;
                default: 
                    fprintf(stderr, "Unknown declaration type for identifier %s. Please, report bug.", symbol->text);
                    exit(42);
                    break;
            }
        }
    }
    else {
        fprintf(stderr, "Compiler implementation error! node->symbol == NULL. Please, consider reporting the bug.\n");
        fprintf(stderr, "Value supposed to be used: %d", value);
        //exit(42);
    }
    return;
}


void check_and_set_declarations(AST* node){
    if (node == 0)
        return;

    int i;

    switch (node->type) {
    case AST_VAR_DEC:
        check_double_dec_and_set(node->symbol, node->son[0], SYMBOL_VARIABLE);
        break;
    
    case AST_VEC_DEC:
        check_double_dec_and_set(node->symbol, node->son[0], SYMBOL_VECTOR);
        break;
    
    case AST_FOO_DEC_HEADER:
        check_double_dec_and_set(node->symbol, node->son[0], SYMBOL_FUNCTION);
        break;
    
    default:
        break;
    }

    for (i=0; i<MAX_SONS; ++i){
        check_and_set_declarations(node->son[i]);
    }
}

void check_undeclared(){
    SemanticErrors += hash_check_undeclared();
}

int get_semantic_errors(){
    return SemanticErrors;
}