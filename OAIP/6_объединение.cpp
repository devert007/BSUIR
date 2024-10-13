#include <iostream>
using namespace std;

void function(int *a1, int n, int m, int *a2)
{
  int *a3 = new int[n];
  for (int i = 0; i < n; i++)
  {
    a3[i] = a1[i];
  }
  int temp = n;
  bool flag = true;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a2[i] == a1[j])
      {
        flag = false;
        break;
      }
      else
      {
        flag = true;
      }
    }
    if (flag)
    {
      a3[temp] = a2[i];
      temp++;
    }
  }
  cout << temp << ' ';
  for (int i = 0; i < temp; i++)
    cout << a3[i] << ' ';
  delete[] a3;
}

int main()
{
  int n, m;
  cin >> n >> m;
  int *matrix1 = new int[n];
  int *matrix2 = new int[m];
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    matrix1[i] = temp;
  }
  for (int i = 0; i < m; i++)
  {
    int temp;
    cin >> temp;
    matrix2[i] = temp;
  }
  function(matrix1, n, m, matrix2);
  delete[] matrix1;
  delete[] matrix2;
  return 0;
}