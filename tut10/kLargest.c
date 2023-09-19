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
    Pq heap = PqNew();

    for (int i = 0; i < n; i++) {
        if (PqSize(heap) < k) {
            PqInsert(heap, arr[i]);
        } else if (arr[i] > PqPeek(heap)) {
            PqExtract(heap);
            PqInsert(heap, arr[i]);
        }

        printf("\nAfter considering %d:\n", arr[i]);
        PqShow(heap);
    }

    int num = 0;
    while (num < k && !PqIsEmpty(heap)) {
        res[num++] = PqExtract(heap);
    }

    return num;
}
