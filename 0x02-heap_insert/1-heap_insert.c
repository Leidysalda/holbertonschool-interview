#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 *
 * @root: is a double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 *
 * Return: pointer or NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
  int total;

  total = binary_tree_is_perfect(*root);
  if (*root == NULL)
    {
      *root = binary_tree_node(*root, value);
      return (*root);
    }

  if (total == 1)
    if (value > (*root)->n)
      *root = binary_tree_insert_left(*root, value);
    else
      return (binary_tree_insert_left(*root, value));
  else
    {
      if (value > (*root)->n)
	*root = binary_tree_validation(*root, value);
      else
	return (binary_tree_validation(*root, value));
    }
  return (*root);
}

/**
 * binary_tree_validation - function that validate tree
 *
 * @tree: is a double pointer to the root node of the Heap
 * @value: value
 *
 * Return: (0) (1)
 */

binary_tree_t *binary_tree_validation(binary_tree_t *tree, int value)
{
  int num1, num2, total, total1;

  if (tree->left && tree->right)
    {
      num1 = binary_tree_height(tree->left);
      num2 = binary_tree_height(tree->right);
      total = binary_tree_is_perfect(tree->left);
      total1 = binary_tree_is_perfect(tree->right);

      if (num1 == num2 && total1)
	{
	  return (binary_tree_validation(tree->left,  value));
	}
      else if (num1 == num2 && total1 == 0)
	return (binary_tree_validation(tree->right, value));
      else if (total == 0)
	{
	  return (binary_tree_validation(tree->left, value));
	}
      else
	return (binary_tree_validation(tree->right, value));
    }
  else
    {
      if (tree->left == NULL)
	return (binary_tree_insert_left(tree, value));
      if (tree->right == NULL)
	return (binary_tree_insert_right(tree, value));
    }
  return (0);
}

/**
 * binary_tree_insert_left - function that validate tree left
 *
 * @parent: node parent
 * @value: value
 *
 * Return: (0) (1)
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
  binary_tree_t *node = NULL;

  if (parent == NULL)
    return (NULL);

  if (value > parent->n)
    {
      if (parent->left == NULL)
	{
	  node = binary_tree_node(parent, value);
	  node->left = parent;
	  node->parent = parent->parent;
	  node->right = parent->right;

	  if (parent->parent != NULL)
	    {
	      if (parent->parent->parent != NULL)
		parent->parent->left = node;
	      else
		parent->parent->right = node;
	    }
	  parent->parent = node;
	  parent->left = NULL;
	  parent->right = NULL;
	}
      else
	node = binary_tree_insert_left(parent->left, value);
    }
  else
    {
      if (parent->left == NULL)
	{
	  node = binary_tree_node(parent, value);
	  parent->left = node;
	}
      else
	node = binary_tree_insert_left(parent->left, value);
    }
  return (node);
}

/**
 * binary_tree_insert_right - function that validate tree right
 *
 * @parent: node parent
 * @value: value
 * 
 * Return: (0) (1)
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
  binary_tree_t *node = NULL;

  if (parent == NULL)
    return (NULL);

  if (value > parent->n)
    {
      if (parent->right == NULL)
	{
	  node = binary_tree_node(parent,  value);
	  node->right = parent;
	  node->parent = parent->parent;
	  node->left = parent->left;

	  if (parent->parent != NULL)
	    parent->parent->left = node;

	  parent->left->parent = node;           
	  parent->parent = node;
	  parent->left = NULL;
	  parent->right = NULL;
	}
      else
	node = binary_tree_insert_right(parent->right, value);
    }
  else
    {
      if (parent->right == NULL)
	{
	  node = binary_tree_node(parent, value);
	  parent->right = node;
	}
      else
	node = binary_tree_insert_right(parent->right, value);
    }
  return (node);
}

/**
 * binary_tree_height - Height tree
 *
 * @tree: tree
 *
 * Return: (0) (1)
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
  size_t height1, height2;

  if (tree == NULL)
    return (0);

  height1 = 0;
  height2 = 0;
  if (tree->left)
    height1 = 1;
  if (tree->right)
    height2 = 1;

  height2 += binary_tree_height(tree->right);
  height1 += binary_tree_height(tree->left);

  if (height2 > height1)
    return (height2);
  return (height1);
}

/**
 * binary_tree_leaves - leaves tree
 *
 * @tree: tree
 *
 * Return: (0) (1)
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
  size_t totalLeaves;

  if (tree == NULL)
    return (0);

  if (tree->left == NULL && tree->right == NULL)
    return (1);

  totalLeaves = binary_tree_leaves(tree->left) +
    binary_tree_leaves(tree->right);

  return (totalLeaves);
}

/**
 * binary_tree_is_perfect - function that validate tree is perfect
 *
 * @tree: tree
 *
 * Return: (0) (1)
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
  int totalLeaves = binary_tree_leaves(tree);
  int heightTree = binary_tree_height(tree);
  int perfect;
  int i, result = 1;

  for (i = 0; i < heightTree; i++)
    result = 2 * result;

  perfect = result;
  if (tree == NULL)
    return (0);

  if (totalLeaves == perfect)
    return (1);
  return (0);
}
