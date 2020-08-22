#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

void binary_tree_print(const binary_tree_t *);
typedef struct binary_tree_s heap_t;
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_depth(const heap_t *tree);
heap_t *swap_with_parent(heap_t *parent, heap_t *node);
size_t binary_tree_depth(const heap_t *tree);
size_t binary_tree_size(const heap_t *tree);
bool isComplete(const heap_t *tree, size_t index, size_t number_nodes);
int binary_tree_is_complete(const heap_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
size_t measure_height(const binary_tree_t *tree);
void insert_node(heap_t *root, heap_t *node, size_t floor, size_t size);

heap_t *is_complete( heap_t *node, heap_t *new, int size, int floor);



#endif /* _BINARY_TREES_H_ */