#include <stdio.h>
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int gcd(int a, int b) {
  while(b > 0) {
    tie(a,b) = pii {b, a%b};
  }

  return a;
}

int main(void) {
  // freopen("euclid2.in", "r", stdin);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T, a, b;
  fin >> T;

  while(T--) {
    fin >> a >> b;
    fout << gcd(a, b) << '\n';
  }

  return 0;
}
