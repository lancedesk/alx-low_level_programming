#include "search_algos.h"

void print_checked_value(int *array, size_t index);

/**
 * interpolation_search - Searches for a value in a sorted array
 * using Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array if found, otherwise -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, position;
	double r_l_diff, r_l_arr, arr_l;

	if (array == NULL)
		return (-1);

	while (left <= right && value >= array[left] && value <= array[right])
	{
		r_l_diff = (double)(right - left);
		r_l_arr = (array[right] - array[left]);
		arr_l = array[left];

		position = left + ((r_l_diff / r_l_arr) * (value - arr_l));

		print_checked_value(array, position);

		if (array[position] == value)
			return (position);
		else if (array[position] < value)
			left = position + 1;
		else
			right = position - 1;
	}

	printf("Value checked array[%lu] is out of range\n", position);
	return (-1);
}

/**
 * print_checked_value - Prints the value checked during interpolation search
 * @array: Pointer to the array being searched
 * @index: Index of the value being checked
 *
 * This function prints value checked during interpolation search algorithm.
 * It prints value and its corresponding index in the array.
 */

void print_checked_value(int *array, size_t index)
{
	printf("Value checked array[%lu] = [%d]\n", index, array[index]);
}
