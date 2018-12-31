CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=-lbsd
EXEC=parse1

all: $(EXEC)

parse1: parse1.o  read_exchange_data.o parse1.o calculate_marg.o report.o read_exchange_data_prv.o
	$(CC) -g  -o $@ -c $^ $(LDFLAGS)

parse1.o: parse1.c   main.h
	$(CC) -o  parse1.o -c parse1.c 

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
