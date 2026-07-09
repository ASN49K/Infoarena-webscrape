#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define eb emplace_back
using ll = long long;

ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

ll gcd(ll a, ll b, ll x, ll y) {
  if (!b) {
    x = 1; y = 0;
    return a;
  }
  int x0, y0, d;
  d = gcd(b, a % b, x0, y0);
  x = y0;
  y = x0 - (a / b) * y0;
  return d;
}

void solve() {
  ll a, b, c, x, y, d;
  fin >> a >> b >> c;
  d = gcd(a, b, x, y);
  if (c % d) x = y = 0;
  fout << x * c/d << ' ' << y * c/d << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  fin.tie(0);
  fout.tie(0);

  int t; for (fin >> t; t; --t) solve();
}
