#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasTwoSum(int a[], int n, int v);

int main(void) {
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int v;
    scanf("%d", &v);

    printf("%s\n", hasTwoSum(a, n, v) ? "true" : "false");

    free(a);
    return 0;
}

bool hasTwoSum(int a[], int n, int v) {
    return false;
}