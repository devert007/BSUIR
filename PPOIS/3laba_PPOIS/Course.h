#pragma once
#include <string>
#include <vector>
#include "Sale.h"
#include "Teacher.h"
#include "Sale.h"
#include "Profession.h"
using namespace std;
class Course {
private:
	Profession profession;
	Teacher teacher;
	vector<Sale> sales;
	int price;
	void setDiscountPrice() {
		for (int i = 0; i < this->sales.size(); i++) {
			if (this->sales[i].getSaleValue() != 0) {
				this->price -= this->sales[i].getSaleValue();
			}
		}
	}

public:
	Course(string nameCourse,Teacher teacher) {
		this->profession.setProfessionName(nameCourse);
		this->teacher = teacher;
	}
	int getPrice() {
		return this->price;
	}
	void setPrice(int price) {
		this->price = price;
		setDiscountPrice();
	}
	Teacher getTeacher() {
		return this->teacher;
	}
	void addSale(Sale new_sale) {
		this->sales.push_back(new_sale);
	}
	void removeSale(int index) {
		this->sales.erase(this->sales.begin() + index);
	}
	vector<Sale>getSales() {
		return this->sales;
	}
	Profession getProfession() {
		return this->profession;
	}
};