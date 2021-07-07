#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grids
 * @grid: Left 3x3 grid
 *
 * Return: void
 */

void print_grid(int grid[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
}
printf("\n");
}
}


/**
 * sandpiles_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int i = 0, j = 0, status;

while (1)
{
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
grid1[i][j] = grid1[i][j] + grid2[i][j], grid2[i][j] = 0;
}
status = validation(grid1);
if (status)
{
printf("=\n");
print_grid(grid1);
sandpiles_loop(grid1, grid2);
}
else
break;
}
}


/**
 * validation - validate grid
 * @grid: Left 3x3 grid
 *
 * Return: (0) (1)
 */

int validation(int grid[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] >= 4)
return (1);
}
}
return (0);
}


/**
 * sandpiles_loop - loop
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 * Return: void
 */

void sandpiles_loop(int grid1[3][3], int grid2[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid1[i][j] >= 4)
{
grid1[i][j] = grid1[i][j] - 4;
if (i + 1 < 3)
grid2[i + 1][j]++;
if (i - 1 >= 0)
grid2[i - 1][j]++;
if (j + 1 < 3)
grid2[i][j + 1]++;
if (j - 1 >= 0)
grid2[i][j - 1]++;
}
}
}
}
