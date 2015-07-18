#include "bigint.hpp"

namespace calculator {

    BigInt::BigInt() {
        digit = 1;
        value[0] = 0;
    }

    BigInt::BigInt(std::string& str) {
        digit = 1;
        toValue(str);
    }

    BigInt& BigInt::operator=(std::string& str) {
        toValue(str);
        return *this;
    }

    std::string BigInt::toStr() {
        return "Good";
    }

    void BigInt::toValue(std::string& str) {
        unsigned idx = digit = str.size();
        for(const char& c : str) {
            value[--idx] = c - '0';
        }
    }
}
