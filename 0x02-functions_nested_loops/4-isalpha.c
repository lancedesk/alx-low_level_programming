#include "main.h"
#include <ctype.h>

/**
 * _isalpha - checks if variable isalpha
 * @c: character input
 * Return: 1 for islower and 0 for !
 */

int _isalpha(int c)
{
if (isalpha(c) || islower(c))
{
	return (1);
}
else
{
	return (0);
}
}
