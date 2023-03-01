CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined,leak

.PHONY: all
all: palindrome twosum polynomial permutation

palindrome: palindrome.c
	$(CC) $(CFLAGS) -o palindrome palindrome.c

twosum: twosum.c
	$(CC) $(CFLAGS) -o twosum twosum.c

polynomial: polynomial.c
	$(CC) $(CFLAGS) -o polynomial polynomial.c

permutation: permutation.c
	$(CC) $(CFLAGS) -o permutation permutation.c

.PHONY: clean
clean:
	rm palindrome twosum polynomial permutation
