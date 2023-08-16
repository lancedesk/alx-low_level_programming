#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to search
 * @size: number of elements in array
 * @cmp: function to compare values
 * Return: returns index or -1 if not found
*/

int int_index(int *array, int size, int (*cmp)(int))
{
	int i, index = 0;

	if (size <= 0 || array == NULL || cmp == NULL)
	{
		return (-1);
	}

	for (i = 0; i <= size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			break;
		}
		index++;
	}

	if (index >= 0)
	{
		return (index);
	}

	else
	{
		return (-1);
	}
}
