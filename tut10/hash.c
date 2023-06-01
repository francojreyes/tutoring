#include <stdio.h>

typedef enum {
    GREEN,
    TEAL,
    PINK,
    RED
} Colour;

typedef struct {
    int row;
    int col;
    Colour colour;
} Rock;

#define N 9
#define SIZE 51

int hash(Rock r, int size) {
    int prime = 31;
    int result = 1;
    result = result * prime + r.row;
    result = result * prime + r.col;
    result = result * prime + r.colour;
    return result % size;
}

int main(void) {
    Rock rocks[9] = {
        { .row = 2, .col = 1, .colour = 0 },
        { .row = 2, .col = 4, .colour = 1 },
        { .row = 4, .col = 1, .colour = 3 },
        { .row = 4, .col = 5, .colour = 2 },
        { .row = 6, .col = 1, .colour = 3 },
        { .row = 6, .col = 7, .colour = 0 },
        { .row = 7, .col = 3, .colour = 1 },
        { .row = 8, .col = 1, .colour = 3 },
        { .row = 8, .col = 8, .colour = 3 }
    };
    
    for (int i = 0; i < 9; i++) {
        Rock r = rocks[i];
        printf("Hash of (%d, %d, %d) is %d\n", r.row, r.col, r.colour, hash(r, SIZE));
    }
}