#ifndef EXPRTREE_H
#define EXPRTREE_H

#include <string>
#include <map>
#include <set>
#include <memory>
#include "bigint.hpp"


namespace calculator {
    enum Symbol {
        Digit,
        Plus,
        Minus,
        Multiple,
        Divide,
        OpenBracket,
        CloseBracket
    };

    const std::map<char, Symbol> OpMap = {
        {'+', Symbol::Plus},
        {'-', Symbol::Minus},
        {'*', Symbol::Multiple},
        {'/', Symbol::Divide}
    };

    const std::set<char> OpCharSet = {
        '+',
        '-',
        '*',
        '/'
    };

    const std::set<Symbol> OpSymSet = {
        Symbol::Plus,
        Symbol::Minus,
        Symbol::Multiple,
        Symbol::Divide
    };

    inline bool isOperator(const char& op) {
        return OpCharSet.find(op) != OpCharSet.end();
    }

    struct ExprNode {
        ExprNode() = delete;
        explicit ExprNode(const std::string&);
        explicit ExprNode(const char&);
        explicit ExprNode(const Symbol&);
        const bool isNumber;
        const BigInt numValue;
        const Symbol symValue;
        std::shared_ptr<ExprNode> lChild = nullptr;
        std::shared_ptr<ExprNode> rChild = nullptr;
        friend std::ostream& operator<<(std::ostream& stream, const ExprNode& that);
    };
}

#endif /* EXPRTREE_H */
