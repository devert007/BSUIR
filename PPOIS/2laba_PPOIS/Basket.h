#pragma once
#ifndef BASKET_H
#define BASKET_H
#include <vector>
#include "Order.h"
using namespace std;
class Basket {
private:
	vector <Order>basketArray;
public:
	vector<Order> getBasketArray() {
		return this->basketArray;
	}
	void deleteFromBasket(int indexToDel) {
		if (indexToDel >= 0 && indexToDel < this->basketArray.size()) {
			// Erase the element at the specified index
			this->basketArray.erase(this->basketArray.begin() + indexToDel);
		}
	}
	void addToBasket(int indexToAdd) {
		//this->basketArray.push_back(indexToAdd)//in  future this will be index of menu Orders
	}

};
#endif