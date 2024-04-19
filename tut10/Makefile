CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: kLargest

kLargest: kLargest.c PQ.h PQ.c
	$(CC) $(CFLAGS) -o kLargest kLargest.c PQ.c
