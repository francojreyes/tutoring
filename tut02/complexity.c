#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Complexity: O( ? )
void func0(int n) {
    char *result;               
    if (n % 2 == 1) {
        result = "n is odd";
    } else {
        result = "n is even";
    }
    printf("%s\n", result);
    return;
}

// Complexity: O( ? )
void func1(int n) {
    int *arr = malloc(n * sizeof(int));

    arr[3] = 1;
    printf("%d\n", arr[0]);

    free(arr);
}


// Complexity: O( ? )
void func2(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
    }
}


// Complexity: O( ? )
void func3(int n) {
    for (int i = 1; i < n; i *= 2) {
        printf("%d\n", i);
    }
}


// Complexity: O( ? )
void func4(int n) {
    for (int i = 0; i < n; i++) {
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
