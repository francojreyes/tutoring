#include <stdio.h>

#include "BST.h"

int main(void) {
    BST t = NULL;
    t = BSTInsert(t, 5);
    t = BSTInsert(t, 3);
    t = BSTInsert(t, 8);
    t = BSTInsert(t, 1);
    t = BSTInsert(t, 4);
    t = BSTInsert(t, 7);
    t = BSTInsert(t, 9);

    printf("Level of 4: %d\n", BSTNodeLevel(t, 4));
    printf("Level of 8: %d\n", BSTNodeLevel(t, 8));
    printf("Level of 2: %d\n", BSTNodeLevel(t, 2));

    BSTFree(t);
}