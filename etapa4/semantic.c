#include <stdio.h>
#include <string.h>
#include "semantic.h"
#include "stack.h"

int SemanticErrors = 0;
STACK_NODE* foo_stack = NULL;
HASH_NODE* current_foo_identifier = NULL;
int flag_return = 0;

void compiler_error(){
    fprintf(stderr, "Compiler syntax analyzer implementation error! Please, consider reporting the bug.\n");
    exit(42);
}



void check_double_dec_and_set(HASH_NODE* symbol, AST* typeSon, int value){
    if (symbol) { //double check
        if ((symbol->type != SYMBOL_IDENTIFIER) && (symbol->type != SYMBOL_OUT_OF_SCOPE)) {

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



void check_and_set_declarations(AST* node){ //AND RETURN FOO VALUE
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
    }

    for (i=0; i<MAX_SONS; ++i){
        check_and_set_declarations(node->son[i]);
    }
}


void is_symbol_undeclared_or_out_of_scope(HASH_NODE* symbol){
    if (symbol->type == SYMBOL_IDENTIFIER){
        fprintf(stderr, "Semantic ERROR: Undeclared identifier '%s'\n", symbol->text);
        ++SemanticErrors;
    }
    else if (symbol->type == SYMBOL_OUT_OF_SCOPE){
        fprintf(stderr, "Semantic ERROR: Parameter '%s' doesn't belong to this function scope, undeclared identifier.\n", symbol->text);
        ++SemanticErrors;
    }
    return;   
}


void check_undeclared(AST* node){
    if (node == 0)
        return;

    int i;

    switch (node->type){
        case AST_FOO_DEC_HEADER:
            if (!flag_return && current_foo_identifier){
                fprintf(stderr, "Semantic ERROR: function '%s' doesn't have a return command\n", 
                    current_foo_identifier->text);
                ++SemanticErrors;
            }

            current_foo_identifier = node->symbol;
            pop_all_nodes(foo_stack);
            foo_stack = NULL;
            flag_return = 0;
            break;
        
        case AST_FOO_DEC_ARG:
            insert_symbol_arg(current_foo_identifier, node->symbol);
            check_double_dec_and_set(node->symbol, node->son[0], SYMBOL_PARAMETER);
            foo_stack = push_node(foo_stack, node->symbol);
            break;

        case AST_RETURN:
            flag_return = 1;

            if (is_datatype_number_compatible(current_foo_identifier->datatype) &&
                !is_number(node->son[0])){
                    fprintf(stderr, "Semantic ERROR: function '%s' must return a number compatible result\n",
                            current_foo_identifier->text);
                    ++SemanticErrors;
                }

            if ((current_foo_identifier->datatype == DATATYPE_BOOL) &&
                !is_boolean(node->son[0])){
                    fprintf(stderr, "Semantic ERROR: function '%s' must return a boolean compatible result\n",
                            current_foo_identifier->text);
                    ++SemanticErrors;
                }
            break;
        
        default:
            if (node->symbol)
                    is_symbol_undeclared_or_out_of_scope(node->symbol);
            break;
    }

    for (i=0; i<MAX_SONS; ++i){
        check_undeclared(node->son[i]);
    }
}

void check_last_function_return(){
    if (!flag_return && current_foo_identifier){
        fprintf(stderr, "Semantic ERROR: function '%s' doesn't have a return command\n", 
            current_foo_identifier->text);
        ++SemanticErrors;
    }
    return;
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
                (   ((son->symbol->type == SYMBOL_VARIABLE) ||
                     (son->symbol->type == SYMBOL_PARAMETER)) && 
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
        fprintf(stderr, "Semantic ERROR: invalid left operand for '%s'\n", operand);
        ++SemanticErrors;
    }

    if (!is_number(node->son[1])) {
        fprintf(stderr, "Semantic ERROR: invalid right operand for '%s'\n", operand);
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
            (   ((son->symbol->type == SYMBOL_VARIABLE) ||
                (son->symbol->type == SYMBOL_PARAMETER)) 
                && 
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
        fprintf(stderr, "Semantic ERROR: invalid left operand for '%s'\n", operand);
        ++SemanticErrors;
    }

    if (binary) {
        if (node->son[1]==0)
            compiler_error();

        if (!is_boolean(node->son[1])) {
            fprintf(stderr, "Semantic ERROR: invalid right operand for '%s'\n", operand);
            ++SemanticErrors;
        }
    }
}


int is_a_symbol_int(AST* node){
    if (
        (node->type == AST_SYMBOL) && ( 
                (node->symbol->type == SYMBOL_LIT_INT) ||
                (node->symbol->type == SYMBOL_LIT_CHAR) ||
                (   ((node->symbol->type == SYMBOL_VARIABLE) ||
                     (node->symbol->type == SYMBOL_PARAMETER)) && 
                    (   (node->symbol->datatype == DATATYPE_INT) ||
                        (node->symbol->datatype == DATATYPE_CHAR)
                    )
                ) 
        )
    ) return 1;
    else return 0;
}

int is_a_symbol_float(AST* node){
    if (
        (node->type == AST_SYMBOL) && ( 
                (node->symbol->type == SYMBOL_LIT_FLOAT) ||
                (   ((node->symbol->type == SYMBOL_VARIABLE) ||
                     (node->symbol->type == SYMBOL_PARAMETER)) && 
                    (   (node->symbol->datatype == DATATYPE_FLOAT)
                    )
                ) 
        )
    ) return 1;
    else return 0;
}

int is_a_symbol_bool(AST* node){
    if (
        (node->type == AST_SYMBOL) && ( 
                (node->symbol->type == SYMBOL_LIT_FALSE) ||
                (node->symbol->type == SYMBOL_LIT_TRUE) ||
                (   ((node->symbol->type == SYMBOL_VARIABLE) ||
                     (node->symbol->type == SYMBOL_PARAMETER)) && 
                    (   (node->symbol->datatype == DATATYPE_BOOL)
                    )
                ) 
        )
    ) return 1;
    else return 0;
}


int is_a_vec_or_foo_int(AST* node){
    if ( ((node->type == AST_VEC_SYMBOL) ||
         (node->type == AST_FOO_CALL)) && (
            (node->symbol->datatype == DATATYPE_INT) ||
            (node->symbol->datatype == DATATYPE_CHAR)
        )
    ) return 1;
    else return 0;
}

int is_a_vec_or_foo_float(AST* node){
    if ( ((node->type == AST_VEC_SYMBOL) ||
         (node->type == AST_FOO_CALL)) && 
        (node->symbol->datatype == DATATYPE_FLOAT)
    ) return 1;
    else return 0;
}

int is_a_vec_or_foo_bool(AST* node){
    if ( ((node->type == AST_VEC_SYMBOL) ||
         (node->type == AST_FOO_CALL)) && 
        (node->symbol->datatype == DATATYPE_BOOL)
    ) return 1;
    else return 0;
}


void set_expr_ast_datatype(AST* node){

    if (!node)
        return;

    if (node->son[0] && node->son[0]->datatype == RESULT_NOT_SET)
        set_expr_ast_datatype(node->son[0]);  //recursion to the left
    if (node->son[1] && node->son[1]->datatype == RESULT_NOT_SET)
        set_expr_ast_datatype(node->son[1]);  //recursion to the right

    switch (node->type){
    case AST_SYMBOL:
        if (is_a_symbol_int(node))
            node->datatype = RESULTS_IN_INT;
        else if (is_a_symbol_float(node))
            node->datatype = RESULTS_IN_FLOAT;
        else if (is_a_symbol_bool(node))
            node->datatype = RESULTS_IN_BOOL;
        else if (node->symbol->type == SYMBOL_LIT_STRING)
            break;
        //else 
            //compiler_error();
        break;
    
    case AST_VEC_SYMBOL:
    case AST_FOO_CALL:
        if (is_a_vec_or_foo_int(node))
            node->datatype = RESULTS_IN_INT;
        else if (is_a_vec_or_foo_float(node))
            node->datatype = RESULTS_IN_FLOAT;
        else if (is_a_vec_or_foo_bool(node))
            node->datatype = RESULTS_IN_BOOL;
        //else        
            //compiler_error();
        break;

    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
        if ((node->son[0]->datatype == RESULTS_IN_INT) &&
            (node->son[1]->datatype == RESULTS_IN_INT))
            node->datatype = RESULTS_IN_INT;

        else if ((node->son[0]->datatype == RESULTS_IN_FLOAT) &&
                ((node->son[1]->datatype == RESULTS_IN_INT) ||
                (node->son[1]->datatype == RESULTS_IN_FLOAT)))
            node->datatype = RESULTS_IN_FLOAT;
        
        else if ((node->son[0]->datatype == RESULTS_IN_INT) &&
                (node->son[1]->datatype == RESULTS_IN_FLOAT))
            node->datatype = RESULTS_IN_FLOAT;
        
        else
            node->datatype = RESULTS_IN_UNDEFINED; //compiler error?
        break;
    
    default:
        node->datatype = RESULTS_IN_UNDEFINED; //to avoid recursion loop
        break;
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
        fprintf(stderr, "Semantic ERROR: invalid type attribution for identifier '%s'\n", identifier);
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
                fprintf(stderr, "Semantic ERROR: '%s' is not a variable!\n", node->symbol->text);
                SemanticErrors++;
            }
            break;

        case AST_VEC_SYMBOL: 
            if (node->symbol->type != SYMBOL_VECTOR){
                fprintf(stderr, "Semantic ERROR: '%s' is not a vector!\n", node->symbol->text);
                SemanticErrors++;
            }
            else if (node->son[0]->datatype != RESULTS_IN_INT) {
                fprintf(stderr, "Semantic ERROR: vector '%s' index must be an integer resulting expression\n", node->symbol->text);
                ++SemanticErrors;
            }
            break;

        case AST_FOO_CALL: 
            if (node->symbol->type != SYMBOL_FUNCTION){
                fprintf(stderr, "Semantic ERROR: '%s' is not a function!\n", node->symbol->text);
                SemanticErrors++;
            }
            break;

        case AST_ATTR: 
            if (node->symbol->type != SYMBOL_VARIABLE){
                fprintf(stderr, "Semantic ERROR: identifier '%s' is not a variable\n", node->symbol->text);
                ++SemanticErrors;
            } else
                match_attr_type(node->symbol->datatype, node->symbol->text, node->son[0]);
            break;
        
        case AST_VEC_ATTR: 
            if (node->symbol->type != SYMBOL_VECTOR){
                fprintf(stderr, "Semantic ERROR: identifier '%s' is not a vector\n", node->symbol->text);
                ++SemanticErrors;
            } 
            else if (node->son[0]->datatype != RESULTS_IN_INT) {
                fprintf(stderr, "Semantic ERROR: vector '%s' index must be an integer resulting expression\n", node->symbol->text);
                ++SemanticErrors;
            }
            else
                match_attr_type(node->symbol->datatype, node->symbol->text, node->son[1]);
            break;
    }

    for (i=0; i<MAX_SONS; ++i){
        check_nature(node->son[i]);
    }
}


void match_foo_arguments(AST* node){
    ARGS* foo_argument = current_foo_identifier->foo_args;
    AST* iter_node = node;

    if (!node && foo_argument){
        fprintf(stderr, "Semantic ERROR: function '%s' must receive its arguments\n", current_foo_identifier->text);
        ++SemanticErrors;
        return;
    }


    if (node && (node->type != AST_FOO_CALL_ARG) && foo_argument){ //it is being called without arguments
        fprintf(stderr, "Semantic ERROR: must provide arguments for function '%s'\n", current_foo_identifier->text);
        ++SemanticErrors;
        return;
    }


    while(foo_argument){
        if  (!iter_node){
            fprintf(stderr, "Semantic ERROR: must provide argument '%s' for function '%s'\n", 
                foo_argument->arg->text, current_foo_identifier->text);
            ++SemanticErrors;
            foo_argument= foo_argument->next;
        } 
        else {
            if (iter_node->type != AST_FOO_CALL_ARG){
                fprintf(stderr, "Semantic ERROR: must provide argument '%s' for function '%s'\n", 
                    foo_argument->arg->text, current_foo_identifier->text);
                ++SemanticErrors;
            }
            else{
                //check son[0] type against expected parameter type
                if (is_datatype_number_compatible(foo_argument->arg->datatype) && !is_number(iter_node->son[0])){
                    fprintf(stderr, "Semantic ERROR: expected a number compatible parameter for argument '%s'\n", 
                            foo_argument->arg->text);
                    ++SemanticErrors;
                }
                else if ((foo_argument->arg->datatype == DATATYPE_BOOL) && !is_boolean(iter_node->son[0])){
                    fprintf(stderr, "Semantic ERROR: expected a boolean compatible parameter for argument '%s'\n", 
                            foo_argument->arg->text);
                    ++SemanticErrors;
                }
            }
            foo_argument = foo_argument->next;
            iter_node = iter_node->son[1];
        }
    }

    if (iter_node && (iter_node->type == AST_FOO_CALL_ARG)){
        fprintf(stderr, "Semantic ERROR: too many arguments for function '%s'\n", current_foo_identifier->text);
        ++SemanticErrors;
    }
    return;
}


void check_foo_call_arguments(AST* node){

    if (node == 0)
        return;
    int i;

    if (node->type == AST_FOO_CALL) {
        current_foo_identifier = node->symbol;
        match_foo_arguments(node->son[0]);
    }

    for (i=0; i<MAX_SONS; ++i){
        check_foo_call_arguments(node->son[i]);
    }    
}

