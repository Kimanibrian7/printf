#include "main.h"

/**
 * _printf - mimicks simple printf
 * @format: string to be printed
 * Return: 0 on success and - if it fails
 */

int _printf(const char *format, ...)
{
	int i, count;
	va_list print;

	va_start(print, format);

	count = 0;
	if (format == NULL)
	{
		va_end(print);
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(print);
				return (-1);
			}
			count += handle(format[i], print);
		}
	}

	va_end(print);
	return (count);
}

/**
 * handle - handles and prints the format specifier
 * @s: format specifier
 * @args: arguments in the list
 * Return: void
 */

int handle(char s, va_list args)
{
	int i, num, printed;
	char c, *str;

	printed = 0;
	if (s == 'c')
	{
		c = va_arg(args, int);
		_putchar(c);
		printed++;
	}
	else if (s == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (printed);
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
			printed++;
		}
	}
	else if (s == '%')
	{
		_putchar('%');
		printed++;
	}
	else if (s == 'd' || s == 'i')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			_putchar('-');
			num = -num;
			printed++;
		}
		printed += print_integer(num);
	}
	else
	{
		_putchar(s);
		printed++;
	}
	return (printed);
}

/**
 * print_integer - prints integer and converts it to a string
 * @num: number to convert
 * Return: void
 */

int print_integer(int num)
{
	int printed;

	printed = 0;
	if (num == 0)
	{
		_putchar('0');
		printed++;
		return (printed);
	}
	if (num / 10)
	{
		printed += print_integer(num / 10);
	}
	_putchar(num % 10 + '0');
	printed++;

	return (printed);
}
