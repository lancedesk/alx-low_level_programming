#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 *
 * Return: None.
 */

void print_binary(unsigned long int n)
{

	if (n == 0)
	{
		_putchar('0');
	}

	else if (n == 1)
	{
		_putchar('1');
	}

	else
	{
		while (n > 0)
		{
			/* Print the least significant bit */
			_putchar((n & 1) + '0');

			/* Right-shift to get the next bit */
			n >>= 1;
		}
	}
}
