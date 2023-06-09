// Recursive implmentation of linked list
// Franco Reyes, COMP2521 23T0 tut01

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static struct node *newNode(int value) {
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

/**
 * Compute the length of a linked list
*/
int listLength(struct node *head) {
    if (head == NULL) {
        return 0;
    } else {
        return 1 + listLength(head->next);
    }
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(struct node *head) {
    if (head == NULL) {
        return 0;
    } else if (head->data % 2 == 1) {
        return 1 + listCountOdds(head->next);
    } else { // head->data is even
        return listCountOdds(head->next);
    }
}

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    } else if (head->data > head->next->data) {
        return false;
    } else {
        return listIsSorted(head->next);
    }
}

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listDelete(struct node *head, int value) {
    if (head == NULL) {
        return head;
    } else if (head->data == value) {
        struct node *restOfList = head->next;
        free(head);
        return restOfList;
    } else {
        head->next = listDelete(head->next, value);
        return head;
    }
}

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listDeleteEvens(struct node *head) {
    if (head == NULL) {
        return head;
    } else if (head->data % 2 == 0) {
        struct node *restOfList = head->next;
        free(head);
        return listDeleteEvens(restOfList);
    } else {
        head->next = listDeleteEvens(head->next);
        return head;
    }
}
