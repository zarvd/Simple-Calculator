#include <iostream>
#include <array>
#include "bigint.hpp"
#include "helper.hpp"


namespace calculator {

    /**
     * Defualt constructor, set number to 0
     */
    BigInt::BigInt() : value {} {
        digit = 1;
    }

    /**
     * Constructor which getting a string of digits
     */
    BigInt::BigInt(const std::string& str) : value {} {
        digit = 1;
        toValue(str);
    }

    BigInt& BigInt::operator=(const std::string& str) {
        toValue(str);
        return *this;
    }

    BigInt BigInt::operator+(BigInt& that) {
        BigInt sum;
        unsigned idx, carry;
        carry = 0;
        idx = 0;
        while(idx < helper::max(digit, that.digit) || carry == 1) {
            unsigned temp;
            temp = value[idx] + that.value[idx] + carry;
            sum.value[idx] = temp % 10;
            carry = temp/10;
            ++ idx;
            sum.digit = idx;
        }
        return sum;
    }

    /**
     * Convert digit to string
     */
    std::string BigInt::toStr() {
        std::string str;
        unsigned idx;
        for(idx = 0; idx < digit; ++ idx) {
            str = static_cast<char>(value[idx] + '0') + str;
        }
        return str;
    }

    /**
     * Convert string to array and store the array
     */
    void BigInt::toValue(const std::string& str) {
        unsigned idx = digit = str.size();
        for(const char& c : str) {
            value[--idx] = c - '0';
        }
    }
}
