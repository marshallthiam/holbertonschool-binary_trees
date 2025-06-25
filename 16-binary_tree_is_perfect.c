#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node.
 * Return: Height or 0 if NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	size_t left = binary_tree_height(tree->left);
	size_t right = binary_tree_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_size - Measures the size (number of nodes) of a binary tree.
 * @tree: Pointer to the root node.
 * Return: Size or 0 if NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * power - Calculates the power of a number recursively.
 * @base: Base number.
 * @exp: Exponent.
 * Return: base raised to the power exp.
 */
size_t power(size_t base, size_t exp)
{
	if (exp == 0)
		return (1);
	return (base * power(base, exp - 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node.
 * Return: 1 if perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t height = binary_tree_height(tree);
	size_t size = binary_tree_size(tree);

	/* A perfect binary tree of height h has (2^(h+1)) - 1 nodes */
	return (size == (power(2, height + 1) - 1));
}
