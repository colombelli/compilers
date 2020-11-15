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
	.long	123
	.globl	d
	.align 4
	.type	d, @object
	.size	d, 4
d:
	.long	456
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	nima
	.type	nima, @function
nima:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	b(%rip), %eax
	movl	%eax, a(%rip)
	movl	a(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	nima, .-nima
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	nima
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.1.0"
	.section	.note.GNU-stack,"",@progbits
