#include "main.h"

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char.
 * @size: size of array
 * @c: specific char to be initialized
 * Return: pointer to the array
 * or Null if it fails
 */

char *create_array(unsigned int size, char c)
{
	char *pointer;
	int i;

	pointer = (char *)(malloc(size * sizeof(char)));

	if (pointer == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < (int)size; i++)
	{
		pointer[i] = c;
	}

	return (pointer);

	free(pointer);
}
