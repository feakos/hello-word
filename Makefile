#változtók deklarálása
CC = gcc
CFLAGS = -Wall

all: bit

bit: bit.o
	$(CC) $(CFLAGS) bit.o -o bit

bit.o: bit.c
	$(CC) $(CFLAGS) -c bit.c

clean:
	rm -f *.o bit

PHONY: all clean
#ezek nem fájlok!