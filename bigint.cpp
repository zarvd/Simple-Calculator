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
        negative = false;
    }

    /**
     * Constructor which getting a string of digits
     */
    BigInt::BigInt(const std::string& str) : value {} {
        digit = 1;
        if(str[0] == '-') {
            negative = true;
            toValue(str.substr(1));
        } else {
            negative = false;
            toValue(str);
        }
    }

    BigInt& BigInt::operator=(const std::string& str) {
        toValue(str);
        return *this;
    }

    BigInt BigInt::operator+(const BigInt& that) const {
        if(negative && ! that.negative) {
            return (that - *this);
        } else if( ! negative && that.negative) {
            return (*this - that);
        } else {
            BigInt sum;
            unsigned idx, carry;
            carry = 0;
            idx = 0;
            sum.negative = negative;
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
    }

    BigInt BigInt::operator-(const BigInt& that) const {
        BigInt difference;
        unsigned idx, borrow;
        idx = 0;
        borrow = 0;
        while(idx < helper::max(digit, that.digit)) {
            ++ idx;
        }
        return difference;
    }

    bool BigInt::operator==(const BigInt& that) const {
        if((negative && that.negative) || ( ! negative && ! that.negative)) {
            if(digit == that.digit) {
                int idx = digit - 1;
                while(idx >= 0) {
                    if(value[idx] != that.value[idx]) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }

    bool BigInt::operator>(const BigInt& that) const {
        if(negative && that.negative) {
            if(digit == that.digit) {
                int idx = digit - 1;
                while(idx >= 0) {
                    if(value[idx] > that.value[idx]) {
                        return false;
                    } else if(value[idx] < that.value[idx]) {
                        return true;
                    }
                    --idx;
                }
            } else if(digit < that.digit) {
                return true;
            }
        } else if( ! negative && ! that.negative) {
            if(digit == that.digit) {
                int idx = digit - 1;
                while(idx >= 0) {
                    if(value[idx] < that.value[idx]) {
                        return false;
                    } else if(value[idx] > that.value[idx]) {
                        return true;
                    }
                    --idx;
                }
            } else if(digit > that.digit) {
                return true;
            }
        } else if( ! negative && that.negative) {
            return true;
        }
        return false;
    }

    bool BigInt::operator<(const BigInt& that) const {
        if(negative && that.negative) {
            if(digit == that.digit) {
                int idx = digit - 1;
                while(idx >= 0) {
                    if(value[idx] < that.value[idx]) {
                        return false;
                    } else if(value[idx] > that.value[idx]) {
                        return true;
                    }
                    --idx;
                }
            } else if(digit > that.digit) {
                return true;
            }
        } else if( ! negative && ! that.negative) {
            if(digit == that.digit) {
                int idx = digit - 1;
                while(idx >= 0) {
                    if(value[idx] > that.value[idx]) {
                        return false;
                    } else if(value[idx] < that.value[idx]) {
                        return true;
                    }
                    --idx;
                }
            } else if(digit < that.digit) {
                return true;
            }
        } else if(negative && ! that.negative) {
            return true;
        }
        return false;
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
        str = negative ? "-" + str : str;
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
