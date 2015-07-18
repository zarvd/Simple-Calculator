#include <iostream>
#include <string>
#include "calculator.hpp"

using namespace calculator;

int main(void) {
    std::cout << "Simple Calculator by Gallon" << std::endl;
    Calculator cal;
    cal.init();
    return 0;
}
