#include "binary_trees.h"

/**
 * heap_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the HEAP to insert the value
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t **tree;

	tree=root;
	if (!tree)
		return (NULL);

	if (!*tree)
	{
		new = binary_tree_node(NULL, value);
		return (new ? *tree = new : NULL);
	}

	return ((*tree)->n > value
			? ((*tree)->left
				? heap_insert(&((*tree)->left), value)
				: ((*tree)->left = binary_tree_node(*tree, value)))
			: ((*tree)->n < value
				? ((*tree)->right
					? heap_insert(&((*tree)->right), value)
					: ((*tree)->right = binary_tree_node(*tree, value)))
				: NULL));
}
