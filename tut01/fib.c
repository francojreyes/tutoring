// This program computes fibonacci values
// Franco Reys, COMP2521 23T0 tut01

#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(void) {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    printf("The %dth fibonacci number is %d\n", n, fib(n));
}

int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}
