#include "main.h"

/**
 * factorial - function that returns the
 * factorial of a given number.
 * @n: number whose factorial is to return
 * Return: factorial of number n
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}
