#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n";

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;

int main() {
  in >> t;
  while (t --) {
    int a, b;
    in >> a >> b;
    out << __gcd(a, b) << "\n";
  }
  return 0;
}
