#include <stdio.h>
#include "semantic.h"

int SemanticErrors = 0;


void compiler_error(){
    fprintf(stderr, "Compiler syntax analyzer implementation error! Please, consider reporting the bug.\n");
    exit(42);
}


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
        exit(42);
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


int is_son_a_symbol_number_compatible(AST* son){

    if (
        (son->type == AST_SYMBOL) && ( 
                (son->symbol->type == SYMBOL_LIT_INT) ||
                (son->symbol->type == SYMBOL_LIT_CHAR) ||
                (son->symbol->type == SYMBOL_LIT_FLOAT) || 
                (   (son->symbol->type == SYMBOL_VARIABLE) && 
                    (   (son->symbol->datatype == DATATYPE_INT) ||
                        (son->symbol->datatype == DATATYPE_CHAR) ||
                        (son->symbol->datatype == DATATYPE_FLOAT)
                    )
                ) 
        )
    ) return 1;

    else return 0;

}


int is_son_a_vec_number_compatible(AST* son){
    if ( (son->type == AST_VEC_SYMBOL) && (
                (son->symbol->datatype == DATATYPE_INT) ||
                (son->symbol->datatype == DATATYPE_CHAR) ||
                (son->symbol->datatype == DATATYPE_FLOAT)
        )
    ) return 1;

    else return 0;
}


int is_son_a_foo_call_number_compatible(AST* son){
   if ( (son->type == AST_FOO_CALL) && (
                (son->symbol->datatype == DATATYPE_INT) ||
                (son->symbol->datatype == DATATYPE_CHAR) ||
                (son->symbol->datatype == DATATYPE_FLOAT)
        )
   ) return 1;

   else return 0;
}


int is_number(AST* son){

    if ( 
        ( (son->type >= AST_ADD) && (son->type <= AST_DIV) ) || //arithmetic ops
        is_son_a_symbol_number_compatible(son) ||
        is_son_a_foo_call_number_compatible(son) ||
        is_son_a_vec_number_compatible(son)
    )   return 1;

    else return 0;
}


void check_numeric_compatible_operands(AST* node, char* operand){

    if ((node->son[0]==0) || (node->son[1]==0))
        compiler_error();


    if (!is_number(node->son[0])) {
        fprintf(stderr, "Semantic ERROR: invalid left operand for %s.\n", operand);
        ++SemanticErrors;
    }

    if (!is_number(node->son[1])) {
        fprintf(stderr, "Semantic ERROR: invalid right operand for %s.\n", operand);
        ++SemanticErrors;
    }
}


int is_boolean_operand(int node_type){

    switch (node_type) {
        case AST_EQ ... AST_NOT: return 1; break;
        default: return 0; break;
    }
}


int is_son_a_boolean_symbol(AST* son){
    
    if (
        (son->type == AST_SYMBOL) && ( 
            (son->symbol->type == SYMBOL_LIT_TRUE) ||
            (son->symbol->type == SYMBOL_LIT_FALSE) ||
            (   (son->symbol->type == SYMBOL_VARIABLE) && 
                (son->symbol->datatype == DATATYPE_BOOL)
            )
        ) 
    ) return 1;
    else return 0;
}


int is_son_a_boolean_foo_call(AST* son){
    if ( (son->type == AST_FOO_CALL) &&
         (son->symbol->datatype == DATATYPE_BOOL)
   ) return 1;
   else return 0;
}


int is_son_a_boolean_vec(AST* son){
    if ( (son->type == AST_VEC_SYMBOL) && 
         (son->symbol->datatype == DATATYPE_BOOL) 
    ) return 1;
    else return 0;
}


int is_boolean(AST* son){
    
    if (
        is_boolean_operand(son->type) ||
        is_son_a_boolean_symbol(son) ||
        is_son_a_boolean_foo_call(son) ||
        is_son_a_boolean_vec(son)
    ) return 1;

    else return 0;
}


void check_boolean_operands(AST* node, char* operand, int binary){

    if (node->son[0]==0)
        compiler_error();

    if (!is_boolean(node->son[0])) {
        fprintf(stderr, "Semantic ERROR: invalid left operand for %s.\n", operand);
        ++SemanticErrors;
    }

    if (binary) {
        if (node->son[1]==0)
            compiler_error();

        if (!is_boolean(node->son[1])) {
            fprintf(stderr, "Semantic ERROR: invalid right operand for %s.\n", operand);
            ++SemanticErrors;
        }
    }
}


void check_operands(AST* node){

    if (node == 0)
        return;

    int i;

    switch (node->type) {
        case AST_ADD:  
            check_numeric_compatible_operands(node, "addition");
            break;
        case AST_SUB:  
            check_numeric_compatible_operands(node, "subtraction");
            break;
        case AST_MUL:  
            check_numeric_compatible_operands(node, "multiplication");
            break;
        case AST_DIV:  
            check_numeric_compatible_operands(node, "division");
            break;
        case AST_EQ ... AST_LES:  
            check_numeric_compatible_operands(node, "comparsion");
            break;

        case AST_AND:
            check_boolean_operands(node, "logical and", 1);
            break;
        case AST_OR:
            check_boolean_operands(node, "logical or", 1);
            break;
        case AST_NOT:
            check_boolean_operands(node, "logical not", 0);
            break;
    }

    for (i=0; i<MAX_SONS; ++i){
        check_operands(node->son[i]);
    }
}



int is_datatype_number_compatible(int datatype){
    if (
        (datatype == DATATYPE_FLOAT) ||
        (datatype == DATATYPE_INT) ||
        (datatype == DATATYPE_CHAR)
    ) return 1;
    else return 0;
}


void match_attr_type(int datatype, char* identifier, AST* son){

    if ( 
        (is_datatype_number_compatible(datatype) && !is_number(son)) ||
        ((datatype == DATATYPE_BOOL) && !is_boolean(son))
    ) {
        fprintf(stderr, "Semantic ERROR: invalid type attribution for identifier %s!", identifier);
        ++SemanticErrors;
    }

}


void check_nature(AST* node){

    if (node == 0)
        return;

    int i;

    switch (node->type) {
        case AST_SYMBOL: 
            if (node->symbol->type == SYMBOL_VECTOR || node->symbol->type == SYMBOL_FUNCTION){
                fprintf(stderr, "Semantic ERROR: %s is not a variable!\n", node->symbol->text);
                SemanticErrors++;
            }
            break;

        case AST_VEC_SYMBOL: 
            if (node->symbol->type != SYMBOL_VECTOR){
                fprintf(stderr, "Semantic ERROR: %s is not a vector!\n", node->symbol->text);
                SemanticErrors++;
            }
            break;

        case AST_FOO_CALL: 
            if (node->symbol->type != SYMBOL_FUNCTION){
                fprintf(stderr, "Semantic ERROR: %s is not a function!\n", node->symbol->text);
                SemanticErrors++;
            }
            break;

        case AST_ATTR: 
            match_attr_type(node->symbol->datatype, node->symbol->text, node->son[0]);
            break;
        
        case AST_VEC_ATTR: 
            match_attr_type(node->symbol->datatype, node->symbol->text, node->son[1]);
            break;
    }

    for (i=0; i<MAX_SONS; ++i){
        check_nature(node->son[i]);
    }
}



