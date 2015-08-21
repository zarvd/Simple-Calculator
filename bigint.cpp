#include <iostream>
#include <array>
#include "bigint.hpp"
#include "helper.hpp"


namespace calculator {

    /**
     * Defualt constructor, set number to 0
     */
    BigInt::BigInt() {
        digit = 1;
        negative = false;
        std::fill(value.begin(), value.end(), 0);
    }

    BigInt::BigInt(const int& x) {
        std::fill(value.begin(), value.end(), 0);
        digit = 1;
        negative = x < 0;
        int tmp = x;
        while(tmp > 0) {
            value[digit - 1] = tmp % 10;
            tmp /= 10;
            if(tmp > 0)
                ++ digit;
        }
    }

    /**
     * Constructor which getting a string of digits
     */
    BigInt::BigInt(const std::string& str) {
        std::fill(value.begin(), value.end(), 0);
        toValue(str);
    }

    BigInt::BigInt(const BigInt& that, const unsigned& begin, const unsigned& end) {
        std::fill(value.begin(), value.end(), 0);
        negative = false;
        digit = end - begin;
        unsigned iIdx, jIdx;
        for(iIdx = 0, jIdx = begin; iIdx < digit; ++ iIdx, ++ jIdx) {
            value[iIdx] = that.value[jIdx];
        }
    }

    BigInt& BigInt::operator=(const BigInt& that) {
        negative = that.negative;
        digit = that.digit;
        unsigned idx;
        for(idx = 0; idx < digit; ++ idx) {
            value[idx] = that.value[idx];
        }
        std::fill(value.begin() + idx, value.end(), 0);
        return *this;
    }

    BigInt& BigInt::operator=(const std::string& str) {
        std::fill(value.begin(), value.end(), 0);
        toValue(str);
        return *this;
    }

    BigInt BigInt::operator+(const BigInt& that) const {
        if(negative && ! that.negative) {
            BigInt tmp = *this;
            tmp.negative = false;
            return (that - tmp);
        } else if( ! negative && that.negative) {
            BigInt tmp = that;
            tmp.negative = false;
            return (*this - tmp);
        } else {
            BigInt sum;
            unsigned idx, carry;
            const unsigned maxDigit = helper::max(digit, that.digit);
            carry = 0;
            idx = 0;
            sum.negative = negative;
            while(idx < maxDigit || carry == 1) {
                unsigned tmp;
                tmp = value[idx] + that.value[idx] + carry;
                sum.value[idx] = tmp % 10;
                carry = tmp/10;
                ++ idx;
                sum.digit = idx;
            }
            return sum;
        }
    }

    BigInt BigInt::operator-(const BigInt& that) const {
        if(that.negative) {
            BigInt tmp = that;
            tmp.negative = false;
            return (*this + that);
        } else if(negative) {
            BigInt tmp = *this;
            tmp.negative = false;
            return (that - tmp);
        } else if(*this < that) {
            // TODO optimize
            BigInt tmp = that - *this;
            tmp.negative = true;
            return tmp;
        } else {
            // this > that
            BigInt difference;
            unsigned idx, borrow;
            idx = 0;
            borrow = 0;
            while(idx < digit) {
                if(value[idx]  < that.value[idx] + borrow) {
                    difference.value[idx] = 10 + value[idx] - that.value[idx] - borrow;
                    borrow = 1;
                } else {
                    difference.value[idx] = value[idx] - that.value[idx] - borrow;
                    borrow = 0;
                }
                ++ idx;
            }
            difference.digit = difference.value[digit - 1] == 0 ?
                digit - 1 : digit;
            return difference;
        }
    }

    BigInt BigInt::operator*(const BigInt& that) const {
        BigInt product;
        product.negative = negative != that.negative;  // xor
        product.digit = digit + that.digit;
        unsigned iIdx, jIdx, carry;
        carry = 0;
        for(iIdx = 0; iIdx < digit; ++ iIdx) {
            for(jIdx = 0; jIdx < that.digit; ++ jIdx) {
                unsigned tmp = value[iIdx] * that.value[jIdx] +
                    product.value[iIdx + jIdx] + carry;
                product.value[iIdx + jIdx] = tmp % 10;
                carry = tmp / 10;
            }
        }
        if(carry > 0) {
            product.value[product.digit - 1] = carry;
        } else {
            while(product.value[product.digit - 1] == 0 && product.digit > 1) {
                -- product.digit;
            }
        }
        return product;
    }

    BigInt BigInt::operator/(const BigInt& that) const {
        if(that == BigInt(0)) {
            return BigInt(0);
        } else if(*this < that) {
            return BigInt();
        }
        BigInt quotient, carry;
        short idx;
        for(idx = digit - that.digit; idx >= 0; -- idx) {
            BigInt dividend(*this, idx, idx + that.digit);
            dividend = dividend + (carry * BigInt(10));
            short divisor = 9;
            while(BigInt(divisor) * that > dividend && divisor > 0) {
                -- divisor;
            }
            quotient.value[idx] = divisor;
            carry = dividend - BigInt(divisor) * that;
        }
        if(quotient.value[digit - that.digit] == 0) {
            quotient.digit = digit - that.digit;
        } else {
            quotient.digit = digit - that.digit + 1;
        }
        return quotient;
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
        return that > *this;
    }

    bool BigInt::operator>=(const BigInt& that) const {
        return ! (that > *this);
    }

    bool BigInt::operator<=(const BigInt& that) const {
        return ! (*this > that);
    }

    bool BigInt::operator!=(const BigInt& that) const {
        return (*this > that) || (that > *this);
    }

    bool BigInt::operator==(const BigInt& that) const {
        return ! (*this != that);
    }

    std::ostream& operator<<(std::ostream& stream, const BigInt& that) {
        stream << that.toStr();
        return stream;
    }

    /**
     * Convert digit to string
     */
    std::string BigInt::toStr() const {
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
        unsigned idx;
        std::string tmp;
        if(str[0] == '-') {
            negative = true;
            idx = digit = str.size() - 1;
            tmp = str.substr(1);
        } else {
            negative = false;
            idx = digit = str.size();
            tmp = str;
        }
        for(const char& c : tmp) {
            value[--idx] = c - '0';
        }
    }
}
