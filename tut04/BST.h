// Interface for BST ADT

typedef struct node *BST;

/**
 * Frees the tree
*/
void BSTFree(BST t);

/**
 * Insert a value into a tree
*/
BST BSTInsert(BST t, int value);

/**
 * Counts the number of odd values in a tree
*/
int BSTCountOdds(BST t);

/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int BSTCountInternal(BST t);

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the bst).
 * The level of the root node is zero. 
*/
int BSTNodeLevel(BST t, int key);

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int BSTCountGreater(BST t, int val);
