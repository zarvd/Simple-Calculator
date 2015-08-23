#include <iostream>
#include <string>
#include <cassert>
#include "calculator.hpp"
#include "helper.hpp"

using namespace calculator;


void testConstructor() {
    BigInt A(10), B(1234), C(B, 2, 4), D;
    D = BigInt() * A;
    std::cout << "A = " << A << std::endl
              << "B = " << B << std::endl
              << "C = " << C << std::endl
              << "D = " << D << std::endl;
}

void testAdd() {
    std::cout << "==================="
              << "TEST Addition:"
              << std::endl;
    BigInt A, B;
    for(int i = -100; i < 100; ++ i) {
        A = std::to_string(i);
        for(int j = -300; j < 300; ++ j) {
            B = std::to_string(j);
            assert(A + B == B + A);
            assert((A + B).toStr() == std::to_string(i + j));
        }
    }
}

void testSubtraction() {
    std::cout << "==================="
              << "TEST Subtraction:"
              << std::endl;
    BigInt A, B;
    for(int i = -100; i < 100; ++ i) {
        A = std::to_string(i);
        for(int j = -300; j < 300; ++ j) {
            B = std::to_string(j);
            BigInt sum = A + B;
            if(sum - A != B || sum - B != A) {
                std::cout << "sum: " << sum << std::endl
                          << "A: " << A << std::endl
                          << "B: " << B << std::endl
                          << "sum - A: " << sum - A << std::endl
                          << "sum - B: " << sum - B << std::endl;
            }
            assert(sum - A == B);
            assert(sum - B == A);
        }
    }
}

void testMultiplication() {
    std::cout << "==================="
              << "TEST Multiplication:"
              << std::endl;
    BigInt A, B;
    for(int i = -100; i < 100; ++ i) {
        A = std::to_string(i);
        for(int j = -300; j < 300; ++ j) {
            B = std::to_string(j);
            if((A*B).toStr() != std::to_string(i * j)) {
                std::cout << A << std::endl;
                std::cout << B << std::endl;
                std::cout << A*B << std::endl;
                std::cout << i*j << std::endl;
            }
            assert((A*B).toStr() == std::to_string(i * j));
        }
    }

}

void testDivision() {
    std::cout << "==================="
              << "TEST Division:"
              << std::endl;
    BigInt A, B;
    for(int i = -100; i <= 100; ++ i) {
        if(i == 0) continue;
        A = std::to_string(i);
        for(int j = -300; j <= 300; ++ j) {
            if(j == 0) continue;
            B = std::to_string(j);
            BigInt product = A*B;
            if(product/A != B || product/B != A) {
                std::cout << "A: " << A << std::endl
                          << "B: " << B << std::endl
                          << "Product: " << product << std::endl
                          << "Product/A: " << product/A << std::endl
                          << "Product/B: " << product/B << std::endl;
            }
            assert(product/A == B);
            assert(product/B == A);
        }
    }
}

void testCompare() {
    std::cout << "==================="
              << "TEST Compare:"
              << std::endl;
    BigInt A("-1"), B("-1"), C("1");
    assert(A == B);
    std::cout << A << " == " << B << std::endl;
    assert(A >= B);
    std::cout << A << " >= " << B << std::endl;
    assert(A < C);
    std::cout << A << " < " << C << std::endl;
    assert(A <= C);
    std::cout << A << " <= " << C << std::endl;
    assert(C >= A);
    std::cout << C << " >= " << A << std::endl;
    assert(C > A);
    std::cout << C << " > " << A << std::endl;
    assert(A != C);
    std::cout << A << " != " << C << std::endl;
}

void testValidExpr() {
    std::cout << "==================="
              << "TEST Valid Expression:"
              << std::endl;
    assert(Calculator::isValidExpr("(1 + 2 * 4)"));
    assert( ! Calculator::isValidExpr("(1 + 2 * 4"));
    assert( ! Calculator::isValidExpr("(1 + 2 * 4)()"));
    assert(Calculator::isValidExpr("-100"));
    assert(Calculator::isValidExpr("-100-(-100)"));
    assert(Calculator::isValidExpr("-100-(-100 - 100)"));
    assert( ! Calculator::isValidExpr("-100--100"));
}

