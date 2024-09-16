#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Complexity: 6 = 6 x 1 = 6 x n^0 = O( 1 )
void func0(int n) {
    char *result;               
    if (n % 2 == 1) { // mod, eq, if = 3
        result = "n is odd"; // assn = 1
    } else {
        result = "n is even"; // 1
    }
    printf("%s\n", result); // print = 1
    return; // return = 1
}

// Complexity: 7 = 7x1 = O( 1 )
void func1(int n) {
    // mul, malloc, assn = 3
    int *arr = malloc(n * sizeof(int));

    // index, assn = 2
    arr[3] = 1;

    // print, assn = 2
    printf("%d\n", arr[0]);

    // free = 1
    free(arr);
}


// Complexity: 3n + 2 = O( n )
void func2(int n) {
    // assn = 1, incr = n, check = n+1
    for (int i = 0; i < n; i++) {
        // n
        printf("%d\n", i);
    }
}

// number of times loop runs * complexity of body
// n * O(1) = O(n)

// Complexity: O( logn )
// # loops * body
// log * O(1) = O(logn)

// 2^x = n
// log2(2^x) = log2(n)
// x = log2(n)
void func3(int n) {
    for (int i = 1; i < n; i *= 2) {
        printf("%d\n", i);
    }
}


// Complexity: O( n^2 )
void func4(int n) {
    // # loop * body
    // n * O(n) = O(n^2)
    for (int i = 0; i < n; i++) {

        // # loop * body
        // n * O(1) = O(n)
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( ? )
void func5(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( ? )
void func6(int n) {
    int i = 0;
    while (i < n) {
        // Generate a random number r in the range [0, n)
        int r = rand() % n;

        // Print the next r numbers on this line
        for (int j = 0; j < r && i < n; j++) {
            printf("%d ", i);
            i++;
        }
        printf("\n");
    }
}


// Complexity: O( ? )
void func7(int n) {
    for (int i = 0; i < n; i++) {
        func4(n);
    }
}


// Complexity: O( ? )
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
        printf("Usage: ./complexity <func num> <n>\n");
        return 1;
    }

    int funcNum = atoi(argv[1]);
    assert(funcNum >= 0 && funcNum <= 8);
    int n = atoi(argv[2]);
    assert(n > 0);
    
    funcs[funcNum](n);

}
