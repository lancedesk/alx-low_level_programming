#include "main.h"

/**
 * swap_int - swaps values of 2 integers
 * @a: first integer paramenter
 * @b: second integer parameter
 */

void swap_int(int *a, int *b)
{
	int receivedA = *a;
	
	*a = *b;
	*b = receivedA;
}
