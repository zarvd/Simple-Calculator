CC=clang++
FLAG=-Wall -std=c++11 -g
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

main.o: helper.o bigint.o calculator.o
	$(CC) $(FLAG) -c main.cpp

main: helper.o bigint.o calculator.o main.o
	$(CC) $(FLAG) helper.o bigint.o calculator.o main.o -lm -O0 -o $(MAIN)

test.o: helper.o bigint.o calculator.o
	$(CC) $(FLAG) -c test.cpp

test: helper.o bigint.o calculator.o test.o
	$(CC) $(FLAG) helper.o bigint.o calculator.o test.o -lm -O0 -o $(TEST)

clean:
	rm *.o $(MAIN) $(TEST)
