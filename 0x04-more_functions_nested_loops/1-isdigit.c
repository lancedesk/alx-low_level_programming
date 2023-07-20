#include "main.h"

/**
 * _isdigit - tests digits
 * @c: number input
 * Return: returns 1 if is a digit
 * or 0 if not a digit
 */

int _isdigit(int c)
{
	if (isdigit(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
