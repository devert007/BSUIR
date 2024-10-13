#include <iostream>
#define MAX_SIZE 1000
using namespace std;
bool isLatinLetter(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int main()
{
  char *a = new char[MAX_SIZE];
  int worldcount = 0;
  char firstletter, endletter;
  cin.getline(a, MAX_SIZE);
  int length = 0;
  while (a[length] != '\0')
    length++;
  char *str = new char[MAX_SIZE];
  char *start = a;
  int j = 0;
  int wordcount = 0;
  while (*start)
  {
    while (*start && !isLatinLetter(*start))
      start++;
    if (!*start)
      break;
    char *end = start;
    while (*end && isLatinLetter(*end))
      end++;

    if (*(start) == 'a' || *(start) == 'A')
    {
      int i = 0;
      while (*(start + i) != *(end))
      {
        *str = *(start + i);
        i++;
      }
    }
    start = end;
  }

  int length2 = 0;
  while (str[length2] != '\0')
    length2++;
  for (int i = 0; i < length2 - 1; i++)
    cout << str[i];
  return 0;
}