#include <stdio.h>
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i = a; i < b; i++)

using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int gcd(int a, int b) {
  int c;
  while (a) {
    c = b % a;
    b = a;
    a = c;
  }
  return b;
}

int main(void) {
  int T, a, b;
  fin >> T;
  while (T--) {
    fin >> a >> b;
    fout << gcd(a, b) << '\n';
  }

  return 0;
}
