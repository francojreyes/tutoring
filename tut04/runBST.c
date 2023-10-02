#include <stdio.h>

#include "BST.h"

int main(void) {
    BST t = NULL;
    t = BSTInsert(t, 4);
    t = BSTInsert(t, 2);
    t = BSTInsert(t, 6);
    t = BSTInsert(t, 5);
    t = BSTInsert(t, 1);
    t = BSTInsert(t, 7);
    t = BSTInsert(t, 3);

    printf("%d\n", BSTCountOdds(t));

    BSTFree(t);
}