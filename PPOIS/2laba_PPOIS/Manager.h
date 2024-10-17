#pragma once



#include "Order.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Mig.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Acetaminophen.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Antigistat.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Aspirin.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Diclofenac.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Headflex.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Ibyprofen.h"
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Ketorelac.h"
#include "Human.h"

class Manager :public Human {
private:
	Order order_of_client;
	Order compare_an_order(int indexOfOrder);
	Order sayHelloAndMakeOrder() {
		std::cout << "������ � ���� ������������ �������� "<< this->getName()<< " �� �������� Lekar.by.\n";
		int choose_idnex = 1;
		do {
			std::cout << "�������� ���� �����:\n";
			std::cout << "1.MIG:\n";
			std::cout << "2.HeadFlex:\n";
			std::cout << "3.IBYPROFEN:\n";
			std::cout << "4.ANTIGISTAT:\n";
			std::cout << "5.ACETAMINOPHEN:\n";
			std::cout << "6.ASPIRIN:\n";
			std::cout << "7.DICLOFENAC:\n";
			std::cout << "8.KETOROLAC:\n";
			std::cout << "� ���������� ������� ����� ������ ������� �� ������: \n";
			std::cin >> choose_idnex;
		} while (choose_idnex < 0 || choose_idnex > 9);
		return this->compare_an_order(choose_idnex);
	}
public:
	Manager() {
		this->setName("Olesia");
		this->order_of_client=sayHelloAndMakeOrder();
	}
	Order sendAconfirmationToClient() {
		std::cout << "��� �����: " << this->order_of_client.getName() << ".����: " << this->order_of_client.getPrice() << '\n';
		std::cout << "��� �����?(1-�����, 0-�������): ";
		int choose_client=0;
		std::cin >> choose_client;
		if (choose_client) {
			std::cout << "������� �� ��� �����. �� �������� ��� � �������\n\n";
			return  this->order_of_client;
		}
		else {
			Order emptyOrder ;
			emptyOrder.setName("");
			return emptyOrder;
		}
	}
};
