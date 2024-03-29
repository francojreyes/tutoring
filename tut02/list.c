// Recursive implmentation of linked list
// Franco Reyes, COMP2521 23T0 tut01

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int listLength(struct node *head);
int listCountOdds(struct node *head);
bool listIsSorted(struct node *head);
struct node *listDelete(struct node *head, int value);

struct node *newNode(int value);
void listPrint(struct node *head);
struct node *listAppend(struct node *head, int value);

int main(void) {
    // hello
    struct node *head = NULL;
    head = listAppend(head, 1);
    head = listAppend(head, 2);
    head = listAppend(head, 3);
    head = listAppend(head, 4);
    head = listAppend(head, 5);

    listPrint(head);

    int length = listLength(head);
    printf("%d\n", length);
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Compute the length of a linked list
*/
int listLength(struct node *head) {
    return 0;
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(struct node *head) {
    return 0;
}

/**
 * Check whether a list is sorted in non-descending order
 */
bool listIsSorted(struct node *head) {
    return false;
}

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listDelete(struct node *head, int value) {
    return head;
}

///////////////////////////////////////////////////////////////////////////////

struct node *newNode(int value) {
    struct node *n = malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

/**
 * Print the values of a linked list, space-separated
*/
void listPrint(struct node *head) {
    if (head == NULL) {
        printf("\n");
    } else {
        printf("%d ", head->data);
        listPrint(head->next);
    }
}

/**
 * Append a value to the end of a linked list
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listAppend(struct node *head, int value) {
    if (head == NULL) {
        return newNode(value);
    } else {
        head->next = listAppend(head->next, value);
        return head;
    }
}