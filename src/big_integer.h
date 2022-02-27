#ifndef BIG_INT_H
#define BIG_INT_H

#include <string>
#include <vector>
#include <iostream>

namespace BigIntNS {

class BigInt
{
    friend std::ostream &operator<<(std::ostream &os, const BigInt &obj);
    friend std::istream &operator>>(std::istream &is, BigInt &obj);
    friend bool operator==(const BigInt &lhs, const BigInt &rhs);
    friend bool operator!=(const BigInt &lhs, const BigInt &rhs);
    friend bool operator<(const BigInt &lhs, const BigInt &rhs);
    friend bool operator>(const BigInt &lhs, const BigInt &rhs);
    friend bool operator<=(const BigInt &lhs, const BigInt &rhs);
    friend bool operator>=(const BigInt &lhs, const BigInt &rhs);
    friend BigInt operator+(const BigInt &obj);
    friend BigInt operator-(const BigInt &obj);
    friend BigInt operator+(BigInt lhs, const BigInt &rhs);
    friend BigInt operator-(BigInt lhs, const BigInt &rhs);
    friend BigInt operator*(BigInt lhs, const BigInt &rhs);
    friend BigInt operator/(BigInt lhs, const BigInt &rhs);
    friend BigInt operator%(BigInt lhs, const BigInt &rhs);

public:
    BigInt();
    BigInt(const BigInt &obj);
    BigInt(const std::string &num);
    BigInt(long long num);

    BigInt &operator=(const BigInt &num);

    BigInt &operator++();
    BigInt operator++(int);
    BigInt &operator--();
    BigInt operator--(int);

    BigInt &operator+=(const BigInt &rhs);
    BigInt &operator-=(const BigInt &rhs);
    BigInt &operator*=(const BigInt &rhs);
    BigInt &operator/=(const BigInt &rhs);
    BigInt &operator%=(const BigInt &rhs);

private:
    std::vector<int> value;
    bool negative;

    static int compareValues(const BigInt &lhs, const BigInt &rhs);
    static std::vector<int> addition(const std::vector<int> &lhs, const std::vector<int> &rhs);
    static std::vector<int>
    subtraction(const std::vector<int> &higher, const std::vector<int> &lower);
};

std::ostream &operator<<(std::ostream &os, const BigInt &obj);
std::istream &operator>>(std::istream &is, BigInt &obj);

bool operator==(const BigInt &lhs, const BigInt &rhs);
bool operator!=(const BigInt &lhs, const BigInt &rhs);
bool operator<(const BigInt &lhs, const BigInt &rhs);
bool operator>(const BigInt &lhs, const BigInt &rhs);
bool operator<=(const BigInt &lhs, const BigInt &rhs);
bool operator>=(const BigInt &lhs, const BigInt &rhs);

BigInt operator+(const BigInt &obj);
BigInt operator-(const BigInt &obj);
BigInt operator+(BigInt lhs, const BigInt &rhs);
BigInt operator-(BigInt lhs, const BigInt &rhs);
BigInt operator*(BigInt lhs, const BigInt &rhs);
BigInt operator/(BigInt lhs, const BigInt &rhs);
BigInt operator%(BigInt lhs, const BigInt &rhs);
} // namespace BigIntNS

#endif