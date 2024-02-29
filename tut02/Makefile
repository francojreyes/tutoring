CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: list listContainer examples

list: list.c
	$(CC) $(CFLAGS) -o list list.c

listContainer: listContainer.c
	$(CC) $(CFLAGS) -o listContainer listContainer.c

examples: examples.c
	$(CC) $(CFLAGS) -o examples examples.c

.PHONY: clean
clean:
	rm -rf *.dSYM *.o list listContainer examples twosum palindrome
