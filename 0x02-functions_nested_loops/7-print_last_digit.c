#include "main.h"

/**
 * print_last_digit - prints the last digit
 * @number: digit input to test
 * Return: value of the last digit
 */

int print_last_digit(int number)
{
	int result;

	result = (number % 10);
if (number < 0)
{
	result = -result;
}
	_putchar(result + '0');
	return (result);
}
