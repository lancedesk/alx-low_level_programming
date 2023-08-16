#include "3-calc.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: pointer to arguments array
 * Return: 0
 */


int main(int argc, char **argv)
{
	int a, b, result;
	char *operand;
	int (*func_ptr)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	operand = argv[2];

	func_ptr = get_op_func(operand);

	if (func_ptr == NULL)
	{
		printf("Error\n");
		return (99);
	}

	result = func_ptr(a, b);
	printf("%d\n", result);

	return (0);
}
