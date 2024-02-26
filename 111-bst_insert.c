#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		new = binary_tree_node(NULL, value);
		return (new ? *tree = new : NULL);
	}

	return ((*tree)->n > value
			? ((*tree)->left
				? bst_insert(&((*tree)->left), value)
				: ((*tree)->left = binary_tree_node(*tree, value)))
			: ((*tree)->n < value
				? ((*tree)->right
					? bst_insert(&((*tree)->right), value)
					: ((*tree)->right = binary_tree_node(*tree, value)))
				: NULL));
}
