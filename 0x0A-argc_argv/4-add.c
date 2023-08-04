#include "main.h"

/**
 * main - entry point of the program
 * @argc: command line argument count
 * @argv: command line argument array
 * Return: returns 0
 */

int main(int argc, char *argv[])
{
	int i, j, error, result = 0, is_all_digits = 1;

	if (argc <= 1)
	{
		error = 0;

		printf("%d\n", error);
	}

	else
	{

	for (i = 1; i < argc; i++)
	{

		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				is_all_digits = 0;
				break;
			}
		}
	result += atoi(argv[i]);
	}

	if (!is_all_digits)
	{
		printf("Error\n");
		return (1);
	}

	else
	{
		printf("%d\n", result);
	}
	}

	return (0);
}
