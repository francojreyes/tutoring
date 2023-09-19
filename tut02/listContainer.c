// Recursive container implmentation of linked list
// Franco Reyes, COMP2521 23T3 tut02

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct list {
	struct node *head;
};

struct node {
    int data;
    struct node *next;
};

int listLength(struct list *l);
int listCountOdds(struct list *l);
bool listIsSorted(struct list *l);
void listDelete(struct list *l, int value);

struct node *newNode(int value);
struct list *listNew();
void listPrint(struct list *l);
void doListPrint(struct node *head);
void listAppend(struct list *l, int value);
struct node *doListAppend(struct node *head, int value);

int main(void) {
    struct list *l = listNew();
    listAppend(l, 1);
    listAppend(l, 2);
    listAppend(l, 3);
    listAppend(l, 4);
    listAppend(l, 5);

    listPrint(l);
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Compute the length of a linked list
*/
int listLength(struct list *l) {
    return 0;
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(struct list *l) {
    return 0;
}

/**
 * Check whether a list is sorted in non-descending order
 */
bool listIsSorted(struct list *l) {
    return false;
}

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
void listDelete(struct list *l, int value) {
	return;
}

///////////////////////////////////////////////////////////////////////////////

struct node *newNode(int value) {
    struct node *n = malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

/**
 * Create and return a new empty list
*/
struct list *listNew() {
	struct list *l = malloc(sizeof(struct list));
	l->head = NULL;
	return l;
}


/**
 * Print the values of a linked list, space-separated
*/
void listPrint(struct list *l) {
	doListPrint(l->head);
}

void doListPrint(struct node *head) {
    if (head == NULL) {
        printf("\n");
    } else {
        printf("%d ", head->data);
        doListPrint(head->next);
    }
}

/**
 * Append a value to the end of a linked list
 * The function should return a pointer to the beginning of the updated list.
*/
void listAppend(struct list *l, int value) {
	l->head = doListAppend(l->head, value);
}

struct node *doListAppend(struct node *head, int value) {
    if (head == NULL) {
        return newNode(value);
    } else {
        head->next = doListAppend(head->next, value);
        return head;
    }
}

