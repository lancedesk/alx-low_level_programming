#include "main.h"

/**
 * reverse_array - reverses array of integers
 * @a: array to reverse
 * @n: number of elements in the array
 */

void reverse_array(int *a, int n)
{
	int i, temp;

	for (i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}
