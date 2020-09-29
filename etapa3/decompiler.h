#include "ast.h"

void decompileVarDec(AST* node);
void switchDecompilation(AST* node);
void decompileDec(AST* node);
void decompile(FILE* outFile, AST* node);
