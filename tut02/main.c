#include <stdio.h>

#include "list.h"
#include "list.h"

int main(void) {
    // hello
    List l = NULL;
    l = listAppend(l, 2);
    l = listAppend(l, 4);
    l = listAppend(l, 5);
    l = listAppend(l, 6);
    l = listAppend(l, 8);

    listPrint(l);
    l = listDeleteEvens(l);
    listPrint(l);
}