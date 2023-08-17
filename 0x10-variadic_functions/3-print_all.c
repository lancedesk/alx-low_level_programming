#include "variadic_functions.h"

/**
 * print_all - Print a sequence of various data types
 * based on format string.
 * @format: The format string that specifies
 * the types of arguments to print.
 * @...: The variadic arguments to be printed
 * based on the format string.
 */

void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	char *separator = "", *string;
	va_list arguments;

	va_start(arguments, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", separator, va_arg(arguments, int));
					break;
				case 'i':
					printf("%s%i", separator, va_arg(arguments, int));
					break;
				case 'f':
					printf("%s%f", separator, va_arg(arguments, double));
					break;
				case 's':
					string = va_arg(arguments, char *);
					if (!string)
						string = "(nil)";
					printf("%s%s", separator, string);
					break;
				default:
					i++;
					continue;
			}
			separator = ", ";
			i++;
		}
	}
	printf("\n");
	va_end(arguments);
}

