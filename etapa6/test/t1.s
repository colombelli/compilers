	.file	"t1.c"
	.text
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	2132
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	12
	.globl	c
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.long	6
	.globl	d
	.align 4
	.type	d, @object
	.size	d, 4
d:
	.long	13
	.globl	e
	.align 4
	.type	e, @object
	.size	e, 4
e:
	.long	235
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6

	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, b(%rip)



	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	setg	%al
	movzbl	%al, %eax
	movl	%eax, b(%rip)



	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, b(%rip)



	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	setge	%al
	movzbl	%al, %eax
	movl	%eax, b(%rip)



	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	setle	%al
	movzbl	%al, %eax
	movl	%eax, b(%rip)



	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, b(%rip)


	movl	a(%rip), %eax
	testl	%eax, %eax
	je	.L2
	movl	c(%rip), %eax
	testl	%eax, %eax
	je	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	$0, %eax
.L3:
	movl	%eax, b(%rip)
	movl	$1, a(%rip)
	movl	a(%rip), %eax
	testl	%eax, %eax
	jne	.L4
	movl	c(%rip), %eax
	testl	%eax, %eax
	je	.L5
.L4:
	movl	$1, %eax
	jmp	.L6
.L5:
	movl	$0, %eax
.L6:
	movl	%eax, b(%rip)
	movl	$1, a(%rip)
	movl	a(%rip), %eax
	notl	%eax
	movl	%eax, b(%rip)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.1.0"
	.section	.note.GNU-stack,"",@progbits
