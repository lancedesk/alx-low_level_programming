#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 *                         using Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value in the array if found, otherwise -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, pos;
	double hi_lo_dif, hi_lo_arr;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		hi_lo_dif = (double)(high - low);
		hi_lo_arr = (array[high] - array[low]);
		pos = low + ((hi_lo_dif / hi_lo_arr) * (value - array[low]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);

		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	if (low <= high)
		printf("Value checked array[%lu] is out of range\n", low);

	return (-1);
}
