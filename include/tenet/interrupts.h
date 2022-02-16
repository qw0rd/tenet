#ifndef _TENET_INTERRUPTS_H
#define _TENET_INTERRUPTS_H

#include <stdint.h>

typedef struct idt_descriptor {
    // the lower address offset of the interrupt service routine
    uint16_t base_low;
    uint16_t seg_selector;
    // interrupt stack table
    uint8_t ist:2;
    uint8_t type:3;
    uint8_t dpl_l;
    uint16_t base_lhi;
    uint32_t base_high;
    uint32_t reserved;
} idt_descriptor;

_Static_assert(sizeof(struct idt_descriptor) == 16, "Size of an IDT descriptor should be 16 bytes");

void init_idt();

#endif
