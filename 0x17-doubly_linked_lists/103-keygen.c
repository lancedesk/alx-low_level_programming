#include "lists.h"

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of pointers to the arguments.
 * Return: Always 0 (indicating successful execution).
 */

int main(int argc, char *argv[])
{
	char key[7], *char_array;
	int length = strlen(argv[1]), i, temp;

	(void)argc;
	char_array = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (length ^ 59) & 63;
	key[0] = char_array[temp];

	temp = 0;
	for (i = 0; i < length; i++)
		temp += argv[1][i];
	key[1] = char_array[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < length; i++)
		temp *= argv[1][i];
	key[2] = char_array[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < length; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	key[3] = char_array[rand() & 63];

	temp = 0;
	for (i = 0; i < length; i++)
		temp += (argv[1][i] * argv[1][i]);
	key[4] = char_array[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	key[5] = char_array[(temp ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
