#include <iostream>
#include <string>

class Longint {
private:

    std::string longNum;
    bool isPos;
    std::string add_num_to_string(const Longint& other) {
        std::string sumResult;
        int v_ume = 0;
        int maxLength = std::max(int(longNum.size()), int(other.longNum.size()));
        for (int i = 0; i < maxLength; ++i) {
            int digitLeft = (i < longNum.size()) ? (longNum[longNum.size() - 1 - i] - '0') : 0;
            int digitRight = (i < other.longNum.size()) ? (other.longNum[other.longNum.size() - 1 - i] - '0') : 0;
            int sum = digitLeft + digitRight + v_ume;
            v_ume = sum / 10;
            sumResult += std::to_string(sum % 10);
        }
        if (v_ume > 0) {
            sumResult += std::to_string(v_ume);
        }
        std::reverse(sumResult.begin(), sumResult.end());
        return sumResult;
    }
    std::string sub_num_from_string(const Longint& other) {
        std::string diffResult;
        int v_ume = 0;
        int maxLength = std::max(int(longNum.size()), int(other.longNum.size()));
        for (int i = 0; i < maxLength; ++i) {
            int digitLeft = (i < longNum.size()) ? (longNum[longNum.size() - 1 - i] - '0') : 0;
            int digitRight = (i < other.longNum.size()) ? (other.longNum[other.longNum.size() - 1 - i] - '0') : 0;
            int diff = digitLeft - digitRight - v_ume;
            v_ume = (diff < 0) ? 1 : 0;
            diffResult += std::to_string((diff + 10) % 10);
        }
        if (isPos) {
            while (diffResult.size() > 1 && diffResult.back() == '0') {
                diffResult.pop_back();
            }
        }
        std::reverse(diffResult.begin(), diffResult.end());
      
        return diffResult;
    }
    std::string multiply_strings(const Longint& other) {
        Longint result;
        for (int i = 0; i < other.longNum.size(); ++i) {
            int digitRight = other.longNum[other.longNum.size() - 1 - i] - '0';
            std::string tempResult;
            int v_ume = 0;
            for (int j = 0; j < longNum.size(); ++j) {
                int digitLeft = longNum[longNum.size() - 1 - j] - '0';
                int product = digitLeft * digitRight + v_ume;
                v_ume = product / 10;
                tempResult += std::to_string(product % 10);
            }
            if (v_ume > 0) {
                tempResult += std::to_string(v_ume);
            }
            std::reverse(tempResult.begin(), tempResult.end());
            for (int k = 0; k < i; ++k) {
                tempResult += '0';
            }
            result.longNum = result.add_num_to_string(Longint(tempResult));
        }
        return result.longNum;
    }
    std::string longDivision(const Longint& other) {
       std::string result;
        int index = 0;
        if (other.longNum[0] == '0') { 
            std::cout << "can't divide by zero\n"; 
            return "0";
        }
        // extracting the part that is greater than the given divisor
        int dividend = longNum[index] - '0';
        while (dividend < std::stoll(other.longNum)) {
            dividend = dividend * 10 + (longNum[++index] - '0');
        }
        // iterating until all digits participate in the division
        while (longNum.size() > index) {
            result += (dividend / std::stoll (other.longNum)) + '0';
            // adding the next digit to the dividend
            dividend = (dividend % std::stoi( other.longNum)) * 10 + longNum[++index] - '0';
        }
        if (result.length() == 0) {
            return "0";
        }
        return result;
    }
   

public:
    Longint() {}

    Longint(const std::string& str) {
        if (str[0] == '-') {
            longNum = str.substr(1);
            isPos = false;
        }
        else {
            longNum = str;
            isPos = true;
        }
    }

    int size() { return longNum.size(); }

    std::string getLong() { return (isPos ? "" : "-") + longNum; }

    Longint addLong(const Longint& other) {
        if (isPos && other.isPos) {         //оба положительны
            longNum = add_num_to_string(other);
        }
        else if (!isPos && !other.isPos) {  //оба отрицательны
            longNum = add_num_to_string(other);
            isPos = false;
        }
        else if(isPos&&!other.isPos){       //первый положительный/второй отриц
            if (longNum.size() > other.longNum.size()||
            (longNum.size()==other.longNum.size() && longNum>other.longNum)) {
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
    Longint subLong(const Longint& other) {
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
    Longint multlong(const Longint& other) {
        isPos = ((isPos && other.isPos) || (!isPos && !other.isPos)) ? true : false;
        longNum = multiply_strings(other);
        return *this;
    }
    Longint divLong( const Longint& other) {
        longNum = longDivision(other);
        return *this;
    }
    Longint addInt(const int& other) {
        return addLong(Longint(std::to_string(other)));
    }
    Longint subInt(const int& other) {
        return subLong(Longint(std::to_string(other)));
    }
    Longint multInt(const int& other) {
        return multlong(Longint(std::to_string(other)));
    }
    Longint divInt(const int& other) {
        return divLong(Longint(std::to_string(other)));
    }





    Longint operator++(int) {
        Longint temp(*this);
        Longint one("1");
        addLong(one);
        return *this;
    }
    Longint operator++() {
        Longint one("1");
        longNum = addLong(one).getLong();
        return *this;
    }
    Longint operator--(int) {
        Longint temp(*this);
        Longint one("1");
        subLong(one);
        return *this;
    }
    Longint operator--() {
        Longint one("1");
        longNum = subLong(one).getLong();
        return *this;
    }
    bool operator<=(const Longint& other) {
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
    bool operator<(const Longint& other) {
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
    bool operator>=(const Longint& other) {
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
    bool operator>(const Longint& other) {
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
    bool operator<=(const int& intOther) {
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
    bool operator<(const int& intOther) {
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
    bool operator>=(const int& intOther) {
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
    bool operator>(const int& intOther) {
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


};

int main() {
    Longint a("1200000000");
    Longint b("1000000000");
    int c = -2;
    std::cout << a.multInt(c).getLong() << std::endl;
    return 0;
}