
#include "D:\LABY\BSUIR\tests1PPOIS\tests1PPOIS\Longint.h"


Longint::Longint(const std::string& str) {
    if (str[0] == '-') {
        longNum = str.substr(1);
        isPos = false;
    }
    else {
        longNum = str;
        isPos = true;
    }
}

std::string Longint::getLong()
{
    return (isPos ? "" : "-") + longNum;
}
int Longint::size() { return longNum.size(); }
Longint Longint::addLong(const Longint& other) {
    if (isPos && other.isPos) {         //оба положительны
        longNum = add_num_to_string(other);
    }
    else if (!isPos && !other.isPos) {  //оба отрицательны
        longNum = add_num_to_string(other);
        isPos = false;
    }
    else if (isPos && !other.isPos) {       //первый положительный/второй отриц
        if (longNum.size() > other.longNum.size() ||
            (longNum.size() == other.longNum.size() && longNum > other.longNum)) {
            longNum = sub_num_from_string(other);
        }
        else {
            std::string tempstring = longNum;
            longNum = other.longNum;
            longNum = sub_num_from_string(tempstring);
            isPos = false;
        }
    }
    else {                              //первый отриц/второй положительный
        if (longNum.size() > other.longNum.size() ||
            (longNum.size() == other.longNum.size() && longNum > other.longNum)) {
            longNum = sub_num_from_string(other);
            isPos = false;
        }
        else {
            std::string tempstring = longNum;
            longNum = other.longNum;
            longNum = sub_num_from_string(tempstring);
            isPos = true;
        }
    }
    return *this;
}
Longint Longint::subLong(const Longint& other) {
    if (isPos && other.isPos) {         //x - y
        if (longNum.size() > other.longNum.size() ||
            (longNum.size() == other.longNum.size() && longNum > other.longNum)) {
            longNum = sub_num_from_string(other);
        }
        else {
            std::string tempString = longNum;
            longNum = other.longNum;
            isPos = false;
            longNum = sub_num_from_string(tempString);
        }
    }
    else if (!isPos && !other.isPos) { //(-x) - (-y) = y - x
        if (longNum.size() > other.longNum.size() ||
            (longNum.size() == other.longNum.size() && longNum > other.longNum)) {
            isPos = false;
            longNum = sub_num_from_string(other.longNum);
        }
        else {
            std::string tempString = longNum;
            longNum = other.longNum;
            isPos = true;
            longNum = sub_num_from_string(tempString);

        }
    }
    else if (isPos && !other.isPos) {   //(x) - (-y) = x + y 
        isPos = true;
        longNum = add_num_to_string(other);
    }
    else if (!isPos && other.isPos) {   //(-x) - y = -(x + y)
        isPos = false;
        longNum = add_num_to_string(other);

    }
    return *this;
}
Longint Longint::multlong(const Longint& other) {
    isPos = ((isPos && other.isPos) || (!isPos && !other.isPos)) ? true : false;
    longNum = multiply_strings(other);
    return *this;
}
Longint Longint::divLong(const Longint& other) {
    longNum = longDivision(other);
    return *this;
}


Longint Longint::addInt(const int& other) {
    return addLong(Longint(std::to_string(other)));
}
Longint Longint::subInt(const int& other) {
    return subLong(Longint(std::to_string(other)));
}
Longint Longint::multInt(const int& other) {
    return multlong(Longint(std::to_string(other)));
}
Longint Longint::divInt(const int& other) {
    return divLong(Longint(std::to_string(other)));
}


Longint Longint::operator++(int) {
    Longint temp(*this);
    Longint one("1");
    addLong(one);
    return *this;
}
Longint Longint::operator++() {
    Longint one("1");
    longNum = addLong(one).getLong();
    return *this;
}
Longint Longint::operator--(int) {
    Longint temp(*this);
    Longint one("1");
    subLong(one);
    return *this;
}
Longint Longint::operator--() {
    Longint one("1");
    longNum = subLong(one).getLong();
    return *this;
}



bool Longint::operator<=(const Longint& other) {
    if (isPos && !other.isPos) {
        return false;
    }
    else if (!isPos && other.isPos) {
        return true;
    }
    else if (!isPos && !other.isPos) {
        return longNum >= other.longNum;
    }
    else {
        return longNum <= other.longNum;
    }
}
bool Longint::operator<(const Longint& other) {
    if (isPos && !other.isPos) {
        return false;
    }
    else if (!isPos && other.isPos) {
        return true;
    }
    else if (!isPos && !other.isPos) {
        return longNum > other.longNum;
    }
    else {
        return longNum < other.longNum;
    }
}
bool Longint::operator>=(const Longint& other) {
    if (isPos && !other.isPos) {
        return true;
    }
    else if (!isPos && other.isPos) {
        return false;
    }
    else if (!isPos && !other.isPos) {
        return longNum <= other.longNum;
    }
    else {
        return longNum >= other.longNum;
    }
}
bool Longint::operator>(const Longint& other) {
    if (isPos && !other.isPos) {
        return true;
    }
    else if (!isPos && other.isPos) {
        return false;
    }
    else if (!isPos && !other.isPos) {
        return longNum < other.longNum;
    }
    else {
        return longNum > other.longNum;
    }
}
bool Longint::operator<=(const int& intOther) {
    Longint other = std::to_string(intOther);
    if (isPos && !other.isPos) {
        return false;
    }
    else if (!isPos && other.isPos) {
        return true;
    }
    else if (!isPos && !other.isPos) {
        return longNum >= other.longNum;
    }
    else {
        return longNum <= other.longNum;
    }
}
bool Longint::operator<(const int& intOther) {
    Longint other = std::to_string(intOther);
    if (isPos && !other.isPos) {
        return false;
    }
    else if (!isPos && other.isPos) {
        return true;
    }
    else if (!isPos && !other.isPos) {
        return longNum > other.longNum;
    }
    else {
        return longNum < other.longNum;
    }
}
bool Longint::operator>=(const int& intOther) {
    Longint other = std::to_string(intOther);
    if (isPos && !other.isPos) {
        return true;
    }
    else if (!isPos && other.isPos) {
        return false;
    }
    else if (!isPos && !other.isPos) {
        return longNum <= other.longNum;
    }
    else {
        return longNum >= other.longNum;
    }
}
bool Longint::operator>(const int& intOther) {
    Longint other = std::to_string(intOther);
    if (isPos && !other.isPos) {
        return true;
    }
    else if (!isPos && other.isPos) {
        return false;
    }
    else if (!isPos && !other.isPos) {
        return longNum < other.longNum;
    }
    else {
        return longNum > other.longNum;
    }
}
*/
