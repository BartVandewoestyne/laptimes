CC = gcc
#CFLAGS = -ansi -pedantic -Wall
CFLAGS = -Wall

all: laptimes

laptimes: laptimes.c
	$(CC) -o $@ $(CFLAGS) $< -lm

.PHONY: clean realclean
clean:
	-rm -f *.o a.out

realclean: clean
	-rm -f laptimes
