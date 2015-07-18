#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <array>

namespace calculator {
    struct BigInt {
        const static int precision = 100;
        BigInt();
        explicit BigInt(std::string& str);
        std::string toStr();

        BigInt& operator=(std::string&);
        std::string& operator+(BigInt&);
        std::string& operator-(BigInt&);
        std::string& operator*(BigInt&);
        std::string& operator/(BigInt&);
    private:
        unsigned digit;
        std::array<int, precision> value;
        void toValue(std::string&);
    };
}

#endif /* BIGINT_H */
