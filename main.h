#ifndef _MAIN_H_
#define _MAIN_H_
/*
 * This code includes the stdarg.h, stdio.h, and unistd.h header files.
 * These header files contain definitions and declarations for various
 * functions and macros that are used in the code.
 */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
/*
 * The UNUSED() macro is used to ignore the value of an expression.
 */
#define BUFF_SIZE 1024
/*
 * The BUFF_SIZE macro defines the size of
 * the buffer that is used to store formatted output.
 */

/*
 * FLAGS This code defines five macros to represent the different flags
 * that can be used with format specifiers in the printf() function.
 */

#define F_MINUS 1 /*(-)*/
#define F_PLUS 2 /*(+)*/
#define F_ZERO 4 /*(0)*/
#define F_HASH 8 /*(#)*/
#define F_SPACE 16 /*(" ")*/

/*
 * SIZES This code defines two macros to represent the different sizes
 * that can be used with format specifiers in the printf() function.
 */

#define S_LONG 2 /*l-modifier*/
#define S_SHORT 1 /*h-modifier*/

/**
 * File name: main.h
 * Description: includes all prototypes and functions of the printf project
 * Authers: Basma Shaban Ali and Noran Ahmed
*/

/**
 * struct fmt - Struct for defining a format and its associated function.
 *
 * @fmt: The format.
 * @fn: The function associated with the format.
*/
struct fmt
/*
 * This code defines a struct called fmt. This struct is used to
 * store a format specifier and a pointer to the function
 * that is associated with that format specifier.
 */
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
*/
typedef struct fmt fmt_t;
/*
 * This code defines a typedef for the fmt struct.
 * This makes it easier to use the fmt struct in the code.
 */

int _printf(const char *format, ...);
/*
 * The _printf() function is
 * a wrapper function for the printf() function.
 */
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
/*
 * The handle_print() function is used to parse
 * and format the output according to the format specifier provided.
 */

/**** the functions that we use ****/

/*
 * Funtions to print chars and strings and percent
 * @print_char: prints a character with format specifier %c
 * @print_string: prints a string with format specifier %s
 * @print_percent: prints a percent sign with format specifier %%
*/
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*
 * Functions to print numbers
 * @print_int: prints an integer with format specifier %i & %d
 * @print_binary: prints a binary, custom specifier with format specifier %b
 * @print_unsigned: prints unsigned integer with format specifier %u
 * @print_octal: prints number in base 8 with format specifier %o
 * @print_hexadecimal: prints hexadecimal in lowercase with format specifier %x
 * @print_hexa_upper: prints hexadecimal inuppercase with format specifier %X
 * @print_hexa: prints hexadecimal in lowercase & uppercase
 * with format specifier %x & %X
*/
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/*
 * Function to print non printable characters
 * @print_non_printable: prints string, prints hex value
 * of non visible characters with format specifier %S
*/
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*
 * Funcion to print memory address
 * @print_pointer: prints memory address with format specifier %p
*/
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*
 * Function to print string in reverse
 * @print_reverse: prints string in reverse, custom specifier
 *  with format specifier %r
*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*
 * Function to print a string in rot 13
 * @print_rot13string: print a string in rot 13, custom specifier
 * with format specifier %R
*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/**** UTILS ****/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* _MAIN_H_ */
