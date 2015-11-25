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

void displayInorder(struct node *);
void displayPostorder(struct node *);
void displayPreorder(struct node *);

int main() {
    
    const int arr[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
    const int SIZE = 10;
    struct node *newNode = NULL, *root = NULL;
    int i, choice;
    
    // Insert array elements into tree
    for (i = 0; i < SIZE; ++i) {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->key = arr[i];
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->p = NULL;
        treeInsert(&root, newNode);
    }
    
    printf("Initial binary search tree was created!\n");
    printf("Elements from array: ");
    printf("<30, 10, 45, 38, 20, 50, 25, 33, 8, 12>\n");
    printf("were inserted in that order.\n\n");
    
    // Menu-Driven
    do {
        printf("MENU SELECTION\n");
        printf("\t0)\tEXIT\n");
        printf("\t1)\tDisplay inorder\n");
        printf("\t2)\tDisplay postorder\n");
        printf("\t3)\tDisplay preorder\n");
        
        printf("\n\t==> ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 0 :
                printf("\nHave a nice day!\n");
                break;

            case 1  :
                displayInorder(root);
                break; 
                
            case 2  :
                displayPostorder(root);
                break; 

            case 3  :
                displayPreorder(root);
                break; 
            
            default :
                printf("\nInvalid Choice");
        }
    } while(choice != 0);
    
    // Free tree memory!
    
    return 0;
}

void displayInorder(struct node *root) {
    printf("\n\nInorder: ");
    inorder(root);
    printf("\n\n");  
}

void displayPostorder(struct node *root) {
    printf("\n\nPostorder: ");
    postorder(root);
    printf("\n\n");
}

void displayPreorder(struct node *root) {
    printf("\n\nPreorder: ");
    preorder(root);
    printf("\n\n");
}