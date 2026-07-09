#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while(t--) {
    int a,b;
    cin >> a >> b;
    // while (a != b) {
    //   if (a > b)
    //     a -= b;
    //   else
    //     b -= a;
    // }

    while (b) {
      int r = a % b;
      a = b;
      b = r;
    }

    cout << a << '\n';
  }

  return 0;
}
