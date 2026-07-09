#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }

int main() {
  int T, a, b;
  f >> T;
  while (T-- > 0) {
    f >> a >> b;
    g << gcd(a, b) << '\n';
  }
  f.close();
  g.close();
}