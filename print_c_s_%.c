#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * File: print_c_s_%.c
 * Authers: Basma Shaban Ali and
 * _printf - Prints a char, percent sign and a string
 * @c: print character %c
 * @s: print a string %s
 * @%: print percent sign %%
 * Return: Number of chars printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;
    const char *s;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, const char *);
                    while (*s != '\0')
                    {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main()
{
    int count = _printf("Hello, %s! Today is %c.\n", "My name is Basma & this is my partner Nouran", 'F');
    printf("Number of characters printed: %d\n", count);
    return 0;
}
