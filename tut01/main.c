// This program does list stuff
// Franco Reys, COMP2521 23T0 tut01

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "x.h"

int main(void) {
    List l = NULL;
    // hi
    l = listAppend(l, 1);
    l = listAppend(l, 2);
    l = listAppend(l, 3);
    l = listAppend(l, 4);
    l = listAppend(l, 5);


    listPrint(l);

    l = listDeleteEvens(l);
    listPrint(l);


}
