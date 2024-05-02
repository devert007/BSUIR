#include <iostream>
#define MAX_SIZE 1000
using namespace std;

int main()
{
  char *a = new char[MAX_SIZE];
  cin.getline(a, MAX_SIZE);
  int n = 0;
  while (a[n] != '\0')
    n++;
  cout << n << '\n';
  int count = 0, beg2, beg3, beg4;
  for (int i = 0; i < n; i++)
  {
    if ((i == 0 || a[i - 1] == ' ') && a[i] != ' ')
    {
      count++;
      if (count == 2)
        beg2 = i;
      beg3 = beg4;
      beg4 = i;
    }
  }
  cout << beg3 << '\n';
  int j = 0;
  if (beg3 != 0)
  {

    int countletter = 0;
    for (int i = beg3; a[i] != ' '; i++)
      countletter++;
    cout << countletter;
    if (countletter == 3)
      j = beg3;
    else
      j = beg2;
  }
  for (int i = j; a[i] != ' '; i++)
    cout << a[i];
  delete[] a;
  return 0;
}
