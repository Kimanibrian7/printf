#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int handle(char s, va_list args);
int print_integer(int num);

#endif
