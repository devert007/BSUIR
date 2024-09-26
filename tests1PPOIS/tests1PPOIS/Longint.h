#pragma once
#ifndef LONGINT
#define LONGINT
#include <string>

class Longint {
private:
    std::string longNum;
    bool isPos;
    std::string add_num_to_string(const Longint& other);
    std::string sub_num_from_string(const Longint& other);
    std::string multiply_strings(const Longint& other);
    std::string longDivision(const Longint& other);
public:
    Longint() {};
    Longint(const std::string& str);
    int size();
    std::string getLong();
    Longint addLong(const Longint& other);
    Longint subLong(const Longint& other);
    Longint multlong(const Longint& other);
    Longint divLong(const Longint& other);
    Longint addInt(const int& other);
    Longint subInt(const int& other);
    Longint multInt(const int& other);
    Longint divInt(const int& other);
    Longint operator++(int);
    Longint operator++();
    Longint operator--(int);
    Longint operator--();
    bool operator<=(const Longint& other);
    bool operator<(const Longint& other);
    bool operator>=(const Longint& other);
    bool operator>(const Longint& other);
    bool operator<=(const int& intOther);
    bool operator<(const int& intOther);
    bool operator>=(const int& intOther);
    bool operator>(const int& intOther);
};
#endif // !LONGINT
