CC = gcc
CFLAGS = -Wall -Werror -g

.PHONY: all
all: main

main: main.c BSTree.h BSTree.c
	$(CC) $(CFLAGS) -o main main.c BSTree.c

.PHONY: clean
clean:
	rm main
