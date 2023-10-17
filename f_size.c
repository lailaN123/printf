#include "main.h"

/**
 * f_size - Calculates size to cast arg
 * @format: Form string to print the argument
 * @i: List of arguments to be printed
 *
 * Return: Precision.
 */
int f_size(const char *format, int *i)
{
	int ind_i = *i + 1;
	int size = 0;

	if (format[ind_i] == 'l')
		size = S_LON;
	else if (format[ind_i] == 'h')
		size = S_SHO;

	if (size == 0)
		*i = ind_i - 1;
	else
		*i = ind_i;
	return (size);
}
