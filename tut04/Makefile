CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: runBst

runBst: runBst.c bst.h bst.c
	$(CC) $(CFLAGS) -o runBst runBst.c BST.c

.PHONY: clean
clean:
	rm -rf *.dSYM runBst occurences
