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

void transplant(struct node **root, struct node *u, struct node *v);
struct node *treeMinimum(struct node *root);

int max(int a, int b) {
    return (a > b) ? a : b;
}

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
    else if (newNode->key <= y->key)
        y->left = newNode;
    else 
        y->right = newNode;
}

struct node* treeSearch(struct node *root, int search, int isPrint) {
    struct node *path = root;
 
    do {
        if (isPrint)
            printf("%d ", path->key);
        
        if (path->key == search) {
            if (isPrint)
                printf("[FOUND]");
            return path;
        }
            
        path = (search < path->key) ? path->left : path->right;
    } while (path != NULL);
 
    if (isPrint)
        printf("[NOT FOUND]");
        
    // Will be NULL
    return path;
}

int height(struct node *root) {
   if (root == NULL)
        return -1;
   else 
        return max(height(root->left), height(root->right)) + 1;
}

void treeDelete(struct node **root, struct node *target) {
    struct node *y;
    
    if (target->left == NULL)
        transplant(root, target, target->right);
        
    else if (target->right == NULL)
        transplant(root, target, target->left);
        
    else {
        y = treeMinimum(target->right);
        
        if (y->p != target) {
            transplant(root, y, y->right);
            y->right = target->right;
            y->right->p = y;
        }
        
        transplant(root, target, y);
        y->left = target->left;
        y->left->p = y;
    }
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

void transplant(struct node **root, struct node *u, struct node *v) {
    if (u->p == NULL)
        *root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else 
        u->p->right = v;
    if (v != NULL)
        v->p = u-> p;
}

struct node * treeMinimum(struct node *root) {
    while (root->left != NULL) 
        root = root->left;
    return root;
}