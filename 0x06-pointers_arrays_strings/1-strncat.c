#include "main.h"

/**
 * _strncat - concatenates 2 arrays
 * @dest: destination array
 * @src: source array
 * @n: number of characters to copy
 * Return: pointer to the new array.
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_length = strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + i] = '\0';
	return (dest);
}
