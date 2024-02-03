CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG = -g

.PHONY: clean

test: test.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

clean:
	@rm -rf *.o test
