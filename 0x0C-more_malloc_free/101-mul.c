#include "main.h"

int onlyDigits(char *str);
int getLength(char *str);
void *allocateMemory(unsigned int size);
void printProduct(int *product, int total);
void performMultiplication(char *num1, char *num2);

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the command-line arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	char *first_number = argv[1];
	char *second_number = argv[2];

	if (argc != 3 || !onlyDigits(first_number) || !onlyDigits(second_number))
	{
		printf("Error\n");
		exit(98);
	}

	if (*first_number == '0' || *second_number == '0')
	{
		printf("0\n");
	}
	else
	{
		performMultiplication(second_number, first_number);
	}

	return (0);
}

/**
 * performMultiplication - Multiplies two strings representing numbers
 * @num1: First input number as a string
 * @num2: Second input number as a string
 */

void performMultiplication(char *num1, char *num2)
{
	int i, j, len1, len2, total, digit1, digit2, result = 0;
	int *product;

	len1 = getLength(num1);
	len2 = getLength(num2);
	total = len1 + len2;
	product = allocateMemory(total);

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = num1[i] - '0';
		result = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2[j] - '0';
			result += product[i + j + 1] + (digit1 * digit2);
			product[i + j + 1] = result % 10;
			result /= 10;
		}
		if (result)
		{
			product[i + len2] += result;
		}
	}

	printProduct(product, total);
	free(product);
}

/**
 * onlyDigits - checks if a string contains only digits
 * @str: input string
 * Return: 1 if only digits, 0 otherwise
 */

int onlyDigits(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}

	return (1);
}

/**
 * getLength - calculates the length of a string
 * @str: input string
 * Return: length of the string
 */

int getLength(char *str)
{
	char *ptr = str;

	while (*str)
	{
		str++;
	}

	return (str - ptr);
}

/**
 * allocateMemory - allocates memory and initializes it to zeros
 * @size: size of the memory to allocate
 * Return: pointer to the allocated memory
 */

void *allocateMemory(unsigned int size)
{
	void *ptr = malloc(size * sizeof(int));

	if (!ptr)
	{
		return (NULL);
	}
	memset(ptr, 0, size * sizeof(int));
	return (ptr);
}

/**
 * printProduct - prints the product array and handles leading zeros
 * @product: pointer to the product array
 * @total: total number of digits in the product
 */

void printProduct(int *product, int total)
{
	int i = 0;

	while (i < total && product[i] == 0)
	{
		i++;
	}

	if (i == total)
	{
		printf("0\n");
		return;
	}

	for (; i < total; i++)
	{
		printf("%d", product[i]);
	}

	printf("\n");
}
