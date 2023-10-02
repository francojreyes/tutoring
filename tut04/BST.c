// Implementation for BST ADT

#include <stdio.h>
#include <stdlib.h>

#include "BST.h"
// note: typedef struct node *BST;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

static struct node *newNode(int value);

/**
 * Frees the tree
*/
void BSTFree(BST t) {
    if (t != NULL) {
        BSTFree(t->left);
        BSTFree(t->right);
        free(t);
    }
}

/**
 * Insert a value into a tre
*/
BST BSTInsert(BST t, int value) {
	if (t == NULL) {
		return newNode(value);
	}
	
	if (value < t->value) {
		t->left = BSTInsert(t->left, value);
	} else if (value > t->value) {
		t->right = BSTInsert(t->right, value);
	}

	return t;
}

static struct node *newNode(int value) {
	struct node *n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "Error: out of memory");
		exit(EXIT_FAILURE);
	}

	n->value = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

/**
 * Counts the number of odd values in a tree
*/
int BSTCountOdds(BST t) {
	return 0;
}

/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int BSTCountInternal(BST t) {
	return 0;
}

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the binary search tree).
 * The level of the root node is zero. 
*/
int BSTNodeLevel(BST t, int key) {
	return 0;
}

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int BSTCountGreater(BST t, int val) {
	return 0;
}
