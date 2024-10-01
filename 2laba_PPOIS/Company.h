#pragma once
#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <vector>

class Supplier {
private:
	std::string contactInfo;
	std::vector<Drug> suppliedDrugs;
};

class Drug {
private:
	int price;
	std::string drugName;
	Supplier supplier;
public:
};

class CartOrder {
private:
	std::vector<Order>cart;
};

class Client {
private:
	std::string name;
	std::string surname;
	std::string email;
	//заказы:
public:
	void make_an_order();
	void add_to_cart();


};



#endif