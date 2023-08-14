#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - entry point
 * Return: 0 for success
 */

int _putchar(char c);

int main(void)
{

	char filename[] = __FILE__;
	char *newname;
	int i, size = 0;

	for (i = strlen(filename) + 1; i >= 0 ; i--)
	{
		if (filename[i] == '/')
			break;
		size++;
	}

	newname = malloc(size);

	for (i = strlen(filename); i >= 0 ; i--)
	{
		if (filename[i] == '/')
			break;
		newname[i] = filename[i];
	}

	for (i = 0; i < size ; i++)
	{
		_putchar(newname[i]);
	}

	_putchar('\n');

	free(newname);

	return (0);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
