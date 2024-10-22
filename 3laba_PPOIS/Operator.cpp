#include "Operator.h"

Operator::Operator() {
	this->phone.setContactName("Phone");
	this->email.setContactName("Email");
}
void Operator::changeOperatorNumber(string new_phoneNumber) {
	this->phone.setContactName(new_phoneNumber);
}
void Operator::changeOperatorEmail(string new_emailNumber) {
	this->email.setContactName(new_emailNumber);
}

string Operator::getOperatorPhone() {
	return this->phone.getContact();
}
string Operator::getOperatorEmail() {
	return this->email.getContact();
}