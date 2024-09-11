
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
        const int numberInInteger = std::stoll(longNumber); //convert string to long long number 
            if (numberInInteger <= MIN_INT || numberInInteger >= MAX_INT) {
               std:: cout << "Ваше число превышает размер типа данныых integer\n";
            }
            else {
                return numberInInteger;
            }
    }

    friend LongInt operator+(LongInt& strNum1,LongInt& strNum2);
};
LongInt operator+(LongInt& strLeft, LongInt& strRight)
{   
    std::string sumResult (std::max(LongInt(strLeft), LongInt(strRight)), '0');//initialization resultSum like '0000000...0' (max of strings)

    for (int i = 0; i < sumResult.size(); ++i) {
        int digitOfFirst = (i < strLeft.size()) ?
            strLeft.getLong()[strLeft.size() - 1 - i] - '0' : 0;
        std::cout << digitOfFirst;
    }
    return sumResult;
}




int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << "Введите число: ";
    std::string input_string_num = "";
    std::getline(std::cin, input_string_num);
    LongInt a(input_string_num) ;
    int integerNumFromLong = a;
    std::cout << integerNumFromLong;
}

