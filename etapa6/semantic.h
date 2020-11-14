#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"

extern int SemanticErrors;

void compiler_error(void);

void check_double_dec_and_set(HASH_NODE* symbol, AST* typeSon, int value);
void check_and_set_declarations(AST* node);
void is_symbol_undeclared_or_out_of_scope(HASH_NODE* symbol);
void check_undeclared();
void check_operands(AST* node);

void check_numeric_compatible_operands(AST* node, char* operand);
int is_son_a_symbol_number_compatible(AST* son);
int is_son_a_vec_number_compatible(AST* son);
int is_son_a_foo_call_number_compatible(AST* son);
int is_number(AST* son);
void check_boolean_operands(AST* node, char* operand, int binary);
int is_boolean(AST* son);
int is_boolean_operand(int node_type);
int is_son_a_boolean_symbol(AST* son);
int is_son_a_boolean_vec(AST* son);
int is_son_a_boolean_foo_call(AST* son);

void check_nature(AST* node);
int match_dec_type(int datatype, char* identifier, AST* son);
void check_vec_init(char* vec_identifier, int vec_datatype, AST* vec_val_node);
int is_datatype_number_compatible(int datatype);
void match_attr_type(int datatype, char* identifier, AST* son);


void match_foo_arguments(AST* node);
void check_foo_call_arguments(AST* node);
void check_last_function_return(void);


void set_expr_ast_datatype(AST* node);
int is_a_vec_or_foo_bool(AST* node);
int is_a_vec_or_foo_float(AST* node);
int is_a_vec_or_foo_int(AST* node);
int is_a_symbol_bool(AST* node);
int is_a_symbol_float(AST* node);
int is_a_symbol_int(AST* node);

int get_semantic_errors(void);

#endif