#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	/*heap_t *root;
	heap_t *node;
	root = NULL;
	node = heap_insert(&root, 98);
	printf("Inserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 402);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 12);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 46);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
node = heap_insert(&root, 128);
printf("\nInserted: %d\n", node->n);
binary_tree_print(root);
node = heap_insert(&root, 256);
printf("\nInserted: %d\n", node->n);
binary_tree_print(root);
node = heap_insert(&root, 512);
printf("\nInserted: %d\n", node->n);
binary_tree_print(root);
node = heap_insert(&root, 50);
printf("\nInserted: %d\n", node->n);
binary_tree_print(root);*/

	heap_t *root;
	root = NULL;
	//root = binary_tree_node(NULL, 98);
	heap_insert(&root, 98);
	binary_tree_print(root);
	//root->left = binary_tree_node(root, 12);
	heap_insert(&root, 12);
	binary_tree_print(root);
	//root->left->left = binary_tree_node(root->left, 6);
	heap_insert(&root, 6);
	binary_tree_print(root);
	//root->left->right = binary_tree_node(root->left, 16);
	heap_insert(&root, 16);
	binary_tree_print(root);
	//root->right = binary_tree_node(root, 402);
	heap_insert(&root, 402);
	binary_tree_print(root);
	//root->right->left = binary_tree_node(root->right, 256);
	heap_insert(&root, 256);
	binary_tree_print(root);
	//root->right->right = binary_tree_node(root->right, 512);
	/*heap_insert(&root, 512);
	binary_tree_print(root);*/
	return (0);


}