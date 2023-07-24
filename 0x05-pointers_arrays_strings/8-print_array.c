#include "main.h"

/**
 * print_array - prints elements of array
 * @n: number of elements
 * @a: array to be printed
 */

void print_array(int *a, int n)
{
	int *intArray = a;
	int position = 0;

	while (*intArray != '\0')
	{
		if (position < n && position != (n - 1))
		{
			printf("%d, ", *intArray);
		}

		if (position == (n - 1))
		{
			printf("%d", *intArray);
		}

	intArray++;
	position++;
	}

	putchar('\n');
}
