#include <bits/stdc++.h>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int cmmdc(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main()
{
    int t, a, b;
    fi >> t;
    while (t--) {
      fi >> a >> b;
      fo << cmmdc(a, b) << '\n';
    }
    return 0;
}
