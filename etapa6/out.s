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
	movl	_0(%rip), %edx
	movl	_0(%rip), %eax
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	_xx(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	_1(%rip), %edx
	movl	_1(%rip), %eax
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	_xx(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	_2(%rip), %edx
	movl	_2(%rip), %eax
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	_xx(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	_3(%rip), %edx
	movl	_3(%rip), %eax
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	_xx(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	_4(%rip), %edx
	movl	_4(%rip), %eax
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	_xx(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	$1, %eax
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

	movl	_10(%rip), %edx
	movl	_4(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp0(%rip)
	movl	_mYWeeirT_emp0(%rip), %edx
	movl	_2(%rip), %eax
	imull	%edx, %eax
	movl	%eax, _mYWeeirT_emp1(%rip)
	movl	_mYWeeirT_emp1(%rip), %eax
	movl	_1(%rip), %ecx
	cltd
	idivl	%ecx
	movl	%eax, _mYWeeirT_emp2(%rip)
	movl	_mYWeeirT_emp2(%rip), %eax
	movl	%eax, _x(%rip)

## TAC_IFZ
	movl	_bob(%rip), %eax
	testl	%eax, %eax
	je		.mYLabule_0
	movl	_2(%rip), %edx
	movl	_10(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _mYWeeirT_emp3(%rip)
## TAC_PRINT
	movl	_mYWeeirT_emp3(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	jmp		.mYLabule_1

.mYLabule_0:
## TAC_PRINT
	movl	_b(%rip), %esi
	leaq	.printintstr(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax

.mYLabule_1:
## TAC_ENDFUN
	popq	%rbp
	ret

## DATA SECTION
.data
_0: .long	0
_1: .long	1
_2: .long	2
_3: .long	3
_4: .long	4
_5: .long	5
_a: .long	0
_b: .long	0
_x: .long	0
_mYWeeirT_emp0: .long	0
_mYWeeirT_emp1: .long	0
_mYWeeirT_emp2: .long	0
_bob: .long	0
_mYWeeirT_emp3: .long	0
_10: .long	10
_xx: .zero	4000
_80: .long	80
_TRUE: .long	1
_FALSE: .long	0
.section .rodata
