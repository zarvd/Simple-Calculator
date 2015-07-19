#include <iostream>
#include <string>
#include "calculator.hpp"

using namespace calculator;


void testAdd() {
    std::cout << "TEST Add:" << std::endl;
    BigInt A("1"), B("9999");
    std::cout << (A + B).toStr() << std::endl;
}

void testCompare() {
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
    return 0;
}
