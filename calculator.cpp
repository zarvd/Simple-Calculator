#include "calculator.hpp"
#include "helper.hpp"

#include <iostream>
#include <vector>

namespace calculator {

    const std::map<char, Calculator::Symbol> Calculator::op = {
        {'+', plus},
        {'-', minus},
        {'*', multiple},
        {'/', divide}
    };


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
     * Parse expression
     */
    void Calculator::parse() {
        helper::removeAllSpace(expression);
        if( ! isValidExpr(expression)) {
            throw "Invalid expression";
        } else {
        }
    }

    /**
     * Find operators's precedence and insert parenthese
     */
    void Calculator::findPrecedence(std::string& expr) {
        const std::vector<char> highPrecedenceOps{'*', '/'};
        unsigned short opPos;
        opPos = helper::findChars(expr, highPrecedenceOps);
        while(opPos < expr.length()) {
            unsigned short begIdx, endIdx, parentheseCount;
            begIdx = opPos - 1;
            parentheseCount = 0;
            while(begIdx > 0 && (parentheseCount > 0 || isdigit(expr[begIdx]) || expr[begIdx] == ')')) {
                if(expr[begIdx] == ')') {
                    ++ parentheseCount;
                } else if(expr[begIdx] == '(') {
                    -- parentheseCount;
                }
                -- begIdx;
            }

            if(begIdx == 0) {
                expr = '(' + expr;
            } else {
                expr.insert(begIdx + 1, "(");
            }

            endIdx = opPos + 2;
            parentheseCount = 0;
            while(endIdx < expr.length() && (parentheseCount > 0 || isdigit(expr[endIdx]) || expr[endIdx] == '(')) {
                if(expr[endIdx] == '(') {
                    ++ parentheseCount;
                } else if(expr[endIdx] == ')') {
                    -- parentheseCount;
                }
                ++ endIdx;
            }

            expr.insert(endIdx, ")");

            opPos = helper::findChars(expr, highPrecedenceOps, opPos + 1);
        }
    }

    /**
     * Check if expression is valid
     */
    bool Calculator::isValidExpr(const std::string& expr) {
        unsigned short idx;
        unsigned short parentheseCount = 0;
        std::map<Symbol, bool> nextSym = {
            {digit, true},
            {plus, false},
            {minus, true},
            {multiple, false},
            {divide, false},
            {open, true},
            {close, false}
        };
        for(idx = 0; idx < expr.size(); ++ idx) {
            const char& sym = expr[idx];
            if(sym == '(') {
                if( ! nextSym[open]) return false;
                ++ parentheseCount;
                nextSym[digit] = nextSym[minus] = nextSym[open] = true;
                nextSym[plus] = nextSym[multiple] = nextSym[divide] = nextSym[close] = false;
            } else if(sym == ')') {
                if(parentheseCount == 0 || ! nextSym[close]) {
                    return false;
                } else {
                    -- parentheseCount;
                }
                nextSym[digit] = nextSym[open] = false;
                nextSym[plus] = nextSym[minus] = nextSym[multiple] = nextSym[divide] = nextSym[close] = true;
            } else if(isdigit(sym)) {
                if( ! nextSym[digit]) return false;
                nextSym[digit] = nextSym[plus] = nextSym[minus] = nextSym[multiple] = nextSym[divide] = nextSym[close] = true;
                nextSym[open] = false;
            } else if(helper::isOperator(sym)) {
                if( ! nextSym[op.at(sym)]) return false;
                nextSym[digit] = nextSym[open] = true;
                nextSym[plus] = nextSym[minus] = nextSym[multiple] = nextSym[divide] = nextSym[close] = false;
            } else if( ! isspace(sym)) {
                return false;
            }
        }
        if(parentheseCount > 0) return false;
        return true;
    }

}
