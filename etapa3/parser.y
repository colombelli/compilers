%{
    #include "hash.h"
    #include "ast.h"

    int yyerror();
    int getLineNumber();
    int yylex();
%}

%union
{
    HASH_NODE *symbol;
    AST *ast;
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
%token<symbol> TK_IDENTIFIER 

%token<symbol> LIT_INTEGER   
%token<symbol> LIT_FLOAT     
%token<symbol> LIT_TRUE      
%token<symbol> LIT_FALSE     
%token<symbol> LIT_CHAR      
%token LIT_STRING    
%token TOKEN_ERROR  

%type<ast> cmd
%type<ast> cmd_lst

%type<ast> expr

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '|'
%left '^'
%left '~' 
%left '+' '-'
%left '*' '/'


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

cmd_lst: cmd cmd_lst    { $$ = astCreate(AST_LCMD,0,$1,$2,0,0); }
    | cmd               { $$ = astCreate(AST_LCMD,0,$1,0,0,0); }
    ;

cmd: TK_IDENTIFIER '=' expr                    { astPrint($3, 0); } 
    | TK_IDENTIFIER '[' expr ']' '=' expr       
    | KW_READ TK_IDENTIFIER
    | KW_PRINT printable print_lst
    | KW_RETURN expr
    | flow_cmd
    | block
    |                                           { $$ = 0; }
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

expr: TK_IDENTIFIER                 { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }    
    | TK_IDENTIFIER '[' expr ']'    
    | LIT_INTEGER                   { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_FLOAT                     { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_FALSE                     { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_TRUE                      { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_CHAR                      { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | expr '+' expr                 { $$ = astCreate(AST_ADD,0,$1,$3,0,0); }
    | expr '-' expr                 { $$ = astCreate(AST_SUB,0,$1,$3,0,0); }
    | expr '*' expr                 { $$ = astCreate(AST_MUL,0,$1,$3,0,0); }
    | expr '/' expr                 { $$ = astCreate(AST_DIV,0,$1,$3,0,0); }
    | expr OPERATOR_EQ expr         { $$ = astCreate(AST_EQ,0,$1,$3,0,0); }
    | expr OPERATOR_GE expr         { $$ = astCreate(AST_GE,0,$1,$3,0,0); }
    | expr OPERATOR_LE expr         { $$ = astCreate(AST_LE,0,$1,$3,0,0); }
    | expr OPERATOR_DIF expr        { $$ = astCreate(AST_DIF,0,$1,$3,0,0); }
    | expr '>' expr                 { $$ = astCreate(AST_GRE,0,$1,$3,0,0); }
    | expr '<' expr                 { $$ = astCreate(AST_LES,0,$1,$3,0,0); }
    | expr '^' expr                 { $$ = astCreate(AST_AND,0,$1,$3,0,0); }
    | expr '|' expr                 { $$ = astCreate(AST_OR,0,$1,$3,0,0); }
    | '~' expr                      { $$ = astCreate(AST_NOT,0,$2,0,0,0); }
    | '(' expr ')'                  { $$ = $2; }
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