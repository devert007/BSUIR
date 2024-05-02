/*Задана матрица размером NxN.
Получить массив В, присвоив его k-му элементу значение 1,
 если элементы k-й строки матрицы упорядочены по убыванию,
  и значение 0 - в противном случае.*/

#include <iostream>
#include <algorithm>
using namespace std;

void function(int **a, int size, int k);

int main()
{
  setlocale(LC_ALL, "Russian");
  int n;
  cin >> n;
  int **a = new int *[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  cout << "введите kтый элемент: ";
  int k;
  cin >> k;
  function(a, n, k);
  return 0;
}

void function(int **a, int size, int k)
{
  bool flag = true;
  for (int i = 0; i < size; i++)
  {
    if (a[k][i] < a[k][i + 1])
    {
      flag = false;
      a[k][k] = 0;
    }
    else
    {
      flag = true;
      a[k][k] = 1;
    }
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << a[i][j];
    }
    cout << '\n';
  }
}
