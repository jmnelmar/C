#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "Binary_tree.h"

void printleft();

int main(){
    binary_tree_t *root;
    size_t height;
    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    height = binary_tree_height(root);

    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_height(root->right);
    printf("Height from %d: %lu\n", root->right->n, height);
    height = binary_tree_height(root->left->right);
    printf("Height from %d: %lu\n", root->left->right->n, height);

    /*printf("Height from %d: %i\n", root->n, (int)height);
    height = binary_tree_height(root->right);
    printf("Height from %d: %i\n", root->right->n, (int)height);
    height = binary_tree_height(root->left->right);
    printf("Height from %d: %i\n", root->left->right->n, (int)height);*/
}

