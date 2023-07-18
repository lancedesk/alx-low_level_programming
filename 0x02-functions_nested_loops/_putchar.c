#include <unistd.h>
/**
 * _putchar - function to print single character
 * @c: single character input
 * Return: writes single character to output
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
