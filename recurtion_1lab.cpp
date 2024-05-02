#include <iostream>
using namespace std;

double y(int n);
double function(int n);

int main()
{
	cout << "Enter a N: " << '\n';
	int n;
	cin >> n; 
	cout << y(n)<<" simple fu(): "<<function(n);
	return 0;
}

double y(int n)
{
	if (n < 2) return 1 / (1 + 0.5);
	
		return 1 / (n + y(n - 1));
}

double function(int n) {
	double result=1;
	for (int i = 1; i <= n; i++) {
		result = (i == 1) ? ( 1 / (i + 0.5)) : (1/(i + result));
	}
	
	return result;
}