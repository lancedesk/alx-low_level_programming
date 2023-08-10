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
	int i, size1, size2, totalsize, index = 0;
	char *newstring, *tempstring;

	size1 = strlen(s1);
	size2 = strlen(s2);
	totalsize = size1 + size2;

	tempstring  = (char *)(malloc(totalsize * sizeof(char)));
	if (tempstring == NULL)
	{
		return (NULL);
	}

	newstring = malloc((size1 + n) * sizeof(char));
	if (newstring == NULL)
	{
		free(tempstring);
		return (NULL);
	}

	for (i = 0; i < size1; i++)
	{
		tempstring[i] = s1[i];
		index++;
	}

	for (i = 0; i < size2; i++)
	{
		tempstring[index] = s2[i];
		index++;
	}

	for (i = 0; i < (int)n; i++)
	{
		newstring[i] = tempstring[i];
	}

	newstring[index] = '\0';
	free(tempstring);
	return (newstring);
}
