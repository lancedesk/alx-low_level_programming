#include "main.h"

/**
 * _print_rev_recursion - Recursive function to print a string in reverse
 * @s: string to be reversed
 */

void _print_rev_recursion(char *s)
{
	/* Base case: If the string is empty or reaches the end, return */
	if (*s == '\0')
	{
		return;
	}

	_print_rev_recursion(s + 1);
	_putchar(*s);
}
