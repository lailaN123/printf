#include "main.h"
/**
 * handle_w_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  flags.
 * @width: width.
 * @precision: precision
 * @size: Size
 *
 * Return: Number of chars printed.
 */
int handle_w_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZER)
		pad = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFSIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFSIZE - i - 2] = pad;

		if (flags & F_MIN)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFSIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFSIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_nbr - Prints a string
 * @is_neg: Lista of arguments
 * @index: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_nbr(int is_neg, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFSIZE - index - 1;
	char pad = ' ', ex_ch = 0;

	UNUSED(size);

	if ((flags & F_ZER) && !(flags & F_MIN))
		pad = '0';
	if (is_neg)
		ex_ch = '-';
	else if (flags & F_PLU)
		ex_ch = '+';
	else if (flags & F_SPA)
		ex_ch = ' ';

	return (write_num(index, buffer, flags, width, precision,
		length, pad, ex_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @pad: Pading char
 * @ex_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char pad, char ex_c)
{
	int i, pad_start = 1;

	if (prec == 0 && ind == BUFSIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFSIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (ex_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MIN && pad == ' ')
		{
			if (ex_c)
				buffer[--ind] = ex_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MIN) && pad == ' ')
		{
			if (ex_c)
				buffer[--ind] = ex_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MIN) && pad == '0')
		{
			if (ex_c)
				buffer[--pad_start] = ex_c;
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (ex_c)
		buffer[--ind] = ex_c;
	return (write(1, &buffer[ind], length));
}


/**
 * write_uns - Writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_uns(int is_neg, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFSIZE - index - 1, i = 0;
	char pad = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && index == BUFSIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((flags & F_ZER) && !(flags & F_MIN))
		pad = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = pad;

		buffer[i] = '\0';

		if (flags & F_MIN)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], len));
		}
	}

	return (write(1, &buffer[index], len));
}

/**
 * write_p - Write a memory address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad: Char representing the padding
 * @ex_c: Char representing extra char
 * @pad_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_p(char buffer[], int index, int length,
	int width, int flags, char pad, char ex_c, int pad_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MIN && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ex_c)
				buffer[--index] = ex_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MIN) && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ex_c)
				buffer[--index] = ex_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MIN) && pad == '0')
		{
			if (ex_c)
				buffer[--pad_start] = ex_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[index], length - (1 - pad_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (ex_c)
		buffer[--index] = ex_c;
	return (write(1, &buffer[index], BUFSIZE - index - 1));
}

