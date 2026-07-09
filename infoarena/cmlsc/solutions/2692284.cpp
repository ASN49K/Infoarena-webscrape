#include <stdio.h>
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int main(void) {
  // freopen("cmlsc.in", "r", stdin);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int N, M;
  fin >> M >> N;

  vi a(M+1), b(N+1);
  rep(i,M) { fin >> a[i+1]; }
  rep(i,N) { fin >> b[i+1]; }

  vector<vi> dp(M+1, vi(N+1));

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  int ans = dp[M][N];
  fout << ans << "\n";
  // for(int i = 1; i <= M; ++i) {
  //   for(int j = 1; j <= N; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  vi res;
  int m = M, n = N;
  while(ans) {
    if (a[m] == b[n]) {
      res.push_back(a[m]);
      --ans;
      --m;
      --n;
    } else if (m > 0 && dp[m][n] == dp[m-1][n]) {
      --m;
    } else {
      --n;
    }

  }
  reverse(res.begin(), res.end());
  for(auto el: res) { fout << el << ' '; } fout << "\n";

  return 0;
}
