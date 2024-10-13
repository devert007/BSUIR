#include <iostream>
using namespace std;

void pow_h(int a, int b)
{
  int stepen = 1;
  for (int i = 0; i < b; i++)
    stepen *= a;
  cout << stepen;
}
int main()
{
  int x, a, b;
  cin >> a >> b;
  pow_h(a, b);
  return 0;
}