#include "main.h"

/**
 * allocate_memory - allocates memory to string
 * @size: size of string
 * Return: returns final string
 */

char *allocate_memory(size_t size)
{
	char *newstring = (char *)malloc((size + 1) * sizeof(char));

	return (newstring);
}

/**
 * copy_string - copies string
 * @source: string to copy
 * Return: returns NULL if failure
 */

char *copy_string(char *source)
{
	size_t i, size;
	char *newstring;

	size = strlen(source);
	newstring = allocate_memory(size);
	if (newstring != NULL)
	{
		for (i = 0; i < size; i++)
		{
			newstring[i] = source[i];
		}
		newstring[size] = '\0';
	}
	return (newstring);
}

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 * Return: returns NULL if failure
 */

char *str_concat(char *s1, char *s2)
{
	size_t i, size1, size2, totalsize;
	char *newstring;

	if (s1 == NULL && s2 == NULL)
	{
		return (NULL);
	} else if (s1 != NULL && s2 == NULL)
	{
		return (copy_string(s1));
	} else if (s1 == NULL && s2 != NULL)
	{
		return (copy_string(s2));
	}

	size1 = strlen(s1);
	size2 = strlen(s2);
	totalsize = size1 + size2;

	newstring = allocate_memory(totalsize);

	if (newstring != NULL)
	{
		for (i = 0; i < size1; i++)
		{
			newstring[i] = s1[i];
		}

		for (i = 0; i < size2; i++)
		{
			newstring[size1 + i] = s2[i];
		}
		newstring[totalsize] = '\0';
	}

	return (newstring);
}
