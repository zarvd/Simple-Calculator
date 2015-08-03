#include "exprtree.hpp"


namespace calculator {
    DigitNode::DigitNode(const std::string& number) :
        value(number), lChild(nullptr), rChild(nullptr) {}

    OpNode::OpNode(const Operator& op) :
        value(op), lChild(nullptr), rChild(nullptr) {}
}
