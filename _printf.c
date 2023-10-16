#include "main.h"

void print_bf(char bf[], int *bf_len);
/**
 * print_bf - Prints the contents of the buffer if it exist
 * @bf: Array of characters
 * @bf_len : a pointer to an integer that represents
 * the length of the content in the buffer.
 */
void print_bf(char bf[], int *bf_len)
{
	if (*bf_len > 0)
		write(1, &bf[0], *bf_len);
	*bf_len = 0;
}

/**
 * _printf - produces output according to a format.
 * @format: character string
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int prtd_sp = 0, prtd_char = 0, bf_len = 0;
	int i, flags, width, precision, size;
	va_list args;
	char bf[BUFSIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bf[bf_len] = format[i];
			bf_len++;
			if (bf_len == BUFSIZE)
				print_bf(bf, &bf_len);
			prtd_char++;
		}
		else
		{
			print_bf(bf, &bf_len);
			flags = f_flags(format, &i);
			width = f_width(format, &i, args);
			precision = f_precision(format, &i, args);
			size = f_size(format, &i);
			++i;
			prtd_sp = handle_print(format, &i, args, bf,
				flags, width, precision, size);
			if (prtd_sp == -1)
				return (-1);
			prtd_char += prtd_sp;
		}
	}

	print_bf(bf, &bf_len);

	va_end(args);

	return (prtd_char);

