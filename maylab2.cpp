#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y, f, a, b; int c;
	cout << "vvedite x : "; 
	          cin >> x;
	cout << "vvedite y : "; 
	          cin >> y ;
	cout << "vvedite f : 1.f=sh(x); 2.f=x^2; 3.f=e^x : ";
	          cin >> c ;
	switch (c)
{
	          case 1 : f = sinh(x); break;
	          case 2 : f = pow(x,2); break; 
	          case 3 : f = exp(x); break;
			  default: cout << "ne vybrali function";
				  return 1;
}
	a = x * y;
	if (a > 0) 
	{
		b = tan(f) + x / (pow(y, 1.0 / 3));
	}	
	else
	if (a < 0)
		b = log(fabs(pow(f, 2) * y));
	else
		b = pow(f, 2) + pow(sin(x), 2);
	cout<< "b = " << b << endl;
}
