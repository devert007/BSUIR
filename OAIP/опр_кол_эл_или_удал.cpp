#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int *mas = new int[n];
  for (int i = 0; i < n; i++)
    cin >> mas[i];
  int size_new = n;
  for (int i = 0; i < n; i++)
  {
    if (mas[i] < 0)
      size_new--;
  }
  cout << "new size " << size_new;
  cout << '\n';

  for (int i = 0; i < n; i++)
  {
    if (mas[i] < 0)
    {
      int index = i;
      for (int j = 0; j < n - 1; j++)
        mas[j] = mas[j + 1];
    }
  }
  for (int i = 0; i < size_new; i++)
    cout
        << mas[i] << ' ';
  // delete[] res;
  delete[] mas;
  return 0;
}