%{  
    #include "tokens.h"
    #include "hash.c"

    int Running = 1;
    int lineNumber = 1;

    int isRunning(void) {
        return Running;
    }

    int getLineNumber(void) {
        return lineNumber;
    }

%}


%%

    /* KEYWORDS */
"char"          return KW_CHAR;
"int"           return KW_INT;
"float"         return KW_FLOAT;
"bool"          return KW_BOOL;
"if"            return KW_IF;
"then"          return KW_THEN;
"else"          return KW_ELSE;
"while"         return KW_WHILE;
"loop"          return KW_LOOP;
"read"          return KW_READ;
"print"         return KW_PRINT;
"return"        return KW_RETURN;


    /* SPECIAL CHAR */
[\,\;\:\(\)\[\]\{\}\+\-\*\/\<\>\=\|\^\~\&\$\#]      return yytext[0];


    /* COMPOUND OPERATORS */
"<="    return OPERATOR_LE;
">="    return OPERATOR_GE;
"=="    return OPERATOR_EQ;
"!="    return OPERATOR_DIF;     


    /* Ignore white spaces and tabs */
[ \t]


    /* Increase line count */
"\n"    return lineNumber++;


    /* Error (outside defined rules)*/
.       return TOKEN_ERROR;

%%

#include "main.c"


int yywrap(){
    Running = 0;
    return 1;
}