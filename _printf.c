#include "main.h"

/**
 * File name: _printf.c
 * Authers: Basma Shaban Ali and Noran Ahmed
 */

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

/*
 * This function declaration defines the _printf() function,
 * which is a wrapper function for the printf() function.
 * It takes a format string as its first argument,
 * and a variable number of arguments to be printed according
 * to the format string. The function returns the number of characters printed.
 */

int _printf(const char *format, ...)
{
	/*
	 * These variables are used to track the position in the format string,
	 * the number of characters printed, the flags, width, precision,
	 * and size associated with the current format specifier,
	 * and the index of the next character in the buffer.
	 */
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
/*
 * This loop iterates over the format string, one character at a time.
 * The loop terminates when the end of the format string is reached.
 */
	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		/*
		 * If the current character in the format string is
		 * not a percent sign, then the character is copied to
		 * the buffer. If the buffer is full,
		 * the print_buffer() function is called to print
		 * the contents of the buffer.
		 */

		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		/*
		 * If the current character in the format string
		 * is a percent sign, then the print_buffer() function
		 * is called to print the contents of the buffer. Then,
		 * the get_flags(), get_width(), get_precision(),
		 * and get_size() functions are called to parse
		 * the format specifier. Finally, the handle_print() function
		 * is called to print the argument according to
		 * the format specifier.
		 */
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
/*
 * After the loop has finished executing, the print_buffer() function is
 * called to print the contents of the buffer. Then, the va_end() function
 * is called to clean up the variable argument list.
 * Finally, the printed_chars variable is returned.
 */
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	/*
	 * The print_buffer() function prints the contents of the buffer to
	 * the standard output stream. The buffer index is then reset to zero.
	 */
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
