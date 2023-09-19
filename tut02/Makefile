CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: list listContainer examples twosum palindrome

list: list.c
	$(CC) $(CFLAGS) -o list list.c

listContainer: listContainer.c
	$(CC) $(CFLAGS) -o listContainer listContainer.c

examples: examples.c
	$(CC) $(CFLAGS) -o examples examples.c

twosum: twosum.c
	$(CC) $(CFLAGS) -o twosum twosum.c

palindrome: palindrome.c
	$(CC) $(CFLAGS) -o palindrome palindrome.c

.PHONY: clean
clean:
	rm -rf *.dSYM *.o list listContainer examples twosum palindrome
