CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: examples twosum polynomial permutation

examples: examples.c
	$(CC) $(CFLAGS) -o examples examples.c

twosum: twosum.c
	$(CC) $(CFLAGS) -o twosum twosum.c

polynomial: polynomial.c
	$(CC) $(CFLAGS) -lm -o polynomial polynomial.c

permutation: permutation.c
	$(CC) $(CFLAGS) -o permutation permutation.c

.PHONY: clean
clean:
	rm examples twosum polynomial permutation
