#include <iostream>
#include <math.h>
#include  <iomanip>
using namespace std;
int main()
{
	double a, b, x,y,d, m,s,p,h; 
	int n, i;
	cout << "vvedite a,b,n " << endl;
	cin >> a >> b >>n>>h;
	h = (b - a) / 10;
	x = a;
	while (x <= b+h/2)
	{
		d=m = p = s = 1;
		for (i = 1; i <= n; i++)
		{
			m = 2 * i ^ 2 + 1;
			d *= 2*i;
			p *= (-1) * pow(x, d) *m / d;
			s += p;
		}
		y = (1 - pow(x, 2)) * cos(x) - x * sin(x) / 2;
		cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
		x += h;
	} 
		cout << endl;
	return 0;
}