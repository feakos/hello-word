#változtók deklarálása
CC = gcc
CFLAGS = -Wall
BINARIES = bit sizes

all: $(BINARIES)

bit: bit.o
	$(CC) $(CFLAGS) -o $@ $^

#$@ -> bit - target
#$^ -> bit.o - dependency lista, ami a : jobb oldala

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

sizes: sizes.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(BINARIES)

.PHONY: all clean
#ezek nem fájlok!