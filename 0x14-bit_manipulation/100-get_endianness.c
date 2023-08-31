#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	unsigned int number;
	char *check_endian;

	number = 1;
	check_endian = (char *)&number;

	if (*check_endian)
	{
		/* Return 1 if Little endian */
		return (1);
	}
	else
	{
		/* Return 0 if Big endian */
		return (0);
	}
}

