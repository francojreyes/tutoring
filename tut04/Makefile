CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: runBST

runBST: runBST.c BST.h BST.c
	$(CC) $(CFLAGS) -o runBST runBST.c BST.c

.PHONY: clean
clean:
	rm -rf *.dSYM runBST occurences
