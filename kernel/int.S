// Copyright (c) 2022, David John <dave@qword.space>
// This code is licensed under GNU GPL v2.

.macro ISR_DEF name, fn
.global \name
\name:
    call \fn
    iret
.endm

.intel_syntax noprefix

.section .text
ISR_DEF _isr0, int_handler
ISR_DEF _isr1, int_handler
ISR_DEF _isr2, int_handler
ISR_DEF _isr3, int_handler
ISR_DEF _isr4, int_handler
ISR_DEF _isr5, int_handler
ISR_DEF _isr6, int_handler
ISR_DEF _isr7, int_handler
ISR_DEF _isr8, int_handler
ISR_DEF _isr9, int_handler
ISR_DEF _isr10, int_handler
ISR_DEF _isr11, int_handler
ISR_DEF _isr12, int_handler
ISR_DEF _isr13, int_handler
ISR_DEF _isr14, int_handler
ISR_DEF _isr15, int_handler
ISR_DEF _isr16, int_handler
ISR_DEF _isr17, int_handler
ISR_DEF _isr18, int_handler
ISR_DEF _isr19, int_handler
ISR_DEF _isr20, int_handler
ISR_DEF _isr21, int_handler
ISR_DEF _isr22, int_handler
ISR_DEF _isr23, int_handler
ISR_DEF _isr24, int_handler
ISR_DEF _isr25, int_handler
ISR_DEF _isr26, int_handler
ISR_DEF _isr27, int_handler
ISR_DEF _isr28, int_handler
ISR_DEF _isr29, int_handler
ISR_DEF _isr30, int_handler
ISR_DEF _isr31, int_handler


// clean this up sometime in the future lmao
.data
.global default_isr_start
default_isr_start:
.quad _isr0
.quad _isr1
.quad _isr2
.quad _isr3
.quad _isr4
.quad _isr5
.quad _isr6
.quad _isr7
.quad _isr8
.quad _isr9
.quad _isr10
.quad _isr11
.quad _isr12
.quad _isr13
.quad _isr14
.quad _isr15
.quad _isr16
.quad _isr17
.quad _isr18
.quad _isr19
.quad _isr20
.quad _isr21
.quad _isr22
.quad _isr23
.quad _isr24
.quad _isr25
.quad _isr26
.quad _isr27
.quad _isr28
.quad _isr29
.quad _isr30
.quad _isr31


