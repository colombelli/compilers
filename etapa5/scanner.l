%{  
    #include "hash.h"
    #include "ast.h"
    #include "y.tab.h"
    

    int Running = 1;
    int lineNumber = 1;

    int isRunning(){
        return Running;
    }

    int getLineNumber(){
        return lineNumber;
    }

    void initMe(){
        hashInit();
    }
%}

%x COMMENT

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


    /* IGNORE WHITE SPACES AND TABS */
[ \t]   


    /* NEW LINE */
"\n"    lineNumber++;


    /* COMMENTS */
"//".*
"/*"    BEGIN(COMMENT);


    /* LITERAL BOOLEANS */
"TRUE"      { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_TRUE); return LIT_TRUE; }
"FALSE"     { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_FALSE); return LIT_FALSE; }

    /* IDENTIFIERS */
[@_a-zA-Z][@_0-9a-zA-Z]*           { yylval.symbol = hashInsert(yytext, SYMBOL_IDENTIFIER); return TK_IDENTIFIER; }

    /* LITERAL FLOATS AND INTS */
[0-9A-F]*"."[0-9A-F][0-9A-F]*      { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_FLOAT); return LIT_FLOAT; }
[0-9][0-9A-F]*                     { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_INT); return LIT_INTEGER; }

    /* LITERAL CHARS AND STRINGS */
'(\\.|[^'\n\t])'                   { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_CHAR); return LIT_CHAR; }
\"(\\.|[^"\n])*\"                  { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_STRING); return LIT_STRING; }


    /* Error (outside defined rules)*/
.       return TOKEN_ERROR;


    /* BLOCK COMMENT AUTOMATA */
<COMMENT>.
<COMMENT>"\n"   ++lineNumber;
<COMMENT>"*/" BEGIN(INITIAL);


%%


int yywrap(){
    Running = 0;
    return 1;
}

