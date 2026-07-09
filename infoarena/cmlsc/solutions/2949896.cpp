#include <bits/stdc++.h>
using namespace std;

const int nmax = 1030;

static int n, m;
static int a[nmax];
static int b[nmax];
static pair<int, int> dp[nmax][nmax];
static int val[nmax][nmax];

void solve() {
  
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (val[i - 1][j] > val[i][j - 1]) val[i][j] = val[i - 1][j], dp[i][j] = {i - 1, j};
      else val[i][j] = val[i][j - 1], dp[i][j] = {i, j - 1};
      if (a[i] == b[j] && val[i - 1][j - 1] + 1 > val[i][j]) val[i][j] = val[i - 1][j - 1] + 1, dp[i][j] = {i - 1, j - 1};
    }
  }

  int i = n, j = m;

  vector<int> res(val[i][j]);
  auto it = res.rbegin();

  while (i && j) {
    if (a[i] == b[j]) *it++ = a[i];
    auto cur = dp[i][j];
    i = cur.first;
    j = cur.second;
  }

  cout << res.size() << '\n';
  for (int r : res) cout << r << ' ';

}

int main() {

  #ifdef LOCAL
  freopen("file.in", "r", stdin);
  #else
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  #endif

  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}