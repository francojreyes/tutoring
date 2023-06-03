// Linked struct node *interface
// Franco Reyes, COMP2521 23T0 tut01

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};

/**
 * Print the values of a linked list, space-separated
*/
void listPrint(struct node *l);

/**
 * Append a value to the end of a linked list
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listAppend(struct node *head, int value);

/**
 * Compute the length of a linked list
*/
int listLength(struct node *head);

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(struct node *head);

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(struct node *head);

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listDelete(struct node *head, int value);

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listDeleteEvens(struct node *head);

#endif
