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
 *
 * Complexity: O((n+k)logk)
 */
int kLargest(int *arr, int n, int *res, int k) {
	Pq largestSoFar = PqNew();
	for (int i = 0; i < n; i++) { // runs n times - O(nlogk)
		if (PqSize(largestSoFar) < k || arr[i] > PqPeek(largestSoFar)) { // O(1)
			PqExtract(largestSoFar); // O(logk)
			PqInsert(largestSoFar, arr[i]); // O(logk)
		}
	}

	int numReturned = 0;
	while (!PqIsEmpty(largestSoFar)) { // k => klogk
		res[numReturned++] = PqExtract(largestSoFar); // logk
	}

    return numReturned;
}

/**
 * Idea 1: put all the items from arr into a pq (max heap) - nlogn
 *         grab the k largest from there - klogn
 *         (n+k)logn
 * Idea 2: O(nk) without pq
 *         k times, iterate and find the largest
 * Idea 3: O(nk) without pq
 *         Iterate through whole array, and store the k largest so far in res
 *         arr = 80, 43, 20, 94, 21, 3, 91, 14, 86, 67, k=3
 *         i = 0, res = { 80 }
 *         i = 1, res = { 80, 43 }
 *         i = 2, res = { 80, 43, 20 }
 *         i = 3, res = { 80, 43, 94 } evicted smallest 20
 *         i = 4, res = { 80, 43, 94 }
 * Idea 4: Like Idea 3 but use a pq for "k largest so far"
 */
