#include "main.h"

/**
 * print_diagsums - function that prints
 * the sum of the two diagonals of a square matrix of integers.
 *
 * @a: null terminated array of integers
 * @size : size of a square matrix of integers.
 */

void print_diagsums(int *a, int size)
{
	int i;
	int first_diagonal_sum = 0;
	int second_diagonal_sum = 0;

	for (i = 0; i < size; i++)
	{
		first_diagonal_sum += a[i * size + i];
		second_diagonal_sum += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d \n", first_diagonal_sum, second_diagonal_sum);
}
