CC = gcc
CFLAGS = -Wall -Werror -g

.PHONY: all
all: palindrome twoSum

palindrome: palindrome.c
	$(CC) $(CFLAGS) -o palindrome palindrome.c

twoSum: twoSum.c
	$(CC) $(CFLAGS) -o twoSum twoSum.c

.PHONY: clean
clean:
	rm *.o palindrome twoSum
