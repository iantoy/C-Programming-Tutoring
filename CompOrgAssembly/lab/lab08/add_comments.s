	.file	"add.c"       # file name
	.text
	.section	.rodata   # starts the section of read-only data
.LC0:                     # label
	.string	"Enter an integer: "  # string variable
.LC1:
	.string	"%d"
.LC2:
	.string	"Enter a second integer: "
.LC3:
	.string	"Sum of %d and %d is %d \n"
	.text                    # start the .text (code) section
	.globl	main             # we'll start at main
	.type	main, @function  # main is a function
main:                        # a label to designate the start of main
.LFB0:                       # label
	.cfi_startproc           # these are compiler notes, startproc used at the start of a process.  
	/* preamble */
	pushq	%rbp				# preamble, push rbp onto the stack to save for later
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp			# move current stack pointer value into base pointer register, now bp points to top of stack
	.cfi_def_cfa_register 6
	/* set up for local variables */
	subq	$32, %rsp			# subtract 32 bytes from stack pointer - allocate space for variables
	/* stack canary */
	movq	%fs:40, %rax		# move stack canary (fs:40) into rax
	movq	%rax, -8(%rbp)		# move rax (stack canary) into stack at bp-8 bytes
	xorl	%eax, %eax			# xor rax, essentially same as moving 0 into rax
	/* print user input prompt */
	leaq	.LC0(%rip), %rdi	# prep for print, load effective address move LCO ("Enter an integer") pointer into rdi
	movl	$0, %eax			# move 0 into rax, get ready to call a function. Tells compiler we're using 0 floating point registers
	call	printf@PLT			# call print function, print will take first argument from rdi, print, return # chars printed into rax
	/* take user input, a */
	leaq	-20(%rbp), %rax		# load effective address of a into rax, pointer to stack, to hold variable a
	movq	%rax, %rsi			# move that pointer to rsi, rsi now pointer to a
	leaq	.LC1(%rip), %rdi	# move LC1 ("%d") pointer to rdi
	movl	$0, %eax			# move 0 into rax, get ready to call function
	call	__isoc99_scanf@PLT	# call scanf, it will pass in rdi and rsi, place 'int a' on stack, returns # args read into rax
	/* ========== NOTE: remaining code is not fully commented ========== */
	/* print user input prompt, get ready to input b */
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	/* take user input b */
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	/* add a and b */
	movl	-20(%rbp), %edx		# move a into rdx
	movl	-16(%rbp), %eax		# move b into rax
	addl	%edx, %eax			# add a + b to get c, rax is now c
	/* print a, b, c */
	movl	%eax, -12(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	-12(%rbp), %ecx
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	/* check stack canary */
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	/* clean up and return */
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.1.0-2ubuntu2~18.04) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
