#include "main.h"

/**
 * main - Multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Argument vectors
 * Return: 0 on success
 **/

int main(int argc, char *argv[])
{
	unsigned long product;
	int index1, index2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (index1 = 1; index1 < argc; index1++)
	{
		for (index2 = 0; argv[index1][index2] != '\0'; index2++)
		{
			if (argv[index1][index2] > '9' || argv[index1][index2] < '0')
			{
				printf("Error\n");
				exit(98);
			}
		}
	}

	product = atoi(argv[1]) * atoi(argv[2]);
	printf("%lu\n", product);
	return (0);
}
