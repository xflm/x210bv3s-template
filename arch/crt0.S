.equ USR_MODE,              0x10    /* normal user mode */
.equ FIQ_MODE,              0x11    /* fiq fast interrupts mode */
.equ IRQ_MODE,              0x12    /* irq standard interrupts mode */
.equ SVC_MODE,              0x13    /* supervisor interrupts mode */
.equ ABT_MODE,              0x17    /* abort processing memory faults mode */
.equ UDF_MODE,              0x1b    /* undefined instructions mode */
.equ MODE_MASK,             0x1f    /* system running in priviledged operating mode */
.equ NO_INT,                0xc0    /* FIQ IRQ, 1:disable 0:enable */
.equ CPSR_IRQ_EN,           0x80
.equ CPSR_IRQ_MASK,	    0x40    /* disable interrupt mode (irq) */
.equ CPSR_FIQ_MASK,	    0x80    /* disable fast interrupt mode (fiq) */


	.text
	.arm
	.global	Reset_Handler
	.type	Reset_Handler,	%function
	.align	2

Reset_Handler:
	/* io retention release */
	/* P466 in S5PV210_UM---.pdf */
	ldr	r0,	=0xE010E000
	ldr	r1,	[r0]
	ldr	r2,	=((1 << 31) | (1 << 29) | (1 << 28))
	orr	r1,	r1, r2
	str	r1,	[r0]

	/* ps_hold pin (gph0_0) set to high */
	/* P470 in S5PV210_UM---.pdf */
	ldr	r0,	=0xE010E81C
	ldr	r1,	[r0]
	orr	r1,	r1, #0x300
	orr	r1,	r1, #0x1
	str	r1,	[r0]

set_vector:
	ldr	r0,	=vector_table
	mcr	p15,	0, r0, c12, c0, 0

init_stacks:
	mrs	r0,	cpsr
	bic	r0,	r0,	#MODE_MASK | NO_INT

	orr	r1,	r0,	#UDF_MODE
	msr	cpsr_cxsf,	r1
	ldr	sp,	=_estack_und

	orr	r1,	r0,	#ABT_MODE
	msr	cpsr_cxsf,	r1
	ldr	sp,	=_estack_abt

	orr	r1,	r0,	#IRQ_MODE
	msr	cpsr_cxsf,	r1
	ldr	sp,	=_estack_irq

	orr	r1,	r0,	#FIQ_MODE
	msr	cpsr_cxsf,	r1
	ldr	sp,	=_estack_fiq

	orr	r1,	r0,	#SVC_MODE
	msr	cpsr_cxsf,	r1
	ldr	sp,	=_estack_srv

init_data:
	ldr	r0,	=_sdata
	ldr	r1,	=_edata
	ldr	r2,	=_sidata
	cmp	r0,	r1
	beq	clear_bss
	cmp	r0,	r2
	beq	clear_bss
init_data_loop:
	ldr	r3,	[r2]
	str	r3,	[r0]
	add	r0,	#4
	add	r2,	#4
	cmp	r0,	r1
	bne	init_data_loop

clear_bss:
	ldr	r0,	=_sbss
	ldr	r1,	=_ebss
	mov	r2,	#0
	cmp	r0,	r1
	beq	to_main
clear_bss_loop:
	str	r2,	[r0]
	add	r0,	#4
	cmp	r0,	r1
	bne	clear_bss_loop

to_main:
	bl	main
	b	.


	.section	.bl1_header,	"a",	%progbits
	.type		bl1_header,	%object
	.align		2

bl1_header:
	.word 	__bin_sizes    /* bl1 size */
	.word	0x00000000     /* reserved (should be 0) */
	.word	0x00000000     /* check sum, this write by other tool */
	.word	0x00000000     /* reserved (should be 0) */
	b	Reset_Handler  /* entry */
	
	
	.section	.vector,	"a",	%progbits
	.type		vector_table,	%object
	.align		5      /* 32 bytes align */

vector_table:
	b	Reset_Handler
	ldr	pc,	=Undefined_Instruction_Handler
	ldr	pc,	=Software_Interrupt_Handler
	ldr	pc,	=Prefetch_Abort_Handler
	ldr	pc,	=Data_Abort_Handler
	.word	0x00000000
	ldr	pc,	=_IRQ_Handler
	ldr	pc,	=FIQ_Handler


	.text
	.align 2
Default_Handler:
	b	Default_Handler

.macro def_handler handler_name
	.weak	\handler_name
	.set	\handler_name,	Default_Handler
.endm

def_handler Undefined_Instruction_Handler
def_handler Software_Interrupt_Handler
def_handler Prefetch_Abort_Handler
def_handler Data_Abort_Handler
def_handler FIQ_Handler


_IRQ_Handler:
	sub lr, lr, #4
	stmfd sp!, {r0-r12, lr}
	bl IRQ_Handler
	ldmfd sp!, {r0-r12, pc}^

.end
