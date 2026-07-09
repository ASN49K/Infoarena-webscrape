#include <iostream>
#include <fstream>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  std::ifstream in("euclid2.in");
  std::ofstream out("euclid2.out");
  int tests, a, b;

  in >> tests;
  for (int i = 0; i < tests; ++i) {
    in >> a >> b;
    out << gcd(a, b) << '\n';
  }

  return 0;
}
