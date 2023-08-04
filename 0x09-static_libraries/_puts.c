#include "main.h"

/**
 * _puts - writes the string s to stdout
 * @s: The string to print
 */
void _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]); /* Call _putchar to print each character */
		i++;
	}
	_putchar('\n');/* Add a new line after completion of output */
}
