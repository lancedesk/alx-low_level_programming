#include "main.h"

/**
 * print_alphabet_x10 - function to print aphabets
 */

void print_alphabet_x10(void)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int i, j = 0;

while (j < 10)
{
for (i = 0; i < (int)sizeof(alphabet) - 1; i++)
{
	_putchar(alphabet[i]);
}
	_putchar('\n');
	j++;
}
}
