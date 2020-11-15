.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"


## TAC_BEIGNFUN
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_PRINT
	movl	b(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax

## TAC_ENDFUN
	popq	%rbp
	ret


## DATA SECTION
a: .long	2132
b: .float	2132.5
