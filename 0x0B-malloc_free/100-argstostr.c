#include "main.h"

/**
 * argstostr - concatenates all the arguments
 * of your program.
 *
 * @ac: number of arguments
 * @av: an array of arguments
 * Return: returns pointer to new string
 */

char *argstostr(int ac, char **av)
{
	int i, total_length = 0, index = 0;
	char *finalstring;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	/* Calculate the total length of the concatenated string */
	for (i = 0; i < ac; i++)
	{
		/* +1 for the newline character */
		total_length += strlen(av[i]) + 1;
	}

	/* Allocate memory for the concatenated string */
	finalstring = (char *)(malloc((total_length + 1) * sizeof(char)));

	if (finalstring == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		/* Copy argument to the result string */
		strcpy(finalstring + index, av[i]);
		index += strlen(av[i]);
		finalstring[index] = '\n'; /* Add a newline character */
		index++;
	}

	return (finalstring);
}
