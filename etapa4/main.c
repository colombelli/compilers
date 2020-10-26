#include <stdio.h>
#include "hash.h"
#include "ast.h"
#include "decompiler.h"
#include "semantic.h"

extern FILE *yyin;
extern AST *finalAST;
extern void initMe();
int yyparse();

int main (int argc, char **argv) {

  FILE *decompilationOutputFile;

  initMe();

  if (argc < 2){
    fprintf(stderr, "Call: etapa4 fileName decompFileName\n");
    exit(1);
  }
  
  yyin = fopen(argv[1], "r");
  if (yyin == 0){
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    exit(2);
  }

  decompilationOutputFile = fopen(argv[2], "w");
  if (decompilationOutputFile == 0){
    fprintf(stderr, "Cannot open file %s\n", argv[2]);
    exit(2);
  }
  
  
  yyparse();
  
  
  int semanticErrors = get_semantic_errors();
  if (semanticErrors > 0)
    //exit(4);
    fprintf(stderr, "Semantic Errors: %d\n", semanticErrors);


  fprintf(stdout, "Compilation successful!\n");
  
  //hashPrint();
  astPrint(finalAST, 0);

  fprintf(stdout, "\n\nDecompiling...\n");
  decompile(decompilationOutputFile, finalAST);
  fprintf(stdout, "Decompilation successful!\n\n");
  exit(0); //0 is CODE for SUCCESS
}