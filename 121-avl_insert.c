#include "binary_trees.h"
/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree for
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int B;
	avl_t *N = NULL;

	if (!tree || !value)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree); }
	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert(&(*tree)->left, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert(&(*tree)->right, value);
		if ((*tree)->right == NULL)
			return (NULL); }
	else
		return (NULL);
	B = binary_tree_balance(*tree);
	if (B > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (B < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (B > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (B < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	N = *tree;
	return (N);
}
