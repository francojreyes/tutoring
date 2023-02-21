#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

typedef int Integer;

char *numToDay(Integer n);

int main(void) {
    // typdef old_type new_type
    int day = 4;
    printf("%s\n", numToDay(day));
}

char *numToDay(Integer n) {
    switch (n) {
        case 0: return "Sun"; 
        case 1: return "Mon"; 
        case 2: return "Tue"; 
        case 3: return "Wed"; 
        case 4: return "Thu"; 
        case 5: return "Fri"; 
        case 6: return "Sat"; 
        default: return "???"; 
    }
}