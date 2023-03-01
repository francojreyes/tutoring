#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int evalPolynomial(int *p, int n, int x);
void printPolynomial(int *p, int n);

int main(void) {
    // Read input
    int n;
    scanf("%d", &n);

    int *p = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int x;
    scanf("%d", &x);

    // Print the result
    printPolynomial(p, n);
    printf("p(%d) = %d\n", x, evalPolynomial(p, n, x));

    free(p);
}

/**
 * Given a degree n polynomial p and the a value x, evaluate p(x)
 * Polynomials are given as an array {a_0, a_1, a_2, ..., a_n} (length n + 1)
 * For example, if p = {1, 2, 3}, p(x) = 3x^2 + 2x + 1
*/
int evalPolynomial(int *p, int n, int x) {
    return 0;
}

/**
 * Prints a polynomial
*/
void printPolynomial(int *p, int n) {
    printf("p(x) = ");

    bool first = true;
    for (int i = n; i >= 0; i--) {
        // Terms with coefficient of 0 are skipped
        if (p[i] == 0) continue;

        // Print the prefix
        if (first && p[i] < 0) {
            // The first term should have "-" if negative
            printf("-");
        } else if (!first && p[i] < 0) {
            // Negative terms are preceded by a " - "
            printf(" - ");
        } else if (!first && p[i] > 0) {
            // Positive terms are preceded by a " + "
            printf(" + ");
        }

        // Coefficients of 1 are omitted, unless its constant
        if (i == 0 || abs(p[i]) != 1) {
            printf("%d", abs(p[i]));
        }

        // Should not print x for the constant term
        if (i != 0) {
            printf("x");
        }

        // Indices of 1 are omitted, so is the constant index
        if (i > 1) {
            printf("^%d", i);
        }
        
        // After the first term is printed, first should be false
        first = false;
    }

    printf("\n");
}
