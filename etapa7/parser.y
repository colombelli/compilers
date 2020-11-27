%{
    #include "hash.h"
    #include "ast.h"
    #include "semantic.h"
    #include "tac.h"
    #include "asm.h"

    int yyerror();
    int getLineNumber();
    int yylex();

    int has_syntatic_error = 0;

    AST *finalAST;


    void syntax_error(char* error_message){
        fprintf(stderr, "Syntax error at line %d: %s\n", getLineNumber(), error_message);
        return;
    }

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
%token<symbol> LIT_STRING    
%token TOKEN_ERROR  

%type<ast> var_type
%type<ast> block
%type<ast> cmd
%type<ast> cmd_lst
%type<ast> flow_cmd
%type<ast> expr
%type<ast> printable
%type<ast> print_lst
%type<ast> foo_call
%type<ast> foo_call_args
%type<ast> foo_call_args_lst
%type<ast> foo_dec
%type<ast> foo_header
%type<ast> foo_header_lst
%type<ast> foo_arg
%type<ast> programa
%type<ast> dec_lst
%type<ast> dec
%type<ast> var_dec
%type<ast> vec_dec
%type<ast> vec_dec_lst
%type<ast> init_lits


%left '|'
%left '^'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '~' 
%left '+' '-'
%left '*' '/'


%%

programa: dec_lst   { 
                        $$ = $1;  finalAST = $$; 
                        
                        if (has_syntatic_error)
                            exit(3);

                        TAC* code;
                        // semantic checks
                        check_and_set_declarations($1);
                        set_expr_ast_datatype($1);
                        check_undeclared($1);
                        check_operands($1);
                        check_nature($1);
                        check_foo_call_arguments($1);
                        check_last_function_return();
                        int semanticErrors = get_semantic_errors();
                        if (semanticErrors > 0){
                            fprintf(stderr, "Semantic Errors: %d\n", semanticErrors);
                            exit(4);
                        }

                        // tac generation
                        code = generate_code($1);
                        tac_print_backwards(code);
                        
                        code = tac_reverse(code);
                        generate_asm(code);


                    }
    ;

dec_lst: dec ';' dec_lst    { $$ = astCreate(AST_DEC,0,$1,0,0,0); $$->son[1] = $3; }
    | dec error dec_lst     { $$ = 0; syntax_error("expecting ;"); }
    |                       { $$ = 0; }
    ;

dec: var_dec    { $$ = $1; }
    | foo_dec   { $$ = $1; }
    ;

var_dec: TK_IDENTIFIER '=' var_type ':' init_lits               { $$ = astCreate(AST_VAR_DEC,$1,$3,$5,0,0); }
    | TK_IDENTIFIER error var_type ':' init_lits                {$$=0; syntax_error("wrong variable declaration");}
    | TK_IDENTIFIER '=' error ':' init_lits                     {$$=0; syntax_error("unknown type for variable declaration");}
    | TK_IDENTIFIER '=' var_type error init_lits                {$$=0; syntax_error("wrong variable declaration");}
    | TK_IDENTIFIER '=' var_type '[' LIT_INTEGER ']' vec_dec    { AST* vecSizeLit = astCreate(AST_SYMBOL,$5,0,0,0,0);
                                                                  $$ = astCreate(AST_VEC_DEC,$1,$3,vecSizeLit,$7,0); }
    | TK_IDENTIFIER error var_type '[' LIT_INTEGER ']' vec_dec  {$$=0; syntax_error("wrong vector declaration");}
    | TK_IDENTIFIER '=' error '[' LIT_INTEGER ']' vec_dec       {$$=0; syntax_error("unknown type for vector declaration");}
    | TK_IDENTIFIER '=' var_type '[' error ']' vec_dec          {$$=0; syntax_error("wrong size in vector declaration");}
    ;

var_type: KW_BOOL   { $$ = astCreate(AST_TBOOL,0,0,0,0,0); }
    | KW_INT        { $$ = astCreate(AST_TINT,0,0,0,0,0); }
    | KW_FLOAT      { $$ = astCreate(AST_TFLOAT,0,0,0,0,0); }
    | KW_CHAR       { $$ = astCreate(AST_TCHAR,0,0,0,0,0); }
    ;

init_lits: LIT_CHAR     { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_FALSE         { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_TRUE          { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_FLOAT         { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | LIT_INTEGER       { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    ;

vec_dec: ':' init_lits vec_dec_lst  { $$ = astCreate(AST_VEC_INIT_VAL,0,$2,$3,0,0); }
    |                               { $$ = 0; }
    ;

vec_dec_lst: init_lits vec_dec_lst      { $$ = astCreate(AST_VEC_INIT_VAL,0,$1,$2,0,0);  }
    |                                   { $$ = 0; }
    ;

foo_dec: foo_header block       { $$ = astCreate(AST_FOO_DEC,0,$1,$2,0,0); }
    ; 

foo_header: TK_IDENTIFIER '(' ')' '=' var_type                      { $$ = astCreate(AST_FOO_DEC_HEADER,$1,$5,0,0,0); }
    | TK_IDENTIFIER '(' foo_arg foo_header_lst ')' '=' error        { $$=0; syntax_error("unknown type for funtion declaration");}
    | TK_IDENTIFIER error '=' var_type                              { $$=0; syntax_error("wrong function declaration");}
    | TK_IDENTIFIER '(' foo_arg foo_header_lst ')' '=' var_type     { $$ = astCreate(AST_FOO_DEC_HEADER,$1,$7,$3,0,0); 
                                                                      $3->son[1] = $4; }
    ;

foo_header_lst: ',' foo_arg foo_header_lst  { $$ = $2; $$->son[1] = $3; }
    |                                       { $$ = 0; }
    ;

foo_arg: TK_IDENTIFIER '=' var_type     { $$ = astCreate(AST_FOO_DEC_ARG,$1,$3,0,0,0); }
    ;

block: '{' cmd_lst '}'  { $$ = astCreate(AST_BLOCK,0,$2,0,0,0); }
    |  '{' cmd_lst error  { $$=0; syntax_error("missing }");}
    ;

cmd_lst: cmd cmd_lst    { $$ = astCreate(AST_LCMD,0,$1,$2,0,0); }
    | cmd               { $$ = astCreate(AST_LCMD,0,$1,0,0,0); }
    ;

cmd: TK_IDENTIFIER '=' expr                     { $$ = astCreate(AST_ATTR,$1,$3,0,0,0); }
    | TK_IDENTIFIER '[' expr ']' '=' expr       { $$ = astCreate(AST_VEC_ATTR,$1,$3,$6,0,0); }
    | KW_READ TK_IDENTIFIER                     { $$ = astCreate(AST_READ,$2,0,0,0,0); }
    | KW_PRINT printable print_lst              { $$ = astCreate(AST_LPRINT,0,$2,$3,0,0); }
    | KW_RETURN expr                            { $$ = astCreate(AST_RETURN,0,$2,0,0,0); }
    | flow_cmd                                  { $$ = $1; }
    | block                                     { $$ = $1; }
    |                                           { $$ = 0; }
    ;

printable: LIT_STRING   { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
    | expr              { $$ = $1; }
    ;

print_lst: ',' printable print_lst      { $$ = astCreate(AST_LPRINT,0,$2,$3,0,0); }
    |                                   { $$ = 0; }
    ;

flow_cmd: KW_IF '(' expr ')' KW_THEN cmd                            { $$ = astCreate(AST_IF,0,$3,$6,0,0); }
    | KW_IF error KW_THEN cmd                                       { $$=0; syntax_error("wrong if expression"); }
    | KW_IF '(' expr ')' KW_THEN cmd KW_ELSE cmd                    { $$ = astCreate(AST_IF_ELSE,0,$3,$6,$8,0); }
    | KW_IF error KW_THEN cmd KW_ELSE cmd                           { $$=0; syntax_error("wrong if expression"); }
    | KW_WHILE '(' expr ')' cmd                                     { $$ = astCreate(AST_WHILE,0,$3,$5,0,0); }
    | KW_WHILE '(' error ')' cmd                                    { $$=0; syntax_error("wrong expression for command while"); }
    | KW_LOOP '(' TK_IDENTIFIER ':' expr ',' expr ',' expr ')' cmd  { $$ = astCreate(AST_LOOP,$3,$5,$7,$9,$11); }
    | KW_LOOP '(' error ')' cmd  { $$=0; syntax_error("wrong expression for command loop"); }
    ;

expr: TK_IDENTIFIER                 { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }    
    | TK_IDENTIFIER '[' expr ']'    { $$ = astCreate(AST_VEC_SYMBOL,$1,$3,0,0,0); }
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
    | foo_call                      { $$ = $1; }
    ;

foo_call: TK_IDENTIFIER '(' ')'             { $$ = astCreate(AST_FOO_CALL,$1,0,0,0,0); }
    | TK_IDENTIFIER '(' foo_call_args ')'   { $$ = astCreate(AST_FOO_CALL,$1,$3,0,0,0); }
    ;

foo_call_args: expr foo_call_args_lst       { $$ = astCreate(AST_FOO_CALL_ARG,0,$1,$2,0,0); }
    ;

foo_call_args_lst: ',' expr foo_call_args_lst   { $$ = astCreate(AST_FOO_CALL_ARG,0,$2,$3,0,0); }
    |                                           { $$ = 0; }
    ;

%%

#include <stdio.h>
#include <stdlib.h>

int yyerror() {
    has_syntatic_error = 1;
    return 0;
}