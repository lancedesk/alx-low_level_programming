#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line.
 *
 * @s: null terminated string to print
 */

void _puts_recursion(char *s)
{
	int i;

	for (i = 0; i < (int)strlen(s); i++)
	{
		if(s[i] != '\0')
		{
			_putchar(s[i]);
		}
	}
	_putchar('\n');
}
