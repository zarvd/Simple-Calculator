#include <iostream>
#include <string>
#include "calculator.hpp"

using namespace calculator;


int main(void) {
    BigInt A("9999"), B("1");
    std::cout << A.toStr() << std::endl;
    std::cout << B.toStr() << std::endl;
    std::cout << (A + B).toStr() << std::endl;
    return 0;
}
