#include <iostream>
using namespace std;

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
    for (int j = 0; j < n; j++)
      matrix[i][j] = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  int num = 1; // число
  int c = 0;   // номер витка
  while (num != n * n + 1)
  {
    for (int i = c; i < n - c; i++) // иду по строкам
    {
      matrix[c][i] = num;
      num++;
      if (i == n - c - 1)
      {

        for (int j = c + 1; j < n - c; j++)
        {
          matrix[j][i] = num;
          num++;
          if (j == n - c - 1)
          {
            for (int k = n - 2 - c; k >= c; k--)
            {
              matrix[j][k] = num;
              num++;
              if (k == c)
              {
                for (int z = n - 2 - c; z > c; z--)
                {
                  matrix[z][c] = num;
                  num++;
                }
              }
            }
          }
        }
      }
    }
    c++;
  }
  cout << '\n';
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}