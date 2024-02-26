#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 * @tree: Root node of the tree to be rotated.
 *
 * Return: Pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left != NULL)
		new_root->left->parent = tree;

	new_root->left = tree;
	new_root->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree == tree->parent->left)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}

	tree->parent = new_root;

	return (new_root);
}

