#include <iostream>
#include <string>
#include "calculator.hpp"

using namespace calculator;


void testAdd() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Add:" << std::endl;
    BigInt A("1"), B("9999");
    std::cout << "A = " << A.toStr() << std::endl;
    std::cout << "B = " << B.toStr() << std::endl;
    std::cout << "A + B = " << (A + B).toStr() << std::endl;
}

void testMinus() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Minus:" << std::endl;
    BigInt A("2"), B("1");
    std::cout << "A = " << A.toStr() << std::endl;
    std::cout << "B = " << B.toStr() << std::endl;
    std::cout << "A - B = " << (A - B).toStr() << std::endl;
    A = "1";
    B = "2";
    std::cout << "A = " << A.toStr() << std::endl;
    std::cout << "B = " << B.toStr() << std::endl;
    std::cout << "A - B = " << (A - B).toStr() << std::endl;
    A = "100000";
    B = "1";
    std::cout << "A = " << A.toStr() << std::endl;
    std::cout << "B = " << B.toStr() << std::endl;
    std::cout << "A - B = " << (A - B).toStr() << std::endl;
}

void testCompare() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Compare:" << std::endl;
    BigInt A("-1"), B("-1");
    A = "5";
    std::cout << "A = " << A.toStr() << std::endl;
    std::cout << "B = " << B.toStr() << std::endl;
    if(A > B) {
        std::cout << "A > B" << std::endl;
    } else if(A < B) {
        std::cout << "A < B" << std::endl;
    } else {
        std::cout << "A == B" << std::endl;
    }
}

int main(void) {
    testCompare();
    testAdd();
    testMinus();
    return 0;
}
