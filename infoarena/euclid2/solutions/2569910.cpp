#include <bits/stdc++.h>
#define dbg() cerr <<
#define name(x) (#x) << ": " << (x) << ' ' <<

using namespace std;

int main() {
  ifstream cin("euclid2.in");
  ofstream cout("euclid2.out");

  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    while (b) {
      a %= b;
      swap(a, b);
    }
    cout << a << '\n';
  }
}
