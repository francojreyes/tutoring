#include <stdio.h>

#include "List.h"

int main(void) {
    // create list containing -3..3
    List l = NULL;
    for (int i = -3; i <= 3; i++) {
        l = ListAppend(l, i);
    }
    ListPrint(l);

    l = ListDeleteEvens(l);
    ListPrint(l);

    ListFree(l);
}