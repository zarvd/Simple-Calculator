#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <array>

namespace calculator {
    const unsigned short IntPrecision = 100;

    class BigInt final {
        unsigned short digit;
        bool negative;
        std::array<unsigned short, IntPrecision> value;
        void toValue(const std::string&);

    public:
        BigInt();
        explicit BigInt(const std::string&);
        explicit BigInt(const int&);
        BigInt(const BigInt&, const unsigned&, const unsigned&);
        ~BigInt() = default;

        std::string toString() const;

        BigInt& operator=(const std::string&);
        BigInt& operator=(const BigInt&);
        BigInt& operator++();
        BigInt operator+(const BigInt&) const;
        BigInt operator-(const BigInt&) const;
        BigInt operator*(const BigInt&) const;
        BigInt operator/(const BigInt&) const;
        bool operator<(const BigInt&) const;
        bool operator>(const BigInt&) const;
        bool operator<=(const BigInt&) const;
        bool operator>=(const BigInt&) const;
        bool operator!=(const BigInt&) const;
        bool operator==(const BigInt&) const;
    friend std::ostream& operator<<(std::ostream& stream, const BigInt& that);
    };
}

#endif /* BIGINT_H */
