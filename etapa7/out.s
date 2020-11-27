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

	movl	_1(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_2(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_3(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_4(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_5(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_6(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_7(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_8(%rip), %eax
	movl	%eax, _i(%rip)
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
	movl	_9(%rip), %eax
	movl	%eax, _i(%rip)
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
_3: .long	3
_4: .long	4
_5: .long	5
_6: .long	6
_7: .long	7
_8: .long	8
_9: .long	9
_a: .long	0
_i: .long	0
_mYWeeirT_emp0: .long	0
_10: .long	10
_TRUE: .long	1
_FALSE: .long	0
.section .rodata
