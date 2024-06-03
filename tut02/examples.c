#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Complexity: 6 operations = 6 * 1 = 6 * n^0 = O( 1 )
void func0(int n) {
    char *result;               
    if (n % 2 == 1) { // modulo, equality check, if
        result = "n is odd"; // assignment
    } else {
        result = "n is even"; // assignment
    }
    printf("%s\n", result); // print
    return; // return
}

// Complexity: 8 = O( 1 )
void func1(int n) {
	// malloc, multiplication, assignment
    int *arr = malloc(n * sizeof(int));

	// indexing, assignment
    arr[3] = 1;

	// indexing, print
    printf("%d\n", arr[0]);

	// free
    free(arr);
}


// Complexity: 3n + 2 = O( n )
void func2(int n) {
	// loops: numberOfRuns * complexityOfBody
	//        n            * O(1)
	//        O(n)


	// assignment, n+1 checks, n increments
    for (int i = 0; i < n; i++) {
		// n prints
        printf("%d\n", i);
    }
}


// Complexity: O( logn )
void func3(int n) {
	// numberOfRuns * complexityOfBody
	// O(logn) * O(1)
    for (int i = 1; i < n; i *= 2) {
        printf("%d\n", i);
    }

	// 2^x = n
	// log2(2^x) = log2(n)
	// x = log2(n)
}


// Complexity: O( n^2 )
void func4(int n) {
	// numRuns * bodyComplexity
	// n * O(n) = O(n^2)
    for (int i = 0; i < n; i++) {
		// numRuns * bodyComplexity
		// n * O(1) = O(n)
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }
}


// Complexity: O( n^2 )
void func5(int n) {
    for (int i = 0; i < n; i++) {
		// numRuns = n - i <= n
		// numRuns * body = n * O(1) = O(n)
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


// Complexity: O( n )
// numberOfTimesFnRecurses * complexityExcludingRecursion
// O(n)                    * O(1)
// = O(n)
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
