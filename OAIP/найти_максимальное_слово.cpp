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
  int index = 0, max_length = 0;
  int cout2_index = 0;
  for (int i = 0; i < n; i++)
  {
    int length = 0;
    if ((i == 0 || a[i - 1] == ' ') && a[i] != ' ')
    {
      index++;
      int index_first = i;

      for (int j = index_first; (a[j] != ' ') && (a[j] != '\0'); j++)
        length++;
      if (max_length <= length)
      {
        max_length = length;
        cout2_index = index;
      }
    }
  }
  cout << cout2_index;
  return 0;
}