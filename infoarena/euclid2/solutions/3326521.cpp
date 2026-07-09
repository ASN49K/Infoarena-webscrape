#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b) {
  if (!b)
    return a;
  if (a > b)
    return gcd(a - b, b);
  return gcd(a, b - a);
}

void solve() {
  int a, b;
  f >> a >> b;
  g << gcd(a, b);
}

int main() {
  int cases;
  f >> cases;
  while (cases--) {
    solve();
    g << "\n";
  }
}
