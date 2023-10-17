#include "main.h"

/**
 * f_width - Calculates the width
 * @format: F string to print the arguments
 * @i: List
 * @list: list of arguments
 * Return: width
 */
int f_width(const char *format, int *i, va_list list)
{
	int ind_i;
	int width = 0;

	for (ind_i = *i + 1; format[ind_i] != '\0'; ind_i++)
	{
		if (is_dig(format[ind_i]))
		{
			width *= 10;
			width += format[ind_i] - '0';
		}
		else if (format[ind_i] == '*')
		{
			ind_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ind_i - 1;

	return (width);
}
