.printintstr: .string "%d"
.printstring: .string "%s"

## TAC_BEIGNFUN
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_PRINT
	movl	$5, %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax

## TAC_ENDFUN
	popq	%rbp
	ret
