#include <stdio.h>

/**
 * linear_search - Search for a value in an array using Linear search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Description: Each time a value in the array is compared to the value
 * being searched, it prints the value checked.
 *
 * Return: Index of the first occurrence of value in array,
 * or -1 if value is not present or if array is NULL
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
