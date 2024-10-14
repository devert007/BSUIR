#pragma once
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Order {
private: 
	string name;
	double price;
public:
string getName() {
	return this->name;
}
double getPrice() {
	return this->price;
}
};
#endif