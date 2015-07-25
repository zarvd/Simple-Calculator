#include <iostream>
#include <string>
#include <cassert>
#include "calculator.hpp"
#include "helper.hpp"

using namespace calculator;


void testConstructor() {
    BigInt A(10), B(1234), C(B, 2, 4), D;
    D = BigInt() * A;
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "C = " << C << std::endl;
    std::cout << "D = " << D << std::endl;
}

void testAdd() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Add:" << std::endl;
    BigInt A("1"), B("9999");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A + B = " << (A + B) << std::endl;
}

void testSubtraction() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Subtraction:" << std::endl;
    BigInt A("2"), B("1");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    A = "1";
    B = "2";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
    A = "100000";
    B = "1";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A - B = " << (A - B) << std::endl;
}

void testMultiplication() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Multiplication:" << std::endl;
    BigInt A("2"), B("1");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
    A = "1000";
    B = "1";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
    A = "9999";
    B = "9";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
    A = "-9999";
    B = "9";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;
}

void testDivision() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Division:" << std::endl;
    BigInt A("10"), B("1");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A / B = " << A / B << std::endl;
    assert((A / B) == BigInt("10"));
    A = "999";
    B = "9";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A / B = " << A / B << std::endl;
    assert(A / B == BigInt("111"));
    A = "1234";
    B = "9";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A / B = " << A / B << std::endl;
    assert(A / B == BigInt("137"));
}

void testCompare() {
    std::cout << "===================" << std::endl;
    std::cout << "TEST Compare:" << std::endl;
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
    std::cout << "===================" << std::endl;
    std::cout << "TEST Valid Expression:" << std::endl;
    assert(Calculator::isValidExpr("(1 + 2 * 4)"));
    assert( ! Calculator::isValidExpr("(1 + 2 * 4"));
    assert( ! Calculator::isValidExpr("(1 + 2 * 4)()"));
}

int main(void) {
    // testCompare();
    // testAdd();
    // testSubtraction();
    // testMultiplication();
    // testDivision();
    // testConstructor();
    testValidExpr();
    return 0;
}
