#include "main.h"

/**
 * string_toupper - converts string to uppercase
 * @str: array to reverse
 * Return: return the uppercase string
 */

char *string_toupper(char *str)
{
	int i = 0;
	int length = strlen(str);

	for (; i < length; i++)
	{
		str[i] = toupper(str[i]);
	}

	return (str);
}
