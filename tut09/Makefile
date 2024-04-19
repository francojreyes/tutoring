CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: hash

hash: hash.c
	$(CC) $(CFLAGS) -o hash hash.c