// Linked list interface
// Franco Reyes, COMP2521 23T0 tut01

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

/**
 * Print the values of a linked list, space-separated
*/
void listPrint(List l);

/**
 * Append a value to the end of a linked list 
 * The function should return a pointer to the beginning of the updated list.
*/
List listAppend(List l, int value);

/**
 * Compute the length of a linked list
*/
int listLength(List l);

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(List l);

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(List l);

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDelete(List l, int value);

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDeleteEvens(List l);
