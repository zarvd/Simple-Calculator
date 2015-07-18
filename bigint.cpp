#include "bigint.hpp"

namespace calculator {

    /**
     * Defualt constructor, set number to 0
     */
    BigInt::BigInt() {
        digit = 1;
        value[0] = 0;
    }

    /**
     * Constructor which getting a string of digits
     */
    BigInt::BigInt(std::string& str) {
        digit = 1;
        toValue(str);
    }

    BigInt& BigInt::operator=(std::string& str) {
        toValue(str);
        return *this;
    }

    BigInt BigInt::operator+(BigInt& that) {
        BigInt sum;
        unsigned idx, carry;
        carry = 0;
        for(idx = 0; idx < that.digit; ++idx) {
            unsigned temp;
            temp = value[idx] + that.value[idx];
            sum.value[0] = carry + (temp % 10);
            carry = temp/10;
        }
    }

    /**
     * Convert digit to string
     */
    std::string BigInt::toStr() {
        return "";
    }

    /**
     * Convert string to array and store the array
     */
    void BigInt::toValue(std::string& str) {
        unsigned idx = digit = str.size();
        for(const char& c : str) {
            value[--idx] = c - '0';
        }
    }
}
