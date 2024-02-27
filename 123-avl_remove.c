#include "binary_trees.h"
int get_successor(avl_t *node);
int replacesuccessor(avl_t *root);
int get_successor(avl_t *node);
/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int le;
	if (node == NULL)
		return (0);

	le = get_successor(node->left);
	return (le == 0 ? node->n : le);
}

/**
 * replacesuccessor - Replace the node value with its successor.
 * @root: The node with two children.
 * Return: The value of the successor.
 */
int replacesuccessor(avl_t *root)
{
	int X;

	X = get_successor(root->right);
	root->n = X;
	return (X);
}

/**
 * removen- Remove a node based on its children.
 * @node: The node to remove.
 * Return: 0 if no children, or other value if it has.
 */
int removen(avl_t *node)
{
	avl_t *ch;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		ch = node->left ? node->left : node->right;

		if (node->parent->right == node)
			node->parent->right = ch;
		else
			node->parent->left = ch;

		ch->parent = node->parent;
		free(node);
		return (0);
	}
	else
		return (replacesuccessor(node));
}

/**
 * bst_remove - Remove a node from a AVL tree.
 * @root: The root of the tree.
 * @value: The value of the node to remove.
 * Return: The updated tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int t;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		avl_remove(root->left, value);
	else if (value > root->n)
		avl_remove(root->right, value);
	else if (value == root->n)
	{
		t = removen(root);
		if (t != 0)
			avl_remove(root->right, t);
	}
	return (root);
}
