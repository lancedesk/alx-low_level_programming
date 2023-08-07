#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory which contains a copy of the string
 * given as a parameter.
 *
 * @str: pointer to string
 * Return: returns NULL if str = NULL
 */

char *_strdup(char *str)
{
	char *newstring;
	size_t size, i;

	size = strlen(str);
	newstring = (char *)(malloc((size + 1) * sizeof(char)));

	if (newstring == NULL || size == 0)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		newstring[i] = str[i];
	}

	newstring[size] = '\0'; /* Null-terminate the new string */
	return (newstring);
}
