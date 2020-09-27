#include <stdio.h>
#include "hash.h"

extern FILE *yyin;
extern void initMe();
int yyparse();

int main (int argc, char **argv) {

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
  
  //hashPrint();
  yyparse();
  hashPrint();
  fprintf(stdout, "Compilation successful!\n\n");
  exit(0); //0 is CODE for SUCCESS
}