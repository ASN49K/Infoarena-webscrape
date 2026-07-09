#include <fstream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b) {
  return 0 == b ? a : gcd(b, a % b);
}

int main() {
  ifstream in{"euclid2.in"};
  ofstream out{"euclid2.out"};

  int T, a, b;
  for(in >> T; T; --T) {
    in >> a >> b;
    out << gcd(a, b) << '\n';
  }

  return 0;
}
