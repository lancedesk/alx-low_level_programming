#include <stdio.h>

/**
 * main - entry point
 * Return: always 0
 * a program that prints the alphabet in lowercase, followed by a new line.
 * prints all the letters except q and e
 */

int main(void)
{
	char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	char lowercase;

for (i = 0; i < (int)sizeof(alphabets) - 1; i++)
{
	lowercase = (alphabets[i] + 32);
	if (lowercase == 'e' || lowercase == 'q')
	{
		continue;
	}
	putchar(lowercase);
}
	putchar('\n');
	return (0);
}
