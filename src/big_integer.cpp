#include "big_integer.h"
#include <cctype>
#include <algorithm>

BigIntNS::BigInt::BigInt() : value({0}), negative(false) {}

BigIntNS::BigInt::BigInt(std::string inputValue)
{
    if (inputValue.empty()) {
        throw std::invalid_argument(
            "The input string must be a negative or a positive number!");
    }

    if (inputValue[0] == '-' && inputValue.size() < 2) {
        throw std::invalid_argument(
            "The input string must be a negative or a positive number!");
    }

    if (inputValue[0] != '-' && !isdigit(inputValue[0])) {
        throw std::invalid_argument(
            "The input string must be a negative or a positive number!");
    }

    for (size_t i = 1; i < inputValue.size(); ++i) {
        if (!isdigit(inputValue[i])) {
            throw std::invalid_argument(
                "The input string must be a negative or a positive number!");
        }
    }

    if (inputValue[0] == '-' && inputValue.size() > 2) {
        inputValue.erase(
            1, std::min(inputValue.find_first_not_of('0', 1) - 1, inputValue.size() - 2));
    } else if (inputValue[0] != '-' && inputValue.size() > 1) {
        inputValue.erase(
            0, std::min(inputValue.find_first_not_of('0'), inputValue.size() - 1));
    }

    negative = (inputValue[0] == '-' && inputValue[1] != '0') ? true : false;

    for (auto itr = inputValue.crbegin(); itr != inputValue.crend(); ++itr) {
        if (*itr == '-') {
            continue;
        }
        int digit = *itr - '0';
        value.push_back(digit);
    }
}

BigIntNS::BigInt::BigInt(const BigInt &obj)
{
    value = obj.value;
    negative = obj.negative;
}

BigIntNS::BigInt::BigInt(long long inputValue)
{
    if (inputValue < 0) {
        negative = true;
        inputValue *= -1;
    } else {
        negative = false;
    }

    do {
        value.push_back(inputValue % 10);
        inputValue /= 10;
    } while (inputValue != 0);
}

BigIntNS::BigInt &BigIntNS::BigInt::operator=(const BigInt &obj)
{
    if (this == &obj) {
        return *this;
    }

    value = obj.value;
    negative = obj.negative;

    return *this;
}

bool BigIntNS::operator==(const BigInt &lhs, const BigInt &rhs)
{
    if (lhs.negative == rhs.negative && lhs.value == rhs.value) {
        return true;
    }
    return false;
}

bool BigIntNS::operator!=(const BigInt &lhs, const BigInt &rhs)
{
    return !(lhs == rhs);
}

bool BigIntNS::operator<(const BigInt &lhs, const BigInt &rhs)
{
    if (lhs.negative && !rhs.negative) {
        return true;

    } else if (!lhs.negative && rhs.negative) {
        return false;

    } else if (!lhs.negative && !rhs.negative) {
        int test = BigInt::compareAbsoluteValues(lhs.value, rhs.value);
        if (test == 1 || test == 0) {
            return false;
        }
        return true;

    } else {
        int test = BigInt::compareAbsoluteValues(lhs.value, rhs.value);
        if (test == -1 || test == 0) {
            return false;
        }
        return true;
    }
}

bool BigIntNS::operator>(const BigInt &lhs, const BigInt &rhs)
{
    return !(lhs < rhs);
}

bool BigIntNS::operator<=(const BigInt &lhs, const BigInt &rhs)
{
    return (lhs < rhs || lhs == rhs);
}

bool BigIntNS::operator>=(const BigInt &lhs, const BigInt &rhs)
{
    return (!(lhs < rhs) || lhs == rhs);
}

BigIntNS::BigInt &BigIntNS::BigInt::operator++()
{
    operator+=(1);
    return *this;
}

BigIntNS::BigInt BigIntNS::BigInt::operator++(int)
{
    BigInt old = *this;
    operator+=(1);
    return old;
}

BigIntNS::BigInt &BigIntNS::BigInt::operator--()
{
    operator-=(1);
    return *this;
}

BigIntNS::BigInt BigIntNS::BigInt::operator--(int)
{
    BigInt old = *this;
    operator-=(1);
    return old;
}

BigIntNS::BigInt &BigIntNS::BigInt::operator+=(const BigInt &rhs)
{
    if (!negative && rhs.negative) {
        if (compareAbsoluteValues(value, rhs.value) == -1) {
            value = subtraction(rhs.value, value);
            negative = true;
            return *this;

        } else if (compareAbsoluteValues(value, rhs.value) == 1) {
            value = subtraction(value, rhs.value);
            return *this;

        } else {
            value = {0};
            negative = false;
            return *this;
        }
    } else if (negative && !rhs.negative) {
        if (compareAbsoluteValues(value, rhs.value) == -1) {
            value = subtraction(rhs.value, value);
            negative = false;

        } else if (compareAbsoluteValues(value, rhs.value) == 1) {
            value = subtraction(value, rhs.value);

        } else {
            value = {0};
            negative = false;
        }
    } else if (negative && rhs.negative) {
        value = addition(value, rhs.value);

    } else {
        value = addition(value, rhs.value);
    }

    return *this;
}

