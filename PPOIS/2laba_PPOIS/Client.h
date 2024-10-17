#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include <string>
#include "Order.h"
#include "Human.h"
#include "RegistrationMenu.h"
#include "Manager.h"
using namespace std;
class Client:public Human {
private:
	string email;
	vector<Order>basket;
	int cash;
public:
	Client();
	string getEmail();
	int getCash();
	void addBasket();
	void getBasketList();
	void deleteFromBasket();

	void doMainOrder();
};



#endif