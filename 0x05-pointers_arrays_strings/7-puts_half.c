#include "main.h"

/**
 * puts_half - prints second half of string
 * @str: string input
 */

void puts_half(char *str)
{
	int len = strlen(str);
	int odd = (len - 1) / 2;
	int position = 0;
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (len % 2 == 0 && position >= (len / 2))
		{
			putchar(*ptr);
		}

		else if (len % 2 != 0 && position > odd)
		{
			putchar(*ptr);
		}

	ptr++;
	position++;
	}

	putchar('\n');
}
