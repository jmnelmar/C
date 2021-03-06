/*
el max heap es un arbol binario completo donde cada nodo tiene dos hijos y se debe cumplir 
que el nodo hijo debe ser menor a su padre.

TASK:
* Write a function that inserts a value into a Max Binary Heap:
* Prototype: heap_t *heap_insert(heap_t **root, int value)
  root is a double pointer to the root node of the Heap
  value is the value store in the node to be inserted
* Your function must return a pointer to the inserted node, or NULL on failure
* If the address stored in root is NULL , the created node must become the root node.
* You have to respect a Max Heap ordering
* You are allowed to have up to 6 functions in your file
Help
Your file 0-binary_tree_node.c will be compiled during the correction

lo que se necesita.
Una funcion swap.
Una funcion que determine si el arbol esta completo
Una funcion que calcule el level del nodo.
*/

#include <stdlib.h>
#include "binary_trees.h"

heap_t *initializate(int value){
	heap_t *new = NULL;
	new = calloc(1, sizeof(binary_tree_t));
	if(new == NULL)
		return NULL;
	new -> n = value;
	new -> left = NULL;
	new -> right = NULL;
	new -> parent = NULL;
	return new;
}



void insert_node(heap_t *root, heap_t *node, size_t floor, size_t size){
	size_t isComplete = 0; //binary_tree_is_complete( root );
	if( isComplete == 0 ) {
		
		if( root->left == NULL || root->right == NULL){
			if (root->left == NULL)
				root->left = node;
			else
				root->right = node;
			node->parent = root;
		}else{
			if(floor+1<size){
				insert_node(root->left,node,floor+1,size);
				insert_node(root->right,node,floor+1,size);
			}
			
		}	
	}

}



heap_t *heap_insert(heap_t **root, int value){
	
	heap_t *new = NULL;
    heap_t *aux = NULL;

	new = calloc(1, sizeof(binary_tree_t));
    int size = 0;
	
	if(new == NULL)
		return NULL;
	
    new = initializate(value);

    if (*root == NULL){
        *root = new;
        return new;
    }

	size = binary_tree_height( *root );
    aux = is_complete( *root, new, size,0);

    /*if( aux == NULL){
        aux = *root;
        while( aux -> left != NULL)
		    aux = aux -> left;
        aux -> left = new;
        new -> parent = aux;
    }*/
    
    
	
    return aux;
    

}


heap_t *swap_with_parent(heap_t *parent, heap_t *node){
		
	int val ;
	val = parent->n;
	parent->n = node->n;
	node->n = val; 

	/*section to debug*/
	/*printf("\tnode:%i, node->parent:%i, node->left:%i, node->right:%i \n", 
		(node!=NULL)? node->n:-1,
		(node->parent!=NULL)? node->parent->n:-1,
		(node->left!=NULL)? node->left->n:-1,
		(node->right!=NULL)? node->left->n:-1
	);

	printf("\tparent:%i, parent->parent:%i, parent->left:%i, parent->right:%i \n", 
		(parent!=NULL)? parent->n:-1,
		(parent->parent!=NULL)? parent->parent->n:-1,
		(parent->left!=NULL)? parent->left->n:-1,
		(parent->right!=NULL)? parent->right->n:-1
	);*/
	
	return parent;
}



/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the height
 * Return: height of tree or 0 if the tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	height = measure_height(tree);
	return (height - 1);
}

/**
 * measure_height - helper func for binary_tree_height
 * @tree: input tree
 * Return: the maximun height between left and right nodes + 1
 */
size_t measure_height(const binary_tree_t *tree)
{
	size_t maxl, maxr, max;

	if (tree == NULL)
		return (0);

	maxl = measure_height(tree->left);
	maxr = measure_height(tree->right);
	if (maxl > maxr)
		max = maxl;
	else
		max = maxr;
	return (max + 1);
}


heap_t *is_complete( heap_t *node, heap_t *new, int size, int floor){
    int floor2 = binary_tree_height( node );

   printf("size:%i, floor2:%i, node:%i, floor:%i\n", size, floor2,node->n,floor);
	if( new -> parent == NULL){
		if( (node -> left != NULL && node -> right != NULL) || (floor == size && size >0)  ){
			is_complete(node -> left,new, size,floor+1);
			floor = floor -1;	
			is_complete(node -> right,new, size,floor+1);
		}
		else if (node -> left == NULL ){
			//if( size == 0 || floor<=size ){
				node -> left = new;
				new ->parent = node;
				printf("inserted in parent:%i\n", new->parent->n);
			//}
			return new;
		}
		else if (node -> right == NULL ){
			//if(size==0 || floor<= size){
				node -> right = new;
				new ->parent = node;
				printf("inserted in parent:%i\n", new->parent->n);
			//}
			return new;
		}
	}
	
    return new; 

}