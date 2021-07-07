#include "menger.h"

/**
 * menger - Menger Sponge to draw
 *
 * @level: is the level of the Menger Sponge to draw
 *
 * Return: Success o failure
 */

void menger(int level)
{
int i, j, lev;

if (level < 0)
return;

lev = (int)pow(3, level);

for (i = 0; i < lev; i++)
{
for (j = 0; j < lev; j++)
{
if (i % 3 == 1 && j % 3 == 1)
{
printf(" ");
continue;
}
if (lev / 3 <= i && 2 * (lev / 3) > i)
{
if (lev / 3 <= j && 2 * (lev / 3) > j)
{
printf(" ");
continue;
}
}
if (validate_one(lev, i, j))
continue;
if (validate_two(i, j))
continue;

printf("#");
}
printf("\n");
}
}


/**
 * validate_one - validate
 *
 * @lev: is the level of the Menger Sponge to draw
 * @i: int
 * @j: int
 *
 * Return: Success o failure
 */

int validate_one(int lev, int i, int j)
{
int a, b;

for (a = 1; a < lev / 3; a += 3)
{
for (b = 1; b < lev / 3; b += 3)
{
if ((lev / 9) * a <= i && ((lev / 9) * a) + lev / 9 > i)
{
if ((lev / 9) * b <= j && ((lev / 9) * b) + lev / 9 > j)
{
printf(" ");
return (1);
}
}
}
}
return (0);
}


/**
 * validate_two - validate
 *
 * @i: int
 * @j: int
 *
 * Return: Success o failure
 */

int validate_two(int i, int j)
{
int k, l;

for (k = 3; k < 6; k++)
{
for (l = 3; l < 6; l++)
{
if (i % 9 == k && j % 9 == l)
{
printf(" ");
return (1);
}
}
}
return (0);
}








