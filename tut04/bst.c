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
    // Base case
    if (t == NULL) {
        return 0;
    }

    // Recursive case
    int leftOdds = bstCountOdds(t->left);
    int rightOdds = bstCountOdds(t->right);

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
int bstCountInternal(Bst t) {
	return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

/**
 * Compute the height of a tree. The height of a tree is defined as the
 * length of the longest path from the root to a leaf. The path length is
 * a count of the number of links (edges) on the path. The height of an
 * empty tree is -1.
 */
int bstHeight(Bst t) {
    // Base case
    if (t == NULL) {
        return -1;
    }

    // Recursive case
    int lh = bstHeight(t->left);
    int rh = bstHeight(t->right);

    return max(lh, rh) + 1;
}

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the binary search tree).
 * The level of the root node is zero. 
*/
int bstNodeLevel(Bst t, int key) {
    // Base cases
    if (t == NULL) {
        return -1;
    } else if (t->value == key) {
        return 0;
    }

    // Recursive case
    int childLevel;
    if (key < t->value) {
        childLevel = bstNodeLevel(t->left, key);
    } else { // gt
        childLevel = bstNodeLevel(t->right, key);
    }

	return childLevel == -1 ? -1 : childLevel + 1;
}

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int bstCountGreater(Bst t, int val) {
	// base case ...


    // recursive case
    // right if val >= t->value
    // left only if val < t->value

    return 0;
}
