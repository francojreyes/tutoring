#include <stdio.h>

#include "bst.h"

int main(void) {
    Bst t = NULL;
    t = bstInsert(t, 5);
    t = bstInsert(t, 3);
    t = bstInsert(t, 1);
    t = bstInsert(t, 8);
    t = bstInsert(t, 4);
    t = bstInsert(t, 7);
    t = bstInsert(t, 9);

    printf("%d\n", bstCountOdds(t));

    bstFree(t);
}