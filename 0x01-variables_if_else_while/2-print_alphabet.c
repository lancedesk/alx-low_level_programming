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

	for (i = 0; 0 < sizeof(alphabets) - 1; i++)
		{
			lowercase = (alphabets[i] + 32);
			putchar(lowercase);
		}
	return (0);
}
