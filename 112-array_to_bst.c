#include "binary_trees.h"
/**
 * array_to_bst - turns an array 
 * @array: array to turns to BST tree
 * @size: size of array
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t X = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	while(X<size)
	{
		if (X == 0)
		{
			bst_insert(&root, array[X]);
			if (!bst_insert(&root, array[X]))
			{
				return (NULL);
			}

		}
		else
		{
			bst_insert(&root, array[X]);
			if (!bst_insert(&root, array[X]))
			{
				return (NULL);
			}
		}
		if (!bst_insert(&root, array[X]))
	{
			return (NULL);
		}
		X++;
	}
	return (root);
}
