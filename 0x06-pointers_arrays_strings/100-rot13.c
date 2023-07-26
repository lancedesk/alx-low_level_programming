#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 * @str: array for encoding
 * Return: returns the encoded string
 */

char *rot13(char *str)
{
	char *ptr = str;

	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			char base = (*str >= 'a') ? 'a' : 'A';
			*str = ((*str - base + 13) % 26) + base;
		}

		str++;
	}

	return ptr;
}
