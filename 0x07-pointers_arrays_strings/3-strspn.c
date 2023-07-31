#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: null terminated string array to search
 * @accept: Null-terminated string containing characters to search.
 * Return: Number of bytes in the initial segment of s
 * that consist only of bytes from the accept string.
 */

unsigned int _strspn(char *s, char *accept)
{
	int bytenumber = strspn(s, accept);

	return (bytenumber);
}
