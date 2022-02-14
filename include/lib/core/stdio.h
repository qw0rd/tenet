
#ifndef _LIB_CORE_STDIO_H
#define _LIB_CORE_STDIO_H
#include <stddef.h>
#include <stdarg.h>

/**
 * Prints a string to an arbitrary output (framebuffer, serial port, etc...)
 *
 * **NOTE:** This function requires that the function `putstr` be defined.
 * The Declaration of the function is as follows:
 * ```c
 * void putstr(const char*, size_t);
 * ```
 *
 * @param fmt the format string
 *
 * # Example
 * ```c
 *
 * int main()
 * {
 *      printk("Hello, %s\n", "World");
 * }
 *
 * ```
 */
void printk(const char* fmt, ...);

/**
 * Formats a string and writes the output to `str`
 *
 * @param str pointer to an char buffer
 * @param format the format string (follows standard C specifiers) 
 *
 * # Example
 * ```c
 *
 * int main()
 * {
 *      char buf[100];
 *      sprintf(buf, "Hello, %s", "World");
 * }
 *
 * ```
 */
int sprintf(char* str, const char* format, ...);

/**
 * Formats a string and writes the output to `str`
 *
 * @param str pointer to an char buffer
 * @param format the format string (follows standard C specifiers) 
 * @param args the variadic parameters to the format string
 */
int vsprintf(char* restrict str, const char* restrict format, va_list args);

#endif

