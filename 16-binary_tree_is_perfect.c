#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth or 0 if tree is NULL
 */
 size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree && tree->parent)
    {
        depth++;
        tree = tree->parent;
    }
    return (depth);
}

/**
 * check_perfect - recursive helper to check if tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: expected depth of all leaves
 * @level: current level in the tree (root is 0)
 * Return: 1 if perfect, 0 otherwise
 */
static int check_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (!tree)
        return 1;

    /* If leaf node, check depth */
    if (!tree->left && !tree->right)
        return (depth == level + 1);

    /* If internal node missing a child, not perfect */
    if (!tree->left || !tree->right)
        return 0;

    /* Recurse on both children */
    return (check_perfect(tree->left, depth, level + 1) &&
            check_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if NULL or not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth;

    if (!tree)
        return 0;

    /* Get depth of leftmost leaf */
    depth = binary_tree_depth(tree);

    return check_perfect(tree, depth, 0);
}
