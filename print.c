#include "main.h"

/**
 * _printf - mimicks simple printf
 * @format: string to be printed
 * Return: 0 on success and - if it fails
 */

int _printf(const char *format, ...)
{
	int i;
	va_list print;

	va_start(print, format);

	if (format == NULL)
	{
		va_end(print);
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			_putchar(format[i]);
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(print);
				return (-1);
			}
			handle(format[i], print);
		}
	}

	va_end(print);
	return (0);
}

/**
 * handle - handles and prints the format specifier
 * @s: format specifier
 * @args: arguments in the list
 * Return: void
 */

void handle(char s, va_list args)
{
	int i, num;
	char c, *str;

	if (s == 'c')
	{
		c = va_arg(args, int);
		_putchar(c);
	}
	else if (s == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return;
		for (i = 0; str[i] != '\0'; i++)
			_putchar(str[i]);
	}
	else if (s == '%')
		_putchar('%');
	else if (s == 'd' || s == 'i')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			_putchar('-');
			num = -num;
		}
		print_integer(num);
	}
	else
		_putchar(s);
}

/**
 * print_integer - prints integer and converts it to a string
 * @num: number to convert
 * Return: void
 */

void print_integer(int num)
{

	if (num == 0)
	{
		_putchar('0');
		return;
	}
	if (num / 10)
	{
		print_integer(num / 10);
	}
	_putchar(num % 10 + '0');
}
