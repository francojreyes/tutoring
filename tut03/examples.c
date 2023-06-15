#include <stdio.h>
#include <stdlib.h>


// Complexity: O( ? )
int func0(int n) {
    char *result;
    if (n % 2 == 1) {
        result = "n is odd";
    } else {
        result = "n is even";
    }
    printf("%s\n", result);
}


// Complexity: O( ? )
int func1(int n) {
    int *arr = malloc(n * sizeof(int));
    arr[0] = 1;

    for (int i = 1; i < n; i++) {
        arr[i] = 2 * arr[i - 1];
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
}


// Complexity: O( ? )
int func2(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
    }
}


// Complexity: O( ? )
int func3(int n) {
    for (int i = 0; i < n; i *= 2) {
        printf("%d\n", i);
    }
}


// Complexity: O( ? )
int func4(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( ? )
int func5(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( ? )
int func6(int n) {
    int count = 0;
    while (count < n) {
        int random = rand() % n;
        for (int i = 0; i < random && count < n; i++) {
            printf("%d\n", count);
            count++;
        }
    }
}


// Complexity: O( ? )
int func7(int n) {
    func4(n);
}


// Complexity: O( ? )
int func8(int n) {
    func4(n);
}

// Complexity: O( ? )
int func9(int n) {
    if (n <= 0) {
        return;
    } else {
        func9(n - 1);
        printf("%d\n", n);
    }
}


int main(void) {

}
