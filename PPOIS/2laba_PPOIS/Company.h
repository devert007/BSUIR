#pragma once
#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <vector>
#include <iostream>
#include "Order.h"
using namespace std;
class Company {
protected:
	string name;
	string info;
public:
	void showInfoAboutCompany() {
		cout << this->info;
	}
	string setName(string name) {
		this->name = name;
		return this->name;
	}
	void setInfo(string name) {
		this->info = info;
	}
};



#endif