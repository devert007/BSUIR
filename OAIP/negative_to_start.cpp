#include <iostream>
using namespace std;

void function(int *a, int n)
{
  int j = 0;
  for (int i = 0; i < n; i++)
  {

    if (a[i] < 0)
    {
      int temp = a[j];
      a[j] = a[i];
      a[i] = temp;
      j++;
    }
  }
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
}
int main()
{
  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  function(a, n);

  return 0;
}