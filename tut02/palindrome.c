#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s);

int main(int argc, char **argv) {
    printf("%s\n", isPalindrome(argv[1]) ? "true" : "false");
    return 0;
}

// COmplexity O(n)
bool isPalindrome(char *s) {
    int n = strlen(s);          // O(n)
    int l = 0;                  // O(1)
    int r = n - 1;              // O(1)
    while (l < r) {             // O(n)
        if (s[l] != s[r]) {         // O(1)
            return false;           // O(1)
        }                           
        l++;                        // O(1)
        r--;                        // O(1)
    }
    return true;                    // O(1)
}
