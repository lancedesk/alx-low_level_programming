#include <stdio.h>

/**
 * main - entry point
 * Return: always 0
 * a program that prints the alphabet in lowercase
 * and then in uppercase, followed by a new line.
 */

int main(void)
{
	char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char capitals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	char lowercase, uppercase;

for (i = 0; i < (int)sizeof(alphabets) - 1; i++)
{
	lowercase = (alphabets[i] + 32);
	putchar(lowercase);
}

for (i = 0; i < (int)sizeof(capitals) - 1; i++)
{
	uppercase = (capitals[i]);
	putchar(uppercase);
}
	putchar('\n');
	return (0);
}
