// Implementation of the Set ADT using a balanced BST

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

typedef struct node *Tree;
struct node {
	int item;
	struct node *left;
	struct node *right;
	int height;
};

struct set {
	struct node *tree;
	int size;
};

static void doFree(Tree t);
static Tree doInsert(Tree t, int item, bool *success);
static bool doContains(Tree t, int item);
static void doShow(struct node *t);

static Tree newNode(int item);
static int height(Tree t);
static void updateHeight(Tree t);
static Tree rotateLeft(Tree t1);
static Tree rotateRight(Tree t1);

static int max(int a, int b);


////////////////////////////////////////////////////////////////////////
// Basic Operations

/**
 * Creates a new empty set
 * Complexity O(1)
 */
Set SetNew(void) {
	Set s = malloc(sizeof(struct set));
	if (s == NULL) {
		fprintf(stderr, "couldn't allocate Set\n");
		exit(EXIT_FAILURE);
	}
	s->tree = NULL;
	s->size = 0;
	return s;
}

/**
 * Frees all memory associated with the given set
 * Complexity O(n)
 */
void SetFree(Set s) {
	doFree(s->tree);
	free(s);
}

/**
 * Recursive helper function for SetFree
 * Complexity O(logn)
 */
static void doFree(Tree t) {
	if (t == NULL) return;
	doFree(t->left);
	doFree(t->right);
	free(t);
}

/**
 * Inserts an item into the set
 * Complexity O(logn)
 */
void SetInsert(Set s, int item) {
	bool success = false;
	s->tree = doInsert(s->tree, item, &success);

	// increment size if inserted
	s->size += success;
}

/**
 * Insert an item into the tree (AVL)
 * Return whether or not inserted in success
 * Complexity O(logn)
 */
static Tree doInsert(Tree t, int item, bool *success) {
	// Base cases
	if (t == NULL) {
		*success = true;
        return newNode(item);
    } else if (item == t->item) {
		*success = false;
		return t;
	}

	// Recursive insertion
	if (item < t->item) {
        t->left = doInsert(t->left, item, success);
    } else { // item > t->item
        t->right = doInsert(t->right, item, success);
	}
	updateHeight(t);

    // Rebalancing
    int lHeight = height(t->left);
    int rHeight = height(t->right);
    if ((lHeight - rHeight) > 1) {
        if (item > t->left->item) {
            t->left = rotateLeft(t->left);
        }
        t = rotateRight(t);
    } else if ((rHeight - lHeight) > 1) {
        if (item < t->right->item) {
            t->right = rotateRight(t->right);
        }
        t = rotateLeft(t);
    }
	return t;
}

/**
 * Returns the number of elements in the set
 */
int SetSize(Set s) {
	return s->size;
}

/**
 * Returns true if the set contains the given item, and false otherwise
 * Complexity O(logn)
 */
bool SetContains(Set s, int item) {
	return doContains(s->tree, item);
}

/**
 * Recursive search, returns if tree contains item
 * Complexity O(logn)
 */
static bool doContains(Tree t, int item) {
	if (t == NULL) return false;

	if (t->item == item)
		return true;
	else if (t->item < item)
		return doContains(t->right, item);
	else // t->item > item
		return doContains(t->left, item);
}

/**
 * Prints the given set in the format
 * {elem1, elem2, elem3}
 * Complexity O(n)
 */
void SetShow(Set s) {
	putchar('{');
	doShow(s->tree);
	putchar('}');
}

static void doShow(struct node *t) {
    if (t == NULL) {
        return;
    }

    doShow(t->left);
    if (t->left) {
        printf(", ");
    }
    printf("%d", t->item);
    if (t->right) {
        printf(", ");
    }
    doShow(t->right);

}

////////////////////////////////////////////////////////////////////////
// Tree Helper Functions

/**
 * Create a new node with given item
 * Complexity O(1)
 */
static Tree newNode(int item) {
	Tree t = malloc(sizeof(*t));
	if (t == NULL) {
		fprintf(stderr, "couldn't allocate Tree\n");
		exit(EXIT_FAILURE);
	}
	t->item = item;
	t->left = NULL;
	t->right = NULL;
	t->height = 0;
	return t;
}

/**
 * Return the height of a tree, or -1 if NULL
 * Complexity O(1)
 */
static int height(Tree t) {
	return t != NULL ? t->height : -1;
}

/**
 * Recalculate the height of a Tree
 * Assumes children have accurate heights
 * Complexity O(1)
 */
static void updateHeight(Tree t) {
	t->height = max(height(t->left), height(t->right)) + 1;
}

/**
 * Rotate tree left about t1
 * Complexity O(1)
 */
static Tree rotateLeft(Tree t1) {
    if (t1 == NULL || t1->right == NULL) {
        return t1;
    }
    
	// Rotate
    Tree t2 = t1->right;
    t1->right = t2->left;
    t2->left = t1;

	// Update heights
	updateHeight(t1);
	updateHeight(t2);
    return t2;
}

/**
 * Rotate tree right about t1
 * Complexity O(1)
 */
static Tree rotateRight(Tree t1) {
    if (t1 == NULL || t1->left == NULL) {
        return t1;
    }

	// Rotate
    Tree t2 = t1->left;
    t1->left = t2->right;
    t2->right = t1;

	// Update heights
	updateHeight(t1);
	updateHeight(t2);
    return t2;
}

////////////////////////////////////////////////////////////////////////
// Utility Functions

/**
 * Return the maximum of two integers
 * Complexity O(1)
 */
static int max(int a, int b) {
	return a > b ? a : b;
}
