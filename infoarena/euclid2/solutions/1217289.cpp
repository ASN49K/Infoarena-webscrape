#include <fstream>
#include <cstdlib>

inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main() {
  int a, b, T;

  std::ifstream in{"euclid2.in"};
  std::ofstream out{"euclid2.out"};

  in >> T;
  while (in >> a >> b) {
   out << gcd(a, b) << '\n';
  }

  return EXIT_SUCCESS;
}
