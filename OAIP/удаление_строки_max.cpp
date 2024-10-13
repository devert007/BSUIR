#include <iostream>
#include <ctime>
using namespace std;

void deletestr(int **a, int n)
{
  int max = a[0][0];
  int str;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (a[i][j] > max)
      {
        max = a[i][j];
        str = i;
      }
    }
  }
  for (int i = str; i < n - 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      a[i][j] = a[i + 1][j];
    }
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
int main()
{
  srand(time(NULL));
  int n;
  cin >> n;
  int **a = new int *[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      a[i][j] = rand() % 10;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n'
       << '\n';
  deletestr(a, n);
  return 0;
}