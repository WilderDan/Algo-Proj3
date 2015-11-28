/*	Dan Wilder
 *	
 *	University of Missouri - St. Louis
 *	CS 3130 - Design & Analysis of Algorithms
 *	Galina Piatnitskiaia (instructor)
 *	Project #3
 *	
 *	part_b.c - Program satisfying part B requirements
 */
 
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MIN_VAL     1
#define MAX_VAL     9999

void randomInitialize(int *, int, int, int);
void deallocate(struct node *);

int main() {
    const int N_ELEMENTS[] = {100, 500, 1000};
    const int T_TREES[] = {5, 10, 15};
    const int SIZE = 3; // For both above arrays 
    int i, j, k, m;
    int *arr;
    int totalHeight;
    double averageHeight;
    struct node *newNode = NULL, *root = NULL;
    
    srand(time(NULL));
    
    // For each element in N_ELEMENTS
    for (i = 0; i < SIZE; ++i) {
        // For each element in T_TREES
        for (j = 0; j < SIZE; ++j) {
            totalHeight = 0;
            
            // Create T_TREES[j] arrays with N_ELEMENTS[i]
            for (k = 0; k < T_TREES[j]; ++k) {
            
                arr = (int *)malloc(N_ELEMENTS[i] * sizeof(int));
                randomInitialize(arr, N_ELEMENTS[i], MIN_VAL, MAX_VAL);
                root = NULL;
                
                // Insert each element into single BST
                for (m = 0; m < N_ELEMENTS[i]; ++m) {
                    newNode = (struct node *)malloc(sizeof(struct node));
                    newNode->key = arr[m];
                    newNode->left = NULL;
                    newNode->right = NULL;
                    newNode->p = NULL;
                    treeInsert(&root, newNode);
                }
            
                totalHeight += height(root);
                
                // Free Memory!!!
                free(arr);
                deallocate(root);
            }
            
            averageHeight = (double)totalHeight / T_TREES[j];
            
            // Print results
            printf("\tN == %d\tT == %d\n", N_ELEMENTS[i], T_TREES[j]);
            printf("\t\tAverage Height == %.2lf\n\n", averageHeight);
        }
    }
    return 0;
}

void randomInitialize(int arr[], int size, int minVal, int maxVal) {
/* Initialize arr[0..size-1] to random int in interval [minVal, maxVal]
 * srand() should be called in application program ONCE prior to calling this
 */
    int i, randomInt;
   
    for (i = 0; i < size; i++) {
        randomInt = rand() % (maxVal-minVal) + minVal;
        arr[i] = randomInt;
    }
}

void deallocate (struct node *root) {
    if (root != NULL) {
        deallocate(root->left);
        deallocate(root->right);
        free (root);
    }
}