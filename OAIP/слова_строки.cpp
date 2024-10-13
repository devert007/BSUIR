#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX_LENGTH 100

using namespace std;

bool isLatinLetter(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜
int word_count(char *str, int size)
{
  int wordcount = 0;
  char *start = str;
  while (*start)
  {
    while (*start && !isLatinLetter(*start))
      start++;
    if (!*start)
      break;
    char *end = start;
    while (*end && isLatinLetter(*end))
      end++;
    wordcount++;
    start = end;
  }

  return wordcount;
}

// ˜˜˜-˜˜ ˜˜˜˜˜˜˜
int count_of_symbol(char *str, int size, char symbol)
{
  int sum = 0;
  char *start = str; // ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜

  while (*start) // ˜˜˜˜ ˜˜˜˜˜˜˜˜˜ true
  {
    while (*start && !isLatinLetter(*start)) // ˜˜˜˜ ˜˜˜˜˜˜˜˜˜ true ˜˜ ˜˜˜ ˜˜˜ ˜˜ ˜˜˜˜˜(˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜)
      start++;
    if (!*start) // ˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜
      break;

    char *word = start;            // ˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜
    while (*word && isLatinLetter) // ˜˜˜˜ ˜˜˜˜˜˜˜˜˜ true ˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜
    {
      if (static_cast<int>(*word) == static_cast<int>(symbol)) // ˜˜˜˜˜˜˜˜˜˜ ˜˜
        sum++;                                                 // ˜˜˜˜˜˜˜
      word++;                                                  // ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜
    }
    start = word; // ˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜
  }
  return sum;
}

int main()
{
  setlocale(LC_ALL, "Russian");
  char *input = new char[MAX_LENGTH];
  cin.getline(input, MAX_LENGTH);
  int size = sizeof(input) / sizeof(input[0]);
  cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜: " << '\n';
  cout << word_count(input, size) << '\n';
  char k;
  cout << "˜˜˜˜˜˜˜ ˜˜˜˜˜˜ " << '\n';
  cin >> k;
  cout << count_of_symbol(input, size, k) << '\n';
  delete[] input;
  return 0;
}