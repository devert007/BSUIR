#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include <string>
#include "Order.h"

#include "Basket.h"
using namespace std;
class Client {
private:
	string name;
	string email;
	Basket basket;
public:
	string getName() {
		return this->name;
	}
	string getEmail() {
		return this->email;
	}
	
	void doOrder() {

	}
};



#endif