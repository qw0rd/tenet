
#include <tenet/asm.h>
#include <tenet/interrupts.h>

enum {
    // x86_64 can have 256 interrupt descriptor entries 
    IDT_ENTRIES = 256,

    IDT_SIZE = IDT_ENTRIES * sizeof(struct idt_descriptor)
};

_Static_assert(IDT_SIZE == 0x1000, "x86_64 idt should exactly fit in a single page of 4 KiB");

// we want the table to be 16 byte aligned
__attribute__((aligned(16))) static idt_descriptor idt[IDT_ENTRIES];

_Static_assert(sizeof(idt) == IDT_SIZE, "Size of IDT should be 4 KiB");

extern void* default_isr_start[32];

void init_idt()
{
}

void int_handler()
{
    asm("hlt");
}

void idt_load_descriptor(uint8_t vector, void* isr)
{
    uintptr_t isr_addr = (uintptr_t)isr;

    idt_descriptor* desc = &idt[vector];
    desc->base_low = isr_addr & 0xffff;
    desc->base_lhi = (isr_addr >> 16) & 0xffff;
    desc->base_high = (isr_addr >> 32) & 0xffffffff;
}


