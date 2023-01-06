// Recursive implmentation of linked list
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
    if (l == NULL) {
        printf("\n");
    } else {
        printf("%d ", l->data);
        listPrint(l->next);
    }
}

/**
 * Append a value to the end of a linked list 
 * The function should return a pointer to the beginning of the updated list.
*/
List listAppend(List l, int value) {
    if (l == NULL) {
        return newNode(value);
    } else {
        l->next = listAppend(l->next, value);
        return l;
    }
}

/**
 * Compute the length of a linked list
*/
int listLength(List l) {
    if (l == NULL) {
        return 0;
    } else {
        return listLength(l->next) + 1;
    }
}

/**
 * Count the number of odd numbers in a linked list
*/
int listCountOdds(List l) {
    if (l == NULL) {
        return 0;
    } else {
        return listCountOdds(l->next) + (l->data % 2);
    }
}

/**
 * Check whether a list is sorted in ascending order
*/
bool listIsSorted(List l) {
    if (l == NULL || l->next == NULL) {
        return true;
    } else if (l->next->data < l->data) {
        return false;
    } else {
        return listIsSorted(l->next);
    }
}

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDelete(List l, int value) {
    if (l == NULL) {
        return l;
    } else if (l->data == value) {
        List tmp = l->next;
        free(l);
        return tmp;
    } else {
        l->next = listDelete(l->next, value);
        return l;
    }
}

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
List listDeleteEvens(List l) {
    if (l == NULL) {
        return l;
    } else if (l->data % 2 == 0) {
        List tmp = l->next;
        free(l);
        return listDeleteEvens(tmp);
    } else {
        l->next = listDeleteEvens(l->next);
        return l;
    }
}
