#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFSIZE 1024

/* SIZES */
#define S_LON 2
#define S_SHO 1

/* FLAGS */
#define F_MIN 1
#define F_PLU 2
#define F_ZER 4
#define F_HAS 8
#define F_SPA 16

/**
 * struct fmt_st - Struct op
 *
 * @fmt_st: The format.
 * @fun: The function associated.
 */
struct fmt_st
{
	char fmt_st;
	int (*fun)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt_st fmt_tp - Struct op
 *
 * @fmt_st: The format.
 * @fm_tp: The function associated.
 */
typedef struct fmt_st fmt_tp;

int _printf(const char *format, ...);
int handle_print(const char *fmt_st, int *index,
va_list list, char buffer[], int flags, int width, int precision, int size);

int write_p(char buffer[], int index, int length,
	int width, int flags, char pad, char ex_c, int pad_start);
int handle_w_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_nbr(int is_neg, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int prec,
	int length, char pad, char ex_c);

int print_int(va_list integer, char buffer[],
	int flags, int width, int precision, int size);
int print_unsign(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list binary, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list octal, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_lower(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_ch(va_list chars, char buffer[],
	int flags, int width, int precision, int size);
int print_prct(va_list percent, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list string, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list args, char mapo[],
char buffer[], int flags, char fla_ch, int width, int precision, int size);

int print_nprint(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int f_width(const char *format, int *i, va_list list);
int f_flags(const char *format, int *i);
int f_precision(const char *format, int *i, va_list list);
int f_size(const char *format, int *i);

int print_p(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_rev(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13str(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int write_unsgnd(int is_neg, int index,
char buffer[],
	int flags, int width, int precision, int size);

int is_print(char);
int app_hexa_code(char, char[], int);
int is_dig(char);

long int convert_size_nbr(long int num, int size);
long int convert_s_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

