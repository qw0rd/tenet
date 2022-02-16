#ifndef _TENET_CORE_H
#define _TENET_CORE_H

#define LOOP while (1)


/**
 * Hangs the cpu by writing `_code` into `eax` and halting the CPU.
 *
 * @param _code 32 bit integer to be written to eax
 *
 */
inline static void hang(int _code)
{
    asm volatile ("mov %0, %%eax" :: "r"(_code));
    LOOP {
        asm("hlt");
    }
}


#endif
