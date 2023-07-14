#include <stdio.h>

/**
 * main - entry point
 * Return: always 0
 * a program that prints all the numbers
 * of base 16 in lowercase, followed by a new line.
 */

int main(void)
{
	int i;

for (i = 0; i < 10; i++)
{
	putchar(i + '0');
}

for (i = 0; i < 6; i++)
{
	putchar(i + 'a');
}

	putchar('\n');
	return (0);
}
