#include "main.h"

/**
 * _putchar - prints a character to stardard output
 * @c: character to be printed
 * Return: return character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

