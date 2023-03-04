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

// A = [CAT, DOG, MOUSE] P = [2, 3, 1], outputs [MOUSE, CAT, DOG]
void printPermutation(char **a, int *p, int n) {
    char **temp = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {       // O(n)
        temp[p[i] - 1] = a[i];
    }

    for (int i = 0; i < n; i++) {       // O(n)
        printf("%s\n", temp[i]);
    }
    free(temp);
}