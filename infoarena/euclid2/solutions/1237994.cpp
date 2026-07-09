#include <fstream>
#include <cstdlib>

inline int gcd(int x, int y) {return 0 == y ? x : gcd(y, x % y);}

int main() {
  int T, a, b;
  std::ifstream in {"euclid2.in"};
  std::ofstream out {"euclid2.out"};
  
  for (in >> T; T; --T) {
    in >> a >> b;
    out << gcd(a, b) << '\n';
  }

  return EXIT_SUCCESS;
}
