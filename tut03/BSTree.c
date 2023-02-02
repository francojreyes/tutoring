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
		return BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right) + 1;
	}
}

/**
 * Counts the number of odd values in a tree
*/
int BSTreeCountOdds(BSTree t) {
	if (t == NULL) {
		return 0;
	} else {
		return BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right) + (t->value % 2);
	}
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
		int lr = BSTreeHeight(t->right);
		return 1 + ((lh > lr) ? lh : lr);
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
		return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
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
	}

	int level;
	if (key < t->value) {
		level = BSTreeNodeLevel(t->left, key);
	} else {
		level = BSTreeNodeLevel(t->right, key);
	}

	return (level != -1) ? level + 1 : -1;
}

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int BSTreeCountGreater(BSTree t, int val) {
	if (t == NULL) {
		return 0;
	} else if (t->value <= val) {
		return BSTreeCountGreater(t->right, val);
	} else {
		return BSTreeCountGreater(t->left, val) + BSTreeCountGreater(t->right, val) + 1;
	}
}

/**
 * Returns the height of a given basic binary tree if it is height-balanced.
 * Otherwise, if the given binary tree is not height-balanced, the function
 * returns NOT_HEIGHT_BALANCED.
*/
int isHeightBalanced(BSTree t) {
	if (t == NULL) {
		return -1;
	} else {
		int lh = BSTreeHeight(t->left);
		int rh = BSTreeHeight(t->right);

		if (lh == NOT_HEIGHT_BALANCED || rh == NOT_HEIGHT_BALANCED) {
			return NOT_HEIGHT_BALANCED;
		}

		int diff = lh - rh;
		if (diff > 1 || diff < -1) {
			return NOT_HEIGHT_BALANCED;
		} else {
			return 1 + ((lh > rh) ? lh : rh);
		}
	}
}
