#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
#ifdef INFOARENA
  freopen ("euclid2.in", "r", stdin);
  freopen ("euclid2.out", "w", stdout);
#else
  freopen ("input.txt", "r", stdin);
#endif // INFOARENA

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    cout << g << "\n";
  }
  return 0;
}