BigIntNS::BigInt &BigIntNS::BigInt::operator-=(const BigInt &rhs)
{
    if (!negative && rhs.negative) {
        value = addition(value, rhs.value);

    } else if (negative && !rhs.negative) {
        value = addition(value, rhs.value);

    } else if (negative && rhs.negative) {
        if (compareAbsoluteValues(value, rhs.value) == -1) {
            value = subtraction(rhs.value, value);
            negative = false;

        } else if (compareAbsoluteValues(value, rhs.value) == 1) {
            value = subtraction(value, rhs.value);

        } else {
            value = {0};
            negative = false;
        }
    } else {
        if (compareAbsoluteValues(value, rhs.value) == -1) {
            value = subtraction(rhs.value, value);
            negative = true;

        } else if (compareAbsoluteValues(value, rhs.value) == 1) {
            value = subtraction(value, rhs.value);

        } else {
            value = {0};
            negative = false;
        }
    }

    return *this;
}

BigIntNS::BigInt &BigIntNS::BigInt::operator*=(const BigInt &rhs)
{
    if ((value.size() == 1 && value[0] == 0) || (rhs.value.size() == 1 && rhs.value[0] == 0)) {
        value.clear();
        value.push_back(0);
        negative = false;
    } else {
        std::vector<std::vector<int>> values;
        for (size_t i = 0; i < value.size(); ++i) {
            int carryOver = 0;
            std::vector<int> tempValue(i, 0);
            for (size_t j = 0; j < rhs.value.size(); ++j) {
                int temp = value[i] * rhs.value[j] + carryOver;
                carryOver = temp / 10;
                temp -= carryOver * 10;
                tempValue.push_back(temp);
            }
            if (carryOver > 0) {
                tempValue.push_back(carryOver);
            }
            values.push_back(tempValue);
        }

        std::vector<int> sum;
        for (auto v : values) {
            sum = addition(sum, v);
        }
        value = sum;

        if (negative && rhs.negative) {
            negative = false;
        } else if (negative || rhs.negative) {
            negative = true;
        }
    }

    return *this;
}

BigIntNS::BigInt &BigIntNS::BigInt::operator/=(const BigInt &rhs)
{
    if ((rhs.value.size() == 1 && rhs.value[0] == 0)) {
        throw std::invalid_argument("Division by zero.");
    }
    if (compareAbsoluteValues(value, rhs.value) == -1) {
        value.clear();
        value.push_back(0);
        negative = false;
    } else if (compareAbsoluteValues(value, rhs.value) == 0) {
        value.clear();
        value.push_back(1);
        if (negative && rhs.negative) {
            negative = false;
        } else if (negative || rhs.negative) {
            negative = true;
        }
    } else {
        std::vector<int> temp;
        std::vector<int> result;

        auto valueItr = value.crbegin();
        while (valueItr != value.crend()) {
            int counter = 0;
            temp.insert(temp.begin(), *valueItr);
            ++valueItr;
            while (compareAbsoluteValues(temp, rhs.value) >= 0) {
                temp = subtraction(temp, rhs.value);
                ++counter;
            }
            result.insert(result.begin(), counter);

            std::reverse(temp.begin(), temp.end());
            auto tempItr = temp.begin();
            while (tempItr != temp.end() && *tempItr == 0) {
                tempItr = temp.erase(tempItr);
            }
            std::reverse(temp.begin(), temp.end());
        }

        removeLeadingZeros(result);

        value = result;

        if (negative && rhs.negative) {
            negative = false;
        } else if (negative || rhs.negative) {
            negative = true;
        }
    }

    return *this;
}

BigIntNS::BigInt &BigIntNS::BigInt::operator%=(const BigInt &rhs)
{
    if ((rhs.value.size() == 1 && rhs.value[0] == 0)) {
        throw std::invalid_argument("Division by zero.");
    }
    if (compareAbsoluteValues(value, rhs.value) == -1) {
        // Do nothing
    } else if (compareAbsoluteValues(value, rhs.value) == 0) {
        value.clear();
        value.push_back(0);
        negative = false;
    } else {
        std::vector<int> temp;
        std::vector<int> result;

        auto valueItr = value.crbegin();
        while (valueItr != value.crend()) {
            int counter = 0;
            temp.insert(temp.begin(), *valueItr);
            ++valueItr;
            while (compareAbsoluteValues(temp, rhs.value) >= 0) {
                temp = subtraction(temp, rhs.value);
                ++counter;
            }
            result.insert(result.begin(), counter);

            std::reverse(temp.begin(), temp.end());
            auto tempItr = temp.begin();
            while (tempItr != temp.end() && *tempItr == 0) {
                tempItr = temp.erase(tempItr);
            }
            std::reverse(temp.begin(), temp.end());
        }
        if(temp.empty()) {
            negative = false;
            temp.push_back(0);
        }
        value = temp;
    }

    return *this;
}

