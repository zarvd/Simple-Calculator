#include "calculator.hpp"
#include "helper.hpp"

#include <iostream>

namespace calculator {

    /**
     * Init calculator
     */
    void Calculator::init() {
        while( ! isExit) {
            input();
            parse();
            printResult();
        }
    }

    /**
     * Read command
     */
    void Calculator::input() {
        std::getline(std::cin, expression);
    }

    /**
     * Output result
     */
    void Calculator::printResult() {
        std::cout << "Result: " << result.toStr() << std::endl;
    }

    /**
     * Parse command
     */
    void Calculator::parse() {
        helper::removeAllSpace(expression);
    }
}
