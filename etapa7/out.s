.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VARIABLES INICIALIZATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	_1(%rip), %eax
	movl	%eax, _a(%rip)
	movl	_0(%rip), %eax
	movl	%eax, _i(%rip)
	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


## TAC_BEIGNFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_PRINT
	movl	_a(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_0: .long	0
_1: .long	1
_2: .long	2
_a: .long	0
_i: .long	0
_mYWeeirT_emp0: .long	0
_10: .long	10
_TRUE: .long	1
_FALSE: .long	0
.section .rodata
