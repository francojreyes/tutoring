
#include <stdio.h>

#include "BSTree.h"

#define NUM_TREES 4
#define NUM_VALS 7

int main(void) {
    // Four trees
    // - t[0] is tree created by inserting 4 2 6 5 1 7 3
    // - t[2] is tree created by inserting 5 6 2 3 4 7 1
    // - t[2] is tree created by inserting 1 2 3 4 5 6 7
    // - t[3] is empty tree
    BSTree t[NUM_TREES] = {};

    int vals[NUM_TREES - 1][NUM_VALS] = {
        {4, 2, 6, 5, 1, 7, 3},
        {5, 6, 2, 3, 4, 7, 1},
        {1, 2, 3, 4, 5, 6, 7}
    };

    for (int i = 0; i < NUM_VALS; i++) {
        for (int j = 0; j < NUM_TREES - 1; j++) {
            t[j] = BSTreeInsert(t[j], vals[j][i]);
        }
    }

    for (int i = 0; i < NUM_TREES; i++) {
        printf("t[%d]: %d\n", i, isHeightBalanced(t[i]));
    }

}