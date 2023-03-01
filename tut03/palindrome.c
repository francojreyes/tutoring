#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char *s);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./palindrome <string>\n");
        return 1;
    }

    printf("Is \"%s\" a palindrome?\n", argv[1]);
    printf("%s\n", isPalindrome(argv[1]) ? "Yes" : "No");

    return 0;
}

/**
 * Takes a string `s` and returns whether or not it is a palindrome
 * A palindrome reads the same backwards as forwards
 * For example, "racecar" is a palindrome, while "reviewer" is not
*/
bool isPalindrome(char *s) {
    return false;
}
