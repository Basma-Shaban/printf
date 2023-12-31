#include "main.h"

/**
 * File: get_precision.c
 * Authers: Basma Shaban Ali and Noran Ahmed
 */

/**
 * get_precision - Calculates the precision for printing a value.
 *
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	/*
	 * These variables are used to track the current position in
	 * the formatted string and the precision. The precision is
	 * initialized to -1 to indicate that no precision is specified.
	 */
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
