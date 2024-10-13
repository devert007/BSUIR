#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
  int n;
  srand(time(0));
  cin >> n;
  int k, m;
  cin >> k >> m;
  int **matrix = new int *[n];
  for (int i = 0; i < n; i++)
  {
    matrix[i] = new int[n];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      matrix[i][j] = rand() % 10;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
  for (int i = 0; i < n; ++i)
  {
    int temp = matrix[k][i];
    matrix[k][i] = matrix[m][i];
    matrix[m][i] = temp;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  delete[] matrix;
  return 0;
}