void testOpPrecedence() {
    std::cout << "==================="
              << "TEST Operator Precedence:"
              << std::endl;
    std::string
        t1 = "123*456",
        t2 = "123*456/789",
        t3 = "(1+2)*3",
        t4 = "1+2*3",
        t5 = "1*(2+3)",
        t6 = "1+2*3-4",
        t7 = "1",
        t8 = "-100",
        t9 = "-100-(-100)";
    Calculator calc;
    calc.setPrecedence(t1);
    assert(t1 == "(123*456)");
    calc.setPrecedence(t2);
    assert(t2 == "((123*456)/789)");
    calc.setPrecedence(t3);
    assert(t3 == "(((1+2))*3)");
    calc.setPrecedence(t4);
    assert(t4 == "(1+(2*3))");
    calc.setPrecedence(t5);
    assert(t5 == "(1*((2+3)))");
    calc.setPrecedence(t6);
    assert(t6 == "((1+(2*3))-4)");
    calc.setPrecedence(t7);
    assert(t7 == "1");
    calc.setPrecedence(t8);
    assert(t8 == "-100");
    calc.setPrecedence(t9);
    assert(t9 == "(-100-(-100))");
    t9 = "(-20)/(-5)";
    calc.setPrecedence(t9);
    assert(t9 == "((-20)/(-5))");
}

void testFindChildExpr() {
    std::cout << "==================="
              << "TEST Finding Child Expression:"
              << std::endl;
    std::string
        c = "1+((2*3)+4/5)";
    Calculator calc;
    // calc.setPrecedence(c);
    std::cout << c << std::endl;
    // unsigned idx = calc.findChildExpr(c, 0);
    // std::cout << idx << " : " << c[idx] << std::endl;
    // std::cout << c.substr(1, idx - 1) << "   &&&   "
    // << c.substr(idx + 1) << std::endl;
}

void testRemoveBracket() {
    std::cout << "==================="
              << "TEST Finding Child Expression:"
              << std::endl;

    Calculator calc;

    std::string expr = "(1+((2*3)+4/5))";
    std::cout << "Before: " << expr << std::endl
              << "After: " << calc.removeBracket(expr) << std::endl;

    expr = "1+((2*3)+4/5)";
    std::cout << "Before: " << expr << std::endl
              << "After: " << calc.removeBracket(expr) << std::endl;

    expr = "(1+2)*(3+4)";
    std::cout << "Before: " << expr << std::endl
              << "After: " << calc.removeBracket(expr) << std::endl;

    expr = "(((1+2)*(3+4)))";
    std::cout << "Before: " << expr << std::endl
              << "After: " << calc.removeBracket(expr) << std::endl;
}

void testGetExprTree() {
    std::cout << "===================" << std::endl
              << "TEST Getting Expression tree:"
              << std::endl;

    Calculator calc;

    std::string expr = "(-20)/(-5)";
    std::shared_ptr<ExprNode> head = calc.getExprTree(expr);

    std::cout << head->symValue << std::endl;
    std::cout << head->lChild->numValue << std::endl;
    std::cout << head->rChild->numValue << std::endl;
}

void testCalculate() {
    std::cout << "===================" << std::endl
              << "TEST Calculating Expression:"
              << std::endl;

    Calculator calc;

    std::string expr = "1+(2*3)";
    std::shared_ptr<ExprNode> head = calc.getExprTree(expr);

    std::cout << calc.calculate(head) << std::endl;
}

int main(void) {
    // testCompare();
    testAdd();
    testSubtraction();
    testMultiplication();
    testDivision();
    // testConstructor();
    // testValidExpr();
    // testOpPrecedence();
    // testFindChildExpr();
    // testRemoveBracket();
    // testGetExprTree();
    // testCalculate();
    return 0;
}
