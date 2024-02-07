#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array if found, otherwise -1
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low, high, mid;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size - 1) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	while (low <= high)
	{
		printf("Searching in array: ");
		for (mid = low; mid <= high; mid++)
		{
			printf("%d", array[mid]);
			if (mid < high)
				printf(", ");
		}
		printf("\n");

		mid = (low + high) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}
