#include "D:/LABY/BSUIR/1labaPPOIS/Longint.h"
#include <iostream>
int main() {

    Longint a("22435670");
    Longint b("-2243");
    std::cout << (a).getLong() << '\n';
    std::cout << (a+=b).getLong() << '\n';

    std::cout <<(a).getLong()<< '\n';
    std::cout << "Hello";
    return 0;
}