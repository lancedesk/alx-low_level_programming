#include "main.h"

/**
 * array_range - creates an array of integers.
 * @min: starting number in the array
 * @max: last number in the array
 * Return: pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *pointer, i, totalsize;

	if (min > max)
	{
		return (NULL);
	}

	totalsize = (max - min) + 1;

	pointer = (int *)(calloc(totalsize, sizeof(int)));

	if (pointer == NULL)
	{
		return (NULL);
	}

	for (i = min; i < totalsize; i++)
	{
		pointer[i] = min++;      
	}

	pointer[totalsize] = '\0';

	return (pointer);
}
