#include "main.h"


/**
 * f_precision - Calculates precision
 * @format: string in which to print the argument
 * @i: List
 * @list: list of arguments
 * Return: Precision
 */
int f_precision(const char *format, int *i, va_list list)
{
	int ind_i = *i + 1;
	int precision = -1;

	if (format[ind_i] != '.')
		return (precision);

	precision = 0;

	for (ind_i += 1; format[ind_i] != '\0'; ind_i++)
	{
		if (is_dig(format[ind_i]))
		{
			precision *= 10;
			precision += format[ind_i] - '0';
		}
		else if (format[ind_i] == '*')
		{
			ind_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ind_i - 1;

	return (precision);
}
