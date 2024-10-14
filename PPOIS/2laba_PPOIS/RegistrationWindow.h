#pragma once
#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <iostream>
#include <string>
using namespace std;
class RegWindow {
private:
	std::string mainMenu =
		"\t\t |------------------------------------------------------|\n\
		 |\t\tHello.Welcome to Lekar.by!\t\t|\n\
		 |------------------------------------------------------|\n\
		 |\t\tplease authorize\t\t\t|\n\
		 |------------------------------------------------------|\n\
		 |                                                      |\
";
	std::string name =
		"\t\t |\t\t\tNAME:";
	std::string email =
		"\t\t |\t\t\tEMAIL:";
public:
void showMainMenu() {
	std::cout << mainMenu << '\n';
}
void showNameMenu(string name) {
	std::cout << this->name<< name<<"\t\t \t| " << '\n';
}
void showEmailMenu(string email) {
	std::cout << this->email<<email <<"\t\t\t| " << '\n';
}
};
#endif