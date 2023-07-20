#include "main.h"

/**
 * print_line - prints a line
 * @n: number of times to draw line
 */

void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
