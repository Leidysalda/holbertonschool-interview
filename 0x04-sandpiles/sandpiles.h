#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int validation(int grid[3][3]);
void sandpiles_loop(int grid[3][3], int grid2[3][3]);

#endif
