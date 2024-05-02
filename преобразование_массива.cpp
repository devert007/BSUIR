#include <iostream>

using namespace std;

void bias(int *mas, int n, int shift) // функци€ сдвига на shift влево
{
  for (int i = 0; i < shift; i++)
  {
    int temp = mas[0];
    for (int j = 0; j < n - 1; j++)
    {
      mas[j] = mas[j + 1];
    }
    mas[n - 1] = temp;
  }

  for (int i = 0; i < n; i++)
    cout
        << mas[i] << ' ';
}

int main()
{
  int n;
  cin >> n;
  int *mas = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> mas[i];
  }
  int shift;
  cout << "¬ведите на сколько хотите сместить массив: ";
  cin >> shift;
  bias(mas, n, shift);
  return 0;
}