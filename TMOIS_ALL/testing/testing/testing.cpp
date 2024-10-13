#include <iostream>
using namespace std;


bool proverka(int a[], int n)
{
	int res;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				cout << "Введите элементы множества еще раз" << endl;
				return 0;
			}
			else {
				i++;
				if (i >= n && j >= n)return 1;
			}
		}
	}
}

void peresechenie(int a[], int b[])
{
	int c[100];

	for (int i = 0; i < 100; i++)
	{
		for (int j = i+1; j < 100; j++) 
	    {
			if (a[i] == b[j])
				c[i] = a[i];
		}
	}
	for (int i=0;i<100;i++)
	cout <<c[i];

}



int main()
{
	setlocale(LC_ALL, "russian");
	int  i, j, n, m;
	bool N = 0, M = 0;
	int a[100]; int b[100];
	cout << "Введите мощность множества А" << endl;
	while (!N) {
		cin >> n;
		N = (n > 100 || n < 0) ? 0 : 1;
		if (!N) cout << "Введите верную мощность множества А" << endl;
	}

	cout << "Введите элементы множества А" << endl;
	do {
		for (i = 0; i < n; i++)
			cin >> a[i];
	} while (!proverka(a, n));

	cout << "Введите мощность множества B" << endl;
	while (!M) {
		cin >> m;
		M = (m > 100 || m < 0) ? 0 : 1;
		if (!M) cout << "Введите верную мощность множества B" << endl;
	}
	cout << "Введите элементы множества B" << endl;
	do {
		for (j = 0; j < m; j++)
			cin >> b[j];
	} while (!proverka(b, m));
	int* pa = a; int* pb = b;
	peresechenie(a,b);


}