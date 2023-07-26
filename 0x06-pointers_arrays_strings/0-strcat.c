#include "main.h"

/**
 * _strcat - concatenates 2 arrays
 * @dest: destination array
 * @src: source array
 * Return: pointer to the new array.
 */

char *_strcat(char *dest, char *src)
{
	dest = strcat(dest, src);
	return dest;
}
