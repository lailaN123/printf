#include "main.h"
/**
 * print_ch - Print char
 * @chars: arguments
 * @buffer: Buffer
 * @flags: flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Numb of printed chrs
 */
int print_ch(va_list chars, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(chars, int);

	return (handle_w_char(c, buffer, flags, width, precision, size));
}

/**
 * print_str - Prints string
 * @string: Arguments
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number chars
 */
int print_str(va_list string, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(string, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MIN)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_prct - Prints sign percent
 * @percent: arguments
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Numb of printd chars
 */
int print_prct(va_list percent, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(percent);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @integer: arguments
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: nbr of chars printed
 */
int print_int(va_list integer, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFSIZE - 2;
	int is_neg = 0;
	long int m = va_arg(integer, long int);
	unsigned long int nbr;

	m = convert_size_nbr(m, size);

	if (m == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';
	nbr = (unsigned long int)m;

	if (m < 0)
	{
		nbr = (unsigned long int)((-1) * m);
		is_neg = 1;
	}

	while (nbr > 0)
	{
		buffer[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}

	i++;

	return (write_nbr(is_neg, i, buffer, flags, width, precision, size));
}

/**
 * print_bin - Prints binary
 * @binary: arguments
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: cunt
 */
int print_bin(va_list binary, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int m, n, i, sum;
	unsigned int t[32];
	int cunt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(binary, unsigned int);
	n = 2147483648;
	t[0] = m / n;
	for (i = 1; i < 32; i++)
	{
		n /= 2;
		t[i] = (m / n) % 2;
	}
	for (i = 0, sum = 0, cunt = 0; i < 32; i++)
	{
		sum += t[i];
		if (sum || i == 31)
		{
			char z = '0' + t[i];

			write(1, &z, 1);
			cunt++;
		}
	}
	return (cunt);
}
