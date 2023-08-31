#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string containing binary digits.
 *
 * Return: The converted number, or 0
 * if there are invalid characters
 * in the string or if the string is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	int index = 0, wrong_character_count = 0;
	unsigned int result = 0;

	/* Return 0 immediately for NULL input */
	if (b == NULL)
	{
		return (0);
	}

	while (b[index] != '\0')
	{
		if (b[index] != '0' && b[index] != '1')
		{
			wrong_character_count++;
		}
		index++;
	}

	if (wrong_character_count > 0)
	{
		/* Return 0 for invalid characters */
		return (0);
	}

	/* Conversion from binary to unsigned integer */
	index = 0;
	while (b[index] != '\0')
	{
		result = result * 2 + (b[index] - '0');
		index++;
	}

	return (result);
}

