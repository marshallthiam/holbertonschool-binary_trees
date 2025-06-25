#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point to test the binary_tree_uncle function
 *
 * Return: Always 0
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *n1;
    binary_tree_t *n2;
    binary_tree_t *n3;
    binary_tree_t *uncle;

    root = binary_tree_node(NULL, 98);
    n1 = binary_tree_node(root, 12);
    n2 = binary_tree_node(root, 402);
    root->left = n1;
    root->right = n2;

    n3 = binary_tree_node(n1, 54);
    n1->left = n3;

    binary_tree_print(root);

    uncle = binary_tree_uncle(n3);
    printf("Uncle of [%d]: ", n3->n);
    if (uncle)
        printf("%d\n", uncle->n);
    else
        printf("(nil)\n");

    return (0);
}
