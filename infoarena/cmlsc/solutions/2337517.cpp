// By Stefan Radu

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define sz(x) (int)(x).size()

typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int main() {

  int n, m;
  cin >> n >> m;

  vector < int > a (n + 1), b (m + 1);

  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; ++ i) {
    cin >> b[i];
  }

  vector < vector < int > > dp (n + 1, vector < int > (m + 1, -1e9));

  dp[1][0] = dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      dp[i][j] = max (dp[i][j - 1], dp[i - 1][j]);
      if (a[i] == b[j] and dp[i][j] < dp[i - 1][j - 1] + 1) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
    }
  }

  vector < int > sol;
  int k = n, l = m;
  while (k) {

    if (a[k] == b[l]) {
      sol.push_back (a[k]);
      -- k;
      -- l;
    }
    else if (dp[k - 1][l] < dp[k][l - 1]) {
      -- l;
    }
    else {
      -- k;
    }
  }

  cout << dp[n][m] << '\n';
  for (int i = sz(sol) - 1; i >= 0; -- i) cout << sol[i] << ' ';
}
