#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool twoSum(int *array, int n, int target);

int main(void) {
    // Read the input
    int n;
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int target;
    scanf("%d", &target);

    // Print the prompt
    printf("\nDoes {");
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d, ", array[i]);
        } else {
            printf("%d", array[i]);
        }
    }
    printf("} contain two numbers that sum to %d?\n", target);

    // Print the result
    printf("%s\n", twoSum(array, n, target) ? "Yes" : "No");

    free(array);
}

/**
 * Return whether or not the array contains two numbers that sum to the target
*/
bool twoSum(int *array, int n, int target) {
    // Loop through every element
        // Loop throguh every other element
        // If they sum to target return true
    for (int i = 0; i < n; i++) {                   // O(n)
        for (int j = i + 1; j < n; j++) {               // O(n)
            if (array[i] + array[j] == target) {            // O(1)
                return true;                                // O(1)
            }                                           // O(n) * O(1) = O(n)
        }                                           // O(n) * O(n) = O(n^2)
    }
    return false;                                   // O(1)
}
// Overall complexity; O(n^2)
