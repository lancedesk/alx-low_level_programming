#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip
 * to get from n to m.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count;
	unsigned long int difference;

	/* XOR gives the differing bits */
	difference = n ^ m;
	count = 0;

	while (difference)
	{
		/* Check the least significant bit */
		count += difference & 1;

		/* Right-shift to process the next bit */
		difference >>= 1;
	}

	return (count);
}

