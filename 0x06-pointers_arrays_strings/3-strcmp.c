#include "main.h"

/**
 * _strcmp - copies one string to another
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 * Return:  return an integer less than, equal to,
 * or greater than zero if s1 (or the first n bytes thereof)
 * is found, respectively, to be less than,
 * to match, or be greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	else if (*s1 == '\0')
	{
		return (-(*s2));
	}
	else
	{
		return (*s1);
	}
}
