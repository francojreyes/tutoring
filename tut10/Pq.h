// Priority queue of integers

// !!! DO NOT MODIFY THIS FILE !!!

#ifndef PQ_H
#define PQ_H

#include <stdbool.h>

typedef struct pq *Pq;

/**
 * Creates a new priority queue
 * Complexity: O(1)
 */
Pq   PqNew(void);

/**
 * Frees all memory associated with the given priority queue
 * Complexity: O(1)
 */
void PqFree(Pq pq);

/**
 * Adds an item to the priority queue
 * Amortised complexity: O(log n)
 */
void PqInsert(Pq pq, int item);

/**
 * Returns the smallest item in the priority queue without removing it.
 */
int PqPeek(Pq pq);

/**
 * Removes and returns the smallest item from the priority queue. If
 * multiple items are the smallest, one of them will be removed.
 * Complexity: O(log n)
 */
int PqExtract(Pq pq);

/**
 * Returns the number of items in the given priority queue
 * Complexity: O(1)
 */
int PqSize(Pq pq);

/**
 * Returns true if the given priority queue is empty, or false otherwise
 * Complexity: O(1)
 */
bool PqIsEmpty(Pq pq);

/**
 * Prints the given priority queue to stdout for debugging purposes
 */
void PqShow(Pq pq);

#endif