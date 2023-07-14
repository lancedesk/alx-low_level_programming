#include <stdio.h>

/**
 * main - entry point
 * Return: always 0
 * a program that prints all single digit numbers of base 10
 * starting from 0, followed by a new line.
 */

int main(void)
{
	int n;
	int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

for (n = 0; n < (int)sizeof(numbers) / (int)sizeof(numbers[0]); n++)
{
	printf("%d", numbers[n]);
}
	putchar('\n');
	return (0);
}
