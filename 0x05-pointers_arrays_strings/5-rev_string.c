#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string input
 */

void rev_string(char *s)
{
		int len = strlen(s);
		char *start = s;
		char *end = s + len - 1;

		while (start < end)
		{
				char temp = *start;
				*start  = *end;
				*end = temp;
				start++;
				end--;
		}
}
