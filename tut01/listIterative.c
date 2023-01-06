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
    List curr = l;
    int len = 0;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }
    return len;
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(List l) {
    int odds = 0;
    for (List curr = l; curr != NULL; curr = curr->next) {
        if (curr->data % 2 == 1) {
            odds++;
        }
    }
    return odds;
}

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(List l) {
    for (List curr = l; curr != NULL && curr->next != NULL; curr = curr->next) {
        if (curr->next->data < curr->data) {
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
    if (l->data == value) {
        List tmp = l->next;
        free(l);
        return tmp;
    }

    List curr = l;
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }
    List tmp = curr->next;
    curr->next = curr->next->next;
    free(tmp);
    return l;
}

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDeleteEvens(List l) {
    while (l != NULL && l->data % 2 == 0) {
        List tmp = l->next;
        free(l);
        l = tmp;
    }

    List curr = l;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data % 2 == 0) {
            List tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
        }
        curr = curr->next;
    }
    
    return l;
}
