#változtók deklarálása
CC = gcc
CFLAGS = -Wall

all: bit

bit: bit.o
	$(CC) $(CFLAGS) -o $@ $^
	#$@ -> bit.o -> target
	#$^ -> dependency lista, ami a : jobb oldala

bit.o: bit.c
	$(CC) $(CFLAGS) -c bit.c

clean:
	rm -f *.o bit

.PHONY: all clean
#ezek nem fájlok!