#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int main() {
  #ifdef BLAT
    freopen("stdin", "r", stdin);
    freopen("stderr", "w", stderr);
  #else 
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
  #endif

  cin.tie(0)->sync_with_stdio(0);

  srand(time(NULL));

  int n, m;
  cin >> n >> m;

  vi a(n + 1);
  vi b(m + 1);

  rep(i,1,n+1) cin >> a[i];
  rep(i,1,m+1) cin >> b[i];

  vector<vi> dp(n + 1, vi(m + 1));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      }

      dp[i][j] = max(dp[i][j], dp[i-1][j]);
      dp[i][j] = max(dp[i][j], dp[i][j-1]);
    }
  }

  int nn = n, mm = m;

  vi sol;
  while (nn && mm) {
    if (a[nn] == b[mm]) {
      sol.emplace_back(a[nn]);
      --nn;
      --mm;
    } else if (dp[nn][mm] == dp[nn-1][mm]) {
      --nn;
    } else {
      --mm;
    }
  }

  cout << sol.size() << '\n';
  reverse(all(sol));
  for (auto &x : sol) {
    cout << x << ' ';
  }
  return 0;
}