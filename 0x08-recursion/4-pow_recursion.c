#include "main.h"

/**
 * _pow_recursion - calculates power of x
 * @x: number to be raised to power y
 * @y: number to raise x to
 * Return: power of number x to y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else if (y == 1)
	{
		return (x);
	}
	else if (y == 2)
	{
		return (x * x);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
