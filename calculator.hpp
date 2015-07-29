#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
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
        static const std::map<char, Symbol> op;
        Calculator() = default;
        Calculator(const Calculator&) = delete;
        ~Calculator() = default;
        void init();
        static bool isValidExpr(const std::string&);
        void setPrecedence(std::string&) const;
        void findPrecedence(std::string&, const std::vector<char>&) const;
        void printResult() const;
    };
}

#endif /* CALCULATOR_H */
