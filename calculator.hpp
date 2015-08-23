#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>
#include <memory>
#include "bigint.hpp"
#include "exprtree.hpp"


namespace calculator {

    class Calculator final {
    private:
        BigInt result;
        std::string expression;
        bool isExit = false;
        void input();
        void parse();

    public:
        Calculator() = default;
        Calculator(const Calculator&) = delete;
        ~Calculator() = default;
        void init();
        BigInt calculate(std::shared_ptr<ExprNode>) const;
        static bool isValidExpr(const std::string&);
        void setPrecedence(std::string&) const;
        void insertBracket(std::string&, const std::vector<char>&) const;
        unsigned short findOpPos(const std::string&, const std::vector<char>&, unsigned) const;
        std::shared_ptr<ExprNode> getExprTree(const std::string&) const;
        std::string removeBracket(const std::string&) const;
        void printResult() const;
    };
}

#endif /* CALCULATOR_H */
