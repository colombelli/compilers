#
# UFRGS - Compiladores B - Marcelo Johann - 2020/ERE - Etapa 3
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa3: main.o lex.yy.o y.tab.o hash.o ast.o decompiler.o
	gcc main.o lex.yy.o y.tab.o hash.o ast.o decompiler.o -o etapa3

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

ast.o: ast.c
	gcc -c ast.c

decompiler.o: decompiler.c
	gcc -c decompiler.c

lex.yy.o: lex.yy.c y.tab.o
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c


y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l 
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c y.tab.h *.o etapa3
