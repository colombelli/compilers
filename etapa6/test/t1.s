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
	.globl	myvec
	.bss
	.align 16
	.type	myvec, @object
	.size	myvec, 20
myvec:
	.zero	20
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
	movl	$3, a(%rip)
	movl	a(%rip), %edx
	movl	c(%rip), %eax
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	myvec(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	$45, a(%rip)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.1.0"
	.section	.note.GNU-stack,"",@progbits
