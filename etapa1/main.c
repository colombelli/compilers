#include <string.h>

int main (int argc, char **argv) {
  
  char fileDest[80] = "inputs/";

  if (argc < 2){
    fprintf(stderr, "Call: etapa1 fileName\n");
    exit(1);
  }
  
  strcat(fileDest, argv[1]);
  yyin = fopen(fileDest, "r");
  if (yyin == 0){
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    exit(2);
  }
  
  int tok;
  while (Running) {
    
    tok = yylex();
    switch (tok)
    {
      case KW_CHAR ... KW_RETURN:
        printf("[Line %d] Found Keyword: %d\n", getLineNumber(), tok); break;

      case TOKEN_ERROR:
        printf("[Line %d] Error!\n", getLineNumber()); break;

      default: printf("[Line %d] Symbol %c\n", getLineNumber(), tok); break;
    }

  }



}