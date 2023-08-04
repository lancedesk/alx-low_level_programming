#include "main.h"

/**
 * main - entry point of the program
 * @argc: command line argument count
 * @argv: command line argument array
 * Return: returns 0
 */

int main(int argc, char *argv[])
{
	int num1, num2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);

		printf("%d\n", num1 * num2);
	}
	return (0);
}
