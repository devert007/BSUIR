#pragma once
#include <string>
#include <vector>


class Profession {
private:
    std::string profession_name;
    std::string profession_info;

public:
    std::string getProfessionName() const {
        return profession_name;
    }
    void setProfessionName(const std::string& name) {
        profession_name = name;
    }
    std::string getProfessionInfo() const {
        return profession_info;
    }
    void setProfessionInfo(const std::string& info) {
        profession_info = info;
    }
};