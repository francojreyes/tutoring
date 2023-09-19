CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: polynomial permutation

polynomial: polynomial.c
	$(CC) $(CFLAGS) -lm -o polynomial polynomial.c

permutation: permutation.c
	$(CC) $(CFLAGS) -o permutation permutation.c

.PHONY: clean
clean:
	rm -rf examples twosum polynomial permutation *.dSYM
