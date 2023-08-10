#include "main.h"

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: argument vectors
 * Return: 0 on success
 **/

int main(int argc, char *argv[])
{
	char *num1_str, *num2_str;

	if (argc != 3 || !onlyNumbers(argv[1]) || !onlyNumbers(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1_str = argv[1];
	num2_str = argv[2];

	multiplyAndPrint(num1_str, num2_str);

	return (0);
}

/**
 * multiplyAndPrint - multiplies two positive numbers and prints the result
 * @num1_str: first positive number as a string
 * @num2_str: second positive number as a string
 **/
void multiplyAndPrint(char *num1_str, char *num2_str)
{
	int len1 = _strlen(num1_str);
	int len2 = _strlen(num2_str);
	int total_len = len1 + len2;
	int *result = calloc(total_len, sizeof(int));
	int start, i, j, carry, digit1, digit2, temp;  

	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = num1_str[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2_str[j] - '0';
			temp = result[i + j + 1] + (digit1 * digit2) + carry;

			result[i + j + 1] = temp % 10;
			carry = temp / 10;
		}

		if (carry)
		{
			result[i] += carry;
		}
	}

	start = (result[0] == 0) ? 1 : 0;

	for (i = start; i < total_len; i++)
	{
		printf("%d", result[i]);
	}
	printf("\n");
	free(result);
}

/**
 * onlyNumbers - checks if a string has only numbers
 * @c: input string
 * Return: 1 if true, 0 if false
 **/
int onlyNumbers(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string s
 * Return: length of string
 **/
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return (length);
}

