#include "main.h"

/**
 * print_unsign - Prints uns num
 * @args: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chrs printed
 */
int print_unsign(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFSIZE - 2;
	unsigned long int nbr = va_arg(args, unsigned long int);

	nbr = convert_s_unsgnd(nbr, size);

	if (nbr == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';

	while (nbr > 0)
	{
		buffer[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}

	i++;

	return (write_uns(0, i, buffer, flags, width, precision, size));
}

/**
 * print_oct - Prints number in octal notation
 * @octal: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Nb chars printed
 */
int print_oct(va_list octal, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFSIZE - 2;
	unsigned long int nbr = va_arg(octal, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);

	nbr = convert_s_unsgnd(nbr, size);

	if (nbr == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';

	while (nbr > 0)
	{
		buffer[i--] = (nbr % 8) + '0';
		nbr /= 8;
	}

	if (flags & F_HAS && init_nbr != 0)
		buffer[i--] = '0';

	i++;

	return (write_uns(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexa_lower - Print number in hexadecimal
 * @args: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width:  width
 * @precision: Precision
 * @size: Size
 * Return: Nm chars printed
 */
int print_hexa_lower(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Print upper hexadecimal notation
 * @args: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal
 * @args: arguments
 * @mapo: Array
 * @buffer: Buffer
 * @flags:  flags
 * @fla_ch: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars
 */
int print_hexa(va_list args, char mapo[], char buffer[],
	int flags, char fla_ch, int width, int precision, int size)
{
	int i = BUFSIZE - 2;
	unsigned long int nbr = va_arg(args, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);

	nbr = convert_s_unsgnd(nbr, size);

	if (nbr == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';

	while (nbr > 0)
	{
		buffer[i--] = mapo[nbr % 16];
		nbr /= 16;
	}

	if (flags & F_HAS && init_nbr != 0)
	{
		buffer[i--] = fla_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_uns(0, i, buffer, flags, width, precision, size));
}
