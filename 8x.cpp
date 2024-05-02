#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double func(double &sum, int x, double epsilon)
{
  int k = 1;
  sum = 0.0;
  double max = epsilon + 1;

  for (; max > epsilon; k += 2)
  {
    max = 1. / (k * k);
    sum += cos(k * x) * max;
  }
  return (k + 1) / 2;
}
double s(double x)
{
  double sum = 0;
  for (int k = 2;; k++)
  {
    sum += pow(-1, k) * cos(k * x) / (k * k - 1);
    return sum;
  }
}
double y(double x)
{
  return (2 * x * sin(x) - 2 + cos(x)) / 4;
}

int main()
{
  double a, b, h;
  cout << "enter an a " << '\n';
  cin >> a;
  cout << "enter an b" << '\n';
  cin >> b;
  cout << "enter an h " << '\n';
  cin >> h;
  const double e = 1E-4;

  cout << "x" << setw(20) << "S(x)" << setw(20) << "Y(x)"
       << "num of iterations " << '\n';
  for (double x = a; x < b + h / 2; x = x + h)
  {
    double sum_sx = s(x);
    double sum_yx = y(x);
    cout << x << setw(15);
    std::cout << sum_sx << fixed << setprecision(e) << setw(15) << sum_yx << setw(15) << func(sum_sx, x, e) << '\n';
  }

  return 0;
}