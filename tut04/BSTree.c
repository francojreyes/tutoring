// Implementation for BST ADT

#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

typedef struct BSTNode {
	int value;
	BSTree left;
	BSTree right;
} BSTNode;

static BSTree newNode(int value);

/**
 * Frees the tree
*/
void BSTreeFree(BSTree t) {
    if (t != NULL) {
        BSTreeFree(t->left);
        BSTreeFree(t->right);
        free(t);
    }
}

/**
 * Insert a value into a tre
*/
BSTree BSTreeInsert(BSTree t, int value) {
	if (t == NULL) {
		return newNode(value);
	}
	
	if (value < t->value) {
		t->left = BSTreeInsert(t->left, value);
	} else if (value > t->value) {
		t->right = BSTreeInsert(t->right, value);
	}

	return t;
}

static BSTree newNode(int value) {
	BSTree n = malloc(sizeof(*n));
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
int BSTreeNumNodes(BSTree t) {
	return 0;
}

/**
 * Counts the number of odd values in a tree
*/
int BSTreeCountOdds(BSTree t) {
	return 0;
}

/**
 * Ccompute the height of a tree.
 * The height is defined as the length of the longest path from the root to a leaf.
 * The path length is a count of the number of links (edges) on the path.
*/
int BSTreeHeight(BSTree t) {
	return 0;
}

/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int BSTreeCountInternal(BSTree t) {
	return 0;
}

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the binary search tree).
 * The level of the root node is zero. 
*/
int BSTreeNodeLevel(BSTree t, int key) {
	return 0;
}

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int BSTreeCountGreater(BSTree t, int val) {
	return 0;
}

/**
 * Returns the height of a given basic binary tree if it is height-balanced.
 * Otherwise, if the given binary tree is not height-balanced, the function
 * returns NOT_HEIGHT_BALANCED.
*/
int isHeightBalanced(BSTree t) {
	return NOT_HEIGHT_BALANCED;
}