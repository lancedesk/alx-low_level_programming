#include "main.h"

/**
 * string_nconcat - concatenates two strings.
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to allocate
 * Return: pointer to newly allocated space
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, size1, size2, index = 0;
	char *newstring;

	size1 = (s1 != NULL) ? strlen(s1) : 0;
	size2 = (s2 != NULL) ? strlen(s2) : 0;

	if (n >= size2)
		/* Limit n to size2 to avoid unnecessary overallocation */
		n = size2;

	newstring = malloc((size1 + n + 1) * sizeof(char));
	if (newstring == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size1; i++)
	{
		newstring[index] = s1[i];
		index++;
	}

	/* Only iterate up to n */
	for (i = 0; i < n; i++)
	{
		newstring[index] = s2[i];
		index++;
	}

	newstring[index] = '\0';
	return (newstring);
}

