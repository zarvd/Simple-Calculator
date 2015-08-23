#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <array>

namespace calculator {
    struct BigInt {
        const static unsigned short precision = 100;
        BigInt();
        explicit BigInt(const std::string&);
        explicit BigInt(const int&);
        BigInt(const BigInt&, const unsigned&, const unsigned&);
        std::string toStr() const;

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
    private:
        unsigned short digit;
        bool negative;
        std::array<unsigned short, precision> value;
        void toValue(const std::string&);
    };
}

#endif /* BIGINT_H */
