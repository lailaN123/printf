#include "main.h"

/**
 * f_flags - Calculates act flags
 * @format: string to print in it the arguments
 * @i: take para
 * Return: Flags
 */
int f_flags(const char *format, int *i)
{
	int j, ind_i;
	int flags = 0;
	const char FLA_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLA_ARR[] = {F_MIN, F_PLU, F_ZER, F_HAS, F_SPA, 0};

	for (ind_i = *i + 1; format[ind_i] != '\0'; ind_i++)
	{
		for (j = 0; FLA_CH[j] != '\0'; j++)
			if (format[ind_i] == FLA_CH[j])
			{
				flags |= FLA_ARR[j];
				break;
			}

		if (FLA_CH[j] == 0)
			break;
	}

	*i = ind_i - 1;

	return (flags);
}
