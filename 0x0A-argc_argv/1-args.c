#include "main.h"

/**
 * main - entry point of the program
 * @argc: command line argument count
 * @argv: command line argument array
 * Return: returns 0
 */

int main(int argc, char *argv[])
{
	/*Ignore the argv paramenter */
	(void) argv;

	printf("%d\n", argc - 1);

	return (0);
}
