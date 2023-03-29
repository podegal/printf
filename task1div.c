#include "main.h"
#include <stdarg.h>

/**
 * print_arg - prints a single argument based on its format specifier
 * @format: format specifier character
 * @args: va_list containing the argument to be printed
 * @count: pointer to the count of characters printed
 * Return: none
 */
void print_arg(char format, va_list args, int *count)
{
	int len;
	char *s;
	char c;

	switch (format)
	{
		case 'c':
			c = va_arg(args, int);

			__prints(&c, 1);
			*count += 1;
			break;
		case 's':
			s = va_arg(args, char *);

			if (s)
			{
				len = 0;
				while (s[len])
					len++;
				__prints(s, len);
				__prints('\0', 1);
				*count += len;
			}
			else
			{
				s = "(null)";
			}
			break;
		case '%':
			__prints("%", 1);
			*count += 1;
			break;
		default:
			__prints("%", 1);
			__prints(&format, 1);
			*count += 2;
			break;
	}
}

/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_arg(format[i], args, &count);
		}
		else
		{
			__prints((char *)&format[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(args);
	return (count);
}

