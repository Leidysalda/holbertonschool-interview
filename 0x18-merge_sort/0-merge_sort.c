#include "sort.h"

/**
 * merge_array - function that merge an array
 *
 * @array: array
 * @new_array: array aux
 * @start: start
 * @middle: middle array
 * @end: end
 *
 * Return:
 */

void merge_array(int *array, int *new_array, int start, int middle, int end)
{
int i, j, k;

printf("Merging...\n");
printf("[left]: ");
print_array(array + start, middle - start);
printf("[right]: ");
print_array(array + middle, end - middle);

for (i = start, j = middle, k = 0; i < middle && j < end; k++)
if (array[i] < array[j])
new_array[k] = array[i++];
else
new_array[k] = array[j++];

while (i < middle)
new_array[k++] = array[i++];
while (j < end)
new_array[k++] = array[j++];
for (i = start, k = 0; i < end; i++)
array[i] = new_array[k++];

printf("[Done]: ");
print_array(array + start, end - start);
}

/**
 * split_array - split array
 *
 * @array: array
 * @new_array: aux
 * @start: start
 * @end: end
 *
 * Return:
 */

void split_array(int *array, int *new_array, int start, int end)
{
int middle;

if (end - start > 1)
{
middle = (end - start) / 2 + start;
split_array(array, new_array, start, middle);
split_array(array, new_array, middle, end);
merge_array(array, new_array, start, middle, end);
};
}

/**
 * merge_sort - function that sorts an array of integers in ascending order
 *
 * @array: array
 * @size: size array
 *
 * Return:
 */

void merge_sort(int *array, size_t size)
{
int *new_array;

new_array = malloc(sizeof(int) * size);
split_array(array, new_array, 0, size);
free(new_array);
}
