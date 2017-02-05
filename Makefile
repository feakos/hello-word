#változtók deklarálása
CC=gcc

CFLAGS=-Wall -c

all: bit

bit: bit.o
	$(CC) bit.o -o bit

bit.o: bit.c
	$(CC) $(CFLAGS) bit.c

clean:
	rm -rf *o bit

