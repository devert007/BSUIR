
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
class LongInt {
private:
    std::string longNumber;
public:
    LongInt(const std::string& str) {

    }

};




int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << "Введите число: ";
    std::string input_string_num = "";
    std::getline(std::cin, input_string_num);
    LongInt a(input_string_num);

}
