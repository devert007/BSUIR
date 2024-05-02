#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 1000
bool isLatinLetter(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int words(char *a, int n)
{
  int numberWord = 0;
  char *start = a;
  while (*start)
  {
    if (!*start)
      break;
    while (*start && !isLatinLetter(*start))
      start++;
    char *end = start;
    while (*end && isLatinLetter(*end))
      end++;
    int wordlength = end - start;
    start = end;
    if (wordlength == 5)
      numberWord++;
  }
  return numberWord;
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
  cout << length;
  char *start = a;
  while (*start)
  {
    while (*start && !isLatinLetter(*start))
      start++;
    if (!*start)
      break;
    char *end = start;
    while (*end && isLatinLetter(*end))
      end++;

    if (*start == *(end - 1))
    {
      worldcount++;
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
  cout << worldcount;
  /*for (int i = 0; i < length; i++)
    {
      if (!isLatinLetter(a[i]))
        continue;
      char first, end;
      if (!isLatinLetter(a[i - 1]) && isLatinLetter(a[i]))
        first = a[i];
      if (isLatinLetter(a[i]) && (!isLatinLetter(a[i + 1]) || a[i + 1] == '\0'))
        end = a[i];
      if (first == end)
        worldcount++;
        while()
    }
    cout << worldcount << '\n';*/
  cout << words(a, length);
  return 0;
}