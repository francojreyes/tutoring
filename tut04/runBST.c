#include <stdio.h>

#include "BSTree.h"

int main(void) {
    BSTree t = NULL;
    t = BSTreeInsert(t, 4);
    t = BSTreeInsert(t, 2);
    t = BSTreeInsert(t, 6);
    t = BSTreeInsert(t, 5);
    t = BSTreeInsert(t, 1);
    t = BSTreeInsert(t, 7);
    t = BSTreeInsert(t, 3);

    printf("%d\n", BSTreeNumNodes(t));

    BSTreeFree(t);
}