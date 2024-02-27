#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree from a given node
 * @tree: pointer to node of tree to measure
 * Return: height of tree or 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t right, left;

	if (tree == NULL)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (1 + (left > right ? left : right));
}
