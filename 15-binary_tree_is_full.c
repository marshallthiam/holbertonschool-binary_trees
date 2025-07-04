#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If leaf node, it's full */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If both left and right are present, check subtrees */
    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    /* If one child is missing, it's not full */
    return (0);
}
