#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void split(int *array, int *arr, int start, int end);
void merge(int *array, int *arr, int start, int middle, int end);
void merge_sort(int *array, size_t size);


#endif /* SORT_H */
