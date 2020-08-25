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
        printf("[Line %d] Keyword: %s\n", getLineNumber(), yytext); break;
      
      case OPERATOR_LE ... OPERATOR_DIF:
        printf("[Line %d] Operator: %s\n", getLineNumber(), yytext); break;

      case TK_IDENTIFIER:
        printf("[Line %d] Identifier: %s\n", getLineNumber(), yytext); break;

      case LIT_INTEGER:
        printf("[Line %d] Integer: %s\n", getLineNumber(), yytext); break;
      
      case LIT_FLOAT:
        printf("[Line %d] Float: %s\n", getLineNumber(), yytext); break;
      
      case LIT_TRUE ... LIT_FALSE:
        printf("[Line %d] Boolean literal: %s\n", getLineNumber(), yytext); break;
      
      case LIT_CHAR:
        printf("[Line %d] Char: %s\n", getLineNumber(), yytext); break;
      
      case LIT_STRING:
        printf("[Line %d] String: %s\n", getLineNumber(), yytext); break;

      case TOKEN_ERROR:
        printf("[Line %d] Error! Undefined token: %s\n", getLineNumber(), yytext); break;

      default: printf("[Line %d] Symbol (ASCII %d): %c\n", getLineNumber(), yytext[0], yytext[0]); break;
    }

  }



}