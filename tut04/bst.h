// Interface for bst

typedef struct node *Bst;

/**
 * Frees the tree
*/
void bstFree(Bst t);

/**
 * Insert a value into a tree
*/
Bst bstInsert(Bst t, int value);

/**
 * Count the total number of nodes in a tree
 */
int bstNumNodes(Bst t);

/**
 * Counts the number of odd values in a tree
*/
int bstCountOdds(Bst t);

/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int bstCountInternal(Bst t);

/**
 * Compute the height of a tree. The height of a tree is defined as the
 * length of the longest path from the root to a leaf. The path length is
 * a count of the number of links (edges) on the path. The height of an
 * empty tree is -1.
 */
int bstHeight(Bst t);

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the bst).
 * The level of the root node is zero. 
*/
int bstNodeLevel(Bst t, int key);

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int bstCountGreater(Bst t, int val);
