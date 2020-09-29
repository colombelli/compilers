#include "ast.h"

void getStringType(int codeType, char* typeString);
void decompileVarDec(AST* node);
void decompileVecInitVal(AST* node);
void decompileVecDec(AST* node);
void switchDecompilation(AST* node);
void decompileDec(AST* node);
void decompile(FILE* outFile, AST* node);
