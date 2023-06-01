CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: recursive iterative fib

recursive: main.c listRecursive.o
	$(CC) $(CFLAGS) -o recursive main.c listRecursive.o

listRecursive.o: list.h listRecursive.c
	$(CC) $(CFLAGS) -c listRecursive.c

iterative: main.c listIterative.o
	$(CC) $(CFLAGS) -o iterative main.c listIterative.o

listIterative.o: list.h listIterative.c
	$(CC) $(CFLAGS) -c listIterative.c

fib: fib.c
	$(CC) $(CFLAGS) -o fib fib.c

# pow: pow.c
# 	$(CC) $(CFLAGS) -o pow pow.c

.PHONY: clean
clean:
	rm *.o fib iterative recursive
