
#include <iostream>
#include <string>

const int MAX_INT = 2147483648;
const int MIN_INT = -2147483648;

class LongInt {
private:
    std::string longNumber;
public:
    LongInt(const std::string& str) : longNumber(str) {}
    operator int() const {
        const int numberInInteger = std::stoll(longNumber); //convert string to long long number 
            if (numberInInteger<MIN_INT || numberInInteger>MAX_INT) {
               std:: cout << "Ваше число превышает размер типа данныых integer\n";
            }
            else {
                return numberInInteger;
            }
    }

    //friend LongInt operator+(LongInt& strNum1,LongInt& strNum2);
};
/*LongInt operator+(LongInt& strNum1, LongInt& strNum2)
{   
    return LongInt();
}*/




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

