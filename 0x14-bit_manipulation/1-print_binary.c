#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 *
 * Return: Void.
 */

void print_binary(unsigned long int n)
{
	int size, i, first_found;
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	size = sizeof(unsigned long int) * 8;
	first_found = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			_putchar('1');
			first_found = 1;
		}
		else if (first_found)
		{
			_putchar('0');
		}
	}
}

