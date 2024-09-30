// Implementation for bst ADT

#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
// note: typedef struct node *Bst;

struct node {
	int value;
	Bst left;
	Bst right;
};

static Bst newNode(int value);

/**
 * Frees the tree
*/
void bstFree(Bst t) {
    if (t != NULL) {
        bstFree(t->left);
        bstFree(t->right);
        free(t);
    }
}

/**
 * Insert a value into a tre
*/
Bst bstInsert(Bst t, int value) {
	if (t == NULL) {
		return newNode(value);
	}
	
	if (value < t->value) {
		t->left = bstInsert(t->left, value);
	} else if (value > t->value) {
		t->right = bstInsert(t->right, value);
	}

	return t;
}

static Bst newNode(int value) {
	Bst n = malloc(sizeof(*n));
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
 * Count the total number of nodes in a tree
 */
int bstNumNodes(Bst t) {
    return 0;
}

/**
 * Counts the number of odd values in a tree
*/
int bstCountOdds(Bst t) {
    return 0;
}

/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int bstCountInternal(Bst t) {
	return 0;
}

/**
 * Compute the height of a tree. The height of a tree is defined as the
 * length of the longest path from the root to a leaf. The path length is
 * a count of the number of links (edges) on the path. The height of an
 * empty tree is -1.
 */
int bstHeight(Bst t) {
    return -1;
}

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the binary search tree).
 * The level of the root node is zero. 
*/
int bstNodeLevel(Bst t, int key) {
	return 0;
}

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int bstCountGreater(Bst t, int val) {
	return 0;
}
