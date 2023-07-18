#include <stdio.h>

/**
 * main - entry point
 * Return: 0
 */

int _putchar(char c);

int main(void)
{
	char putcharString[] = "_putchar";
	int i;

for (i = 0; i < (int)sizeof(putcharString) - 1; i++)
{
	_putchar (putcharString[i]);
}
	_putchar ('\n');
	return (0);
}
