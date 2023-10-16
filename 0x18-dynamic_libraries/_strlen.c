#include "main.h"

/**
 * _strlen - Computes the length of a string.
 * @s: Input string
 *
 * Return: Length of the input string, or -1 if the input is NULL.
 */

int _strlen(char *s)
{
	int count = 0;

	if (s == NULL)
	{
		return (-1);
	}

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
