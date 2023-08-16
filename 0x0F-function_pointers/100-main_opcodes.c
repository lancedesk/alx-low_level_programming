#include <stdlib.h>
#include <stdio.h>

/**
 * main - Entry point for the program.
 * @argc: Number of arguments.
 * @argv: Argument vector.
 *
 * Return: 0 for success.
 */
int main(int argc, char *argv[])
{
	int i, inputSize;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	inputSize = atoi(argv[1]);
	if (inputSize < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < inputSize; i++)
	{
		printf("%02hhx", *((char *)main + i));
		if (i < inputSize - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}

