#ifndef EXPRTREE_H
#define EXPRTREE_H

#include <memory>
#include <string>
#include "bigint.hpp"


namespace calculator {
    enum Operator {
        plus,
        minus,
        multiple,
        divide
    };

    struct ExprTree {};

    struct OpNode;

    struct DigitNode final : public ExprTree {
        DigitNode() = delete;
        explicit DigitNode(const std::string&);
        const BigInt value;
        std::unique_ptr<OpNode> lChild;
        std::unique_ptr<OpNode> rChild;
    };

    struct OpNode final : public ExprTree {
        OpNode() = delete;
        explicit OpNode(const Operator&);
        const Operator value;
        std::unique_ptr<DigitNode> lChild;
        std::unique_ptr<DigitNode> rChild;
    };

}

#endif /* EXPRTREE_H */
