#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt_st: pointer to the format string
 * @list: List of arguments
 * @index: pointer to the current index
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: 1 or 2;
 */
int handle_print(const char *fmt_st, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, char_count = 0, prtd_char = -1;
	fmt_tp fmt_array[] = {
		{'c', print_ch}, {'s', print_str}, {'%', print_prct},
		{'i', print_int}, {'d', print_int}, {'b', print_bin},
		{'u', print_unsign}, {'o', print_oct}, {'x', print_hexa_lower},
		{'X', print_hexa_upper}, {'p', print_p}, {'S', print_nprint},
		{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (i = 0; fmt_array[i].
fmt_st != '\0'; i++)
		if (fmt_st[*index] == fmt_array[i].fmt_st)
			return (fmt_array[i].fun(list, buffer, flags, width, precision, size));

	if (fmt_array[i].fmt_st == '\0')
	{
		if (fmt_st[*index] == '\0')
			return (-1);
		char_count += write(1, "%%", 1);
		if (fmt_st[*index - 1] == ' ')
			char_count += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt_st[*index] != ' ' && fmt_st[*index] != '%')
				--(*index);
			if (fmt_st[*index] == ' ')
				--(*index);
			return (1);
		}
		char_count += write(1, &fmt_st[*index], 1);
		return (char_count);
	}
	return (prtd_char);
}

