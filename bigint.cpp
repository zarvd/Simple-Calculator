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

    /**
     * Constructor which getting a string of digits
     */
    BigInt::BigInt(const std::string& str) {
        std::fill(value.begin(), value.end(), 0);
        toValue(str);
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
            BigInt temp = *this;
            temp.negative = false;
            return (that - temp);
        } else if( ! negative && that.negative) {
            BigInt temp = that;
            temp.negative = false;
            return (*this - temp);
        } else {
            BigInt sum;
            unsigned idx, carry;
            const unsigned maxDigit = helper::max(digit, that.digit);
            carry = 0;
            idx = 0;
            sum.negative = negative;
            while(idx < maxDigit|| carry == 1) {
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
        if(that.negative) {
            BigInt temp = that;
            temp.negative = false;
            return (*this + that);
        } else if(negative) {
            BigInt temp = *this;
            temp.negative = false;
            return (that - temp);
        } else if(*this < that) {
            // TODO optimize
            BigInt temp = that - *this;
            temp.negative = true;
            return temp;
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
        std::string temp;
        if(str[0] == '-') {
            negative = true;
            idx = digit = str.size() - 1;
            temp = str.substr(1);
        } else {
            negative = false;
            idx = digit = str.size();
            temp = str;
        }
        for(const char& c : temp) {
            value[--idx] = c - '0';
        }
    }
}
