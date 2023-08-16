#include "3-calc.h"

/**
 * op_add - adds two integers
 * @a: first integer
 * @b: second integer
 * Return: addition result
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integers
 * @a: first integer
 * @b: second integer
 * Return: subtraction result
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiples two integers
 * @a: first integer
 * @b: second integer
 * Return: product result
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two integers
 * @a: first integer
 * @b: second integer
 * Return: division result
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		/* Handle division by zero error */
		printf("Error\n");
		exit(100);
	}
	else
	{
		return (a / b);
	}
}

/**
 * op_mod - modulo of two integers
 * @a: first integer
 * @b: second integer
 * Return: modulo result
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		/* Handle division by zero error */
		printf("Error\n");
		exit(100);
	}
	else
	{
		return (a % b);
	}
}
