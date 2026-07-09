#include <fstream>


int gcd(int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int main() {
  std::ifstream in {"euclid2.in"};
  std::ofstream out {"euclid2.out"};

  int T, x, y;

  for (in >> T; T; --T) {
    in >> x >> y;
    out << gcd(x, y) << '\n';
  }

  return 0;
}
