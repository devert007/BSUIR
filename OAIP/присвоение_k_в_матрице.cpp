#include <iostream>

using namespace std;
void function1(int **matrix, int size, int k)
{
  int **new_matrix = new int *[size];
  for (int i = 0; i < size; i++)
  {
    new_matrix[i] = new int[size];
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      new_matrix[i][j] = matrix[i][j];
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (new_matrix[i][j] % 2 == 0)
        new_matrix[i][j] = 1;
      else
        new_matrix[i][j] = 0;
    }
  }

  cout << "ваш new массив:" << '\n';
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << '[' << new_matrix[i][j] << ']' << ' ';
    }
    cout << '\n';
  }
}
int main()
{
  int n;
  cin >> n;
  int **matrix = new int *[n];
  for (int i = 0; i < n; i++)
  {
    matrix[i] = new int[n];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];
  }
  cout << "ваш массив:" << '\n';
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << '[' << matrix[i][j] << ']' << ' ';
    }
    cout << '\n';
  }
  int k;
  cin >> k;
  function1(matrix, n, k);
  return 0;
}