CC=gcc
CFLAGS=-c -Wall -I. -fpic -g -fbounds-check
LIBS=-lm

main:	
	$(CC) cube.c -o cube $(LIBS)

clean:
	rm -f cube