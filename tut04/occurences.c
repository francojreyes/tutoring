#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

int numDistinct(int arr[], int size);
int numOddOccurrences(int arr[], int size);
int numSingleOccurrences(int arr[], int size);

int main(void) {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    printf("Enter items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n");
    printf("# of distinct items: %d\n", numDistinct(arr, n));
    printf("# of items occuring an odd number of times: %d\n", numOddOccurrences(arr, n));
    printf("# of items occuring a single time: %d\n", numOddOccurrences(arr, n));
}


/**
 * Takes an array of integers and its size, and returns the number of distinct
 * integers that appear in the array.
 * 
 * For example, if given the array [4, 3, 4, 8, 8, 4], the function should
 * return 3, because there are only three distinct items: 4, 3 and 8.
 */
int numDistinct(int arr[], int size) {
    return 0;
}

/**
 * Takes an array of integers and its size, and returns the number of integers
 * that occur an odd number of times.
 * 
 * For example, if given the array [4, 3, 4, 8, 8, 4], the function should
 * return 2, because there are two elements that appear an odd number of times:
 * 3 (occurs 1 time) and 4 (occurs 3 times).
 */
int numOddOccurrences(int arr[], int size) {
    return 0;
}

/**
 * Takes an array of integers and its size, and returns the number of integers
 * that occur exactly once.
 * 
 * For example, if given the array [4, 3, 4, 8, 7, 4], the function should
 * return 3, because there are three elements that occur exactly once: 3, 8 
 * and 7.
 */
int numSingleOccurrences(int arr[], int size) {
    return 0;
}
