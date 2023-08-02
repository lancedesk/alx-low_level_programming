#include "main.h"

/**
 * _sqrt_recursion - calculates square root of n
 * @n: number whose square root is to be found
 * @low: low
 * @high: high
 *
 * Return: square root of n
 */

int _sqrt_recursive_helper(int n, int low, int high);

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		/* Square root of a negative number is not defined. */
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		/* Base case: Square root of 0 or 1 is the number itself. */
		return (n);
	}

	/* Call a helper function with a range from 1 to n/2. */
	return (_sqrt_recursive_helper(n, 1, n / 2));
}

/**
 * _sqrt_recursive_helper - helps calculate sqrt
 * @n: number whose square root is to be found
 * @low: low
 * @high: high
 * Return: square root of n
 */

int _sqrt_recursive_helper(int n, int low, int high)
{
	int mid;
	long int square;

	if (low > high)
	{
		/* If low becomes greater than high, square root not found. */
		return (-1);
	}

	/* Calculate the middle value. */
	mid = low + (high - low) / 2;
	square = (long int)mid * mid;

	if (square == n)
	{
		/* If the square of the middle is equal to n, we found the square root. */
		return (mid);
	}
	else if (square < n)
	{
		/* If the square of the middle is less than n, search the right half. */
		return (_sqrt_recursive_helper(n, mid + 1, high));
	}
	else
	{
		/* If the square of the middle is greater than n, search the left half. */
		return (_sqrt_recursive_helper(n, low, mid - 1));
	}
}
