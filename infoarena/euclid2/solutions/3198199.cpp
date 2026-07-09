#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
  int t;
  fin >> t;

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

    fout << a << '\n';
  }

  return 0;
}
