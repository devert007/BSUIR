#include <D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Client.h>
#include <vector>
#include <string>
#include <iostream>
Client :: Client() {
	RegMenu menu;
	menu.makeRegistration();
	this->email = menu.getEmail();
	setName(menu.getName());
	this->cash = menu.getCash();
}
string Client::getEmail() {
	return this->email;
}
int Client::getCash() {
	return this->cash;
}
void Client::addBasket() {
	Manager manager;
	Order orderOfClient;
	orderOfClient = manager.sendAconfirmationToClient();
	basket.push_back(orderOfClient);
}
void Client::getBasketList() {
	std::cout << "���� �������:\n";
	for (int i = 0; i < this->basket.size(); i++)
	{
		cout << i + 1 << ") " << basket[i].getName() << "\nPrice:" << basket[i].getPrice() << '\n';
	}
}
void Client::deleteFromBasket() {
	cout << "�������� ����� ��������� ������� �� ������ ������� �� �������:\n ";
	this->getBasketList();
	int chooseClient;
	cin >> chooseClient;
	this->basket.erase(basket.begin() + chooseClient - 1);
	cout << "������� �������\n";
}
void Client::doMainOrder() {

	int sumOfAllBusket = 0;
	for (int i = 0; i < basket.size(); i++) {
		sumOfAllBusket += basket[i].getPrice();
	}
	if (sumOfAllBusket > cash) {
		cout << "� ��� ������������ �������. ��������� ���� ��� ������� ��� ���� �� �������." << '\n';
		return;
	}
	else if (basket.size() != 0) {
		cout << "������� �� ��� �����. �� ����� ��������� � ��� � ���������� �����.\n";
	}
	else {
		cout << "���� ������� �����\n";
	}
}