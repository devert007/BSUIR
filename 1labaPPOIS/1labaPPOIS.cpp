#include "D:/LABY/BSUIR/1labaPPOIS/Longint.h"
#include <iostream>
int main() {

    Longint a("22435670");
    Longint b("-22435670");
    std::cout << (a+=123420342034).getLong() << '\n';

    std::cout <<(a).getLong()<< '\n';
    std::cout << "Hello";
    return 0;
}