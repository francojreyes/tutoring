CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: cmp

cmp: cmp.c
	$(CC) $(CFLAGS) -o cmp cmp.c