#include "asm.h"
#include <string.h>

FILE *fout;

void asm_beginfun(TAC* tac){
fprintf(fout, "## TAC_BEIGNFUN\n"
                ".globl	_%s\n"
                "_%s:\n"
                    "\tpushq	%%rbp\n"
                    "\tmovq	%%rsp, %%rbp\n\n", 
                    tac->res->text, tac->res->text);
}


void asm_endfun(){
    fprintf(fout, "## TAC_ENDFUN\n"
	"\tpopq	%%rbp\n"
	"\tret\n");
}


void asm_print(TAC* tac){
    fprintf(fout, "## TAC_PRINT\n"
	"\tmovl	_%s(%%rip), %%esi\n"
	"\tleaq	.printintstr(%%rip), %%rdi\n"
	"\tmovl	$0, %%eax\n"
	"\tcall	printf@PLT\n"
	"\tmovl	$0, %%eax\n", tac->res->text);
}




void asm_move(TAC* tac){
    //TODO: differentiate between types of literals for the appropriate instructions
    //TODO: test if it's a vector initilization and deal with it

    fprintf(fout,   "\tmovl\t_%s(%%rip), %%eax\n"
                    "\tmovl\t%%eax, _%s(%%rip)\n", tac->op1->text, tac->res->text);
}

TAC* asm_decl_ini(TAC* first){
    TAC* tac=first;

    fprintf(fout, "\n## VARIABLES INICIALIZATION\n"
                ".globl	main\n"
                "main:\n"
                    "\tpushq	%%rbp\n"
                    "\tmovq	%%rsp, %%rbp\n\n");

    while (tac->type == TAC_MOVE){
        asm_move(tac);
        tac=tac->next;
    }
    fprintf(fout, "\tcall\t_main\n");

    //JUMP TO _main
    asm_endfun();
    fprintf(fout, "\n\n");
    return tac;
}


void generate_asm(TAC* first){

    fout = fopen("out.s", "w");
    //init
    fprintf(fout,   ".printintstr: .string \"%%d\"\n"
                    ".printfloatstr: .string \"%%f\"\n"
                    ".printstring: .string \"%%s\"\n");


    TAC* tac = asm_decl_ini(first);
    //each tac
    for (tac; tac; tac=tac->next){
        switch(tac->type){
            case TAC_BEGINFUN: asm_beginfun(tac); break;
            case TAC_ENDFUN: asm_endfun(); break;
            case TAC_PRINT: asm_print(tac); break;
            case TAC_MOVE: asm_move(tac); break;
        }
    }

    //hashtable
    print_asm(fout);

    fclose(fout);
}