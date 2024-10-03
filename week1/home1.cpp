#include <iostream>
using namespace std;

int main()
{
  int a, b, c, d, f;
  float e;

  f = 3;
  a = 4;

  b = f + 3 * a;
  c = b + 19 % (b - 1);
  d = c / 3 / 2;
  cout << "\n b=" << b << "\n c=" << c << "\n d=" << d;
  e = a + b % 8 / 2.0 * (6 - a);
  cout << "\n e=" << e;

  return 0;
}