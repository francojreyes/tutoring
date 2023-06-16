#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


// Complexity: O( 1 )
// 5 operations = 5 * 1
void func0(int n) {
    char *result;               // 0
    if (n % 2 == 1) {           // 1 calulation, 1 check
        result = "n is odd";    // 1 assignment
    } else {
        result = "n is even";   // 1 assignment
    }
    printf("%s\n", result);     // 1 print
    return;                     // 1 return
}


// Complexity: O( 1 )
void func1(int n) {
    int *arr = malloc(n * sizeof(int)); // O(1) malloc

    arr[0] = 1;                         // 1 index, 1 assign
    printf("%d\n", arr[0]);             // 1 index, 1 print

    free(arr);                          // O(1) free
}


// Complexity: O( n )
// Total operations: 3n
void func2(int n) {
    // 1 assignment
    // n + 1 checks
    // n increments

    // n = 3
    // initialise to 0, check 0 < n
    // inc to 1, check 1 < n
    // inc 2, check 2 < n
    // inc to 3, check 3 < n
    for (int i = 0; i < n; i++) { // 2n + 2
        printf("%d\n", i);        // O(1) * n
    }
}
// Complexity of a loop:
// Number of iterations * complexity of body
// n * O(1) = O(n)


// Complexity: O( logn )
void func3(int n) {
    // Number of iterations * complexity of body
    // O(logn) * O(1)
    // 1 * 2^? = n
    // 2^? = n
    // ? = log_2(n)
    for (int i = 1; i < n; i *= 2) {
        printf("%d\n", i);
    }
}


// Complexity: O( n^2 )
void func4(int n) {
    // n it * O(n) body = O(n^2)
    for (int i = 0; i < n; i++) {
        // n it * O(1) body = O(n)
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( n^2 )
void func5(int n) {
    // n it * O(n) body = O(n^2)
    for (int i = 0; i < n; i++) {
        // O(1) body * n iterations = O(n)
        for (int j = i; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( n )
void func6(int n) {
    int count = 0;
    while (count < n) {
        int random = rand() % n;
        printf("Iterating %d times\n", random);
        for (int i = 0; i < random && count < n; i++) {
            printf("%d\n", count);
            count++;
        }
    }
}


// Complexity: O( n^2 )
void func7(int n) {
    func4(n);
}


// Complexity: O( n )
// Number of recursions
// * body of recursion (excluding more recursions)
// O(1) body * (n + 2) recursions
// = n + 2 = O(n)
void func8(int n) {
    if (n < 0) {
        return;
    } else {
        func8(n - 1);
        printf("%d\n", n);
    }
}


typedef void (*func)(int);

int main(int argc, char **argv) {
    func funcs[10] = {
        func0,
        func1,
        func2,
        func3,
        func4,
        func5,
        func6,
        func7,
        func8,
    };

    if (argc != 3) {
        printf("Usage: ./examples <func num> <n>\n");
        return 1;
    }

    int funcNum = atoi(argv[1]);
    assert(funcNum >= 0 && funcNum <= 8);
    int n = atoi(argv[2]);
    assert(n > 0);
    
    funcs[funcNum](n);

}
