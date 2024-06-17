// Interface to the Set ADT
#include <stdbool.h>


typedef struct set *Set;


// Creates a new empty set
Set SetNew(void);

// Frees memory allocated to the set
void SetFree(Set s);

// Inserts an element into the set
void SetInsert(Set s, int elem);

// Deletes an element from the set
void SetDelete(Set s, int elem);

// Returns true if the given element is in the set, and false otherwise
bool SetContains(Set s, int elem);

// Returns the number of elements in the set
int SetSize(Set s);