BigIntNS::BigInt BigIntNS::operator+(const BigInt &obj)
{
    return obj;
}

BigIntNS::BigInt BigIntNS::operator-(const BigInt &obj)
{
    BigInt temp = obj;
    if (temp.negative == false && (temp.value.size() > 1 || temp.value[0] > 0)) {
        temp.negative = true;
    } else {
        temp.negative = false;
    }
    return temp;
}

BigIntNS::BigInt BigIntNS::operator+(BigInt lhs, const BigInt &rhs)
{
    lhs += rhs;
    return lhs;
}

BigIntNS::BigInt BigIntNS::operator-(BigInt lhs, const BigInt &rhs)
{
    lhs -= rhs;
    return lhs;
}

BigIntNS::BigInt BigIntNS::operator*(BigInt lhs, const BigInt &rhs)
{
    lhs *= rhs;
    return lhs;
}

BigIntNS::BigInt BigIntNS::operator/(BigInt lhs, const BigInt &rhs)
{
    lhs /= rhs;
    return lhs;
}

BigIntNS::BigInt BigIntNS::operator%(BigInt lhs, const BigInt &rhs)
{
    lhs %= rhs;
    return lhs;
}

std::ostream &BigIntNS::operator<<(std::ostream &os, const BigInt &obj)
{
    std::string strValue;

    if (obj.negative) {
        strValue.append("-");
    }
    for (auto itr = obj.value.crbegin(); itr != obj.value.crend(); ++itr) {
        strValue.append(std::to_string(*itr));
    }

    os << strValue;
    return os;
}

std::istream &BigIntNS::operator>>(std::istream &is, BigInt &obj)
{
    std::string strValue;
    is >> strValue;
    BigInt temp(strValue);
    obj.negative = temp.negative;
    obj.value = temp.value;
    return is;
}

int BigIntNS::BigInt::compareAbsoluteValues(
    const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    if (lhs.size() > rhs.size()) {
        return 1;
    }

    if (lhs.size() < rhs.size()) {
        return -1;
    }

    auto itr = lhs.crbegin();
    auto itr2 = rhs.crbegin();
    while (itr != lhs.crend()) {
        if (*itr > *itr2) {
            return 1;
        }

        if (*itr < *itr2) {
            return -1;
        }

        ++itr;
        ++itr2;
    }

    return 0;
}

std::vector<int>
BigIntNS::BigInt::addition(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    std::vector<int> tempValue = lhs;
    size_t size;
    if (rhs.size() > tempValue.size()) {
        size = tempValue.size();
        for (size_t i = tempValue.size(); i < rhs.size(); ++i) {
            tempValue.push_back(rhs[i]);
        }
    } else {
        size = rhs.size();
    }

    bool carryOver = false;
    for (size_t i = 0; i < size; ++i) {
        int temp = tempValue[i] + rhs[i];
        if (carryOver) {
            ++temp;
            carryOver = false;
        }
        if (temp > 9) {
            carryOver = true;
            temp = temp - 10;
        }
        tempValue[i] = temp;
    }

    if (carryOver) {
        if (size == tempValue.size()) {
            tempValue.push_back(1);
        } else {
            size_t i = size;
            while (carryOver && i < tempValue.size()) {
                int temp = tempValue[i] + 1;
                if (temp > 9) {
                    carryOver = true;
                    temp = temp - 10;
                } else {
                    carryOver = false;
                }
                tempValue[i] = temp;
                ++i;
            }
            if (carryOver) {
                tempValue.push_back(1);
            }
        }
    }
    return tempValue;
}

std::vector<int>
BigIntNS::BigInt::subtraction(const std::vector<int> &higher, const std::vector<int> &lower)
{
    std::vector<int> tempValue = higher;
    size_t size = lower.size();
    bool carryOver = false;
    for (size_t i = 0; i < size; ++i) {
        int temp = tempValue[i] - lower[i];
        if (carryOver) {
            --temp;
            carryOver = false;
        }
        if (temp < 0) {
            carryOver = true;
            temp = 10 + temp;
        }
        tempValue[i] = temp;
    }

    if (carryOver) {
        size_t i = size;
        while (carryOver && i < tempValue.size()) {
            int temp = tempValue[i] - 1;
            if (temp < 0) {
                carryOver = true;
                temp = 10 + temp;
            } else {
                carryOver = false;
            }
            tempValue[i] = temp;
            ++i;
        }
    }

    removeLeadingZeros(tempValue);
    return tempValue;
}

void BigIntNS::BigInt::removeLeadingZeros(std::vector<int> &v)
{
    size_t i = v.size() - 1;
    while (v.size() > 1 && v[i] == 0) {
        v.pop_back();
        --i;
    }
}