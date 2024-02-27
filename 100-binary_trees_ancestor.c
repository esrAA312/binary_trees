#include "binary_trees.h"

/**
 * binary_trees_ancestor -  the lowest common ancestor
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: the lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{

	const binary_tree_t *F, *S;

	if (!first || !second)
		return (NULL);

	F = first;
	S = second;

	while (F != S)
	{
		F = F ? F->parent : second;
		S = S ? S->parent : first;
	}

	return ((binary_tree_t *)F);
}
