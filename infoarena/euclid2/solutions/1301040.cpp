#include <fstream>

using namespace std;

int t, a, b, i;

int cmmdc (int d, int i) {
  int r;

  do {
    r = d % i;
    d = i;
    i = r;
  } while (r);
  return d;
}

int main () {
  ifstream fi("euclid2.in");
  ofstream fo("euclid2.out");
  fi >> t;
  for (i = 1; i <= t; i++)
    fi >> a >> b, fo << cmmdc(a, b) << '\n';
  return 0;
}
