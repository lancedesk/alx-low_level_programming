#include "main.h"

/**
 * print_alphabet - function to print aphabets
 */

void print_alphabet(void)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int i;

for (i = 0; i < (int)sizeof(alphabet) - 1; i++)
{
	_putchar(alphabet[i]);
}
	_putchar('\n');
}
