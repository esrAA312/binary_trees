#include "binary_trees.h"
#include <stdio.h>

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)

{
	int balance;
	avl_t *parent = NULL;
	    avl_t *current = *tree;
	        avl_t *new_node = NULL;

	if (!tree || !value)
		return (NULL);

		while (current != NULL)
	{
		parent = current;

		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL;)
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	current = new_node;

	while (current != NULL)
	{
		balance = binary_tree_balance(current);

		if (balance > 1 && value < current->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else if (balance < -1 && value > current->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else if (balance > 1 && value > current->left->n)
		{
			current->left = binary_tree_rotate_left(current->left);
			*tree = binary_tree_rotate_right(*tree);
		}
		else if (balance < -1 && value < current->right->n)
		{
			current->right = binary_tree_rotate_right(current->right);
			*tree = binary_tree_rotate_left(*tree);
		}

		current = current->parent;
	}

	return (new_node);
}

