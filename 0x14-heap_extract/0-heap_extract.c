#include "binary_trees.h"
#include <stdlib.h>

/**
 * height_tree - height
 * @tree: Entry point
 *
 * Return: 0 on success, error code on failure
 */
size_t height_tree(const heap_t *tree)
{
size_t left_h = 0;
size_t right_h = 0;

if (!tree)
return (0);

if (tree->left)
left_h = 1 + height_tree(tree->left);

if (tree->right)
right_h = 1 + height_tree(tree->right);

if (left_h > right_h)
return (left_h);
return (right_h);
}

/**
 * size_tree - size
 * @tree: Entry point
 *
 * Return: 0 on success, error code on failure
 */
size_t size_tree(const binary_tree_t *tree)
{
size_t left_h = 0;
size_t right_h = 0;

if (!tree)
return (0);

if (tree->left)
left_h = 1 + size_tree(tree->left);

if (tree->right)
right_h = 1 + size_tree(tree->right);

return (left_h + right_h);
}

/**
 * _preorder - preorder
 * @tree: Entry point
 * @node: node
 * @height: heig
 *
 * Return: 0 on success, error code on failure
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
if (!tree)
return;

if (!height)
*node = tree;
height--;

_preorder(tree->left, node, height);
_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies
 * @root: Entry point
 *
 * Return: 0 on success, error code on failure
 */
void heapify(heap_t *root)
{
int value;
heap_t *tmp1, *tmp2;

if (!root)
return;

tmp1 = root;

while (1)
{
if (!tmp1->left)
break;
if (!tmp1->right)
tmp2 = tmp1->left;
else
{
if (tmp1->left->n > tmp1->right->n)
tmp2 = tmp1->right;
else
tmp2 = tmp1->right;
}
if (tmp1->n > tmp2->n)
break;

value = tmp1->n;
tmp1->n = tmp2->n;
tmp2->n = value;
tmp1 = tmp2;
}
}

/**
 * heap_extract - heap
 * @root: Entry point
 *
 * Return: 0 on success, error code on failure
 */
int heap_extract(heap_t **root)
{
int value;
heap_t *heap_r, *node;

if (!root || !*root)
return (0);

heap_r = *root;
value = heap_r->n;

if (!heap_r->left && !heap_r->right)
{
*root = NULL;
free(heap_r);
return (value);
}

_preorder(heap_r, &node, height_tree(heap_r));

heap_r->n = node->n;
if (node->parent->right)
node->parent->right = NULL;
else
node->parent->left = NULL;

free(node);
heapify(heap_r);
*root = heap_r;
return (value);
}
