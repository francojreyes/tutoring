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
	if (t == NULL) {
		return 0;
	} else {
		int nodesInLeft = BSTreeNumNodes(t->left);   // L
		int nodesInRight = BSTreeNumNodes(t->right); // R
		return nodesInLeft + nodesInRight + 1;       // N
	}
}

/**
 * Counts the number of odd values in a tree
*/
int BSTreeCountOdds(BSTree t) {
	if (t == NULL) {
		return 0;
	} else {
		int leftOdd = BSTreeCountOdds(t->left);   // L
		int rightOdd = BSTreeCountOdds(t->right); // R
		return leftOdd + rightOdd + (t->value % 2);
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}

/**
 * Ccompute the height of a tree.
 * The height is defined as the length of the longest path from the root to a leaf.
 * The path length is a count of the number of links (edges) on the path.
*/
int BSTreeHeight(BSTree t) {
	if (t == NULL) {
		return -1;
	} else {
		int lh = BSTreeHeight(t->left);
		int rh = BSTreeHeight(t->right);
		return (lh > rh ? lh : rh) + 1;
	}
}



/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int BSTreeCountInternal(BSTree t) {
	if (t == NULL || (t->left == NULL && t->right == NULL)) {
		return 0;
	} else {
		int li = BSTreeCountInternal(t->left);
		int ri = BSTreeCountInternal(t->right);
		return li + ri + 1;
	}
}

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the binary search tree).
 * The level of the root node is zero. 
*/
int BSTreeNodeLevel(BSTree t, int key) {
	if (t == NULL) {
		return -1;
	} else if (t->value == key) {
		return 0;
	} else if (key > t->value) {
		int rl = BSTreeNodeLevel(t->right, key);
		return rl == -1 ? -1 : rl + 1;
	} else { // if (key < t->value)
		int ll = BSTreeNodeLevel(t->left, key);
		return ll == -1 ? -1 : ll + 1;
	}
}

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int BSTreeCountGreater(BSTree t, int val) {
	if (t == NULL) {
		return 0;
	} else if (t->value == val) {
		return BSTreeCountGreater(t->right, val);
	} else if (t->value > val) {
		return BSTreeCountGreater(t->left, val)
			 + BSTreeCountGreater(t->right, val) + 1;
	} else { // if (t->value < val)
		return BSTreeCountGreater(t->right, val);
	}
}

/**
 * Returns the height of a given basic binary tree if it is height-balanced.
 * Otherwise, if the given binary tree is not height-balanced, the function
 * returns NOT_HEIGHT_BALANCED.
 * 
 * Tree is height balanced if:
 * 	for all nodes n in the tree
 * 		abs(height(left(n)) - height(right(n))) <= 1
*/
int isHeightBalanced(BSTree t) {
	if (t == NULL) {
		return -1;
	} else {
		int lh = isHeightBalanced(t->left);
		int rh = isHeightBalanced(t->right);

		if (lh == NOT_HEIGHT_BALANCED || rh == NOT_HEIGHT_BALANCED) {
			return NOT_HEIGHT_BALANCED;
		}
		
		if (abs(lh - rh) <= 1) {
			return (lh > rh ? lh : rh) + 1;
		} else {
			return NOT_HEIGHT_BALANCED;
		}
	}
}
