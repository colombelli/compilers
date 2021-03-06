#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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