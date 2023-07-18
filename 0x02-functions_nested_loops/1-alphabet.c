#include <stdio.h>

/**
* print_alphabet - function to print small letters
* _putchar - function to print single characters
*/

void print_alphabet(void);
int _putchar(char c);

/**
 * main -program entry point
 * Return: 0 for success
 */

int main(void)
{
	print_alphabet();
	return (0);
}

/**
 * print_alphabet - function to print aphabets
 */

void print_alphabet(void)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int i;

for (i = 0; i < (int)sizeof(alphabet) - 1; i++)
{
	_putchar(alphabet[i]);
}
	_putchar('\n');
}
