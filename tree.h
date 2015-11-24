/*	Dan Wilder
 *	
 *	University of Missouri - St. Louis
 *	CS 3130 - Design & Analysis of Algorithms
 *	Galina Piatnitskiaia (instructor)
 *	Project #3
 *	
 *	tree.h - node definition and tree function declarations
 */
 
#ifndef TREE_H
#define TREE_H

struct node {
    int key;
    struct node *left;
    struct node *right;
    struct node *p;
}; 

void treeInsert(struct node **root, struct node *newNode);
void treeSearch(struct node *root, int search);
void treeDelete(struct node *root, struct node *target);
void inorder(struct node *root);
void postorder(struct node *root);
void preorder(struct node *root);

#endif