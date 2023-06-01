CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: runList runBST

runList: runList.c List.h List.c
	$(CC) $(CFLAGS) -o runList runList.c List.c

runBST: runBST.c BSTree.h BSTree.c
	$(CC) $(CFLAGS) -o runBST runBST.c BSTree.c

.PHONY: clean
clean:
	rm runList runBST
