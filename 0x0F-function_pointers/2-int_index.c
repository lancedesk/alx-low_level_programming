#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to search
 * @size: number of elements in array
 * @cmp: function to compare values
 * Return: returns index if found or not
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i, index = -1; /* Initialize index to -1 */

	if (size > 0 && cmp && array)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
			{
				/* Update index only when a match is found */
				index = i;
				break;
			}
		}
	}

	/* Return the correct index or -1 if no match found */
	return (index);
}

