// This program computes fibonacci values
// Franco Reys, COMP2521 23T0 tut01

#include <stdio.h>
#include <stdlib.h>

#define N 10

int fib(int n, int *cache);

int main(void) {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    int *cache = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        cache[i] = -1;
    }
    printf("The %dth fibonacci number is %d\n", n, fib(n, cache));
}

int fib(int n, int *cache) {
    if (cache[n] != -1) {
        return cache[n];
    } else {
        int result;
        if (n == 0) {
            result = 0;
        } else if (n == 1) {
            result = 1;
        } else {
            result = fib(n - 1) + fib(n - 2);
        }
        cache[n] = result;
        return result;
    }
	
}

// fib(4) == 3
    // fib(3) == 2
        // fib(2) == 1
            // fib(1) == 1
            // fib(0) == 0
        // fib(1) == 1
    // fib(2) == 1
