#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define ull unsigned long long
#define pii std::pair<int, int>

#define IO (std::string) "cmlsc"
std::ifstream cin(IO + ".in");
std::ofstream cout(IO + ".out");

#define NMAX 1200

std::vector<char> LCS(int a[], int b[], int n, int m) {
  int dp[NMAX][NMAX];
  std::vector<char> L[NMAX][NMAX];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        L[i][j] = L[i - 1][j - 1];
        L[i][j].push_back(a[i]);
        continue;
      }

      if (dp[i - 1][j] > dp[i][j - 1]) {
        dp[i][j] = dp[i - 1][j];
        L[i][j] = L[i - 1][j];
      } else {
        dp[i][j] = dp[i][j - 1];
        L[i][j] = L[i][j - 1];
      }
    }
  }
  return L[n][m];
}

int main() {
  int n, m, a[NMAX], b[NMAX];
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  for(int j = 1; j <= m; j++)
    cin >> b[j];

  std::vector<char> ans = LCS(a, b, n, m);
  cout << ans.size() << '\n';
  for(auto it : ans)
    cout << it << ' ';
  return 0; 
}
