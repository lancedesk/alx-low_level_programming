#include "variadic_functions.h"

/**
 * print_strings - Print a sequence of strings
 * followed by a separator and a newline.
 * @separator: The string to be printed between strings.
 * @n: The number of strings to be printed.
 * @...: The variadic arguments, representing the strings to be printed.
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list strings;
	char *str;

	va_start(strings, n);

	for (i = 0; i < n; i++)
	{

		str = va_arg(strings, char *);
		printf("%s", str ? str : "(nil)");

		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(strings);
}
