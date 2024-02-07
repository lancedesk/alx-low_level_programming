#include <stdio.h>

/**
 * binary_search - Search for a value in a sorted array
 * using Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Description: Prints the array being searched every time it changes.
 *
 * Return: Index of the value in the array if found, otherwise -1
 */

int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid;

	if (array == NULL)
	{
		return (-1);
	}

	while (left <= right)
	{
		size_t i;

		printf("Searching in array:");
		for (i = left; i <= right; i++)
		{
			if (i == right)
				printf(" %d\n", array[i]);
			else
				printf(" %d,", array[i]);
		}

		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
