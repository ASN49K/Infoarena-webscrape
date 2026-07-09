#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

long long cmmdc(long long a, long long b) {
  while(b) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}


int main() {
  int t;
  long long x, y;
  in >> t;
  for(int i = 1; i <= t; ++i) {
    in >> x >> y;
    out << cmmdc(x, y) << '\n';
  }

  return 0;
}
