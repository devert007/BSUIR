#pragma once
#include "D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Order.h"
class Diclofenac :public Order {
private:
	Company company;
public:
	Diclofenac() {
		setName("DICLOFENAC");
		setPrice(40);
		setInfoAboutOrder("Diclofenac � ��� ������������� ��������, ������� �������� ����������, ���� �� �������� ������������ ��������������������� ���������� (NSAIDs), ������������� �� �������� ������� �������� � ���������� ������������ �����������.\n\n�������� ������������ Diclofenac:\n1. �������� �������� ��������: Diclofenac �������� ������� ������� �������� ��� ��������� ������������, ����� ���������� ��������� ������������ �������, ����� ��� �������� ������������� ���������, ������� �������� ��������� ��������� �������� ��������.\n2. ��������� ����������� ��������: Diclofenac ����� ������ �������� ����������� ��������, ��������� �� ������� ������� ��������� � �����, ��� �������� � ����� ������� � ������ ������ ������� �������.\n3. ����������� ����������� ����: Diclofenac �������� ������������ ����������� ���� � ���������� ���������, ��������� �� ������� ��������� �������, ������������� �� ��������� �����������, ����� ��� ��������� � ��������.");
		this->company.setName("BelAptekaFarm");
	}
	string getSupplierName() {
		return this->company.getName();
	}
};
