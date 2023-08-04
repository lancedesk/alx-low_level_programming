#include "main.h"

/**
 * _strchr - haracter in a string.
 * @s: string to be searched in
 * @c: character to search
 * Return: pointer to first occurence
 * or NULL if not found.
 */

char *_strchr(char *s, char c)
{
	char *occurence = strchr(s, c);

	if (occurence != NULL)
	{
		return (occurence);
	}
	else
	{
	return (NULL);
	}
}
