#!/usr/bin/python3
"""
Module to calculate the perimeter of an island.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in the grid.

    Args:
    - grid (List[List[int]]): A list of lists representing the grid.

    Returns:
    - int: The perimeter of the island.

    Constraints:
    - The grid is a list of list of integers:
      - 0 represents a water zone
      - 1 represents a land zone
    - One cell is a square with side length 1
    - Grid cells are connected horizontally/vertically (not diagonally).
    - Grid is rectangular, width and height don’t exceed 100
    - Grid is completely surrounded by water, and there is one island
    - (or nothing).
    - The island doesn’t have “lakes” (water inside that isn’t connected
    - to the water around the island).
    """
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += 4

                # Check left neighbor
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

                # Check top neighbor
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

    return perimeter
