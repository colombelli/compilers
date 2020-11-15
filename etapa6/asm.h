# include "tac.h"

#ifndef ASM_HEADER
#define ASM_HEADER

void generate_asm(TAC* first);

// prints
void asm_beginfun(TAC* tac);
void asm_endfun();

#endif