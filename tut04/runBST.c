#include <stdio.h>

#include "BSTree.h"

int main(void) {
    BSTree t = NULL;
    t = BSTreeInsert(t, 5);
    t = BSTreeInsert(t, 3);
    t = BSTreeInsert(t, 7);
    t = BSTreeInsert(t, 8);
    t = BSTreeInsert(t, 1);
    t = BSTreeInsert(t, 4);
    t = BSTreeInsert(t, 9);

    int balanced = isHeightBalanced(t);
    printf("%s\n", balanced != NOT_HEIGHT_BALANCED ? "Balanced" : "Not balanced");

    BSTreeFree(t);
}