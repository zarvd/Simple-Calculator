#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "bigint.hpp"


namespace calculator {

    class Calculator final {
    private:
        BigInt result;
        std::string formula;
        bool isExit = false;
        void input();
        void parse();
    public:
        Calculator() = default;
        Calculator(const Calculator&) = delete;  // disable default coping constructor
        ~Calculator() = default;
        void init();
        void printResult();
    };
}

#endif /* CALCULATOR_H */
