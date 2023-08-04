#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: null terminated string array to search in
 * @accept: null terminated array to search
 * Return: a pointer to the byte in s that matches
 * one of the bytes in accept,
 * or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	char *occurence = strpbrk(s, accept);

	if (occurence != NULL)
	{
		return (occurence);
	}
	else
	{
	return (NULL);
	}
}
