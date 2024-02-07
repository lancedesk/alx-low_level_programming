#include "search_algos.h"

void print_index_range(size_t start, size_t end);
void print_index_value(int *array, size_t index);

/**
 * jump_search - Searches for a value in a sorted array
 * using Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Uses the square root of the size of the array as the jump step.
 * Prints each value in the array that is compared to the target value.
 *
 * Return: Index of the value in the array if found, otherwise -1
 */

int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size);
	size_t i = 0, j = 0;

	if (!array || size == 0)
		return (-1);

	while (j < size)
	{
		if (j != 0)
			print_index_value(array, i);
		if (array[j] >= value)
		{
			print_index_range(i, j);
			while (i <= j)
			{
				print_index_value(array, i);
				if (array[i] == value)
					return (i);
				i++;
			}
			return (-1);
		}
		if (j + jump + jump > size)
		{
			print_index_value(array, j);
			print_index_range(j, j + jump);
			while (j < size)
			{
				print_index_value(array, j);
				if (array[j] == value)
					return (j);
				j++;
			}
			return (-1);
		}
		i = j;
		j += jump;
	}
	return (-1);
}

/**
 * print_index_range - Prints the range of indexes
 * where a value is found in an array.
 * @start: The starting index of the range.
 * @end: The ending index of the range.
 *
 */

void print_index_range(size_t start, size_t end)
{
	printf("Value found between indexes [%lu] and [%lu]\n", start, end);
}

/**
 * print_index_value - Prints value stored at a specific index in an array.
 * @array: Pointer to the array containing the value to be printed.
 * @index: The index of the array from which the value is retrieved.
 *
 */

void print_index_value(int *array, size_t index)
{
	printf("Value checked array[%lu] = [%d]\n", index, array[index]);
}
