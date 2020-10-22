#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"

extern int SemanticErrors;

void check_double_dec_and_set(HASH_NODE* symbol, int value);
void check_and_set_declarations(AST* node);
void check_undeclared();
int get_semantic_errors();

#endif