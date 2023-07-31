#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 * Return: pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	memset(s, b, n);
	return (s);
}
