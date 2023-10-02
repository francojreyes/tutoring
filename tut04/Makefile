CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: runBST occurences

runBST: runBST.c BST.h BST.c
	$(CC) $(CFLAGS) -o runBST runBST.c BST.c


occurences: occurences.c Set.h Set.c
	$(CC) $(CFLAGS) -o occurences occurences.c Set.c

.PHONY: clean
clean:
	rm -rf *.dSYM runBST occurences
