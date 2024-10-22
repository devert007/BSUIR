#pragma once
#include "Employee.h"
#include "Contact.h"
class Operator :public Employee {
private:
	Contact phone;
	Contact email;
public:
	Operator();
	void changeOperatorNumber(string new_phoneNumber);
	void changeOperatorEmail(string new_emailNumber);

	string getOperatorPhone();
	string getOperatorEmail();
};
