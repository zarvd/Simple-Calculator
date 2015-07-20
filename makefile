CC=clang++
FLAG=-Wall -std=c++11 -g
MAIN=main
TEST=test

.PHONY: all test clean

all: bigint.o calculator.o main.o main test
bigint.o:
	$(CC) $(FLAG) -c bigint.cpp
calculator.o: bigint.o
	$(CC) $(FLAG) -c calculator.cpp
main.o: bigint.o calculator.o
	$(CC) $(FLAG) -c main.cpp
main: bigint.o calculator.o main.o
	$(CC) $(FLAG) bigint.o calculator.o main.o -lm -O0 -o $(MAIN)
test.o: bigint.o calculator.o
	$(CC) $(FLAG) -c test.cpp
test: bigint.o calculator.o test.o
	$(CC) $(FLAG) bigint.o calculator.o test.o -lm -O0 -o $(TEST)
clean:
	rm *.o $(MAIN) $(TEST)
