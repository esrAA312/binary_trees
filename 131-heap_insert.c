#include "binary_trees.h"

/**
 * heap_insert - inserts a value in a Binary Search Tree
 * @root double pointer to the root node of the HEAP to insert the value
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new = binary_tree_node(NULL, value);
		return (new ? *root = new : NULL);
	}

	return ((*root)->n > value
			? ((*root)->left
				? heap_insert(&((*root)->left), value)
				: ((*root)->left = binary_tree_node(*root, value)))
			: ((*root)->n < value
				? ((*root)->right
					? heap_insert(&((*root)->right), value)
					: ((*root)->right = binary_tree_node(*root, value)))
				: NULL));
}
