#include "exprtree.hpp"
#include <iostream>

namespace calculator {
    ExprNode::ExprNode(const std::string& value) :
        isNumber(true),
        numValue(BigInt(value)),
        symValue() {}

    ExprNode::ExprNode(const char& value) :
        isNumber(false),
        numValue(),
        symValue(OpMap.at(value)) {}

    ExprNode::ExprNode(const Symbol& value) :
        isNumber(false),
        numValue(),
        symValue(value) {}

    std::ostream& operator<<(std::ostream& stream, const ExprNode& that) {
        if(that.isNumber) {
            stream << that.numValue;
        } else {
            char op = ' ';
            switch(that.symValue) {
            case Symbol::Plus:
                op = '+';
                break;
            case Symbol::Minus:
                op = '-';
                break;
            case Symbol::Multiple:
                op = '*';
                break;
            case Symbol::Divide:
                op = '/';
                break;
            default:
                // throw exception
                break;
            }
            stream << that.lChild << op << that.rChild;
        }
        return stream;
    }
}
