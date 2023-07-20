#include "main.h"

/**
 * main - entry point
 * Return: 0 for success
 */

int main(void)
{
		fizz_buzz();
		return (0);
}

/**
 * fizz_buzz - prints Fizz Fizzbuzz
 */

void fizz_buzz(void)
{
		int i;

		for (i = 1; i <= 100; i++)
		{
				if ((i % 3) == 0 && (i % 5) == 0)
				{
						printf(" FizzBuzz");
						continue;
				}

				else if ((i % 3) == 0)
				{
						printf(" Fizz");
						continue;
				}

				else if ((i % 5) == 0)
				{
						printf(" Buzz");
						continue;
				}

				if (i == 1)
				{
					printf("%d", i);
				} else
				
				{
					printf(" %d", i);
				}
		}
		putchar('\n');
}
