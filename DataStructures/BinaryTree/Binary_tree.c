#include "Binary_tree.h"

/*Task 0*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    node = calloc(1,sizeof(binary_tree_t));

    if(node == NULL)
        return NULL;
    node->parent = parent;
    node->n = value;
    return node;    
}

/*Task 1*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;
    node = binary_tree_node(parent,value);
    if(node == NULL || parent == NULL)
        return NULL;

    if(parent->left!=NULL){
        binary_tree_t *aux_left = parent -> left;
        parent -> left = NULL;
        aux_left->parent = NULL;
        node -> left = aux_left;
        aux_left->parent = node;    
    }
    parent -> left = node;
    return node;
}

/*Task 2*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;
    node = binary_tree_node(parent,value);
    if(node == NULL || parent == NULL)
        return NULL;

    if(parent->right!=NULL){
        binary_tree_t *aux_right = parent -> right;
        parent -> right = NULL;
        aux_right->parent = NULL;
        node -> right = aux_right;
        aux_right->parent = node;    
    }
    parent -> right = node;
    return node;
}

/*Task 3*/
void binary_tree_delete(binary_tree_t *tree)
{
    if(tree == NULL)
        return;
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}

/*Task 4*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if(!node)
        return 0;

    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return 0;
}

/*Task 5*/
int binary_tree_is_root(const binary_tree_t *node)
{
    if(!node)
        return 0;
    if(node -> parent == NULL)
        return 1;
    else    
        return 0;
}

/*Task 6*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
		return;
    func(tree->n);
    binary_tree_preorder(tree->left,func);
    binary_tree_preorder(tree->right,func);
}

/*Task 7*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
		return;
    binary_tree_preorder(tree->left,func);
    func(tree->n);
    binary_tree_preorder(tree->right,func);
    
}

/*Task 8*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
		return;
    binary_tree_preorder(tree->left,func);
    binary_tree_preorder(tree->right,func);
    func(tree->n);
}

/*Task 9*/
size_t measure_height(const binary_tree_t *tree){
    size_t maxLeft,maxRight,max;
    if(tree==NULL)
        return 0;
    maxLeft = measure_height(tree->left);
    maxRight = measure_height(tree->right);
   if(maxLeft > maxRight)
        max = maxLeft;
    else
        max = maxRight;    
    return ( max + 1 );
}

size_t binary_tree_height(const binary_tree_t *tree){
    if(!tree)
        return (0);
    return( measure_height(tree)-1);
    
}