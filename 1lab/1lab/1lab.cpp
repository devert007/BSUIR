
#include <iostream>
#include <string>
#include <vector>

class LongInt {
private:
    std::string longNumber;
public:
    LongInt(std::string) {
    }
};




int main()
{
    LongInt a("100000000");
    std::cout << "Hello World!\n";
}
