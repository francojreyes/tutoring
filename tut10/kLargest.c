#include <stdio.h>
#include <stdlib.h>

#include "Pq.h"

#define N 10
#define K 20

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
	// O(n * logn) Insert everything into PQ, extract the (n-k) smallest
	// O(n * k) - iterate k times and find the biggest each time
	// O(n * k) - maintain an array of the k largest, add to it as we go
	// O(n * logk) - maintain a min heap of the k largest, add to it as we go

	Pq pq = PqNew();
	for (int i = 0; i < n; i++) {
		if (i < k) {
			PqInsert(pq, arr[i]);
		} else if (arr[i] > PqPeek(pq)) {
			PqExtract(pq);
			PqInsert(pq, arr[i]);
		}
	}

	int numResults = 0;
	while (!PqIsEmpty(pq)) {
		res[numResults++] = PqExtract(pq);
	}
    return numResults;
}
