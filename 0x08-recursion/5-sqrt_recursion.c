#include "main.h"

/**
 * _sqrt_recursion - calculates square root of n
 * @n: number whose square root is to be found
 *
 * Return: square root of n
 */

int _sqrt_recursion(int n)
{
	double squareRoot = pow(n, 0.5);
	int truncatedSquareRoot = (int)squareRoot;

	if ((truncatedSquareRoot * truncatedSquareRoot) == n)
	{
		return (truncatedSquareRoot);
	}
	else
	return (-1);
}
