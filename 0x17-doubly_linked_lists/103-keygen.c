#include <stdio.h>
#include <stdlib.h>

int strlength(char *str);
char calculate_key_part(char *input, int factor, int bitwise_op);
char *generate_program_key(char *input);


/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always 0 (indicating successful execution).
 */

int main(int argc, char *argv[])
{
	char *program_key;

	(void)argc;
	program_key = generate_program_key(argv[1]);
	printf("%s", program_key);
	free(program_key);

	return (0);
}

/**
 * strlength - Calculates the length of a string.
 * @str: The input string.
 * Return: Length of the string.
 */

int strlength(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * calculate_key_part - Calculates a part of program key based on input string.
 * @input: The input string.
 * @factor: A multiplier used in the calculation.
 * @bitwise_op: A bitwise operation used in the calculation.
 * Return: Calculated key part.
 */

char calculate_key_part(char *input, int factor, int bitwise_op)
{
	int length = strlength(input);
	int i, temporary = 0;
	(void)factor;

	for (i = 0; i < length; i++)
	{
		temporary += (input[i] * input[i]);
	}
	return (input[(temporary ^ bitwise_op) & 63]);
}

/**
 * generate_program_key - Generates the program key based on input string.
 * @input: The input string.
 * Return: Generated program key.
 */

char *generate_program_key(char *input)
{
	char *codex;
	char *program_key = malloc(8 * sizeof(char));
	int length = strlength(input);
	int i, temporary = 0;

	codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	temporary = (length ^ 59) & 63;
	program_key[0] = codex[temporary];

	temporary = 0;
	for (i = 0; i < length; i++)
	{
		temporary += input[i];
	}

	program_key[1] = codex[(temporary ^ 79) & 63];

	temporary = 1;

	for (i = 0; i < length; i++)
	{
		temporary *= input[i];
	}

	program_key[2] = codex[(temporary ^ 85) & 63];

	temporary = 0;
	for (i = 0; i < length; i++)
	{
		if (input[i] > temporary)
		{
			temporary = input[i];
		}
	}

	srand(temporary ^ 14);
	program_key[3] = codex[rand() & 63];

	program_key[4] = calculate_key_part(input, 1, 239);
	program_key[5] = calculate_key_part(input, input[0], 229);

	program_key[6] = '\0';
	return (program_key);
}

