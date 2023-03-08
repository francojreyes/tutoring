// Interface for BST ADT

#define NOT_HEIGHT_BALANCED -99

typedef struct BSTNode *BSTree;

/**
 * Frees the tree
*/
void BSTreeFree(BSTree t);
/**
 * Insert a value into a tree
*/
BSTree BSTreeInsert(BSTree t, int value);

/**
 * Count the total number of nodes in a tree
*/
int BSTreeNumNodes(BSTree t);

/**
 * Counts the number of odd values in a tree
*/
int BSTreeCountOdds(BSTree t);

/**
 * Ccompute the height of a tree.
 * The height is defined as the length of the longest path from the root to a leaf.
 * The path length is a count of the number of links (edges) on the path.
*/
int BSTreeHeight(BSTree t);

/**
 * Count number of internal nodes in a given tree.
 * An internal node is a node with at least one non-empty subtree.
*/
int BSTreeCountInternal(BSTree t);

/**
 * Returns the level of the node containing a given key if such a node exists,
 * otherwise the function returns -1 (when a given key is not in the binary search tree).
 * The level of the root node is zero. 
*/
int BSTreeNodeLevel(BSTree t, int key);

/**
 * Counts the number of values that are greater than a given value.
 * This function should avoid visiting nodes that it doesn't have to visit
*/
int BSTreeCountGreater(BSTree t, int val);

/**
 * Returns the height of a given basic binary tree if it is height-balanced.
 * Otherwise, if the given binary tree is not height-balanced, the function
 * returns NOT_HEIGHT_BALANCED.
*/
int isHeightBalanced(BSTree t);