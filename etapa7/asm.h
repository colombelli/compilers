# include "tac.h"

#ifndef ASM_HEADER
#define ASM_HEADER

void generate_asm(TAC* first);

// prints
void asm_beginfun(TAC* tac);
void asm_endfun();
void asm_print(TAC* tac);
void asm_move(TAC* tac);
TAC* asm_decl_ini(TAC* first);

#endif