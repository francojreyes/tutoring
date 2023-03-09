// Recursive implmentation of linked list
// Franco Reyes, COMP2521 23T0 tut01

#include <stdio.h>
#include <stdlib.h>

#include "List.h"

static List newNode(int value);

/**
 * Frees given list
*/
void ListFree(List l) {
    if (l != NULL) {
        ListFree(l->next);
        free(l);
    }
}

/**
 * Print the values of a linked list, space-separated
*/
void ListPrint(List l) {
    if (l == NULL) {
        printf("\n");
    } else {
        printf("%d ", l->data);
        ListPrint(l->next);
    }
}

/**
 * Append a value to the end of a linked list 
 * The function should return a pointer to the beginning of the updated list.
*/
List ListAppend(List l, int value) {
    if (l == NULL) {
        return newNode(value);
    } else {
        l->next = ListAppend(l->next, value);
        return l;
    }
}

static List newNode(int value) {
    List n = malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

/**
 * Compute the length of a linked list
*/
int ListLength(List l) {
    if (l == NULL) {
        return 0;
    } else {
        return ListLength(l->next) + 1;
    }
}

/**
 * Count the number of odd numbers in a linked list
*/
int ListCountOdds(List l) {
    if (l == NULL) {
        return 0;
    } else {
        return ListCountOdds(l->next) + l->data % 2;
    }
}

/**
 * Check whether a list is sorted in ascending order
*/
bool ListIsSorted(List l) {
    if (l == NULL || l->next == NULL) {
        return true;
    } else if (l->next->data < l->data) {
        return false;
    } else {
        return ListIsSorted(l->next);
    }
}

/**
 * Delete the first instance of a value from a linked list, if it exists.
 * The function should return a pointer to the beginning of the updated list.
*/
List ListDelete(List l, int value) {
    if (l == NULL) {
        return NULL;
    } else if (l->data == value) {
        List newHead = l->next;
        free(l);
        return newHead;
    } else {
        List restOfList = l->next;
        l->next = ListDelete(restOfList, value);
        return l;
    }
}

/**
 * Delete all the even numbers from a linked list.
 * The function should return a pointer to the beginning of the updated list.
*/
List ListDeleteIf(List l, ConditionFunction cf) {
    if (l == NULL) {
        return NULL;
    } else if (cf(l->data)) {
        List newHead = l->next;
        free(l);
        return ListDeleteIf(newHead, cf);
    } else {
        List restOfList = l->next;
        l->next = ListDeleteIf(restOfList, cf);
        return l;
    }
}

