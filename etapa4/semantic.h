#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"

extern int SemanticErrors;

void check_double_dec_and_set(HASH_NODE* symbol, AST* typeSon, int value);
void check_and_set_declarations(AST* node);
void check_undeclared();
void check_operands(AST* node);
void check_artihmetic_operands(AST* node, char* operand);
int is_son_a_symbol_number(AST* son);
int is_son_a_vec_number(AST* son);
int is_son_a_foo_call_number(AST* son);
int is_number(AST* son);
int get_semantic_errors();

#endif