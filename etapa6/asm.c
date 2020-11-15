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

    if (!strcmp(tac->op1->text, "TRUE")){
        fprintf(fout,   "\tmovl\t$1, %%eax\n"
                    "\tmovl\t%%eax, _%s(%%rip)\n", tac->res->text);
    }
    else if (!strcmp(tac->op1->text, "FALSE")){
        fprintf(fout,   "\tmovl\t$0, %%eax\n"
                    "\tmovl\t%%eax, _%s(%%rip)\n", tac->res->text);
    }
    else {
        fprintf(fout,   "\tmovl\t_%s(%%rip), %%eax\n"
                    "\tmovl\t%%eax, _%s(%%rip)\n", tac->op1->text, tac->res->text);
    }
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

void asm_label(TAC* tac){
    fprintf(fout, "\n.%s:\n", tac->res->text);
}

void asm_jump(TAC* tac){
    fprintf(fout, "\tjmp\t\t.%s\n", tac->res->text);
}

void asm_ifz(TAC* tac){
    fprintf(fout,   "\n## TAC_IFZ\n"
                    "\tmovl	_%s(%%rip), %%eax\n"
	                "\ttestl	%%eax, %%eax\n"
	                "\tje\t\t.%s\n", 
                    tac->op1->text, tac->res->text);
}

void asm_double_op_edx_eax(TAC* tac, char* instruction){
    fprintf(fout,   "\tmovl\t_%s(%%rip), %%edx\n"
                    "\tmovl\t_%s(%%rip), %%eax\n"
	                "\t%s\t%%edx, %%eax\n"
                    "\tmovl\t%%eax, _%s(%%rip)\n", 
                    tac->op1->text, tac->op2->text,
                    instruction, tac->res->text);
}

void asm_double_op_eax_edx(TAC* tac, char* instruction){
    fprintf(fout,   "\tmovl\t_%s(%%rip), %%eax\n"
                    "\tmovl\t_%s(%%rip), %%edx\n"
	                "\t%s\t%%edx, %%eax\n"
                    "\tmovl\t%%eax, _%s(%%rip)\n", 
                    tac->op1->text, tac->op2->text,
                    instruction, tac->res->text);
}

void asm_add(TAC* tac){
    asm_double_op_edx_eax(tac, "addl");
}

void asm_sub(TAC* tac){
    asm_double_op_eax_edx(tac, "subl");
}

void asm_mult(TAC* tac){
    asm_double_op_edx_eax(tac, "imull");
}

void asm_div(TAC* tac){
    fprintf(fout,   "\tmovl\t_%s(%%rip), %%eax\n"
	                "\tmovl\t_%s(%%rip), %%ecx\n"
	                "\tcltd\n"
	                "\tidivl\t%%ecx\n"
	                "\tmovl\t%%eax, _%s(%%rip)\n", 
                    tac->op1->text, tac->op2->text,
                    tac->res->text);
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
            case TAC_LABEL: asm_label(tac); break;
            case TAC_JUMP: asm_jump(tac); break;
            case TAC_IFZ: asm_ifz(tac); break;
            case TAC_ADD: asm_add(tac); break;
            case TAC_SUB: asm_sub(tac); break;
            case TAC_MUL: asm_mult(tac); break;
            case TAC_DIV: asm_div(tac); break;
        }
    }

    //hashtable
    print_asm(fout);

    fclose(fout);
}