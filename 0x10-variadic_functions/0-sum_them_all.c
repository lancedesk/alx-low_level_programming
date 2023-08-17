#include "variadic_functions.h"

/**
 * sum_them_all - Calculate the sum of variadic arguments.
 * @n: The number of variadic arguments.
 * @...: Variable number of arguments to be summed.
 *
 * Return: The sum of all variadic arguments, or 0 if @n is 0.
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i;
	va_list numbers;

	/* Check if n is 0 */
	if (n == 0)
	{
		return (0);
	}

	/* Initialize va_list */
	va_start(numbers, n);

	/* Loop through variadic arguments and calculate sum */
	for (i = 0; i < n; i++)
	{
		sum += va_arg(numbers, int);
	}

	/* Clean up va_list */
	va_end(numbers);

	return (sum);
}
