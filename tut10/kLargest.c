#include <stdio.h>
#include <stdlib.h>

#include "Pq.h"

#define N 10
#define K 3

int kLargest(int *arr, int n, int *res, int k);

int main(void) {
    int arr[N] = {80, 43, 20, 94, 21, 3, 91, 14, 86, 67};
    int res[K] = {};

    int num = kLargest(arr, N, res, K);
    for (int i = 0; i < num; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

/**
 * Takes in an array `arr` of size `n`, and places the `k` largest
 * elements into `res`. Returns how many items were placed into `res`.
 */
int kLargest(int *arr, int n, int *res, int k) {
    return 0;
}
