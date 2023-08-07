#include "main.h"

/**
 * str_concat - concatenates two strings.
 *
 * @s1: first string
 * @s2: second string
 * Return: returns NULL if failure
 */

char *str_concat(char *s1, char *s2)
{
	size_t i, size1, size2, totalsize;
	char *newstring;

	/* Return NULL early if NULL s1 or s2 */
	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}

	size1 = strlen(s1);
	size2 = strlen(s2);
	totalsize = size1 + size2;

	newstring = (char *)malloc((totalsize + 1) * sizeof(char));

	if (newstring == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size1; i++)
	{
		newstring[i] = s1[i];
	}

	for (i = 0; i < size2; i++)
	{
		newstring[size1 + i] = s2[i];
	}

	/* Null termination at the end */
	newstring[totalsize] = '\0';

	return (newstring);
}
