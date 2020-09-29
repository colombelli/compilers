#include "ast.h"

void getStringType(int codeType, char* typeString);
void decompileVarDec(AST* node);
void decompileVecInitVal(AST* node);
void decompileVecDec(AST* node);
void decompileFooDecArg(AST* node, int first);
void decompileFooDecHeader(AST* node);
void decompileBlock(AST* node);
void decompileFooDec(AST* node);
void decompileAttr(AST* node);
void decompileVecAttr(AST* node);
void decompileExprBinaryOp(AST* node, char* operation);
void decompileExprUnaryOp(AST* node, char* operation);
void decompileExpr(AST* node);
void decompileIf(AST* node);
void decompileIfElse(AST* node);
void decompileWhile(AST* node);
void decompileLoop(AST* node);
void decompilePrint(AST* node, int first);
void decompileRead(AST* node);
void decompileReturn(AST* node);
void decompileFooCallArg(AST* node, int first);
void decompileFooCall(AST* node);
void switchDecompilation(AST* node);
void decompileDec(AST* node);
void decompile(FILE* outFile, AST* node);
