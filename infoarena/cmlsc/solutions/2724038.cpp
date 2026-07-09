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

  int N, M, nmax = 1025;
  fin >> N >> M;
  vi a(N+1), b(M+1);
  vector<vi> dp(nmax, vi(nmax, 0));

  rep(i, N) fin >> a[i+1];
  rep(i, M) fin >> b[i+1];

  for(int i = 1; i <= N; i++)
  for(int j = 1; j <= M; j++) {
    if (a[i] == b[j]) {
      dp[i][j] = 1 + dp[i-1][j-1];
    } else {
      dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }

  int ans = dp[N][M], n = N, m = M;
  vi res;

  fout << ans << "\n";
  int k = ans;
  while(k && n && m) {
    if (a[n] == b[m]) {
      --k;
      res.push_back(a[n]);
      --n; --m;
    } else if (dp[n][m] == dp[n-1][m]) {
      --n;
    } else {
      --m;
    }
  }
  reverse(res.begin(), res.end());
  for(auto x: res)
    fout << x << ' ';
  fout << "\n";

  return 0;
}
