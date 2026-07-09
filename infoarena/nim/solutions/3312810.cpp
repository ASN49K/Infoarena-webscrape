#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef LOCAL
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (; T--;) {
    int N;
    cin >> N;
    int X{0};
    for (int i = 0; i < N; ++i) {
      int Y;
      cin >> Y;
      X ^= Y;
    }
    cout << (X ? "DA" : "NU") << endl;
  }
  return 0;
}
