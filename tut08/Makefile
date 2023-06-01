CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: reachable

reachable: reachable.c Graph.c Set.c Stack.c Queue.c 
	$(CC) $(CFLAGS) -o reachable reachable.c Graph.c Set.c Stack.c Queue.c