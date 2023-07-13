#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char text[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	ssize_t i;

	for (i = 0; text[i] != '\0'; i++)
	{
	write(2, &text[i], 1);
	}
	return (1);
}
