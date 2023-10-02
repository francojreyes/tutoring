#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Complexity: 6 prim ops = 6 * 1 = O(1)
void func0(int n) {
    char *result;               
    if (n % 2 == 1) {         // 1 (mod) + 1 (equals)      
        result = "n is odd"; // 1 (write)
    } else {
        result = "n is even"; // 1 (write)
    }
    printf("%s\n", result); // 1 (print)
    return;                 // 1 (return)
}

// 

// Complexity: 9 * 1 = O(1)
void func1(int n) {
    // 1 (mult) + 1 (malloc) + 1 (write)
    int *arr = malloc(n * sizeof(int));  

    // 1 (index) + 1 (write)
    arr[3] = 1;

    // 1 (index) + 1 (read) + 1 (print)
    printf("%d\n", arr[0]);

    // 1 (free)
    free(arr);
}


// Complexity: O( n )
void func2(int n) {
    // number of times the loop runs * the complexity of the inside
    // n * O(1) = O(n)
    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
    }
}


// Complexity: O( logn )
void func3(int n) {
    // number of times the loop runs * the complexity of the inside
    // logn * O(1)
    // 2^x = n
    // log2(2^x) = log2(n)
    // x = log2(n)
    for (int i = 1; i < n; i *= 2) {
        printf("%d\n", i);
    }
}


// Complexity: 
void func4(int n) {
    // number of times the loop runs * the complexity of the inside
    // O(n) * O(n) = O(n^2)
    for (int i = 0; i < n; i++) {
        // number of times the loop runs * the complexity of the inside
        // n * O(1) = O(n)
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( )
void func5(int n) {
    for (int i = 0; i < n; i++) {
        // number of times the loop runs * the complexity of the inside
        // n - i = O(n) * O(1) = O(n)
        for (int j = i; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( ? )
void func6(int n) {
    int count = 0;
    while (count < n) {
        int random = rand() % n;
        for (int i = 0; i < random && count < n; i++) {
            printf("%d (%d)\n", count, i);
            count++;
        }
        printf("\n");
    }
}


// Complexity: O( n^2 )
void func7(int n) {
    func4(n);
}


// Complexity: O( ? )
// number of recursions * complexity of inside (excluding the recursion)
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
