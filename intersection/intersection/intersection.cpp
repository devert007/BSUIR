

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k,i,j;
	int m = 0;
	std::cout << "Введите мощность множества А (до 10 элементов) :";
	std::cin >> n;
	std::cout << "Введите мощность множества B (до 10 элементов) :";
	std::cin >> k;
	int a[10], b[10];
	std::cout << "Введите элементы множества А (элементы должны быть от 0 до 100): ";
	for (i=0;i<n;i++)
	std::cin >> a[i];

	std::cout << "Введите элементы множества B (элементы должны быть от 0 до 100): ";
	for (j=0;j<n;j++)
	std::cin >> b[j];
	for (i = 0; i < n; i++) 
	{
		while (a[i] == a[i + 1])
			std::cout << "Введите элементы корректно (элементы множества не должны быть равны)";
	}
	for (j = 0; j< k; j++)
	{
		while (b[j] == b[j + 1])
			
			std::cout << "Введите элементы корректно (элементы множества не должны быть равны)";
	}
	int c[10], el;
	for (i = 0; i < n; i++)
		for (j = 0; j < k; j++)
		{
			if (a[i] == b[j])
			{
				for (el = 0; el < m; el++)
					c[el] = a[i];
			}
		}
	for(el=0;el<m;el++)
	std::cout << c[el];
}
