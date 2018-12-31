CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=-lbsd
EXEC=parse1

all: $(EXEC)

parse1: parse1.c  read_exchange_data.c parse1.c calculate_marg.c report.c read_exchange_data_prv.c
	$(CC) -g  -o $@  $^ $(LDFLAGS)


clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
