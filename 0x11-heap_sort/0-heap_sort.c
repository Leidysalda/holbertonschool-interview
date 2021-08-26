#include "sort.h"

/**
 * heap_b - function that build heap
 *
 * @list_h: array
 * @i: element
 * @j: element
 * @size: size array
 *
 * Return: Always 0
 */

void heap_b(int *list_h, int i, int j, size_t size)
{
int max = j;
int left_c = j * 2 + 1;
int right_c = j * 2 + 2;
int temp;

if (left_c < i && list_h[left_c] > list_h[max])
max = left_c;

if (right_c < i && list_h[right_c] > list_h[max])
max = right_c;

if (max != j)
{
temp = list_h[j];
list_h[j] = list_h[max];
list_h[max] = temp;
print_array(list_h, size);
heap_b(list_h, i, max, size);
}
}

/**
 * heap_sort - function that sorts an array
 *
 * @array: array
 * @size: size array
 *
 * Return: Always 0
 */


void heap_sort(int *array, size_t size)
{
int i;
int temp = 0;

for (i = size / 2; i >= 0; i--)
heap_b(array, size, i, size);

for (i = size - 1; i >= 0; i--)
{
temp = array[0];
array[0] = array[i];
array[i] = temp;
if (i != 0)
print_array(array, size);
heap_b(array, i, 0, size);
}
}
