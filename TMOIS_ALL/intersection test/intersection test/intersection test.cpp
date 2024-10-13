#include <iostream >


int main()
{
	int i, j, n, k, kol = 0, e;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите мощность множества A (мощность не превышает 10) :";
	std::cin >> n;
	while (n < 0 || n>10)
	{
		std::cout << "Введите верные данные :";
		std::cin >> n;
	}
	std::cout << "Введите мощность множества B (мощность не превышает 10) :";
	std::cin >> k;
	while (k < 0 || k>10)
	{
		std::cout << "Введите верные данные :";
		std::cin >> k;
	}
	int a[10], b[10], c[10];
	std::cout << "Введите элементы множества А(элементы должны быть от 0 до 100) :";
	for (i = 0; i < n; i++)
	{
		std::cin >> a[i];
		while (a[i] < 0 || a[i]>100 || a[i] == a[i + 1])
		{
			std::cout << "неверные данные";
			std::cin >> a[i];
		}
	}
	std::cout << "Введите элементы множества B (элементы должны быть от 0 до 100) :";
	for (j = 0; j < k; j++)
	{
		std::cin >> b[j];
		while (b[j] < 0 || b[j]>100 || b[j] == b[j + 1])
		{
			std::cout << "неверные данные";
			std::cin >> b[j];
		}
	}

}
