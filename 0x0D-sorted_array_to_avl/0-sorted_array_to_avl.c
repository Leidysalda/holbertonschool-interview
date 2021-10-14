#include "binary_trees.h"

/**
 * sorted_array_to_avl - sorted array
 *
 * @array: The array to be printed
 * @size: Size of the array
 *
 * Return: Pointer or NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *tree;

if (array == NULL)
return (NULL);

tree = search_avl(array, 0, size - 1, NULL);
return (tree);
}

/**
 * search_avl - search avl
 *
 * @array: array
 * @first: start array
 * @last: end array
 * @node: node
 *
 * Return: 0 on success, error code on failure
 */

avl_t *search_avl(int *array, int first, int last, avl_t *node)
{
int half;
avl_t *new_node;

if (first > last)
return (NULL);

new_node = malloc(sizeof(avl_t));
if (new_node == NULL)
return (NULL);

half = (first + last) / 2;
new_node->n = array[half];
new_node->parent = node;
new_node->left = search_avl(array, first, half - 1, new_node);
new_node->right = search_avl(array, half + 1, last, new_node);
return (new_node);
}
