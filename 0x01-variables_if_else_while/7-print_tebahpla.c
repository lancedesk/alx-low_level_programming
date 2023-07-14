#include <stdio.h>

/**
 * main - entry point
 * Return: always 0
 * a program that prints the alphabet in lowercase, followed by a new line.
 */

int main(void)
{
	char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	char lowercase;

for (i = (int)sizeof(alphabets) - 2; i >= 0;  i--)
{
	lowercase = (alphabets[i] + 32);
	putchar(lowercase);
}
	putchar('\n');
	return (0);
}
