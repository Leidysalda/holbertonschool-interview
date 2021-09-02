#include "search_algos.h"

/**
 * advanced_binary - function that searches for a value in
 * a sorted array of integers.
 *
 * @array: array
 * @size: size array
 * @value: value
 *
 * Return: Always EXIT_SUCCESS
 */

int advanced_binary(int *array, size_t size, int value)
{
int h = ((size - 1) / 2);
int result = 0;
size_t i = 0;

if (array == NULL || size < 1)
return (-1);

printf("Searching in array: ");
for (i = 0; i < size; i++)
{
printf("%d", array[i]);
if (i != (size - 1))
printf(", ");
else
printf("\n");
}

if (array[h] == value && h == 0)
return (h);
else if (size == 1)
return (-1);

if (array[h] >= value)
return (advanced_binary(array, h + 1, value));

h++;
result = advanced_binary(&array[h], size - h, value);
if (result == -1)
return (-1);
return (h + result);
}
