#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("nim.in");
    ofstream cout("nim.out");

    int tests;
    cin >> tests;

    while (tests--) {
          int n; cin >> n;
          int rez = 0;
          for(int i = 0; i < n; ++i) {
              int x; cin >> x;
              rez ^= x;
          }

          if(rez == 0) cout << "NU\n";
          else cout << "DA\n";
    }

    return 0;
}
