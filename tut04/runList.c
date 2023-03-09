#include <stdio.h>
#include <stdlib.h>

#include "List.h"

bool isEven(int value) {
    return value % 2 == 0;
}

bool isOdd(int value) {
    return abs(value % 2) == 1;
}

bool isPositive(int value) {
    return value > 0;
}

int main(void) {
    // create list containing -3..3
    List l = NULL;
    for (int i = -3; i <= 3; i++) {
        l = ListAppend(l, i);
    }
    ListPrint(l);

    l = ListDeleteIf(l, &isOdd);
    ListPrint(l);

    ListFree(l);
}