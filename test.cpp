#include <iostream>
#include <string>
#include "calculator.hpp"

using namespace calculator;


int main(void) {
    BigInt A("-1"), B("-1");
    std::cout << "A = " << A.toStr() << std::endl;
    std::cout << "B = " << B.toStr() << std::endl;
    if(A > B) {
        std::cout << "A > B" << std::endl;
    } else if(A < B) {
        std::cout << "A < B" << std::endl;
    } else {
        std::cout << "A == B" << std::endl;
    }
    std::cout << (A + B).toStr() << std::endl;
    return 0;
}
