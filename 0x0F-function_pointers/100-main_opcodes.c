#include <stdio.h>
#include <stdlib.h>

void print_opcodes(void (*func)());
void main_wrapper();

/**
 * main - entry point
 * @argc: number of arguments.
 * @argv: argument vector.
 * Return: 0 for success.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	int num_bytes = atoi(argv[1]);
	if (num_bytes <= 0)
	{
		printf("Error\n");
		return (2);
	}

	if (num_bytes > 40)
	{
		printf("Error\n");
		return (3);
	}

	/* Calls main */
	void (*main_func)() = main_wrapper;
	print_opcodes(main_func);

	return (0);
}

/**
 * print_opcodes - prints opcodes
 */
void print_opcodes(void (*func)())
{
	int i;
	unsigned char *opcodes = (unsigned char *)func;

	printf("%02x", opcodes[0]);
	for (i = 1; opcodes[i] != 0xc3; i++)
	{
		printf(" %02x", opcodes[i]);
	}
	printf("\n");
}

/**
 * main_wrapper - Wrapper function to call main
 */
void main_wrapper()
{
	main(0, NULL);
}
