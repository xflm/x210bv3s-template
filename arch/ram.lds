/**
 * X210BV3S S5PV210 cortex-a8 arm-v7
 * SRAM  0xD0020000 0xD0035400 85KB
 */

ENTRY(Reset_Handler)

STACK_FIQ_SIZE = 512;
STACK_IRQ_SIZE = 512;
STACK_ABT_SIZE = 128;
STACK_UND_SIZE = 128;
STACK_SRV_SIZE = 1024;

MEMORY
{
	SRAM(RWX)  : ORIGIN = 0xD0020000, LENGTH = 85K   /* 0xD0035400 */
}

SECTIONS
{
	.text : {
		. = ALIGN(4);
		KEEP(*(.bl1_header))
		KEEP(*(.vector))
		. = ALIGN(4);
		KEEP(*(.text.keep.user))
		. = ALIGN(4);
		*(.text)
		*(.text.*)
		*(.glue_7)
		*(.glue_7t)
	} > SRAM

	.rodata : {
		. = ALIGN(4);
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
	} > SRAM

	PROVIDE(_sidata = LOADADDR(.data));

	.data : {
		. = ALIGN(0x4);
		PROVIDE(_sdata = .);
		*(.run_in_ram)
		. = ALIGN(4);
		*(.data)
		*(.data.*)
		. = ALIGN(0x4);
		. = ALIGN(8192);
		PROVIDE(_edata = .);
	} > SRAM

	.bss : {
		. = ALIGN(0x4);
		PROVIDE(_sbss = .);
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(0x4);
		PROVIDE(_ebss = .);
		*(.bss.no_init.user)
		. = ALIGN(0x4);	
		_sstack_fiq = .;
		. += STACK_FIQ_SIZE;
		PROVIDE(_estack_fiq = .);
		_sstack_irq = .;
		. += STACK_IRQ_SIZE;
		PROVIDE(_estack_irq = .);
		_sstack_abt = .;
		. += STACK_ABT_SIZE;
		PROVIDE(_estack_abt = .);
		_sstack_und = .;
		. += STACK_UND_SIZE;
		PROVIDE(_estack_und = .);
		_sstack_srv = .;
		. += STACK_SRV_SIZE;
		PROVIDE(_estack_srv = .);
		end = .;
		KEEP(*(.heap))
	} > SRAM

	/DISCARD/ : {
		libc.a ( * )
		libm.a ( * )
		libgcc.a ( * )
	}

	.mlds.sram : {mlds_sram = .;} > SRAM
}

PROVIDE(__bin_start = ORIGIN(SRAM));
PROVIDE(__bin_sizes = ABSOLUTE(mlds_sram)-ORIGIN(SRAM)-SIZEOF(.bss));

sram_mlds_used_sram   = ABSOLUTE(mlds_sram)-ORIGIN(SRAM);
sram_mlds_unused_sram = LENGTH(SRAM)-ABSOLUTE(sram_mlds_used_sram);

