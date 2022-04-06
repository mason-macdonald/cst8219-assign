CC = gcc
CFLAGS = -ansi -pedantic -g -std=c99 -Wall

part1: part1.c
	$(CC) $(CFLAGS) part1.c -o part1

clean:
	rm part1
