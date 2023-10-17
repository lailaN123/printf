#include "main.h"

/**
 * is_print - see if char is printable
 * @c: Char
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * is_dig - Verif if char is a dig
 * @c: Char
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_dig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_nbr - Casts num to specified size
 * @num: Number to cast
 * @size: Number indic type casted
 *
 * Return: Casted num
 */
long int convert_size_nbr(long int num, int size)
{
	if (size == S_LON)
		return (num);
	else if (size == S_SHO)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_s_unsgnd - Casts a num to the spec size
 * @num: Number
 * @size: Number indic the type
 *
 * Return: Casted num
 */
long int convert_s_unsgnd(unsigned long int num, int size)
{
	if (size == S_LON)
		return (num);
	else if (size == S_SHO)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * app_hexa_code - Append ascci in hexad code
 * @buffer: Array
 * @i: Index
 * @ascii_code: Assci code
 * Return: Always 3
 */
int app_hexa_code(char ascii_code, char buffer[], int i)
{
	char mapo[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = mapo[ascii_code / 16];
	buffer[i] = mapo[ascii_code % 16];

	return (3);
}
