#include "variadic_functions.h"

/**
 * print_numbers - Print a sequence of numbers
 * followed by a separator and a newline.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers to be printed.
 * @...: The variadic arguments, representing the integers to be printed.
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list numbers;

	va_start(numbers, n);

	for (i = 0; i < n; i++)
	{
		if (i != n - 1 && separator != NULL)
		{
			printf("%d%s", va_arg(numbers, int), separator);
		}
		else if (i == n - 1 && separator != NULL)
		{
			printf("%d", va_arg(numbers, int));
		}
		else
		{
			printf("%d", va_arg(numbers, int));
		}
	}

	printf("\n");

	va_end(numbers);
}
