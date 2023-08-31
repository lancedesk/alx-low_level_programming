#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The number from which to get the bit value.
 * @index: The index of the bit to retrieve
 * (starting from 0).
 *
 * Return: The value of the bit at the specified index
 * or -1 if an error occurred (invalid index).
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int number;

	number = n;

	if (index >= sizeof(number) * 8)
	{
		/* If invalid index, return -1 */
		return (-1);
	}

	return ((number >> index) & 1);
}
