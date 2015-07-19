#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <array>

namespace calculator {
    struct BigInt {
        const static int precision = 100;
        BigInt();
        explicit BigInt(const std::string& str);
        std::string toStr() const;

        BigInt& operator=(const std::string&);
        BigInt& operator=(const BigInt&);
        BigInt operator+(const BigInt&) const;
        BigInt operator-(const BigInt&) const;
        BigInt operator*(const BigInt&) const;
        BigInt operator/(const BigInt&) const;
        bool operator<(const BigInt&) const;
        bool operator>(const BigInt&) const;
        bool operator==(const BigInt&) const;
        friend std::ostream& operator<<(std::ostream& stream, const BigInt& that);
    private:
        unsigned digit;
        bool negative;
        std::array<unsigned, precision> value;
        void toValue(const std::string&);
    };
}

#endif /* BIGINT_H */
