


%%

int             { fprint(stderr, "Achei uma palavra reservada\n"); }
for             { fprint(stderr, "Achei uma palavra reservada\n"); }
[A-Za-z_]+      { fprint(stderr, "Identificador!\n", yytext); }
[0-9]+          { fprint(stderr, "Achei um literal decimal\n", yytext); }
"["             { fprint(stderr, "Esquerdo\n"); }
"]"             { fprint(stderr, "Direito\n"); }

[ \t\n]         {}
.               {fprint(stderr, "Erro\n"); }

!!! o maior lexema ganha
!!! quando encaixar nas duas, ganha a de cima


%%

int main(){
    yylex();
    return 0;
}


int yywrap(){
    return 1;
}