#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t binary_tree_size(const heap_t *tree)
{
	size_t l_size, r_size;

	if (tree == NULL)
		return (0);

	l_size = binary_tree_size(tree->left);
	r_size = binary_tree_size(tree->right);
	return (1 + l_size + r_size);
}

/**
 * convert - converts number into a binary which determine the floor to insert the node
 * @num: input number
 * Return: result string
 */
char *toBinary(unsigned long int num)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = "0123456789abcdef";

	ptr = &buffer[49];
	*ptr = 0;
	do {
		*--ptr = rep[num % 2];
		num /= 2;
	} while (num);
	return (ptr);
}

/**
 * insert -insert a node in the rigth location
 * @root: double pointer to root of max heap
 * @node: node to insert
 */
void heapify(heap_t **root, heap_t *node)
{
	char c, *binary;
	unsigned int i, size;
	heap_t *tmp = NULL;

	tmp = *root;
	size = binary_tree_size(tmp) + 1;
	binary = toBinary(size);
    //printf("binary %s",binary);
	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
				tmp->right = node;
			else if (c == '0')
				tmp->left = node;
			node->parent = tmp;
		}
		else if (c == '1')
			tmp = tmp->right;
		else if (c == '0')
			tmp = tmp->left;
	}
}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int tmp;

	if (!root)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	heapify(root, new_node);
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = tmp;
		new_node = new_node->parent;
	}
	return (new_node);
}