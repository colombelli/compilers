%{
    #include "hash.h"
    
%}

%union
{
    int value;
    HASH_NODE *symbol;
}

%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_BOOL

%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_LOOP
%token KW_READ
%token KW_PRINT
%token KW_RETURN

%token OPERATOR_LE
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_DIF  
%token TK_IDENTIFIER 

%token LIT_INTEGER   
%token LIT_FLOAT     
%token LIT_TRUE      
%token LIT_FALSE     
%token LIT_CHAR      
%token LIT_STRING    
%token TOKEN_ERROR  

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '|'
%left '^'
%left '~' 
%left '+' '-'
%left '*' '/'

%{
int yylex();
int yyerror();
%}

%%

programa: dec_lst
    ;

dec_lst: dec ';' dec_lst
    |
    ;

dec: var_dec
    | foo_dec
    ;

var_dec: TK_IDENTIFIER '=' var_type ':' init_lits
    | TK_IDENTIFIER '=' var_type '[' LIT_INTEGER ']' vec_def
    ;

var_type: KW_BOOL
    | KW_INT
    | KW_FLOAT
    | KW_CHAR
    ;

init_lits: LIT_CHAR
    | LIT_FALSE
    | LIT_TRUE
    | LIT_FLOAT
    | LIT_INTEGER
    ;

vec_def: ':' init_lits vec_def_lst
    |
    ;

vec_def_lst: init_lits vec_def_lst
    |
    ;

foo_dec: foo_header block
    ; 

foo_header: TK_IDENTIFIER '(' ')' '=' var_type
    | TK_IDENTIFIER '(' foo_arg foo_header_lst ')' '=' var_type
    ;

foo_header_lst: ',' foo_arg foo_header_lst
    |
    ;

foo_arg: TK_IDENTIFIER '=' var_type
    ;

block: '{' cmd_lst '}'
    ;

cmd_lst: cmd cmd_lst
    | cmd
    ;

cmd: TK_IDENTIFIER '=' expr
    | TK_IDENTIFIER '[' expr ']' '=' expr
    | KW_READ TK_IDENTIFIER
    | KW_PRINT printable print_lst
    | KW_RETURN expr
    | flow_cmd
    | block
    |
    ;

printable: LIT_STRING
    | expr
    ;

print_lst: ',' printable print_lst
    |
    ;

flow_cmd: KW_IF '(' expr ')' KW_THEN cmd
    | KW_IF '(' expr ')' KW_THEN cmd KW_ELSE cmd
    | KW_WHILE '(' expr ')' cmd
    | KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr ',' expr ')' cmd
    ;

expr: TK_IDENTIFIER
    | TK_IDENTIFIER '[' expr ']'
    | LIT_INTEGER
    | LIT_FLOAT
    | LIT_FALSE
    | LIT_TRUE
    | LIT_CHAR
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr OPERATOR_EQ expr
    | expr OPERATOR_GE expr
    | expr OPERATOR_LE expr
    | expr OPERATOR_DIF expr
    | expr '>' expr
    | expr '<' expr
    | expr '^' expr
    | expr '|' expr
    | expr '~' expr
    | '(' expr ')'
    | foo_call
    ;

foo_call: TK_IDENTIFIER '(' ')'
    | TK_IDENTIFIER '(' foo_call_args ')'
    ;

foo_call_args: expr foo_call_args_lst
    ;

foo_call_args_lst: ',' expr foo_call_args_lst
    |
    ;

%%

#include <stdio.h>
#include <stdlib.h>

int yyerror() {
    fprintf(stderr, "Syntax error at line %d \n", getLineNumber());
    exit(3);
}