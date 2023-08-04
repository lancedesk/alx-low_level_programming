#include "main.h"

/**
 * main - entry point of the program
 * @argc: command line argument count
 * @argv: command line argument array
 * Return: returns 0
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
