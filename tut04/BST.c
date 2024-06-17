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
	// Base case
	if (t == NULL) {
		return 0;
	}

	// Recursive case
//	int oddsInRestOfList = ListCountOdds(l->next);
	int leftOdds = BSTCountOdds(t->left);
	int rightOdds = BSTCountOdds(t->right);

	if (t->value % 2 == 1) {
		return leftOdds + rightOdds + 1;
	} else {
		return leftOdds + rightOdds;
	}
}

/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int BSTCountInternal(BST t) {
	// Base cases
	if (t == NULL || (t->left == NULL && t->right == NULL)) {
		return 0;
	}

	// Recursive case
	int leftInternals = BSTCountInternal(t->left);
	int rightInternals = BSTCountInternal(t->right);
	return leftInternals + rightInternals + 1;
}

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the binary search tree).
 * The level of the root node is zero. 
*/
int BSTNodeLevel(BST t, int key) {
	// Base case
	if (t == NULL) return -1;
	if (t->value == key) return 0;

	// Recursive case
	int subtreeLevel;
	if (key < t->value) {
		subtreeLevel = BSTNodeLevel(t->left, key);
	} else /* if (key > t->value) */ {
		subtreeLevel = BSTNodeLevel(t->right, key);
	}

	// (condition) ? (value if true) : (value if false)
	return subtreeLevel == -1 ? -1 : subtreeLevel + 1;

	if (subtreeLevel == -1) {
		return -1;
	} else {
		return subtreeLevel + 1;
	}

}

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int BSTCountGreater(BST t, int val) {

	// Reucrisve case
	int numGreater = BSTCountGreater(t->right, val);

	if (val < t->value) {
		numGreater += BSTCountGreater(t->left, val);


	return 0;
}
