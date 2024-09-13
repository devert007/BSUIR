#include <iostream>
#include <string>
#include <algorithm>

const int MAX_INT = 2147483647;
const int MIN_INT = -2147483647;

class LongInt {
private:
    std::string longNumber;

public:
    LongInt(const std::string& str) : longNumber(str) {}

    int size() { return longNumber.size(); }

    std::string getLong() { return longNumber; }

    operator int() const {
        if (longNumber.size() >= 19) {
            std::cout << "The number exceeds the size of the integer data type\n";
            return 0;
        }
        const int numberInInteger = std::stoll(longNumber); // convert string to long long number

        if (numberInInteger <= MIN_INT || numberInInteger >= MAX_INT || longNumber.size() >= 19) {
            std::cout << "The number exceeds the size of the integer data type\n";
            return 0;
        }
        else {
            return numberInInteger;
        }
    }
    LongInt& operator+=(LongInt& other) {
        std::string sumResult;
        int v_ume = 0;
        int maxLength = std::max(int(longNumber.size()), other.size());

        for (int i = 0; i < maxLength; ++i) {
            int digitLeft = (i < longNumber.size()) ? (longNumber[longNumber.size() - 1 - i] - '0') : 0;//get a digits from last os strings to sum
            int digitRight = (i < other.size()) ? (other.getLong()[other.size() - 1 - i] - '0') : 0;
            int sum = digitLeft + digitRight + v_ume;
            v_ume = sum / 10; //save 10 in mind to sum this in another step in cycle
            sumResult += std::to_string(sum % 10);
        }
        if (v_ume > 0) {
            sumResult += std::to_string(v_ume);
        }
        std::reverse(sumResult.begin(), sumResult.end());

        longNumber = sumResult;
        return *this;
    }
    LongInt operator+( LongInt& other) {
        LongInt result = *this;
        result += other;
        return result;
    }
    LongInt operator-=(LongInt& other) {
        std::string diffResult;
        int v_ume = 0;
        int maxLength = std::max(int(longNumber.size()), other.size());

        for (int i = 0; i < maxLength; ++i) {
            int digitLeft = (i < longNumber.size()) ? (longNumber[longNumber.size() - 1 - i] - '0') : 0;//get a digits from last os strings to sum
            int digitRight = (i < other.size()) ? (other.getLong()[other.size() - 1 - i] - '0') : 0;
            int diff = digitLeft - digitRight - v_ume;
            v_ume = (diff<0) ? 1 : 0; //if digit of left is more than digit of right
            diffResult += std::to_string((diff+10) % 10);
        }
        std::reverse(diffResult.begin(), diffResult.end());
        while (diffResult.size() > 1 && diffResult.back() == '0') {
            diffResult.pop_back();
        }
        longNumber = diffResult;
        return *this;
    }
    LongInt operator-(LongInt& other) {
        LongInt result = *this;
        result -= other;
        return result;
    }
};










int main() {
    setlocale(LC_ALL, "russian");
    std::cout << "Enter a number: ";
    std::string input_string_num = "";
    std::getline(std::cin, input_string_num);
    LongInt a(input_string_num);
    LongInt b("123456789");
    LongInt c = a + b;
    LongInt d = b - a;
    //a += b;
    std::cout << "a += b <=> " << a.getLong() << '\n';
    std::cout << "a + b <=> " << c.getLong() << '\n';
    std::cout << "a -= b <=> " << (b-=a).getLong() << '\n';
    std::cout << "a - b <=> " << (d).getLong() << '\n';
    int integerNumFromLong = a;
    std::cout << "Integer value of a: " << integerNumFromLong << '\n';

    return 0;
}