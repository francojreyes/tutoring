// Iterative implmentation of linked list
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
    for (struct node *curr = head; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("\n");
}

/**
 * Append a value to the end of a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listAppend(struct node *head, int value) {
    if (head == NULL) {
        return newNode(value);
    }

    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode(value);
    return head;
}

/**
 * Compute the length of a linked list
*/
int listLength(struct node *head) {
    int length = 0;
    for (struct node *curr = head; curr != NULL; curr = curr->next) {
        length++;
    }
    return length;
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(struct node *head) {
    int odds = 0;
    for (struct node *curr = head; curr != NULL; curr = curr->next) {
        if (curr->data % 2 == 1) {
            odds++;
        }
    }
    return odds;
}

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(struct node *head) {
    for (struct node *curr = head; curr != NULL && curr->next != NULL; curr = curr->next) {
        if (curr->data > curr->next->data) {
            return false;
        }
    }
    return true;
}

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listDelete(struct node *head, int value) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == value) {
        struct node *newHead = head->next;
        free(head);
        return newHead;
    }

    struct node *curr = head;
    while (curr->next != NULL) {
        if (curr->next->data == value) {
            struct node *tmp = curr->next->next;
            free(curr->next);
            curr->next = tmp;
            break;
        } 
        curr = curr->next;
    }
    return head;
}

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
struct node *listDeleteEvens(struct node *head) {
    // head case
    while (head != NULL && head->data % 2 == 0) {
        struct node *newHead = head->next;
        free(head);
        head = newHead;
    }

    // somewhere in the middle case
    struct node *curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data % 2 == 0) {
            struct node *tmp = curr->next->next;
            free(curr->next);
            curr->next = tmp;
        } 
        curr = curr->next;
    }
    return head;
}
