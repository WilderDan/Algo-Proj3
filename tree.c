/*	Dan Wilder
 *	
 *	University of Missouri - St. Louis
 *	CS 3130 - Design & Analysis of Algorithms
 *	Galina Piatnitskiaia (instructor)
 *	Project #3
 *	
 *	tree.c - Implements tree functions
 */
 
#include "tree.h"
#include <stdio.h>

void treeInsert(struct node **root, struct node *newNode) {
    struct node *y = NULL;
    struct node *x = *root;
    
    while (x != NULL) {
        y = x;
        x = (newNode->key < x->key) ? x->left : x->right;
    }
    
    newNode->p = y;
    
    if (y == NULL)
        *root = newNode;
    else if (newNode->key < y->key)
        y->left = newNode;
    else 
        y->right = newNode;
}

void inorder(struct node *root) {
    if (root->left != NULL)
        inorder(root->left);
        
    printf("%d ", root->key);
    
    if (root->right != NULL)
        inorder(root->right);
}

void postorder(struct node *root) {
    if (root->left != NULL)
        postorder(root->left);
    
    if (root->right != NULL)
        postorder(root->right);   
        
    printf("%d ", root->key);
}

void preorder(struct node *root) {
    printf("%d ", root->key);
    
    if (root->left != NULL)
        preorder(root->left);

    if (root->right != NULL)
        preorder(root->right);   
}