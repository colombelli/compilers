#include <stdio.h>
#include "hash.h"
#include "ast.h"
#include "decompiler.h"

extern FILE *yyin;
extern AST *finalAST;
extern void initMe();
int yyparse();

int main (int argc, char **argv) {

  FILE *decompilationOutputFile;

  initMe();

  if (argc < 2){
    fprintf(stderr, "Call: etapa1 fileName\n");
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
  //hashPrint();
  fprintf(stdout, "Compilation successful!\n");
  fprintf(stdout, "Generated AST:\n\n");
  astPrint(finalAST, 0);
  fprintf(stdout, "\n\nDecompiling...\n");
  decompile(decompilationOutputFile, finalAST);
  fprintf(stdout, "Decompilation successful!\n\n");
  exit(0); //0 is CODE for SUCCESS
}