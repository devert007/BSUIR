#include <iostream>
using namespace std;
#define MAX_SIZE 1000

bool isLatinLetter(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
void show_words2(char *a);
int main()
{
  char *a = new char[MAX_SIZE];
  cin.getline(a, MAX_SIZE);
  char *start = a;
  char w = 'w';
  while (*start)
  {
    while (*start && !isLatinLetter(*start))
      start++;
    if (!*start)
      break;
    char *end = start;
    int temp = 0;
    while (*end && isLatinLetter(*end))
    {
      if (*(end) == *(end + 1) && *end == 'w')
        temp++;

      end++;
    }
    bool flag = (temp >= 2) ? true : false;
    int j = 0;
    if (flag)
    {
      int i = 0;
      while (*(start + i) != *(end))
      {
        cout << *(start + i);
        i++;
      }
      cout << ' ';
    }
    start = end;
  }
  cout << '\n';
  // show_words2(a);
  return 0;
}
void show_words2(char *a)
{
  char *start = a;
  while (*start)
  {
    while (*start && !isLatinLetter(*start))
      start++;
    if (!*start)
      break;
    char *end = start;
    bool flag = 0;

    while (*end && isLatinLetter(*end))
    {
      end++;
    }

    if (*(start) != *(end - 1) && (*(start + 1) == *(start + 2)))
    {
      int i = 0;
      while (*(start + i) != *(end))
      {
        cout << *(start + i);
        i++;
      }
      cout << '\n';
    }
    start = end;
  }
}