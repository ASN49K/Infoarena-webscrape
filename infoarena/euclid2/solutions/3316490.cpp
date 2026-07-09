#include <bits/stdc++.h>
using namespace std;

// !!!
string PREFIX = "euclid2";

int get_gcd(int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;

  int common = 1;
  while ( (!(x&1)) && (!(y&1))) {
    common <<= 1;
    x >>= 1;
    y >>= 1;
  }
  while (!(x&1)) {
    x >>= 1;
  }
  while (!(y&1)) {
    y >>= 1;
  }
  // acum ambele numere sunt impare.
  if (x < y) swap(x, y);
  return common * get_gcd(x - y, y);
}

int main()
{
  ifstream cin(PREFIX + ".in");
  ofstream cout(PREFIX + ".out");

  int t;
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    cout << get_gcd(x, y) << '\n';
  }

}