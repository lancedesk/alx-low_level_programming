#include "main.h"

/**
 * cap_string - converts characters to uppercase
 * @str: array to reverse
 * Return: return the capitalized string
 */

char *cap_string(char *str)
{
	int capitalize = 1;

	while (*str != '\0')
	{
		if (isalpha(*str))
		{
			if (capitalize)
			{
				*str = toupper(*str);
				capitalize = 0;
			}
			else
			{
				*str = tolower(*str);
			}
		}
		else
		{
			capitalize = 1;
		}

		str++;
	}

	return (str);
}
