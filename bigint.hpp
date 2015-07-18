#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <array>

namespace calculator {
    struct BigInt {
        const static int precision = 100;
        BigInt();
        explicit BigInt(const std::string& str);
        std::string toStr();

        BigInt& operator=(const std::string&);
        BigInt& operator=(BigInt&);
        BigInt operator+(BigInt&);
        BigInt operator-(BigInt&);
        BigInt operator*(BigInt&);
        BigInt operator/(BigInt&);
    private:
        unsigned digit;
        std::array<unsigned, precision> value;
        void toValue(const std::string&);
    };
}

#endif /* BIGINT_H */
