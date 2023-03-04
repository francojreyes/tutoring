#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s, int n);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./palindrome <string>\n");
        return 1;
    }

    printf("Is \"%s\" a palindrome?\n", argv[1]);
    printf("%s\n", isPalindrome(argv[1], strlen(argv[1])) ? "Yes" : "No");

    return 0;
}

/**
 * Takes a string `s` and returns whether or not it is a palindrome
 * A palindrome reads the same backwards as forwards
 * For example, "racecar" is a palindrome, while "reviewer" is not
*/
bool isPalindrome(char *s, int n) {
    // Loop from the back, and check each char is equal to the fornt
    for (int i = 0; i < n; i++) {       // O(n)
        if (s[i] != s[n - 1 - i]) {         // O(1)
            return false;                   // O(1)
        }
    }                                   // Overall: O(n) * O(1) = O(n)

    return true;                        // O(1)
}
// Complexity: O(n)
// Best case O(1)
// When first letter and last letter are not equal

// for loop is (number of times it runs) * (time complexity of inside)
