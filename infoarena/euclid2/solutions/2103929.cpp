#include <fstream>

using namespace std;

int t, a, b;

int cmmdc (int d, int i) {
  int r;

  do {
    r = d % i;
    d = i;
    i = r;
  } while (r != 0);
  return d;
}

int main () {
  ifstream fi("euclid2.in");
  ofstream fo("euclid2.out");
  fi >> t;
  for (int i = 1; i <= t; i++)
    fi >> a >> b, fo << cmmdc(a, b) << '\n';
  return 0;
}
