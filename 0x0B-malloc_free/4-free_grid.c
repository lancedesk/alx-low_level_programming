#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid
 * previously created
 * by your alloc_grid function.
 *
 * @grid: allocates memory
 * @height: height of 2d array
 */

void free_grid(int **grid, int height)
{
	int i;

	if (height == 0)
	{
		free(grid);
	}

	else
	{
		for (i = 0; i < height; i++)
		{
			free(grid[i]);
		}

		free(grid);
	}
}
