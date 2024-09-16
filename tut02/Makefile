CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

.PHONY: all
all: list listContainer complexity

list: list.c
	$(CC) $(CFLAGS) -o list list.c

listContainer: listContainer.c
	$(CC) $(CFLAGS) -o listContainer listContainer.c

complexity: complexity.c
	$(CC) $(CFLAGS) -o complexity complexity.c

.PHONY: clean
clean:
	rm -rf *.dSYM *.o list listContainer complexity twosum palindrome
