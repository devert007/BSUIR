#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
      continue;
    if (i == n - 1)
      break;
    if (a[i - 1] + a[i + 1] > 12)
    {
      for (int j = i; j < n; j++)
      {
        a[j] = a[j + 1];
      }
      n--;
    }
    else
      continue;
  }
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  delete[] a;

  return 0;
}