#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - function that produces output according to a format
* @format:  is a character string.
* The format string is composed of zero or more directives.
* Prototype: int _printf(const char *format, ...);
* Return: the number of characters printed
* (excluding the null byte used to end output to strings)
*/

int _printf(const char *format, ...)
{
	int num_printed = 0;
	const char *s = format;
	va_list args;

	va_start(args, format);
	for (; *s != '\0'; s++)
	{
		if (*s == '%' && *(s + 1) == '%')
		{
			write(1, s, 1);
			num_printed++;
			s++;
		}
		else if (*s == '%' && *(s + 1) == 'c')
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			num_printed++;
			s++;
		}
		else if (*s == '%' && *(s + 1) == 's')
		{
			char *string = va_arg(args, char*);

			num_printed += print_str(string);
			s++;
		}
		else
		{
			write(1, s, 1);
			num_printed++;
		}
	}
	va_end(args);
	return (num_printed);
}

/**
* print_str - function that writes a string of characters.
* @str:  is a character string.
* Prototype: int print_str(char *str);
* Return: the number of characters printed
*/

int print_str(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}
