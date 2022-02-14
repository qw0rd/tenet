/**
 * @file string.h
 *
 * Core memory and string utils
 *
 */
#ifndef _LIB_CORE_STRING_H
#define _LIB_CORE_STRING_H

#include <stdint.h>
#include <stddef.h>

/**
 * Copy an non overlapping region of memory of `n` bytes from src -> dest
 *
 * @param dest Pointer to start of destination memory region.
 * @param src Pointer to start of source memory region.
 * @param n The number of bytes to copy
 */
void *memcpy(void *dest, const void *src, size_t n);

size_t strlen(const char* str);

#endif
