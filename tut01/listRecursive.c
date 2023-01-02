// Recursive implmentation of linked list
// Franco Reyes, COMP2521 23T0 tut01

#include <stdlib.h>

#include "list.h"

static Node *newNode(int value) {
    Node *n = malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

/**
 * Print the values of a linked list, space-separated
*/
void listPrint(List l) {

}

/**
 * Append a value to the end of a linked list 
 * The function should return a pointer to the beginning of the updated list.
*/
List listAppend(List l, int value) {
    return newNode(value);
}

/**
 * Compute the length of a linked list
*/
int listLength(List l) {
    return 0;
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(List l) {
    return 0;
}

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(List l) {
    return false;
}

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDelete(List l, int value) {
    return l;
}

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDeleteEvens(List l) {
    return l;
}
