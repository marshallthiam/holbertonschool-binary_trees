#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node == NULL)
        return (0);

    if (node->left == NULL && node->right == NULL)
        return (1);

    return (0);
}
