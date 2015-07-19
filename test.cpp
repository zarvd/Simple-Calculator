#include <iostream>
#include <string>
#include "calculator.hpp"

using namespace calculator;


void testAdd() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Add:" << std::endl;
    BigInt A("1"), B("9999");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A + B = " << (A + B) << std::endl;
}

void testSubtraction() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Subtraction:" << std::endl;
    BigInt A("2"), B("1");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    A = "1";
    B = "2";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    A = "100000";
    B = "1";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
}

void testMultiplication() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Multiplication:" << std::endl;
    BigInt A("2"), B("1");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
    A = "1000";
    B = "1";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
    A = "9999";
    B = "9";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
    A = "-9999";
    B = "9";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
}

void testCompare() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Compare:" << std::endl;
    BigInt A("-1"), B("-1");
    A = "5";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
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
    testSubtraction();
    testMultiplication();
    return 0;
}
