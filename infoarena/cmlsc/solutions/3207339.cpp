#include <fstream>
#include <iostream>
#include <string>

#define ll long long
#define ull unsigned long long
#define pii std::pair<int, int>

#define IO (std::string) "cmlsc"
std::ifstream cin(IO + ".in");
std::ofstream cout(IO + ".out");

#define NMAX 124
int n, m, a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
int LCS(int n, int m) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        continue;
      }

      if (dp[i - 1][j] > dp[i][j - 1])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i][j - 1];
    }
  return dp[n][m];
}

void afis(int i, int j) {
  if (dp[i][j] == 0)
    return;
  if (a[i] == b[j]) {
    afis(i - 1, j - 1);
    cout << a[i] << " ";
    return;
  }
  if (dp[i][j - 1] > dp[i - 1][j])
    afis(i, j - 1);
  else
    afis(i - 1, j);
}

int main() {

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int j = 1; j <= m; j++)
    cin >> b[j];

  cout << LCS(n, m) << '\n';
  afis(n, m);
  return 0;
}
