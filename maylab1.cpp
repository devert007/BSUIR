#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y, z, a, b, c, s;
	cout << "Введите x: \n";
	cin >> x;
	cout << "Введите y: \n";
	cin >> y;
	cout << "Введите z: \n";
	cin >> z;
	a = pow(y, pow(fabs(x),1.0/3));
	b =  pow(cos(y),3)*fabs(x - y) * (1 + pow(sin(z),2) / sqrt(x + y));
	c = exp(fabs(x-y)) + x / 2;
	s = a + b / c;
	cout << "ОТВЕТ= " << s;
	return 0;
}