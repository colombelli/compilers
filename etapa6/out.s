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

	movl	_10(%rip), %eax
	movl	%eax, _i(%rip)

.mYLabule_0:
	movl	_i(%rip), %edx
	movl	_2(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, _mYWeeirT_emp1(%rip)

## TAC_IFZ
	movl	_mYWeeirT_emp1(%rip), %eax
	testl	%eax, %eax
	je		.mYLabule_1
	movl	_a(%rip), %edx
	movl	_i(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
	movl	_mYWeeirT_emp0(%rip), %eax
	movl	%eax, _a(%rip)
## TAC_PRINT
	movl	_i(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movl	_i(%rip), %edx
	movl	_2(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp2(%rip)
	movl	_mYWeeirT_emp2(%rip), %eax
	movl	%eax, _i(%rip)
	jmp		.mYLabule_0

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
_0: .long	0
_1: .long	1
_2: .long	2
_a: .long	0
_i: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_10: .long	10
_TRUE: .long	1
_FALSE: .long	0
.section .rodata
