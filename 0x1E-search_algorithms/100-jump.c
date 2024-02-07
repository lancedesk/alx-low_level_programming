#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array
 * using Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Description: Uses the square root of the size of the array as the jump step.
 * Prints each value in the array that is compared to the target value.
 *
 * Return: Index of the value in the array if found, otherwise -1
 */

int jump_search(int *array, size_t size, int value)
{
	size_t jump, prev, i;
	char *message = "Value found between indexes [%lu] and [%lu]\n";

	if (array == NULL || size == 0)
		return (-1);

	jump = sqrt(size);
	prev = 0;

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

		if (prev + jump >= size)
		{
			printf(message, prev, size - 1);
			break;
		}

		if (array[prev + jump] >= value)
		{
			printf(message, prev, prev + jump);
			break;
		}

		prev += jump;
	}

	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

	for (i = prev; i < size && i <= prev + jump; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
