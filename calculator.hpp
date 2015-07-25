#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <map>
#include "bigint.hpp"


namespace calculator {

    class Calculator final {
    private:
        BigInt result;
        std::string expression;
        bool isExit = false;
        void input();
        void parse();
    public:
        enum Symbol {
            digit,
            plus,
            minus,
            multiple,
            divide,
            open,
            close
        };
        Calculator() = default;
        Calculator(const Calculator&) = delete;  // disable default coping constructor
        ~Calculator() = default;
        void init();
        static bool isValidExpr(const std::string&);
        void printResult();
    };
}

#endif /* CALCULATOR_H */
