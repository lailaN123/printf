#include "main.h"

/**
 * print_p - Print a pointer variable
 * @args: arguments
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of printed
 */
int print_p(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char ex_c = 0, pad = ' ';
	int ind = BUFSIZE - 2, len = 2, pad_start = 1;
	unsigned long num_adrs;
	char mapo[] = "0123456789abcdef";
	void *adrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (adrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFSIZE - 1] = '\0';
	UNUSED(precision);

	num_adrs = (unsigned long)adrs;

	while (num_adrs > 0)
	{
		buffer[ind--] = mapo[num_adrs % 16];
		num_adrs /= 16;
		len++;
	}

	if ((flags & F_ZER) && !(flags & F_MIN))
		pad = '0';
	if (flags & F_PLU)
		ex_c = '+', len++;
	else if (flags & F_SPA)
		ex_c = ' ', len++;

	ind++;

	return (write_p(buffer, ind, len,
		width, flags, pad, ex_c, pad_start));
}

/**
 * print_nprint - print hexa of non printable chars
 * @args: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_nprint(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, ofset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_print(str[i]))
			buffer[i + ofset] = str[i];
		else
			ofset += app_hexa_code(str[i], buffer, i + ofset);

		i++;
	}

	buffer[i + ofset] = '\0';

	return (write(1, buffer, i + ofset));
}

/**
 * print_rev - Prints reverse string.
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rev(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, cunt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char w = str[i];

		write(1, &w, 1);
		cunt++;
	}
	return (cunt);
}

/**
 * print_rot13str - Print str in rot13.
 * @args: arguments
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_rot13str(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int i, j;
	int cunt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				y = out[j];
				write(1, &y, 1);
				cunt++;
				break;
			}
		}
		if (!in[j])
		{
			y = str[i];
			write(1, &y, 1);
			cunt++;
		}
	}
	return (cunt);
}
