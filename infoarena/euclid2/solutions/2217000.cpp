#include <bits/stdc++.h>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main() {
  int t;
  int a, b;
  fin >> t;
  while (t--) {
    fin >> a >> b;
    while (b > 0) {
      int r = a % b;
      a = b;
      b = r;
    }
    fout << a << '\n';
  }
  return 0;
}
