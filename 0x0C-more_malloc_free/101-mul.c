#include "main.h"

/**
 * is_digit_string - Checks if a given string consists of only digits.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */

int is_digit_string(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * multiply - Multiplies two positive numbers represented as strings.
 * @num1: The first input number as a string.
 * @num2: The second input number as a string.
 *
 * Description: This function multiplies two positive numbers represented as
 * strings and prints the result. It performs standard multiplication algorithm
 * using arrays and carries. It also includes input validation for digits.
 */

void multiply(const char *num1, const char *num2)
{
	int i, j, len1, len2,  result_len, *result, start = 0;

	if (!is_digit_string(num1) || !is_digit_string(num2))
	{
		printf("Error\n");
		exit(98);
	}
	len1 = strlen(num1);
	len2 = strlen(num2);
	result_len = len1 + len2;
	result = calloc(result_len, sizeof(int));
	if (!result)
	{
		exit(98);
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
	}
	while (start < result_len && result[start] == 0)
	{
		start++;
	}
	if (start == result_len)
	{
		printf("0\n");
	} else
	{
		for (i = start; i < result_len; i++)
		{
			printf("%d", result[i]);
		}
		printf("\n");
	}
	free(result);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: 0 on success, 98 on error.
 *
 * Description: This function reads two command-line arguments, which are
 * assumed to be positive numbers, and passes them to the 'multiply' function
 * to perform multiplication and print the result.
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	multiply(argv[1], argv[2]);

	return (0);
}
