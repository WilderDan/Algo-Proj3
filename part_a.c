/*	Dan Wilder
 *	
 *	University of Missouri - St. Louis
 *	CS 3130 - Design & Analysis of Algorithms
 *	Galina Piatnitskiaia (instructor)
 *	Project #3
 *	
 *	part_a.c - Program satisfying part A requirements
 */

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    
    const int arr[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
    int SIZE = sizeof(arr)/sizeof(arr[0]);
    struct node *newNode = NULL, *root = NULL;
    int i;
    
    // Insert array elements into tree
    for (i = 0; i < SIZE; ++i) {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->key = arr[i];
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->p = NULL;
        treeInsert(&root, newNode);
    }
    
    // Traversals
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    
    // Free tree memory!
    
    return 0;
}