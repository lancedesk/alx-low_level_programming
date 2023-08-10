#include "main.h"

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: number of elements
 * @size: string 2
 * Return: pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *pointer;

	if (nmemb  == 0 || size == 0)
	{
		return (NULL);
	}

	pointer = calloc(nmemb, size);

	if (pointer == NULL)
	{
		return (NULL);
	}

	return (pointer);
}

