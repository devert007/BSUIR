#include <iostream>
using namespace std;
#define MAX_SIZE 1000
int main()
{
  char *a = new char[MAX_SIZE];
  cin.getline(a, MAX_SIZE);
  int n = 0;
  while (a[n] != '\0')
    n++;
  int index = 0;
  bool flag = false;
  for (int i = 0; i < n; i++)
  {
    if ((i == 0 || a[i - 1] == ' ') && a[i] != ' ')
    {
      int temp = 0;
      for (int j = i; a[j] != ' '; j++)
        if (a[j] == a[j + 1] && a[j] == 'w')
        {
          temp++;
        }
      bool flag = (temp >= 2) ? true : false;
      if (flag)
      {
        for (int j = i; a[j] != ' '; j++)
          cout << a[j];
        cout << ' ';
      }
    }
  }
  delete[] a;
  return 0;
}