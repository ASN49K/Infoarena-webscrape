#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
void solve() {
  int N;
  fin >> N;
  int S = 0;
  for (int i = 0; i < N; i++) {
    int x;
    fin >> x;
    S ^= x;
  }
  fout << (S == 0 ? "NU" : "DA");
}
int main() {
  ios_base::sync_with_stdio(0);
  int T;
  fin >> T;
  while (T--) {
    solve();
    fout << '\n';
  }
  return 0;
}
