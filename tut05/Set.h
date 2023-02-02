// Interface to the Set ADT

#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct set *Set;

////////////////////////////////////////////////////////////////////////

/**
 * Creates a new empty set
 */
Set SetNew(void);

/**
 * Frees all memory associated with the given set
 */
void SetFree(Set s);

/**
 * Inserts an item into the set
 */
void SetInsert(Set s, int item);

/**
 * Returns the number of elements in the set
 */
int SetSize(Set s);

/**
 * Returns true if the set contains the given item, and false otherwise
 */
bool SetContains(Set s, int item);

/**
 * Prints the given set in the format
 * {elem1, elem2, elem3}
 */
void SetShow(Set s);

#endif
