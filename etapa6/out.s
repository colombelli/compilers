.printintstr: .string "%d"
.printfloatstr: .string "%f"
.printstring: .string "%s"

## VARIABLES INICIALIZATION
.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	_80(%rip), %eax
	movl	%eax, _a(%rip)
	movl	_1(%rip), %eax
	movl	%eax, _b(%rip)
	movl	_2(%rip), %eax
	movl	%eax, _x(%rip)
	movl	_TRUE(%rip), %eax
	movl	%eax, _bob(%rip)
	call	_main
## TAC_ENDFUN
	popq	%rbp
	ret


## TAC_BEIGNFUN
.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	_777(%rip), %eax
	movl	%eax, _b(%rip)
	movl	_mYWeeirT_emp1(%rip), %eax
	movl	%eax, _x(%rip)

## TAC_IFZ
	movl	_bob(%rip), %eax
	testl	%eax, %eax
	je		mYLabule_0
## TAC_PRINT
	movl	_a(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	jmp		mYLabule_1

.mYLabule_0:
## TAC_PRINT
	movl	_b(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax

.mYLabule_1:
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
_1: .long	1
_2: .long	2
_a: .long	0
_b: .long	0
_x: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_bob: .long	0
_99: .long	99
_80: .long	80
_777: .long	777
.section .rodata
