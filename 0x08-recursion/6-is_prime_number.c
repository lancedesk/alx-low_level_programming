#include "main.h"

/**
 * is_prime_number - function to check if
 * number is prime number
 * @n: number to check if prime number
 *
 * Return: 1 if prime, 0 if not
 */

int is_prime_number(int n)
{
	int i;

	if (n <= 1)
		return (0);

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return (0);
	}

	return (1);
}
