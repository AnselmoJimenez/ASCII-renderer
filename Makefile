CC=gcc
CFLAGS=-c -Wall -I. -fpic -g -fbounds-check
LIBS=-lm

OBJS=render.o cube.o

%.o:	%.c %.h
	$(CC) $(CFLAGS) $< -o $@

render:	$(OBJS) 
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJS) render