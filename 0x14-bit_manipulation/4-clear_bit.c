#include "main.h"

/**
 * clear_bit - Clears the value of a bit to 0 at a given index.
 * @n: A pointer to the number where the bit should be cleared.
 * @index: The index of the bit to clear (starting from 0).
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int *number;

	number = n;

	if (number == NULL)
	{
		/* Return -1 if n is NULL */
		return (-1);
	}

	if (index >= sizeof(*number) * 8)
	{
		/* Return -1 if index is out of bounds */
		return (-1);
	}

	/* Clear the bit at the specified index */
	*number &= ~(1UL << index);

	/* Return 1 to indicate success */
	return (1);
}
