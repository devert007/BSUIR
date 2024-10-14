
#include "RegistrationWindow.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    RegWindow regMenu;
    regMenu.showMainMenu();
    string name;
    cout << "enter your name: " << '\t';
    getline(cin, name);
    regMenu.showNameMenu(name);
    string email;
     cout << "enter your email: " << '\t';
    getline(cin, email);
    regMenu.showEmailMenu(email);
}
