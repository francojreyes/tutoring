#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printPermutation(char **a, int *p, int n);

int main(int argc, char **argv) {
    // a is the second command line argument onwards
    int n = argc - 1;
    char **a = &argv[1];

    // Read the permutation
    int *p = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        assert(p[i] >= 1 && p[i] <= n);
    }

    printPermutation(a, p, n);
    free(p);
}

void printPermutation(char **a, int *p, int n) {
    
}