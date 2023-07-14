#include <stdio.h>

/**
 * main - entry point
 * Return: always 0
 * a program that prints all possible combinations
 * of single-digit numbers.
 */

int main(void)
{
	int i;

for (i = 0; i < 10; i++)
{
	putchar(i + '0');
if (i < 9)
{
	putchar(',');
	putchar(' ');
}
}
	putchar('\n');
	return (0);
}
