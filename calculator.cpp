#include "calculator.hpp"
#include "helper.hpp"
#include <iostream>
#include <vector>


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
    void Calculator::printResult() const {
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
            std::shared_ptr<ExprNode> head = getExprTree(expression);
            result = calculate(head);
        }
    }

    /**
     * Find operators's precedence and insert bracket
     */
    void Calculator::setPrecedence(std::string& expr) const {
        const std::vector<char> highPreOps{'*', '/'};
        const std::vector<char> lowPreOps{'+', '-'};
        insertBracket(expr, highPreOps);
        insertBracket(expr, lowPreOps);
    }

    void Calculator::insertBracket(std::string& expr, const std::vector<char>& ops) const {
        unsigned short opPos;
        opPos = helper::findChars(expr, ops);
        while(opPos < expr.length()) {
            unsigned short begIdx, endIdx, bracketCount;
            begIdx = opPos - 1;
            bracketCount = 0;
            while(begIdx > 0 && (bracketCount > 0 || isdigit(expr[begIdx]) || expr[begIdx] == ')')) {
                if(expr[begIdx] == ')') {
                    ++ bracketCount;
                } else if(expr[begIdx] == '(') {
                    -- bracketCount;
                }
                -- begIdx;
            }

            if(begIdx == 0) {
                expr = '(' + expr;
            } else {
                expr.insert(begIdx + 1, "(");
            }

            endIdx = opPos + 2;
            bracketCount = 0;
            while(endIdx < expr.length() && (bracketCount > 0 || isdigit(expr[endIdx]) || expr[endIdx] == '(')) {
                if(expr[endIdx] == '(') {
                    ++ bracketCount;
                } else if(expr[endIdx] == ')') {
                    -- bracketCount;
                }
                ++ endIdx;
            }
            expr.insert(endIdx, ")");
            opPos = helper::findChars(expr, ops, opPos + 1);
        }
    }

    BigInt Calculator::calculate(std::shared_ptr<ExprNode> head) const {
        if( ! head) {
            throw "Illegal paremeters";
        } else if(head->isNumber) {
            return head->numValue;
        } else {
            BigInt result;

            switch(head->symValue) {
            case Plus:
                result = calculate(head->lChild) + calculate(head->rChild);
                break;

            case Minus:
                result = calculate(head->lChild) - calculate(head->rChild);
                break;

            case Multiple:
                result = calculate(head->lChild) * calculate(head->rChild);
                break;

            case Divide:
                result = calculate(head->lChild) / calculate(head->rChild);
                break;

            default:
                // throw exception
                break;
            }
            return result;
        }
    }

    /**
     * Convert expression string to expression tree
     */
    std::shared_ptr<ExprNode> Calculator::getExprTree(const std::string& oExpr) const {
        std::shared_ptr<ExprNode> head = nullptr;

        unsigned bracketCount = 0;
        bool isNumber = true;

        std::string expr = removeBracket(oExpr);

        for(unsigned idx = 0; idx < expr.length(); ++ idx) {
            const char& curChar = expr[idx];

            if( ! isdigit(expr[idx])) {
                isNumber = false;
            }

            if(curChar == '(') {
                ++ bracketCount;
            } else if(curChar == ')') {
                -- bracketCount;
            }

            if(bracketCount == 0 && isOperator(curChar)) {
                head = std::shared_ptr<ExprNode>(new ExprNode(curChar));
                head->lChild = getExprTree(expr.substr(0, idx));
                head->rChild = getExprTree(expr.substr(idx + 1));
                break;
            }
        }

        if(isNumber) {
            head = std::shared_ptr<ExprNode>(new ExprNode(expr));
        }

        return head;
    }

    /**
     * Remove redundant brackets
     */
    std::string Calculator::removeBracket(const std::string& expr) const {
        unsigned bracketCount = 0;
        std::string childExpr = expr;
        bool isExit = false;
        while( ! isExit) {
            for(unsigned idx = 0; idx < childExpr.length(); ++ idx) {
                const char& curChar = childExpr[idx];
                if(curChar == '(') {
                    ++ bracketCount;
                } else if(curChar == ')') {
                    -- bracketCount;
                    if(bracketCount == 0) {
                        if(idx + 1 < childExpr.length()) {
                            isExit = true;
                            break;
                        } else {
                            childExpr = childExpr.substr(1, childExpr.length() - 2);
                            break;
                        }
                    }
                } else if(bracketCount == 0 && isOperator(curChar)) {
                    isExit = true;
                    break;
                } else if(idx + 1 == childExpr.length()) {
                    isExit = true;
                }
            }
        }
        return childExpr;
    }

    /**
     * Check if expression is valid
     */
    bool Calculator::isValidExpr(const std::string& expr) {
        unsigned short idx;
        unsigned short bracketCount = 0;
        std::map<Symbol, bool> nextSym = {
            {Symbol::Digit, true},
            {Symbol::Plus, false},
            {Symbol::Minus, true},
            {Symbol::Multiple, false},
            {Symbol::Divide, false},
            {Symbol::OpenBracket, true},
            {Symbol::CloseBracket, false}
        };
        for(idx = 0; idx < expr.size(); ++ idx) {
            const char& sym = expr[idx];
            if(sym == '(') {
                if( ! nextSym[Symbol::OpenBracket]) return false;
                ++ bracketCount;
                nextSym[Symbol::Digit] = nextSym[Symbol::Minus] = nextSym[Symbol::OpenBracket] = true;
                nextSym[Symbol::Plus] = nextSym[Symbol::Multiple] = nextSym[Symbol::Divide] = nextSym[Symbol::CloseBracket] = false;
            } else if(sym == ')') {
                if(bracketCount == 0 || ! nextSym[Symbol::CloseBracket]) {
                    return false;
                } else {
                    -- bracketCount;
                }
                nextSym[Symbol::Digit] = nextSym[Symbol::OpenBracket] = false;
                nextSym[Symbol::Plus] = nextSym[Symbol::Minus] = nextSym[Symbol::Multiple] = nextSym[Symbol::Divide] = nextSym[Symbol::CloseBracket] = true;
            } else if(isdigit(sym)) {
                if( ! nextSym[Symbol::Digit]) return false;
                nextSym[Symbol::Digit] = nextSym[Symbol::Plus] = nextSym[Symbol::Minus] = nextSym[Symbol::Multiple] = nextSym[Symbol::Divide] = nextSym[Symbol::CloseBracket] = true;
                nextSym[Symbol::OpenBracket] = false;
            } else if(helper::isOperator(sym)) {
                if( ! nextSym[OpMap.at(sym)]) return false;
                nextSym[Symbol::Digit] = nextSym[Symbol::OpenBracket] = true;
                nextSym[Symbol::Plus] = nextSym[Symbol::Minus] = nextSym[Symbol::Multiple] = nextSym[Symbol::Divide] = nextSym[Symbol::CloseBracket] = false;
            } else if( ! isspace(sym)) {
                return false;
            }
        }
        if(bracketCount > 0) return false;
        return true;
    }

}
