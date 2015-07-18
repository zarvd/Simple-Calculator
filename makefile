CC=clang++
FLAG=-Wall -std=c++11 -g
MAIN=main

.PHONY: all clean

all: bigint.o calculator.o main.o main
bigint.o:
	$(CC) $(FLAG) -c bigint.cpp
calculator.o: bigint.o
	$(CC) $(FLAG) -c calculator.cpp
main.o: bigint.o calculator.o
	$(CC) $(FLAG) -c main.cpp
main: bigint.o calculator.o main.o
	$(CC) $(FLAG) bigint.o calculator.o main.o -lm -O2 -o $(MAIN)
clean:
	rm *.o $(MAIN)
