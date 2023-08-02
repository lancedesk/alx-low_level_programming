#include "main.h"

/**
 * is_prime_helper - helper function to check if number is prime
 * @n: number to check if prime
 * @i: divisor to check if n is divisible by
 *
 * Return: 1 if prime, 0 if not
 */

int is_prime_helper(int n, int i)
{
	if (n <= 1)
		return (0);

	if (i * i > n)
		return (1);

	if (n % i == 0)
		return (0);

	return (is_prime_helper(n, i + 1));
}

/**
 * is_prime_number - function to check if number is prime
 * @n: number to check if prime
 *
 * Return: 1 if prime, 0 if not
 */

int is_prime_number(int n)
{
	return (is_prime_helper(n, 2));
}
