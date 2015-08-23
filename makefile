CC=clang++
FLAG=-Wall -std=c++11 -g -O2
MAIN=main
TEST=test

.PHONY: all test clean

all: helper.o bigint.o calculator.o main.o main test

helper.o:
	$(CC) $(FLAG) -c helper.cpp

bigint.o:
	$(CC) $(FLAG) -c bigint.cpp

calculator.o: helper.o bigint.o
	$(CC) $(FLAG) -c calculator.cpp

exprtree.o: bigint.o
	$(CC) $(FLAG) -c exprtree.cpp

main.o: helper.o bigint.o calculator.o exprtree.o
	$(CC) $(FLAG) -c main.cpp

main: helper.o bigint.o calculator.o main.o
	$(CC) $(FLAG) exprtree.o helper.o bigint.o calculator.o main.o -lm -o $(MAIN)

test.o: helper.o bigint.o calculator.o exprtree.o
	$(CC) $(FLAG) -c test.cpp

test: helper.o bigint.o calculator.o test.o
	$(CC) $(FLAG) exprtree.o helper.o bigint.o calculator.o test.o -lm -o $(TEST)

clean:
	rm *.o $(MAIN) $(TEST)
