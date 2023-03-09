// Linked list interface
// Franco Reyes, COMP2521 23T0 tut01

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

typedef bool (*ConditionFunction)(int);

/**
 * Frees given list
*/
void ListFree(List l);

/**
 * Print the values of a linked list, space-separated
*/
void ListPrint(List l);

/**
 * Append a value to the end of a linked list 
 * The function should return a pointer to the beginning of the updated list.
*/
List ListAppend(List l, int value);

/**
 * Compute the length of a linked list
*/
int ListLength(List l);

/**
 * Count the number of odd numbers in a linked list
*/
int ListCountOdds(List l);

/**
 * Check whether a list is sorted in ascending order
*/
bool ListIsSorted(List l);

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
List ListDelete(List l, int value);

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
List ListDeleteIf(List l, ConditionFunction cf);

#endif
