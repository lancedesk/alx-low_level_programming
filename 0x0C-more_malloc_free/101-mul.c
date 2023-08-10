#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of pointers to command-line arguments
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	char *first_num_str = argv[1];
	char *second_num_str = argv[2];

	if (argc != 3 || !isOnlyDigits(first_num_str) || !isOnlyDigits(second_num_str))
	{
		printf("Error\n");
		return (98);
	}

	if (*first_num_str == '0' || *second_num_str == '0')
	{
		printf("0\n");
	}
	else
	{
		performMultiplication(second_num_str, first_num_str);
	}

	return (0);
}

/**
 * performMultiplication - Multiplies two positive numbers and prints the result
 * @num1_str: First positive number as a string
 * @num2_str: Second positive number as a string
 */
void performMultiplication(char *num1_str, char *num2_str)
{
	int i, j, len1, len2, total, digit1, digit2, result = 0;
	int *product_array;

	len1 = strLength(num1_str);
	len2 = strLength(num2_str);
	total = len1 + len2;
	product_array = allocateAndInitialize(total);

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = num1_str[i] - '0';
		result = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2_str[j] - '0';
			result += product_array[i + j + 1] + (digit1 * digit2);
			product_array[i + j + 1] = result % 10;
			result /= 10;
		}
		if (result)
		{
			product_array[i + len2] += result;
		}
	}

	printProduct(product_array, total);
	free(product_array);
}

/**
 * isOnlyDigits - Checks if a string contains only digits
 * @str: Input string
 * Return: 1 if only digits, 0 otherwise
 */
int isOnlyDigits(char *str)
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
 * strLength - Calculates the length of a string
 * @str: Input string
 * Return: Length of the string
 */
int strLength(char *str)
{
	char *ptr = str;

	while (*str)
	{
		str++;
	}
	return (str - ptr);
}

/**
 * allocateAndInitialize - Allocates memory for an array and initializes it to zeros
 * @size: Size of the array to allocate
 * Return: Pointer to the allocated array
 */
void *allocateAndInitialize(unsigned int size)
{
	void *ptr = malloc(size * sizeof(int));

	if (!ptr)
	{
		return (NULL);
	}
	initializeMemory(ptr, 0, size * sizeof(int));
	return (ptr);
}

/**
 * initializeMemory - Fills memory with a constant value
 * @mem: Memory area
 * @value: Constant value
 * @size: Size of the memory area
 */
void initializeMemory(void *mem, char value, unsigned int size)
{
	char *ptr = mem;

	while (size--)
	{
		*ptr = value;
		ptr++;
	}
}

/**
 * printProduct - Prints the product array and handles leading zeros
 * @product_array: Pointer to the product array
 * @total: Total number of digits in the product
 */
void printProduct(int *product_array, int total)
{
	int i = 0;

	while (i < total && product_array[i] == 0)
	{
		i++;
	}

	if (i == total)
	{
		_putchar('0');
	}
	else
	{
		for (; i < total; i++)
		{
			_putchar(product_array[i] + '0');
		}
	}
	_putchar('\n');
}

