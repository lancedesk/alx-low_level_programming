#include "lists.h"

char calculate_key_part(char *input, int factor, int bitwise_op);
char *generate_key(char *input);

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of pointers to the arguments.
 * Return: Always 0 (indicating successful execution).
*/

int main(int argc, char *argv[])
{
    char *key = generate_key(argv[1]);
	
	(void)argc;
    printf("%s", key);
    free(key);

    return (0);
}

/**
 * calculate_key_part - Calculates a part of the key based on input string.
 * @input: The input string.
 * @factor: A multiplier used in the calculation.
 * @bitwise_op: A bitwise operation used in the calculation.
 * Return: Calculated key part.
*/

char calculate_key_part(char *input, int factor, int bitwise_op)
{
    int length = strlen(input);
    int i, temporary = 0;
	
	(void)factor;

    for (i = 0; i < length; i++)
	{
        temporary += (input[i] * input[i]);
    }
    return (input[(temporary ^ bitwise_op) & 63]);
}

/**
 * generate_key - Generates the key based on input string.
 * @input: The input string.
 * Return: Generated key.
*/

char *generate_key(char *input)
{
    char *codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
    int len = strlen(input), i, tmp;

    char *key = malloc(8 * sizeof(char));

    tmp = (len ^ 59) & 63;
    key[0] = codex[tmp];

    tmp = 0;
    for (i = 0; i < len; i++)
	{
        tmp += input[i];
    }
    key[1] = codex[(tmp ^ 79) & 63];

    tmp = 1;
    for (i = 0; i < len; i++)
	{
        tmp *= input[i];
    }
    key[2] = codex[(tmp ^ 85) & 63];

    tmp = 0;
    for (i = 0; i < len; i++)
	{
        if (input[i] > tmp)
		{
            tmp = input[i];
        }
    }

    srand(tmp ^ 14);
    key[3] = codex[rand() & 63];

    key[4] = calculate_key_part(input, 1, 239);
    key[5] = calculate_key_part(input, input[0], 229);

    key[6] = '\0';
    return (key);
}
