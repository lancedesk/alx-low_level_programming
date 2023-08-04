#include "main.h"

/**
 * _strstr - function finds the first occurrence
 * of the substring needle in the string haystack
 * @haystack: null terminated string
 * array to search in
 * @needle: null terminated array to search
 * Return: a pointer to the beginning of the
 * located substring,
 * or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	char *locatedstring = strstr(haystack, needle);

	if (locatedstring != NULL)
	{
		return (locatedstring);
	}
	else
	{
		return (NULL);
	}
}
