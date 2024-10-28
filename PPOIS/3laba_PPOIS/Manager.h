#pragma once
#include "Employee.h"
#include "Contact.h"

class Manager :public Employee {
private:
	Contact phone;
	Contact email;
public:
	Manager(string phoneNumber, string email);
	void changeManagerNumber(string new_phoneNumber);
	void changeManagerEmail(string new_emailNumber);

	string getManagerPhone();
	string getManagerEmail();
};