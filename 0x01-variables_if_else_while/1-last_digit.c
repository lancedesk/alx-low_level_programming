#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point
 * Return: always 0
 * program will assign a random number to the variable n
 * each time it is executed
 */

int main(void)
{
	int n, ld; /*Last digit variable is represented by ld here */

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	ld = abs(n % 10); /*Take the absolute value of the modulo */
	/* your code goes there */
	if (n < 0)
	{
		ld = -ld;
	}
	if (ld > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, ld);
	} else if (ld == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, ld);
	} else if (ld < 6 && ld != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, ld);
	}
	return (0);
}
