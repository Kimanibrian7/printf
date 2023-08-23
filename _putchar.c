#include "main.h"

/**
 * _putchar - prints a character to stardard output
 * @c: character to be printed
 * Return: return character printed
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

