#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Complexity: 6 = 6 * 1 = O( 1 )
void func0(int n) {
    char *result;
    if (n % 2 == 1) {           // modulo (1) + comparison (1) + if (1)
        result = "n is odd";    // assignment (1)
    } else {
        result = "n is even";   // assignemnt (1)
    }
    printf("%s\n", result);     // print (1)
    return;                     // return (1)
}


// Complexity: 7 = 7 * 1 = O( 1 )
void func1(int n) {
    int *arr = malloc(n * sizeof(int));     // mult (1) + malloc (1) + assignment (1)

    arr[0] = 1;                             // index (1) + assignment (1)
    printf("%d\n", arr[0]);                 // print (1)

    free(arr);                              // free (1)
}


// Complexity: O( n )
void func2(int n) {
    // number of times loop runs * complexity of body
    // n * O(1) = O(n)
    for (int i = 0; i < n; i++) {   // assignment (1) + increements (n) + comparisons (n+1)
        printf("%d\n", i);
    }
}


// Complexity: O( logn )
void func3(int n) {
    // times loop runs * complexity of body
    // O(logn) * O(1)

    // 1 * 2 * 2 * 2.... = n
    // 2^x = n
    // log2(2^x) = log2(n)
    // xlog2(2) = log2(n)
    // x = log2(n)
    for (int i = 1; i < n; i *= 2) {
        printf("%d\n", i);
    }
}


// Complexity: O( n^2 )
void func4(int n) {
    // n * O(n) = O(n^2)
    for (int i = 0; i < n; i++) {

        // n * O(1) = O(n)
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: n^2/2 - n/2 = n^2/2 =  O( n^2 )
void func5(int n) {
    for (int i = 0; i < n; i++) {
        // n, n - 1, n - 2, ..., 1 = 1 + ... + n = n(n-1)/2 = n^2/2 - n/2
        for (int j = i; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}

// Complexity: O( n^2 )
void func6(int n) {
    int count = 0;
    while (count < n) {
        int random = rand() % n;
        for (int i = 0; i < random && count < n; i++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }
}


// Complexity: O( n^3 )
void func7(int n) {
    // n * O(n) = O(n^3)
    // n^2 + logn = n^2
    for (int i = 0; i < n; i++) {
        func4(i); // O(n^2)

        // O(logn)
        for (int j = 1; j < n; j *= 2) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( )
// loops = number of times loop runs * complexity of body
// recursion = number of recursive calls * complexity of function (excluding recursion)
// (n + 2) = O(n) * O(1) = O(n)
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
    srand(time(NULL));

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
