// Iterative implmentation of linked list
// Franco Reyes, COMP2521 23T0 tut01

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static List newNode(int value) {
    List n = malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

/**
 * Print the values of a linked list, space-separated
*/
void listPrint(List l) {
    // hello
    for (List curr = l; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("\n");
}

/**
 * Append a value to the end of a linked list 
 * The function should return a pointer to the beginning of the updated list.
*/
List listAppend(List l, int value) {
    if (l == NULL) {
        return newNode(value);
    }

    List curr = l;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode(value);
    return l;
}

/**
 * Compute the length of a linked list
*/
int listLength(List l) {
    int count = 0;
    for (List curr = l; curr != NULL; curr = curr->next) {
        count++;
    }
    return count;
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(List l) {
    int count = 0;
    for (List curr = l; curr != NULL; curr = curr->next) {
        count += curr->data % 2;
    }
    return count;
}

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(List l) {
    for (List curr = l; curr != NULL && curr->next != NULL; curr = curr->next) {
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
List listDelete(List l, int value) {
    List prev = NULL;
    List curr = l;
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next; 
    }

    if (prev != NULL) {
        prev->next = curr->next;
        free(curr);
        return l;
    } else {
        List newHead = l->next;
        free(l);
        return newHead;
    }
}

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDeleteEvens(List l) {
    return l;
}
