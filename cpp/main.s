	.file	"main.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
	.section	.rodata
.LC0:
	.string	"\n\320\234\320\265\320\275\321\216 \320\267\320\260\320\264\320\260\320\275\320\270\320\271:\n"
	.align 8
.LC1:
	.string	"1. a^x mod p (\321\201\320\262\320\276\320\271\321\201\321\202\320\262\320\260, \320\261\321\213\321\201\321\202\321\200\320\260\321\217 \321\201\321\202\320\265\320\277\320\265\320\275\321\214, \320\244\320\265\321\200\320\274\320\260)\n"
	.align 8
.LC2:
	.string	"2. \320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\225\320\262\320\272\320\273\320\270\320\264\320\260 (u \320\270 v)\n"
	.align 8
.LC3:
	.string	"3. \320\236\320\261\321\200\320\260\321\202\320\275\320\276\320\265 \320\277\320\276 \320\274\320\276\320\264\321\203\320\273\321\216 (\321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\271 \320\225\320\262\320\272\320\273\320\270\320\264)\n"
	.align 8
.LC4:
	.string	"4. \320\224\320\270\321\204\321\204\320\270-\320\245\320\265\320\273\320\273\320\274\320\260\320\275 (\320\276\320\261\320\274\320\265\320\275 \320\272\320\273\321\216\321\207\320\260\320\274\320\270, \320\260\321\202\320\260\320\272\320\260)\n"
	.align 8
.LC5:
	.string	"5. \320\246\320\265\320\277\320\275\320\260\321\217 \320\264\321\200\320\276\320\261\321\214 \320\270 \320\264\320\270\320\276\321\204\320\260\320\275\321\202\320\276\320\262\320\276 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265\n"
	.align 8
.LC6:
	.string	"6. MITM-\320\260\321\202\320\260\320\272\320\260 \320\275\320\260 \320\224\320\270\321\204\321\204\320\270-\320\245\320\265\320\273\320\273\320\274\320\260\320\275\n"
.LC7:
	.string	"0. \320\222\321\213\321\205\320\276\320\264\n"
	.align 8
.LC8:
	.string	"\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\320\265: "
	.align 8
.LC9:
	.string	"\320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\270\320\265 \321\200\320\260\320\261\320\276\321\202\321\213.\n"
#NO_APP
	.text
	.globl	main
	.type	main, @function
main:
.LFB2389:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movb	$1, -1(%rbp)
	jmp	.L2
.L11:
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movl	$6, %esi
	movl	$0, %edi
	call	_Z11getIntInputii@PLT
	movl	%eax, -8(%rbp)
	cmpl	$6, -8(%rbp)
	ja	.L3
	movl	-8(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L5(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L5(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L5:
	.long	.L3-.L5
	.long	.L10-.L5
	.long	.L9-.L5
	.long	.L8-.L5
	.long	.L7-.L5
	.long	.L6-.L5
	.long	.L4-.L5
	.text
.L10:
	call	_Z15taskFermatPowerv@PLT
	jmp	.L2
.L9:
	call	_Z20taskExtendedEuclidUVv@PLT
	jmp	.L2
.L8:
	call	_Z18taskModularInversev@PLT
	jmp	.L2
.L7:
	call	_Z17taskDiffieHellmanv@PLT
	jmp	.L2
.L6:
	call	_Z35taskContinuedFractionAndDiophantinev@PLT
	jmp	.L2
.L4:
	call	_Z21taskDiffieHellmanMITMv@PLT
	jmp	.L2
.L3:
	movb	$0, -1(%rbp)
	leaq	.LC9(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
.L2:
	cmpb	$0, -1(%rbp)
	jne	.L11
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2389:
	.size	main, .-main
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: (Debian 14.2.0-19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
