#include "main.h"

/**
 * alloc_grid - returns a pointer
 * to a 2 dimensional array of integers.
 * @width: width of array
 * @height: height of array
 * Return: returns pointer to array
 */

int **alloc_grid(int width, int height)
{
	int i, j;
	int **the2darray;

	if (height <= 0 || width <= 0)
	{
		return (NULL);
	}

	/* Allocate memory for array of pointers (rows)*/
	the2darray = (int **)(malloc(height * sizeof(int)));

	if (the2darray == NULL)
	{
		return (NULL);
	}

	/* Allocate memory for each row (array of integers)*/
	for (i = 0; i < height; i++)
	{
		the2darray[i] = (int *)malloc(width * sizeof(int));

		if (the2darray[i] == NULL)
		{
			/* Clean up previously allocated rows */
			for (j = 0; j < i; j++)
			{
				free(the2darray[j]);
			}
			free(the2darray);
			return (NULL);
		}

		/* Initialize each element to 0 */
		for (j = 0; j < width; j++)
		{
			the2darray[i][j] = 0;
		}
	}

	return (the2darray);
}
