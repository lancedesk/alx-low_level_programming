#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string input
 */

void rev_string(char *s)
{
	int len = strlen(s);
	char *ptr = s + len - 1;

	while (ptr >= s)
	{
		putchar(*ptr);
		ptr--;
	}
	putchar('\n');
}
