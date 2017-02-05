#változtók deklarálása
CC = gcc
CFLAGS = -Wall

all: bit

bit: bit.o
	$(CC) $(CFLAGS) -o $@ $^

#$@ -> bit - target
#$^ -> bit.o - dependency lista, ami a : jobb oldala

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o bit

.PHONY: all clean
#ezek nem fájlok!