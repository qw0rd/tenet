
#include <stdarg.h>
#include <core/stdio.h>
#include <core/string.h>

const char* chars = "0123456789abcdef";

// buffer size is 65 since we need 65 chars for binary (64 bits + null terminator)
static char buf[65]; 

enum BASE {
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16
};

static const char* int_2_str(int64_t num, enum BASE base)
{
    size_t cur = 64;
    buf[cur] = 0;

    int64_t tmp = num;

    if (num == 0) {
        buf[--cur] = '0';
        return &buf[cur];
    } else if (num < 0) {
        tmp = (~tmp + 1);
    }

    while (tmp) {
        int64_t n = tmp % base;
        char c = chars[n % base];
        buf[--cur] = c;
        tmp /= base;
    }

    if (base == DEC && num < 0) {
        buf[--cur] = '-';
    }

    return &buf[cur];
}

static const char* uint_2_str(uint64_t num, enum BASE base)
{
    size_t cur = 64;
    buf[cur] = 0;

    uint64_t tmp = num;

    if (num == 0) {
        buf[--cur] = '0';
        return &buf[cur];
    }

    while (tmp) {
        uint64_t n = tmp % base;
        char c = chars[n % base];
        buf[--cur] = c;
        tmp /= base;
    }

    return &buf[cur];
}

// helper function to copy strings into a buffer (basically memcpy but dont need to provide the string length)
static inline size_t ez_cpy(char* buf, const char* str)
{
    size_t len = strlen(str);
    memcpy(buf, str, len);
    return len;
}

#define CPY_AND_UPDATE(s)                        \
    cursor += ez_cpy(&buf[cursor], s)           \

int vsprintf(char* restrict buf, const char* restrict fmt, va_list args)
{
    size_t cursor = 0;

    // we return if either `buf` or `fmt` is NULL to save our foots.
    if (!buf || !fmt) 
        return 0;

    //va_list args;
    //va_start(args, fmt);

    while (*fmt) {
        switch(*fmt)  {
            case '%': 
            {
                fmt++;
                switch(*fmt) {
                    case '%': 
                    {
                        buf[cursor++] = '%';
                        break;
                    }
                    case 'd': 
                    {
                        const char* s = int_2_str(va_arg(args, int), DEC);
                        CPY_AND_UPDATE(s);
                        break;
                    }
                    case 'l':
                    {
                        fmt++;
                        switch(*fmt) {
                            case 'd':
                            {
                                const char* s = int_2_str(va_arg(args, int64_t), DEC);
                                CPY_AND_UPDATE(s);
                                break;
                            }
                            case 'u':
                            {
                                const char* s = uint_2_str(va_arg(args, uint64_t), DEC);
                                CPY_AND_UPDATE(s);
                                break;
                            }
                            case 'x':
                            {
                                const char* s = uint_2_str(va_arg(args, uint64_t), HEX);
                                CPY_AND_UPDATE(s);
                                break;
                            }
                        }
                        break;
                    }
                    case 'u':
                    {
                        const char* s = uint_2_str(va_arg(args, uint32_t), DEC);
                        CPY_AND_UPDATE(s);
                        break;
                    }
                    case 'x':
                    {
                        const char* s = uint_2_str(va_arg(args, uint32_t), HEX);
                        CPY_AND_UPDATE(s);
                        break;
                    }
                    case 's': 
                    {
                        const char* s = va_arg(args, const char*);
                        CPY_AND_UPDATE(s);
                        break;
                    }
                }
                break;
            }
            default:
            {
                buf[cursor++] = *fmt;
            }
        }
        fmt++;
    }

    buf[cursor++] = 0;
    return cursor;
}

int sprintf(char* restrict str, const char* restrict format, ...)
{

    va_list args;
    va_start(args, format);
    int len = vsprintf(str, format, args);
    va_end(args);
    return len;
}

extern void putchar(char c);

extern void putstr(const char* str, size_t len);

void printk(const char*fmt, ...)
{
    static char buf[1024];
    va_list args;
    va_start(args, fmt);
    int len = vsprintf(buf, fmt, args);
    va_end(args);

    if (len > 0) {
        putstr(buf, len);
    }
}

